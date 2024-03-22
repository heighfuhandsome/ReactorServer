#pragma once
class noncopyable{
public:
    noncopyable& operator=(const noncopyable&) = delete;
protected:
    noncopyable() = default;
private:
    noncopyable(const noncopyable&){};
};