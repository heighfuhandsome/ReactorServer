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

class TcpServer;
class TcpConnect :noncopyable,public std::enable_shared_from_this<TcpConnect>{
    friend class TcpServer;
public:
    explicit TcpConnect(EventLoop *loop,int fd,const InetAddr &localAddr,const InetAddr &peerAddr,uint64_t id);
    void send(const std::string &msg);
    std::any& getContext() {return context_;}
    template <typename T>
    void setContext(T &&t){ context_ = t;}
    const InetAddr &peerAddr() const { return peerAddr_; }
    ConnStatus connStatus() const {return status_;}
private:
    void handlerRead();
    void handlerClose();
    void handlerWrite();

    void setConnectCallBack(const std::function<void(const std::shared_ptr<TcpConnect>&)> &func){ connectCallBack_ = func; }
    void setCloseCallBack(const std::function<void(uint64_t)> &func){  closeCallBack_= func; }
    void setWriteCompleteCallBack(const std::function<int(const std::shared_ptr<TcpConnect>&)> &func){ writeCompleteCallBack_= func; }
    void setReadCallBack(const std::function<void(const std::shared_ptr<TcpConnect>&,Buffer &buffer)> &func){  readCallBack_ = func; }
    void establish() ;
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
    uint64_t id_;

    std::function<void(const std::shared_ptr<TcpConnect>&)> connectCallBack_;
    std::function<int(const std::shared_ptr<TcpConnect>&)> writeCompleteCallBack_;
    std::function<void(uint64_t)> closeCallBack_;
    std::function<void(const std::shared_ptr<TcpConnect>&,Buffer &buffer)> readCallBack_;
};