#include "TcpServer.h"
#include "TcpConnect.h"
void TcpServer::start()
{
    assert(!start_);
    start_ = true;
    acceptor_->start();
    if(poolSize_ > 0)
    {
        loopThreadPoll_ = std::make_unique<EventLoopThreadPoll>();
        loopThreadPoll_->setPollSize(poolSize_);
        loopThreadPoll_->start();
    }
    mainLoop_.loop();
}


void TcpServer::createConnect(int cfd, const InetAddr &localAddr, const InetAddr &peerAddr)
{
    EventLoop *loop = &mainLoop_;
    if (poolSize_ >0 )
        loop = loopThreadPoll_->getLoop();
    auto conn = std::make_shared<TcpConnect>(loop,cfd,localAddr,peerAddr,connectId_);
    if(readCallBack_) conn->setReadCallBack(readCallBack_);
    if(writeComplteteCallBack_) conn->setWriteCompleteCallBack(writeComplteteCallBack_);
    if(connectCallBack_) conn->setConnectCallBack(connectCallBack_);
    conn->setCloseCallBack([this](uint64_t id){
        removeConn(id);
    });


    connectContainer_[connectId_++] = conn;
    conn->establish();
    LOG_INFO("eventLoop name is %s and conn count is %d",loop->name().c_str(),loop->getConnCnt())
}

void TcpServer::removeConn(uint64_t id)
{
    std::lock_guard<std::mutex> guard(mutex_);
    connectContainer_.erase(connectContainer_.find(id));
}
