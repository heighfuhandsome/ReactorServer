#include "Acceptor.h"
#include "Logger.h"
#include "EventLoop.h"
#include <fcntl.h>

static int createLfd()
{
    int fd = ::socket(AF_INET,SOCK_STREAM,0);
    if (fd>0)
    {
        return fd;
    }
    LOG_FATAL("%s",strerror(errno));
    return -1;
}


Acceptor::Acceptor(EventLoop *loop, const InetAddr &addr):loop_(loop),mfd_(::open("/dev/null",O_RDONLY)) {
    auto *socket = new Socket(createLfd());
    socket->setNonBlocking();
    socket->reusePort();
    socket->reuseAddr();
    socket->bind(addr);
    socket->listen();
    listenSocket_.reset(socket);
    LOG_INFO("listen fd is %d",listenSocket_->fd());

    auto *channel = new Channel(loop,listenSocket_->fd());
    channel->setReadCallBack([this](){
        accept();
    });

    channel->enableRead();
    acceptChannel_.reset(channel);
}

void Acceptor::accept() {
    sockaddr addr;
    socklen_t len = static_cast<socklen_t>(sizeof addr);
    int cfd = ::accept(acceptChannel_->fd(),&addr,&len);
    if (cfd == -1){
        if (errno == EMFILE)
        {
            ::close(mfd_);
            ::close(::accept(acceptChannel_->fd(), nullptr, nullptr));
            mfd_ = ::open("/dev/null",O_RDONLY);
        }
        LOG_ERROR("%s", strerror(errno));
        return;
    }

    

    // auto channelPtr = std::make_unique<Channel>(loop_,cfd);
    // auto socket = std::make_unique<Socket>(cfd);
    // socket->setNonBlocking();
    // channelPtr->setReadCallBack([&]{
    //     LOG_INFO("%d get readCallback",channelPtr->fd());
    //     char buff[128]{0};
    //     ::read(channelPtr->fd(),buff,sizeof buff);
    //     LOG_INFO("%s",buff);
    // });

    // channelPtr->setCloseCallBack([&]{
    //     LOG_INFO("%d disconnect",channelPtr->fd());
    //     socket.reset();
    //     channelPtr.reset();
    // });
    // channelPtr->enableRead();
}
