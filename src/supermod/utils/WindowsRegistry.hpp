#pragma once
#include <supermod/pch.hpp>

namespace sm::utils
{
struct WindowsRegistry
{
    static void WriteRegSz(HKEY hkey, const std::string& subKey, const std::string& key, const std::wstring& value);
};
} // namespace sm::utils