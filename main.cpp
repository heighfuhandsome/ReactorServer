#include "ReactorServer/Logger.h"
#include "ReactorServer/TcpConnect.h"
#include "ReactorServer/TcpServer.h"
#include "mysql.h"
#include <algorithm>
#include <iostream>
#include <json/json.h>
#include <json/value.h>
#include <json/writer.h>

int main() {
    

  using namespace std;
  InetAddr addr{"localhost", 80};
  TcpServer server(addr);
  server.setPoolSize(std::thread::hardware_concurrency() - 1);
  thread_local Json::Reader reader;
  thread_local Json::FastWriter writer;
  server.setReadCallBack([&](const std::shared_ptr<TcpConnect> &conn,
                             Buffer &buffer) mutable {
    Json::Value value;
    reader.parse(buffer.readAll(), value);
    LOG_INFO("%s", writer.write(value).c_str());
    buffer.retrieveAll();
    Conn &mconn = std::any_cast<Conn &>(conn->getContext());
    auto &&type = value["type"].asString();

    if (type == "put") {
      auto tempurature = value["temperature"].asCString();
      auto moderation = value["moderation"].asCString();
      auto mq135 = value["mq135"].asCString();
      char buff[128]{0};
      snprintf(
          buff, sizeof buff,
          "insert "
          "sensor_collect(`temperature`,`moderation`,`mq135`)values(%s,%s,%s);",
          tempurature, moderation, mq135);
      if (!mconn.insert(buff)) {
        LOG_ERROR("%s", mconn.strErr())
      }
    } else if (type == "get") {
      if (!mconn.query(
              "select * from sensor_collect order by id desc limit 50;")) {
        LOG_INFO("%s", mconn.strErr())
        return;
      }
      Json::Value array;
      thread_local Json::FastWriter jsonWriter;
      while (1) {
        vector<string> &&vec = mconn.getRow();
        if (vec.size() == 0)
          break;
        Json::Value item;
        item["temperature"] = vec[0];
        item["moderation"] = vec[1];
        item["mq135"] = vec[2];
        array.append(item);
      }
      conn->send(jsonWriter.write(array));
    }
  });

  server.setConnectCallBack([](const std::shared_ptr<TcpConnect> &conn) {
    if (conn->connStatus() == ConnStatus::CONNECTED) {
      LOG_INFO("%s connected", conn->peerAddr().toIpPort().c_str());
      conn->setContext(
          Conn("localhost", "graduation_design", "root", "qwert112233", 3306));
    } else {
      LOG_INFO("%s disconnect", conn->peerAddr().toIpPort().c_str());
    }
  });
  server.start();

  return 0;
                                                                               }
