#pragma once
#include <exception>
#include <string_view>

class Error : public std::exception
{
public:
    explicit Error(std::string message);
};
