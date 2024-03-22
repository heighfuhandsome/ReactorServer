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
    Buffer():readPos_(0),writePos_(0){
        buffer_.reserve(4096);
    }

    uint32_t readableBytes() { return writePos_-readPos_; }

    void write(char *str,int len)
    {
        write({str,static_cast<size_t>(len)});
    }

    void write(const std::string &str){
        ::memcpy(&*buffer_.begin()+writePos_,str.c_str(),str.size());
        writePos_+=str.size();
    }
    
    void setHead(uint64_t size)
    {
        uint32_t headSize = ::htonl(size);
        ::memcpy(&*(buffer_.begin()+writePos_),&headSize,sizeof(headSize));
        writePos_ +=4;
    }

    uint32_t getHead()
    {
        if (readableBytes()>=4)
        {
            uint32_t size;
            ::memcpy(&size,&*(buffer_.begin()+readPos_),4);
            readPos_+=4;
            return ::ntohl(size);
        }

        return 0;
    }

    void retrieve(uint32_t n)
    {
        if(n>readableBytes())
            retrieveAll();
        readPos_ +=n;
        if (readableBytes()<=40960 && buffer_.capacity()>40960 )
            buffer_.resize(40960);
        resetPos();
    }

    void retrieveAll()
    {
        retrieve(readableBytes());
    }

    std::string readnBytes(uint32_t n)
    {
        if (n > readableBytes())
        {
            LOG_ERROR("n > readableSize")
            return "";
        }
        return {&*buffer_.begin()+readPos_,static_cast<size_t>(n)};
    }

    std::string readAll()
    {
        return readnBytes(readableBytes());
    }

    char* writeMemAddr()
    {
        return &*(buffer_.begin()+writePos_);
    }

    char* readMemAddr()
    {
        return &*(buffer_.begin()+readPos_);
    }    

    size_t writeableBytes()
    {
       return static_cast<size_t>(buffer_.capacity() - writePos_);
    }

    //直接拷贝到buffer_ 跟新writePos_
    void write(ssize_t size)
    {
        writePos_+=size;
    }

private:
    void resetPos()
    {
        if (readableBytes() ==0)
            readPos_ = writePos_ = 0;
        
    }
private:
    std::vector<char> buffer_;
    uint32_t readPos_;
    uint32_t writePos_;

};