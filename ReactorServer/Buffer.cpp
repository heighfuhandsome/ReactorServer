#include "Buffer.h"
#include "sys/uio.h"

std::string Buffer::readN(uint32_t n) {
    if (n > readableBytes())
    {
        LOG_ERROR("n > readableSize")
        return "";
    }
    return std::string {buffer_+readPos_,n};
}

void Buffer::expend(uint32_t len) {
    if (writeableBytes() >= len) return;
    uint32_t readable = readableBytes();
    if (readPos_ + writeableBytes() >= len)
    {
        ::memcpy(buffer_,buffer_+readPos_,readable);
    }else{
        char *newBuffer = new char[len+readable];
        ::memcpy(newBuffer,buffer_+readPos_,readable);
        delete[] buffer_;
        buffer_ = newBuffer;
        capacity_ = len+readable;
    }
    readPos_ = 0;
    writePos_ = readable;
}

void Buffer::write(const char *str, uint32_t len) {
    expend(len);
    ::memcpy(buffer_+writePos_,str,len);
    writePos_+=len;
}

int Buffer::readSocket(int fd){
    char tmp[65536];
    uint32_t writeable = writeableBytes();
    int vecCnt = writeableBytes()>=65536?1:2;

    iovec vec[2];
    vec[0].iov_base = buffer_+writePos_;
    vec[0].iov_len = writeable;
    vec[1].iov_base = tmp;
    vec[1].iov_len = sizeof tmp;

    ssize_t len = ::readv(fd,vec,vecCnt);

    if (len == -1)
        LOG_INFO("%s", strerror(errno))
    else if(len == 0){

    }else if (len > 0 && len<= writeable)
        writePos_+=len;
    else{
        writePos_+=writeable;
        write(tmp,len - writeable);
    }

    return static_cast<int>(len);
}

uint32_t Buffer::writeSocket(int fd) {
    auto len = ::send(fd,buffer_+readPos_,readableBytes(),0);
    if (len >0)
        readPos_+=len;
    return len;
}



