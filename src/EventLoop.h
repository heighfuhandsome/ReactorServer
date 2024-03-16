#pragma once
#include "noncopyable.h"
#include <atomic>
#include "Channel.h"
#include "Dispatch.h"
#include <unordered_map>
#include <memory>
#include <functional>
#include <mutex>
#include <thread>
class EventLoop:noncopyable{
public:
    EventLoop();
    void loop();
    void stop() { loop_ = false;}

    void updateChannel(Channel *Channel);
    void removeChannel(Channel *Channel);
    void addFunc(std::function<void()> &func);

private:
    void doFunc();
    void weakUp();
private:
    std::atomic_bool loop_;
    std::unordered_map<int,Channel*> ChannelMap_; 
    std::unique_ptr<Dispatch> dispatch_;
    std::mutex mutex_;
    std::vector<std::function<void()>> func_;
    bool callFunc_;
    std::unique_ptr<Channel> weakUpChannel_;
    int  weakUpFd_;
    std::thread::id tid_;
    std::string name_;
    static std::atomic_int sequence;

    std::atomic_int connCnt_;
};