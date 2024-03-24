#pragma once
#include "noncopyable.h"
#include <vector>
#include <cassert>
#include <mutex>
#include <condition_variable>
#include <memory>

class EventLoop;
class EventLoopThreadPoll:noncopyable{
public:
    explicit EventLoopThreadPoll():size_(0){
    }

    unsigned char size()const{return size_;}
    void setPollSize(uint8_t size) { size_ = size;}
    void start();
//    void stop() const;
    EventLoop* getLoop() const ;
private:
    void createEventLoop(EventLoop **loop);
private:
    uint8_t size_;
    std::vector<EventLoop*> loops_;
    std::mutex mutex_;
    std::condition_variable cond_;
};