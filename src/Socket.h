#pragma once
#include "noncopyable.h"
#include "InetAddr.h"
#include <unistd.h>
class Socket:noncopyable{
public:
    explicit Socket(int fd):fd_(fd){};
    ~Socket(){
       ::close(fd_); 
    };
    void setNonBlocking() const;
    int fd() const{ return fd_;}
    void setNoDelay() const;
    void reusePort() const;
    void reuseAddr() const;
    void listen() const;

    void bind(const InetAddr &addr) const;
private:
    int fd_;
};