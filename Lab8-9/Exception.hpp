#pragma once
#include <exception>
#include <iostream>
#include <string>

class Exception : public std::exception
{
private:
    std::string message;
public:
    Exception(const std::string& message) : message(message) {};
    virtual const char* what() const noexcept override
    {
        return message.c_str();
    }
    ~Exception() {};
};

