#include <iostream>
#include <algorithm>
#include "ReactorServer/TcpServer.h"
#include "ReactorServer/TcpConnect.h"
#include "mysql.h"
#include <json/json.h>
#include <json/value.h>

int main()
{
    using namespace std;
    InetAddr addr{"localhost",8080};
    TcpServer server(addr);
    server.setPoolSize(std::thread::hardware_concurrency()-1);
    Json::Reader reader;

    server.setReadCallBack([reader](const std::shared_ptr<TcpConnect> &conn,Buffer &buffer)mutable{
        Json::Value value;
        reader.parse(buffer.readAll(),value);
        buffer.retrieveAll();
        Conn &mconn = std::any_cast<Conn&>(conn->getContext());
        // if (mconn.connected())
        // {
        //     LOG_INFO("connected");
        // }
        
        if (value["type"].asString() == "put")
        {
            auto tempurature = value["tempurature"].asCString();
            auto moderation = value["moderation"].asCString(); 
            auto mq135 = value["mq135"].asCString();
            char buff[128]{0};
            snprintf(buff,sizeof buff,"insert sensor_collect(`tempurature`,`moderation`,`mq135`)values(%s,%s,%s);",tempurature,moderation,mq135);
            // LOG_INFO("sql is %s",buff)
            if (!mconn.insert(buff)){
                LOG_ERROR("%s",mconn.strErr())
            }
        }
        
    });

    server.setConnectCallBack([](const std::shared_ptr<TcpConnect> &conn){
        if (conn->connStatus() == ConnStatus::CONNECTED)
        {
            LOG_INFO("%s connected",conn->peerAddr().toIpPort().c_str());
            conn->setContext<Conn&&>(Conn("123.60.11.91","graduation_design","root","qwert112233",3306));
        }else{
            LOG_INFO("%s disconnect",conn->peerAddr().toIpPort().c_str());
        }
    });
    server.start();

    return 0;
}