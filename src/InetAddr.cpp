//
// Created by jiexiao on 2024/3/19.
//

#include "InetAddr.h"

InetAddr::InetAddr(const std::string &ip, uint16_t port) {
    auto *addr = new sockaddr_in;
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    ::inet_pton(AF_INET,ip.c_str(),&addr->sin_addr);
    addr_.reset(reinterpret_cast<sockaddr*>(addr));
}

std::string InetAddr::toIpPort() const {
    auto && ip = toIp();
    auto port = toPort();
    char buff[128]{0};
    snprintf(buff,sizeof buff,"%s:%u",ip.c_str(),port);
    return buff;
}

std::string InetAddr::toIp()  const{
    auto *addr = reinterpret_cast<sockaddr_in*>(addr_.get());
    return inet_ntoa(addr->sin_addr);
}

uint16_t InetAddr::toPort() const{
    auto *addr = reinterpret_cast<sockaddr_in*>(addr_.get());
    return ntohs(addr->sin_port);
}

bool InetAddr::operator==(const InetAddr &addr) const {
    return (addr.toIp() == toIp()) && (addr.toPort() == toPort());
}

InetAddr& InetAddr::operator=(const InetAddr &addr) {
    if (this == &addr)
        return *this;
    auto *copyAddr = new sockaddr;
    ::memcpy(copyAddr,addr.addr_.get(),sizeof(sockaddr));
    addr_.reset(copyAddr);
    return *this;
}

InetAddr::InetAddr(const InetAddr &addr) {
    operator=(addr);
}

InetAddr::InetAddr(const sockaddr &addr):InetAddr(::inet_ntoa())
{
}
