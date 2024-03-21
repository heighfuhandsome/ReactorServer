#pragma once
#include "noncopyable.h"
#include <unordered_map>
#include <sys/epoll.h>
#include <vector>
#include <cstdlib>

class EventLoop;
class Channel;
class Dispatch:noncopyable{
public:
    Dispatch(EventLoop *loop);
    ~Dispatch();
    void updateChannel(Channel *channel,std::unordered_map<int,Channel*> &map);
    void dispatch(std::unordered_map<int,Channel*>&);
private:
    void update(Channel *channel,int operation);
    const char* operationToStr(int operation);
private:
    int efd_;
    struct
    {
        epoll_event *events_;
        int currentSize_;
        void expend()
        {
            epoll_event *newArr = (epoll_event*)::malloc(sizeof(epoll_event) * currentSize_ * 2);
            currentSize_ *=2;
            if (events_)
            {
                free(events_);
                events_ = nullptr;
            }
            events_ = newArr;
               
        }
    }epollEvents_;
    
    EventLoop *loop_;
};