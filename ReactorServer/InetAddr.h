//
// Created by jiexiao on 2024/3/19.
//
#pragma once
#include <arpa/inet.h>
#include <string>
#include <cstring>
#include <memory>
class InetAddr {
public:
    InetAddr(const std::string &ip,uint16_t port);
    InetAddr(InetAddr const &addr);
    InetAddr(const sockaddr &addr);
    InetAddr(const sockaddr_in &addr);

    std::string toIpPort() const;
    uint16_t toPort() const;
    std::string toIp() const;
    InetAddr& operator=(const InetAddr& addr);
    bool operator==(const InetAddr &addr) const;
    const sockaddr& getSockAddr() const {return  *addr_;}
private:
    std::unique_ptr<sockaddr> addr_;
};


