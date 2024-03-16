#pragma once
#include "noncopyable.h"
#include <unordered_map>
#include <sys/epoll.h>
#include <vector>

class EventLoop;
class Channel;
class Dispatch:noncopyable{
public:
    Dispatch(EventLoop *loop);
    void updateChannel(Channel *channel,std::unordered_map<int,Channel*> &map);
    void dispatch(std::unordered_map<int,Channel*>&);
private:
    void update(Channel *channel,int operation);
    const char* operationToStr(int operation);
private:
    std::vector<epoll_event> events_;
    int efd_;
    EventLoop *loop_;
};