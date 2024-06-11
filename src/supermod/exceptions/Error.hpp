#pragma once
#include <supermod/pch.hpp>

#include <exception>
#include <utility>

namespace sm
{
class Error : public std::runtime_error
{
public:
    explicit Error(const std::string& message) : runtime_error(message.c_str()) {}
};

class NetworkError final : public Error
{
public:
    enum StatusCodes : long
    {
        UNAUTHORIZED = 401
    };

    std::string body;
    long statusCode;

    explicit NetworkError(long statusCode, std::string body)
        : Error(std::format("HTTP {}", statusCode)),
          body(std::move(body)),
          statusCode(statusCode)
    {
    }
};
} // namespace sm
