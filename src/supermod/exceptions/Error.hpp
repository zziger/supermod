#pragma once
#include <supermod/pch.hpp>

#include <exception>

namespace sm
{
class Error : public std::exception
{
public:
    explicit Error(const std::string& message);
};
} // namespace sm
