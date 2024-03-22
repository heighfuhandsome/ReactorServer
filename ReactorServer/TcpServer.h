#pragma once
#include "noncopyable.h"
#include "Acceptor.h"
#include "EventLoopThreadPoll.h"
#include <memory>
#include <unordered_map>
class TcpConnect;
class TcpServer : noncopyable{
public:
private:
    std::unique_ptr<Acceptor> acceptor_;
    std::unique_ptr<EventLoopThreadPoll> loopThreadPoll_;
    std::unordered_map<uint64_t,std::shared_ptr<TcpConnect>> connectContainer_;
    uint64_t connectId_;
};