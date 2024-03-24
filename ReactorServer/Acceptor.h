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
    void start() const;
    void setAcceptCallBack(const std::function<void(int,const InetAddr &,const InetAddr &)> func){  acceptCallBack_ = func; }
    InetAddr bindAddr() const {return bindAddr_;}
private:
    void accept();
private:
EventLoop *loop_;
std::unique_ptr<Socket> listenSocket_;
std::unique_ptr<Channel> acceptChannel_;
std::function<void(int,const InetAddr &localAddr,const InetAddr &peerAddr)> acceptCallBack_;
InetAddr bindAddr_;
int mfd_;
};