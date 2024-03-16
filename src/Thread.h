#pragma once
#include "noncopyable.h"
#include <thread>
#include "EventLoop.h"
#include <cassert>
class Thread:noncopyable{
    Thread(){ running_ = false;}
    EventLoop* start()
    {
        
    }


private:
    bool running_;
};