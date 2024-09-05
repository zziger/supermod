#include <supermod/Utils.hpp>
#include <supermod/utils/WindowsRegistry.hpp>

void sm::utils::WindowsRegistry::WriteRegSz(const HKEY hkey, const std::string& subKey, const std::string& key,
                                            const std::wstring& value)
{
    HKEY hKey;
    LONG openRes = RegCreateKeyExA(hkey, subKey.c_str(), 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, NULL);
    if (openRes != ERROR_SUCCESS)
        throw std::runtime_error(std::format("Failed to open registry key {}", subKey));

    LONG setRes = RegSetValueExW(hKey, key.empty() ? NULL : str_to_wstr(key).c_str(), 0, REG_SZ, (LPBYTE)value.c_str(),
                                 value.size() * 2);
    if (setRes != ERROR_SUCCESS)
        throw std::runtime_error(std::format("Failed to write registry key {}/{}", subKey, key));

    LONG closeOut = RegCloseKey(hKey);
    if (closeOut != ERROR_SUCCESS)
        throw std::runtime_error(std::format("Failed to close registry key {}", subKey));
}