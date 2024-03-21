#pragma once
#include "noncopyable.h"
#include "Socket.h"
#include "Channel.h"
#include "InetAddr.h"

#include <memory>

class EventLoop;
class Socket;
class Channel;

class Acceptor:noncopyable{
public:
    explicit Acceptor(EventLoop *loop,const InetAddr &addr);
private:
    void accept();
private:
EventLoop *loop_;
std::unique_ptr<Socket> listenSocket_;
std::unique_ptr<Channel> acceptChannel_;
int mfd_;
};