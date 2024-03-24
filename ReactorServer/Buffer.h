#pragma once
#include "noncopyable.h"
#include "Logger.h"
#include <vector>
#include <string>
#include <cstdint>
#include <cstring>
#include <arpa/inet.h>
class Buffer : noncopyable{
public:
    explicit Buffer():readPos_(0),writePos_(0){
        buffer_ = new char[4096];
        capacity_ = 4096;
    }
    ~Buffer()
    {
        if (buffer_)
        {
            delete[] buffer_;
            buffer_ = nullptr;
        }
    }


    const char* peek() const{ return buffer_;}

    uint32_t readableBytes() const { return writePos_-readPos_; }

    std::string readAll(){return readN(readableBytes()); }

    std::string readN(uint32_t n);

    uint32_t writeableBytes() const{ return capacity_ - writePos_; }

    void write(const char *str,uint32_t len);

    void write(const std::string &str){ write(str.data(),str.size()); }

    int readSocket(int fd);

    void retrieve(uint32_t n){ if (n>readableBytes()) return; else readPos_+=n;  }
    void retrieveAll(){ retrieve(readableBytes()); }

    uint32_t writeSocket(int fd);
    
//    void setHead(uint64_t size)
//    {
//        uint32_t headSize = ::htonl(size);
//        ::memcpy(&*(buffer_.begin()+writePos_),&headSize,sizeof(headSize));
//        writePos_ +=4;
//    }
//
//    uint32_t getHead()
//    {
//        if (readableBytes()>=4)
//        {
//            uint32_t size;
//            ::memcpy(&size,&*(buffer_.begin()+readPos_),4);
//            readPos_+=4;
//            return ::ntohl(size);
//        }
//
//        return 0;
//    }

private:
    void expend(uint32_t len);
private:
    char *buffer_;
    uint32_t readPos_;
    uint32_t writePos_;
    uint32_t capacity_;
};