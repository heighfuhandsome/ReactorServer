#pragma once
#include "noncopyable.h"
#include <sys/epoll.h>
#include <functional>
enum EVENT_TYPE{
    READ = EPOLLIN | EPOLLPRI,
    WRITE = EPOLLOUT ,
    CLOSE =  EPOLLHUP,
    ERROR = EPOLLERR
};

class EventLoop;

class Channel : noncopyable{
    typedef std::function<void()> CallBack;
    typedef unsigned char uchar;
public:
    Channel(EventLoop *loop,int fd);
public:
    const static uchar KNew = 1;
    const static uchar KAdded = 2;
    const static uchar KDeled = 3;

    int fd(){return fd_;}
    int index() {return index_;}
    int events(){return events_;}
    void setIndex(u_char index){index_ = index;}
    void setReadCallBack(CallBack func){ readCallback_ = std::move(func); }
    
    void handerEvent(int event);
    void enableRead() { events_ |= EPOLLIN;updateEvent(); }
    void enableWrite(){ events_ |= EPOLLOUT;updateEvent();}
    void disableRead() { events_ &= ~EPOLLIN; updateEvent(); }
    void disableWrite() {events_ &= ~EPOLLOUT;updateEvent();}
    void disableAll() {events_ = 0;updateEvent();};


    bool isReading(){return events_ & EPOLLIN; }
    bool isWriting(){return events_ & EPOLLOUT;}
    bool isNoneEvent(){return events_ == 0;}
private:
    void updateEvent();
private:
    CallBack readCallback_;
    CallBack writeCallback_;
    CallBack closeCallback_;
    CallBack errorCalback_;
    EventLoop *loop_;
    int fd_;
    int events_;
    

    uchar index_;

};