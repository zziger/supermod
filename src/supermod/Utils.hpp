#pragma once
#include <supermod/pch.hpp>

#include <fstream>
#include <imgui.h>
#include <locale>

#define MAX_INPUT_LENGTH 255

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

namespace sm::utils
{
inline std::string readline()
{
    unsigned long read;
    void* con = GetStdHandle(STD_INPUT_HANDLE);

    wchar_t wstr[MAX_INPUT_LENGTH];
    char mbStr[MAX_INPUT_LENGTH * 3 + 1];

    ReadConsole(con, wstr, MAX_INPUT_LENGTH, &read, nullptr);
    int size = WideCharToMultiByte(CP_UTF8, 0, wstr, (int)read, mbStr, sizeof mbStr, nullptr, nullptr);
    mbStr[size] = 0;

    return {mbStr};
}

inline std::string trim(std::string& str)
{
    str.erase(str.find_last_not_of(' ') + 1);
    str.erase(0, str.find_first_not_of(' '));
    return str;
}

inline std::string trim(std::string str)
{
    str.erase(str.find_last_not_of(' ') + 1);
    str.erase(0, str.find_first_not_of(' '));
    return str;
}

inline void* read_file(const std::string& filename, int& size)
{
    std::ifstream fstream{filename, std::ios::binary | std::ios::ate};
    size = fstream.tellg();
    fstream.seekg(0, std::ios::beg);
    const auto mem = malloc(size);
    fstream.read((char*)mem, size);

    return mem;
}

inline void copy_text(std::string text)
{
    const size_t len = text.size() + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), text.c_str(), len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}

inline std::wstring str_to_wstr(const std::string& str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

inline std::string wstr_to_str(const std::wstring& wstr)
{
    int count = WideCharToMultiByte(65001, 0, wstr.c_str(), wstr.length(), NULL, 0, NULL, NULL);
    std::string str(count, 0);
    WideCharToMultiByte(65001, 0, wstr.c_str(), -1, &str[0], count, NULL, NULL);
    return str;
}

inline std::string get_module_name()
{
    wchar_t dllPath[MAX_PATH] = {0};
    GetModuleFileNameW((HINSTANCE)&__ImageBase, dllPath, _countof(dllPath));
    return wstr_to_str(dllPath);
}

inline void handle_error(std::function<void()> fn, std::string where)
{
    try
    {
        fn();
    }
    catch (std::exception& e)
    {
        MessageBox(nullptr, str_to_wstr(std::format("Произошла ошибка {}:\r\n{}", where, e.what())).c_str(),
                   L"SuperMod", MB_OK);
        exit(1);
    }
    catch (...)
    {
        MessageBox(nullptr, str_to_wstr(std::format("Произошла неизвестная ошибка {}", where)).c_str(), L"SuperMod",
                   MB_OK);
        exit(1);
    }
}

inline std::optional<std::string> read_resource(const int resource)
{
    const auto res = FindResource((HMODULE)&__ImageBase, MAKEINTRESOURCE(resource), RT_RCDATA);
    if (!res)
        return std::nullopt;
    const auto resHandle = LoadResource((HMODULE)&__ImageBase, res);
    if (!resHandle)
        return std::nullopt;
    std::string result((char*)LockResource(resHandle), SizeofResource((HMODULE)&__ImageBase, res));
    FreeResource(resHandle);
    return result;
}

inline std::unique_ptr<miniz_cpp::zip_file> read_zip_resource(const int resource)
{
    const auto res = FindResource(reinterpret_cast<HMODULE>(&__ImageBase), MAKEINTRESOURCE(resource), RT_RCDATA);
    if (!res)
        return nullptr;
    const auto resHandle = LoadResource(reinterpret_cast<HMODULE>(&__ImageBase), res);
    if (!resHandle)
        return nullptr;

    const auto size = SizeofResource(reinterpret_cast<HMODULE>(&__ImageBase), res);
    const auto data = static_cast<unsigned char*>(LockResource(resHandle));
    std::vector vec(data, data + size);
    FreeResource(resHandle);

    return std::make_unique<miniz_cpp::zip_file>(vec);
}

inline std::string pluralize(const int count, const std::array<std::string, 3>& words)
{
    static std::array cases = {2, 0, 1, 1, 1, 2};
    std::stringstream ss;
    ss << count << " " << words[count % 100 > 4 && count % 100 < 20 ? 2 : cases[std::min(count % 10, 5)]];
    return ss.str();
}
} // namespace sm::utils

template <typename...>
struct WhichType;

constexpr ImVec4 operator"" _color(unsigned long long int color)
{
    return {(color >> 24 & 0xFF) / 255.f, (color >> 16 & 0xFF) / 255.f, (color >> 8 & 0xFF) / 255.f,
            (color & 0xFF) / 255.f};
}

// ReSharper disable once CppDeprecatedEntity
inline std::wstring_convert<std::codecvt<char16_t, char, std::mbstate_t>, char16_t>
    convert; // NOLINT(clang-diagnostic-deprecated-declarations)
#define U16(s) (char16_t*)convert.from_bytes(s).c_str()

#define ARGS(...) __VA_ARGS__

#define HOOK_FN(retn, name, args)                                                                                      \
    retn (*name##_orig)(args) = nullptr;                                                                               \
    retn name(args)
#define HOOK_FN_CONV(retn, name, args, conv)                                                                           \
    retn(conv* name##_orig)(args) = nullptr;                                                                           \
    retn conv name(args)

#define HOOK_REF(name) name, &name##_orig
#define HOOK_REF_FORCE(name) (void*)name, (void**)&name##_orig

#define ENSURE_SIZE(class, size) static_assert(sizeof(class) == size, "Invalid size of class " #class)