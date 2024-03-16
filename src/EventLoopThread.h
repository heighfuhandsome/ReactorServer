#pragma once
#include "noncopyable.h"
#include <vector>
#include "EventLoop.h"
#include <cassert>
class EventLoopThread:noncopyable{
public:
    EventLoopThread(unsigned char size):size_(size){
        loops_.reserve(size);
    }

    void start()
    {
        for(int i=0;i<size_;i++)
        {
            
        }
    }
    void stop()
    {

    }

    void initThread(EventLoop **loop){
        
    }
private:



private:
    unsigned char size_;
    std::vector<std::unique_ptr<EventLoop>> loops_;
};