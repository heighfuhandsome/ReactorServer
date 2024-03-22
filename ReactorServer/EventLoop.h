#pragma once
#include "noncopyable.h"
#include "Dispatch.h"
#include "Channel.h"
#include <atomic>
#include <unordered_map>
#include <functional>
#include <mutex>
#include <thread>
#include <memory>

class EventLoop:noncopyable{
public:
    EventLoop();
    ~EventLoop() = default;
    void loop();
    void stop() { loop_ = false;}

    void updateChannel(Channel *Channel);
    void removeChannel(Channel *Channel);
    void addFunc(const std::function<void()> &func);
    bool isInLoopThread()
    {
        return tid_ == std::this_thread::get_id();
    }
private:
    void doFunc();
    void weakUp();

private:
    std::atomic_bool loop_;
    std::unordered_map<int,Channel*> ChannelMap_; 
    std::unique_ptr<Dispatch> dispatch_;
    std::mutex mutex_;
    std::vector<std::function<void()>> func_;
    std::atomic_bool callFunc_;
    std::unique_ptr<Channel> weakUpChannel_;
    int  weakUpFd_;
    std::thread::id tid_;
    std::string name_;
    static std::atomic_int sequence;

    std::atomic_int connCnt_;
};