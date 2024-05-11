#include "HttpRequest.h"
#include <cstring>

int HttpRequest::parse(const std::string &str)
{
    int parseSize = 0;
    size_t pos = str.find("\r\n");
    if (stat_ == HTTP_PARSE_STAT::NONE && pos != -1)
    {
        std::string line = str.substr(0,pos);
        parseSize = parseLine(line);
        if (parseSize == -1)
        {
            return -1;
        }
        stat_ = HTTP_PARSE_STAT::LINE;
    }

     

    return parseSize;
    
}

std::string HttpRequest::reqLine() const
{
    char buff[128]{0};
    if (method_ == HTTP_REQUEST_METHOD::GET)
    {
        sprintf(buff,"%s","GET ");
    }else if(method_ == HTTP_REQUEST_METHOD::PUT){
        sprintf(buff,"%s","PUT ");
    }else{
        sprintf(buff,"%s","NONE ");
    }

    sprintf(buff+strlen(buff),"%s ",path_.c_str());

    if (version_ == HTTP_VERSION::v11)
    {
        sprintf(buff+strlen(buff),"%s ","HTTP/1.1");
    }else if(version_ == HTTP_VERSION::v10){
        sprintf(buff+strlen(buff),"%s ","HTTP/1.0");

    }else{
        sprintf(buff+strlen(buff),"%s ","NONE");
    }
   
    return buff;
}

int HttpRequest::parseLine(std::string &line)
{
    auto pos = line.find(" ");
    if (pos == -1)
    {
        return -1;
    }

    std::string method = line.substr(0,pos);
    if (method == "GET")
    {
        method_ = HTTP_REQUEST_METHOD::GET;
    }
    else if(method == "PUT")
    {
       method_ = HTTP_REQUEST_METHOD::PUT; 
    }
    else
    {
        return -1;
    }
    line.erase(0,pos+1);
    pos = line.find(" ");
    if (pos == -1)
    {
        return -1;
    }

    path_ = line.substr(0,pos);
    line.erase(0,pos+1);
    if (line == "HTTP/1.1")
    {
        version_ = HTTP_VERSION::v11;
    }else{
        version_ = HTTP_VERSION::v10;
    }
    
}
