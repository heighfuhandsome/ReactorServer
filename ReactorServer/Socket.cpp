//
// Created by jiexiao on 2024/3/19.
//

#include "Socket.h"
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <fcntl.h>
#include <sys/socket.h>
#include "Logger.h"

void Socket::reusePort() const {
    int reusePort = 1;
    if(::setsockopt(fd_,SOL_SOCKET,SO_REUSEPORT,&reusePort,static_cast<socklen_t>(sizeof reusePort)) == -1)
    {
        LOG_ERROR("%s",strerror(errno));
    }
}

void Socket::reuseAddr() const{
    int reuseAddr = 1;
    if(::setsockopt(fd_,SOL_SOCKET,SO_REUSEADDR,&reuseAddr,static_cast<socklen_t>(sizeof reuseAddr))==-1)
    {
        LOG_ERROR("%s",strerror(errno));
    }
}

void Socket::listen() const
{
    if(::listen(fd_,1024) == -1)
    {
        LOG_FATAL("%s",strerror(errno));
    }
}

void Socket::setNoDelay() const  {
    int opt = 1;
    if(setsockopt(fd_,IPPROTO_TCP,TCP_NODELAY,&opt,static_cast<socklen_t>(sizeof opt)) == -1){
        LOG_ERROR("%d %s",strerror(errno));
    }
}


void Socket::setNonBlocking() const{
    int flag = ::fcntl(fd_,F_GETFL);
    if (flag==-1)
    {
        LOG_ERROR("setNonBlocking Fail,fd is %d",fd_);
        return;
    }

    if (::fcntl(fd_,F_SETFL,O_NONBLOCK | flag) == -1)
    {
        LOG_ERROR("setNonBlocking Fail,fd is %d",fd_);
        return;
    }
}

void Socket::bind(const InetAddr &addr) const {
    sockaddr laddr = addr.getSockAddr();
    if(::bind(fd_,&laddr,static_cast<socklen_t>(sizeof laddr)) == -1){
        LOG_FATAL("%s", strerror(errno));
    }
}
