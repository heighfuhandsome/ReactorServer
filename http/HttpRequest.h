#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

enum class HTTP_VERSION { none, v10, v11 };

enum class HTTP_PARSE_STAT { NONE, LINE, HEAD, BODY, DONE };

enum class HTTP_REQUEST_METHOD { NONE, GET, PUT };

class HttpRequest {

public:
  HttpRequest(const HttpRequest &) = delete;
  void operator=(const HttpRequest &) = delete;
  HttpRequest()
      : stat_(HTTP_PARSE_STAT::NONE), version_(HTTP_VERSION::none),
        method_(HTTP_REQUEST_METHOD::NONE) {}
  int parse(const std::string &str);

  // HTTP_PARSE_STAT stat()const {return  stat_; }
  // HTTP_VERSION version()const {return version_;}
  // std::string path()const {return path_;}
  std::string reqLine() const;

private:
  int parseLine(std::string &line);

private:
  std::string path_;
  std::unordered_map<std::string, std::string> headers_;
  std::string body_;
  HTTP_REQUEST_METHOD method_;
  HTTP_VERSION version_;
  HTTP_PARSE_STAT stat_;
};
