#pragma once
#include "noncopyable.h"
#include "Channel.h"
#include "Socket.h"
#include "Buffer.h"
#include <any>
#include <memory>
enum class ConnStatus{
    CONNECTED,
    DISCONNECT
};


class TcpConnect :noncopyable,std::enable_shared_from_this<TcpConnect>{
public:
    explicit TcpConnect(EventLoop *loop,int fd,const InetAddr &localAddr,const InetAddr &peerAddr);
    void send(const std::string &msg);
    std::any& getContext() {return context_;}
    template <typename T>
    void setContext(T &&t){ context_ = t;}
private:
    void handlerRead();
    void handlerClose();
    void handlerWrite();
private:
    std::unique_ptr<Channel> channel_;
    std::unique_ptr<Socket> socket_;
    InetAddr localAddr_;
    InetAddr peerAddr_;
    EventLoop *loop_;
    ConnStatus status_;
    Buffer in_;
    Buffer out_;
    std::any context_;
    std::function<void(const std::shared_ptr<TcpConnect>)> connectCallBack_;
    std::function<int(const std::shared_ptr<TcpConnect>)> writeComplteteCallBack_;
    std::function<void(const std::shared_ptr<TcpConnect>)> closeCallBack_;
    std::function<void(const std::shared_ptr<TcpConnect>,Buffer &buffer)> readCallBack_;
};