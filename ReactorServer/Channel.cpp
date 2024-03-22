#include "Channel.h"
#include "EventLoop.h"
Channel::Channel(EventLoop *loop,int fd):fd_(fd),loop_(loop),index_(KNew),events_(0)
{
}

void Channel::handerEvent(int event)
{
    if (event & EPOLLERR)
    {
        if (errorCalback_)
            errorCalback_();
    }

    if (event & EPOLLHUP)
    {
        if(closeCallback_)
            closeCallback_();   
        return;
    }

    if (event & (EPOLLIN | EPOLLPRI | EPOLLRDHUP))
    {
        if (readCallback_)
            readCallback_();
    }

    if (event & EPOLLOUT)
    {
        if (writeCallback_)
            writeCallback_();
    }
}

void Channel::updateEvent()
{
    loop_->updateChannel(this);
}
