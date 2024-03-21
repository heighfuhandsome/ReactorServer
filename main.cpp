#include <iostream>
#include "src/EventLoop.h"
#include "src/Acceptor.h"
int main()
{

    EventLoop loop;
    InetAddr addr("127.0.0.1",8080);
    Acceptor acceptor(&loop,addr);
    loop.loop();
    return 0;
}