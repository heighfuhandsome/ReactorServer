
#include "EventLoopThreadPoll.h"
#include "EventLoop.h"
#include "Logger.h"

void EventLoopThreadPoll::createEventLoop(EventLoop **loop) {
    EventLoop loop1;
    {
        std::lock_guard<std::mutex> guard(mutex_);
        *loop = &loop1;
        cond_.notify_one();
    }
    loop1.loop();
}

EventLoop *EventLoopThreadPoll::getLoop() const{
    EventLoop *loop = loops_[0];
    for(auto i : loops_)
    {
        if (i->getConnCnt() < loop->getConnCnt())
            loop = i;
    }

    return loop;
}

void EventLoopThreadPoll::start() {

    auto size = size_;
    do{
        EventLoop *loop = nullptr;
        std::thread t([this,loop=&loop]{
            createEventLoop(loop);
        });
        std::unique_lock<std::mutex> guard(mutex_);
        cond_.wait(guard,[&]{
            return loop;
        });
        loops_.push_back(loop);
        t.detach();
    }while(--size);

}

