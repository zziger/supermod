#pragma once
#include <imgui/imgui.h>
#include <locale>
#include <string>
#include <Windows.h>
#include <fstream>

#include <thirdparty/directx/d3d8.h>
#include <format>
#include <functional>

#define MAX_INPUT_LENGTH 255

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

namespace utils
{
    inline std::string readline() {
        unsigned long read;
        void* con = GetStdHandle(STD_INPUT_HANDLE);

        wchar_t wstr[MAX_INPUT_LENGTH];
        char mbStr[MAX_INPUT_LENGTH * 3 + 1];

        ReadConsole(con, wstr, MAX_INPUT_LENGTH, &read, nullptr);
        int size = WideCharToMultiByte(CP_UTF8, 0, wstr, (int) read, mbStr, sizeof mbStr, nullptr, nullptr);
        mbStr[size] = 0;

        return { mbStr };
    }

    inline std::string trim(std::string& str) {
        str.erase(str.find_last_not_of(' ') + 1);
        str.erase(0, str.find_first_not_of(' '));
        return str;
    }

    inline void* read_file(const std::string& filename, int& size) {
        std::ifstream fstream { filename, std::ios::binary | std::ios::ate };
        size = fstream.tellg();
        fstream.seekg(0, std::ios::beg);
        const auto mem = malloc(size);
        fstream.read((char*)mem, size);

        return mem;
    }

    inline std::string get_module_name() {
        char dllPath[MAX_PATH] = {0};
        GetModuleFileNameA((HINSTANCE)&__ImageBase, dllPath, _countof(dllPath));
        return std::string(dllPath); 
    }

    inline void copy_text(std::string text) {
        const size_t len = text.size() + 1;
        HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
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

    inline void handle_error(std::function<void()> fn, std::string where) {
        try {
            fn();
        } catch(std::exception& e) {
            MessageBox(nullptr, str_to_wstr(std::format("Произошла ошибка {}:\r\n{}", where, e.what())).c_str(), L"SuperMod", MB_OK);
            exit(1);
        } catch(...) {
            MessageBox(nullptr, str_to_wstr(std::format("Произошла неизвестная ошибка {}", where)).c_str(), L"SuperMod", MB_OK);
            exit(1);
        }
    }
}

template <typename...> struct WhichType;

constexpr ImVec4 operator "" _color(unsigned long long int color) {
    return { (color >> 24 & 0xFF) / 255.f, (color >> 16 & 0xFF) / 255.f, (color >> 8 & 0xFF) / 255.f, (color & 0xFF) / 255.f  };
}

// ReSharper disable once CppDeprecatedEntity
inline std::wstring_convert<std::codecvt<char16_t, char, std::mbstate_t>, char16_t> convert;  // NOLINT(clang-diagnostic-deprecated-declarations)
#define U16(s) (char16_t*) convert.from_bytes(s).c_str()

#define ARGS(...) __VA_ARGS__

#define HOOK_FN(retn, name, args) retn (*name##_orig)(args) = nullptr;\
    retn name(args)
#define HOOK_FN_CONV(retn, name, args, conv) retn (conv *name##_orig)(args) = nullptr;\
    retn conv name(args)

#define HOOK_REF(name) name, &name##_orig
#define HOOK_REF_FORCE(name) (void*) name, (void**) &name##_orig