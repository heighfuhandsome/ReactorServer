#include "TcpConnect.h"
#include "EventLoop.h"
#include <sys/uio.h>
#include <iconv.h>

TcpConnect::TcpConnect(EventLoop *loop, int fd, const InetAddr &localAddr, const InetAddr &peerAddr):loop_(loop),localAddr_(localAddr),
peerAddr_(peerAddr_),status_(ConnStatus::DISCONNECT)
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
    if (connectCallBack_)
    {
        if(loop_->isInLoopThread())
        {
            connectCallBack_(shared_from_this());
        }
        else
        {
            loop_->addFunc([this,ptr = shared_from_this()]{
                connectCallBack_(ptr);
            });

        }
    }
}

void TcpConnect::send(const std::string &msg)
{
    ssize_t size = 0;
    while (out_.readableBytes() == 0)
    {
        size = ::send(channel_->fd(),msg.c_str(),msg.size(),0);

        if(size < 0) 
        {
            LOG_ERROR("%s",strerror(errno));
            break;
        }

        if(size == msg.size())
            return;

        out_.write(msg.c_str()+size);
        break;
    }

    if (size < 0 )
    {
        out_.write(msg);
    }

    if (!channel_->isWriting())
    {
        channel_->enableWrite();
    }
    
}

void TcpConnect::handlerRead()
{
    iovec vec[2];
    char tmp[40960];
    size_t writeableBytes = in_.writeableBytes();
    vec[0].iov_base = in_.writeMemAddr();
    vec[0].iov_len = writeableBytes;
    vec[1].iov_base = tmp;
    vec[1].iov_len = sizeof tmp;
    ssize_t size = ::writev(channel_->fd(),vec,2);

    if (size < 0)
    {
        LOG_ERROR("%s",strerror(errno))
        return;
    }
    

    if (size == 0)
    {
        channel_->disableAll();
        handlerClose();
        return;
    }

    if(size > writeableBytes)
    {
        ::memcpy(in_.writeMemAddr() + writeableBytes,tmp,size - writeableBytes);
    }

    in_.write(size);

    if(readCallBack_)
        readCallBack_(shared_from_this(),in_);
    
}

void TcpConnect::handlerClose()
{
    if (closeCallBack_)
    {
        closeCallBack_(shared_from_this());
    }
}

void TcpConnect::handlerWrite()
{
    ssize_t size = ::send(channel_->fd(),out_.readMemAddr(),out_.readableBytes(),0);
    if(size == -1)
        LOG_ERROR("%s",strerror(errno))

    if (size > 0)
    {
        out_.retrieve(size);
    }

    bool complete = out_.readableBytes() == 0;    

    complete? channel_->disableWrite() ? writeComplteteCallBack_ != nullptr ? writeComplteteCallBack_(shared_from_this()) : 0 :0 :0;
}
