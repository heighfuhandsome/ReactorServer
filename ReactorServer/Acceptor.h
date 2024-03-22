#pragma once
#include "noncopyable.h"
#include "InetAddr.h"
#include "Channel.h"
#include "Socket.h"
#include <memory>


class EventLoop;
class Acceptor:noncopyable{
public:
    explicit Acceptor(EventLoop *loop,const InetAddr &addr);
    ~Acceptor() = default;
private:
    void accept();
private:
EventLoop *loop_;
std::unique_ptr<Socket> listenSocket_;
std::unique_ptr<Channel> acceptChannel_;
int mfd_;
};