#include "EventLoop.h"
#include <cassert>
#include <sys/socket.h>
#include "Logger.h"
thread_local EventLoop *eventloop = nullptr;
std::atomic_int EventLoop::sequence = 0;
EventLoop::EventLoop():callFunc_(false),loop_(false),connCnt_(0)
{
    if (eventloop)
    {
        LOG_FATAL("eventloop repeat create");
    }
    eventloop = this;
    dispatch_ = std::make_unique<Dispatch>(this);
    int pair[2];
    if(::socketpair(AF_UNIX,SOCK_STREAM,0,pair) == -1){
        LOG_FATAL("%s",strerror(errno));
    }
    weakUpChannel_ = std::make_unique<Channel>(this,pair[0]);
    weakUpFd_ = pair[1];
    weakUpChannel_->setReadCallBack([this]{
        char buff[128];
        ::recv(this->weakUpChannel_->fd(),buff,sizeof buff,0);
//        LOG_INFO("%s is weak up",name_.c_str());
    });
    tid_ = std::this_thread::get_id();
    char nameBuf[128]{0};
    snprintf(nameBuf,sizeof nameBuf,"EventLoop%d",sequence++);
    name_ = std::string(nameBuf);
    weakUpChannel_->enableRead();
}

void EventLoop::loop()
{
    assert(!loop_);
    loop_ = true;
    while (loop_)
    {
        dispatch_->dispatch(ChannelMap_);
        doFunc();
    }
}

void EventLoop::updateChannel(Channel *Channel)
{
    if (!isInLoopThread())
    {
        addFunc([this,channel = Channel](){
            updateChannel(channel);
        });
        return;
    }
    
    if (Channel->index() == Channel::KNew)
    {
        connCnt_ ++;   
        ChannelMap_[Channel->fd()] = Channel;
    }
    
    dispatch_->updateChannel(Channel,ChannelMap_);
    
    if (Channel->index() == Channel::KDeled)
    {
        connCnt_ --;
        ChannelMap_.erase(Channel->fd());
    }
}

void EventLoop::addFunc(const std::function<void()> &func)
{
    {
        std::lock_guard<std::mutex> guard(mutex_);
        func_.push_back(func);
    }
    if(!(std::this_thread::get_id()==tid_ )|| callFunc_) 
    {
        weakUp();
    }
}

void EventLoop::doFunc()
{
    std::vector<std::function<void()>> func;
    {
        std::lock_guard<std::mutex> guard(mutex_);
        func.swap(func_);
        callFunc_ = true;
    }

    for(auto &f : func){
        f();
    }
    callFunc_  = false;
}

void EventLoop::weakUp()
{
    int len = ::send(weakUpFd_,"hello",5,0);
    if (len<0)
    {
        LOG_ERROR("weakup fail ");
    }
    
}