#include <iostream>
#include "ReactorServer/TcpServer.h"
#include "ReactorServer/TcpConnect.h"

int main()
{
    using namespace std;
    InetAddr addr{"localhost",8080};
    TcpServer server(addr);
    server.setPoolSize(std::thread::hardware_concurrency()-1);

    server.setReadCallBack([](const std::shared_ptr<TcpConnect> &conn,Buffer &buffer){
        LOG_INFO("%s",buffer.readAll().c_str());
        conn->send(buffer.readAll());
        buffer.retrieveAll();
    });

    server.setConnectCallBack([](const std::shared_ptr<TcpConnect> &conn){
        if (conn->connStatus() == ConnStatus::CONNECTED)
        {
            LOG_INFO("%s connected",conn->peerAddr().toIpPort().c_str());
        }else{
            LOG_INFO("%s disconnect",conn->peerAddr().toIpPort().c_str());
        }
    });
    server.start();

    return 0;
}