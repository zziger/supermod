#pragma once
#include <supermod/pch.hpp>

#include <exception>

class Error : public std::exception
{
public:
    explicit Error(const std::string& message);
};
