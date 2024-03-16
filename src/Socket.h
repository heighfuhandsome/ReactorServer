#pragma once
#include "noncopyable.h"
#include <sys/socket.h>
#include <sys/fcntl.h>
#include "Logger.h"
#include <netinet/in.h>
#include <netinet/tcp.h>
class Socket:noncopyable{
public:
    Socket(int fd):fd_(fd){};
    void setNonBlocking()
    {
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


    void setNoDealy()
    {
        int opt = 1;
        if(setsockopt(fd_,IPPROTO_TCP,TCP_NODELAY,&opt,static_cast<socklen_t>(sizeof opt)) == -1){
            LOG_ERROR("%d %s",strerror(errno));
        }
    }
private:
    int fd_;

};