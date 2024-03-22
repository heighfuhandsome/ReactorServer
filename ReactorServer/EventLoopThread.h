#pragma once
#include "noncopyable.h"
#include <vector>
#include <cassert>
#include <mutex>
#include <condition_variable>
#include <memory>

class EventLoop;
class EventLoopThread:noncopyable{
public:
    explicit EventLoopThread(unsigned char size):size_(size){
        loops_.reserve(size);
    }

    unsigned char size()const{return size_;}

    void start();
    void stop();
private:
    void initThread(EventLoop **returnLoop);

private:
    unsigned char size_;
    std::vector<std::shared_ptr<EventLoop>> loops_;
    std::mutex mutex_;
    std::condition_variable cond_;
};