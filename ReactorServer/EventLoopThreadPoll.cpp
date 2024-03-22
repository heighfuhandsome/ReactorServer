//
// Created by jiexiao on 2024/3/20.
//
#include "EventLoopThreadPoll.h"
#include "EventLoop.h"
void EventLoopThreadPoll::start() {
    for(int i=0;i<size_;i++)
    {
        std::unique_lock<std::mutex> mutex(mutex_);
        EventLoop *loop = nullptr;
        std::thread t([this,&loop]{
            initThread(&loop);
        });
        cond_.wait(mutex,[&](){
            return loop;
        });
        loops_.push_back(std::shared_ptr<EventLoop>(loop));
        t.detach();
    }

}

void EventLoopThreadPoll::stop() {
    for(auto &e:loops_)
    {
        e->stop();
    }
}

void EventLoopThreadPoll::initThread(EventLoop **returnLoop) {
    EventLoop loop;
    {
        std::lock_guard<std::mutex> guard(mutex_);
        *returnLoop = &loop;
        cond_.notify_one();
    }
    loop.loop();
}
