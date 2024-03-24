#pragma once
#include "noncopyable.h"
#include "Acceptor.h"
#include "EventLoopThreadPoll.h"
#include "EventLoop.h"
#include <memory>
#include <unordered_map>
class TcpConnect;
class Buffer;
class TcpServer : noncopyable{
public:
    explicit TcpServer(const InetAddr &bindAddr):acceptor_(std::make_unique<Acceptor>(&mainLoop_,bindAddr)),poolSize_(0),connectId_(0),start_(false){
        connectContainer_.reserve(1024);
        using namespace std::placeholders;
        acceptor_->setAcceptCallBack(std::bind(&TcpServer::createConnect,this,_1,_2,_3));
    }
    void setPoolSize(uint8_t size){ poolSize_ = size; };
    void start() ;

    //setCallBack
    void setConnectCallBack(const std::function<void(const std::shared_ptr<TcpConnect>&)> &func){ connectCallBack_ = func;}
    void setWriteCompleteCallBack(const std::function<int(const std::shared_ptr<TcpConnect>&)> &func){ writeComplteteCallBack_= func; }
    void setReadCallBack(const std::function<void(const std::shared_ptr<TcpConnect>&,Buffer &buffer)> &func){  readCallBack_ = func; };

private:
    void createConnect(int cfd,const InetAddr &localAddr,const InetAddr &peerAddr);
    void removeConn(uint64_t id);
private:
    EventLoop mainLoop_;
    std::unique_ptr<Acceptor> acceptor_;
    std::unique_ptr<EventLoopThreadPoll> loopThreadPoll_;
    uint8_t poolSize_;

    std::mutex mutex_;
    std::unordered_map<uint64_t,std::shared_ptr<TcpConnect>> connectContainer_;
    
    uint64_t connectId_;
    std::atomic_bool start_;


    std::function<void(const std::shared_ptr<TcpConnect>&)> connectCallBack_;
    std::function<int(const std::shared_ptr<TcpConnect>&)> writeComplteteCallBack_;
    std::function<void(const std::shared_ptr<TcpConnect>&,Buffer &buffer)> readCallBack_;
};