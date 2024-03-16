#include "Dispatch.h"
#include "Channel.h"
#include "Logger.h"
#include <cassert>
Dispatch::Dispatch(EventLoop *loop):loop_(loop)
{
    efd_ = ::epoll_create1(EPOLL_CLOEXEC);
    if (efd_<0)
    {
        LOG_FATAL("%s",strerror(errno));
    }
    events_.reserve(128);
}

void Dispatch::updateChannel(Channel *channel, std::unordered_map<int, Channel *> &map)
{
    u_char index = channel->index();
    int fd = channel->fd();
    if ((index==Channel::KDeled) || (index==Channel::KNew))
    {
        if (index==Channel::KNew)
        {
          assert(map.find(fd) == map.end());  
        }else{
          assert(map.find(fd) != map.end());  
        }
        update(channel,EPOLL_CTL_ADD);
        channel->setIndex(Channel::KAdded);
    }else{
        assert(map.find(fd) != map.end());
        if (channel->isNoneEvent())
        {
            update(channel,EPOLL_CTL_DEL);
            channel->setIndex(Channel::KDeled);
        }else{
            update(channel,EPOLL_CTL_MOD);
        }
    }
}

void Dispatch::dispatch(std::unordered_map<int,Channel *>& Channels)
{
    int len = epoll_wait(efd_,&(*events_.begin()),static_cast<int>(events_.size()),-1);
    if (len < 0)
    {
        LOG_ERROR("%s",strerror(errno));
    }else{
        for(struct epoll_event &e : events_){
            Channels[e.data.fd]->handerEvent(static_cast<int>(e.events));
        }
        if (len == events_.size())
            events_.resize(events_.size()*2);
    }
    
}

void Dispatch::update(Channel *channel, int operation)
{
    int fd = channel->fd();
    struct epoll_event event;
    event.data.fd = fd;
    event.events = channel->events();
    int ret = ::epoll_ctl(efd_,operation,fd,&event);
    if (ret == -1 )
    {
        LOG_ERROR("%d %s : %s",operationToStr(operation),strerror(errno));
        if (operation == EPOLL_CTL_ADD)
        {
            exit(-1);
        }
        
    }
}

const char *Dispatch::operationToStr(int operation)
{
    switch(operation)
    {
        case EPOLL_CTL_ADD : return "EPOLL_CTL_ADD";
        case EPOLL_CTL_MOD: return "EPOLL_CTL_MOD";
        case EPOLL_CTL_DEL: return "EPOLL_CTL_DEL";
    }   
    return "";
}
