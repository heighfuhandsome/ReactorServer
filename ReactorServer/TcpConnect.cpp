#include "TcpConnect.h"
#include "EventLoop.h"

TcpConnect::TcpConnect(EventLoop *loop, int fd, const InetAddr &localAddr, const InetAddr &peerAddr,uint64_t id):loop_(loop),localAddr_(localAddr),
peerAddr_(peerAddr),status_(ConnStatus::DISCONNECT),id_(id)
{
    channel_ = std::make_unique<Channel>(loop,fd);
    socket_ = std::make_unique<Socket>(fd);
    socket_->setNonBlocking();
    socket_->setNoDelay();    

    channel_->setReadCallBack([this]{
        handlerRead(); 
    });


    channel_->setWriteCallBack([this]{
        handlerWrite();
    });

    channel_->setCloseCallBack([this]{
        handlerClose();
    });

    channel_->enableRead();
}

void TcpConnect::send(const std::string &msg)
{
    int len = ::send(channel_->fd(),msg.c_str(),msg.size(),0);
    if (len == msg.size())
        return;

    if (len == -1 )
    {
        if (errno == EAGAIN)
        {

        } else{
            handlerClose();
        }
    }

    if (len>0)
    {
        out_.write(msg.c_str()+len,msg.size()-len);
        channel_->enableWrite();
    }
}

void TcpConnect::handlerRead()
{

    int len  = in_.readSocket(channel_->fd());
    if (len == 0)
    {
        handlerClose();
        return;
    }

    if(readCallBack_ && in_.readableBytes()>0)
        readCallBack_(shared_from_this(),in_);
    
}

void TcpConnect::handlerClose()
{
    status_ = ConnStatus::DISCONNECT;
    if (connectCallBack_)
    {
        connectCallBack_(shared_from_this());
    }
    channel_->disableAll();
    if (closeCallBack_)
    {
        closeCallBack_(id_);
    }
}

void TcpConnect::handlerWrite()
{
    auto len = out_.writeSocket(channel_->fd());
    if(len == -1)
    {
        if (errno==EAGAIN) return;
        else
        {
            handlerClose();
            return;
        }
    }

    if (len > 0)
    {
        out_.retrieve(len);
    }

    if (out_.readableBytes() == 0)
    {
        if (writeCompleteCallBack_) writeCompleteCallBack_(shared_from_this());
        channel_->disableWrite();
    }

}

void TcpConnect::establish()
{
    status_ = ConnStatus::CONNECTED;

    if(connectCallBack_ ){
        if( loop_->isInLoopThread())
            connectCallBack_(shared_from_this());
        else
            loop_->addFunc([this]{  connectCallBack_(shared_from_this()); });
    }   
}
