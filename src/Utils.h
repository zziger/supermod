#pragma once
#include <locale>
#include <string>
#include <iostream>
#include <Windows.h>

#define MAX_INPUT_LENGTH 255

namespace Utils
{
    inline std::string Readline() {
        unsigned long read;
        void* con = GetStdHandle(STD_INPUT_HANDLE);

        wchar_t wstr[MAX_INPUT_LENGTH];
        char mbStr[MAX_INPUT_LENGTH * 3 + 1];

        ReadConsole(con, wstr, MAX_INPUT_LENGTH, &read, nullptr);
        int size = WideCharToMultiByte(CP_UTF8, 0, wstr, (int) read, mbStr, sizeof mbStr, nullptr, nullptr);
        mbStr[size] = 0;

        return { mbStr };
    }

    inline std::string Trim(std::string& str) {
        str.erase(str.find_last_not_of(' ') + 1);
        str.erase(0, str.find_first_not_of(' '));
        return str;
    }
}

inline std::wstring_convert<std::codecvt<char16_t, char, std::mbstate_t>, char16_t> convert;
#define U16(s) (char16_t*) convert.from_bytes(s).c_str()

#define ARGS(...) __VA_ARGS__

#define DETOUR_HOOK(pattern, name) pattern.Search().Detour((void*) name##_hook, (void**) &name##_orig)

#define GLOBAL_HOOK(pat, retn, name, args, fn) retn (*name##_orig)##(args) = nullptr;\
    retn name##_hook##(args) fn; \
    static CMemory::Hook name##_ ([] { \
        Log::Debug << "Hooking " << #name << " function..." << Log::Endl; \
        static constexpr CMemory::Pattern pattern(pat);\
        DETOUR_HOOK(pattern, name); \
    })

#define GLOBAL_HOOK_THISCALL(pat, retn, name, args, fn) retn (__thiscall *name##_orig)##(void* this_, args) = nullptr;\
    retn __fastcall name##_hook##(void* this_, void* unk, args) fn; \
    static CMemory::Hook name##_([] { \
        Log::Debug << "Hooking " << #name << " __thiscall function..." << Log::Endl; \
        static constexpr CMemory::Pattern pattern(pat);\
        DETOUR_HOOK(pattern, name); \
    })

#define HOOK_DEF(pat, retn, name, args, fn) static inline retn (*name##_orig)##(args) = nullptr;\
    static retn name##_hook##(args) fn; \
    static constexpr CMemory::Pattern name##_pattern = { pat }

#define HOOK_THISCALL_DEF(pat, retn, name, args, fn) static inline retn (__thiscall *name##_orig)##(void* this_, args) = nullptr;\
    static retn __fastcall name##_hook##(void* this_, void* unk, args) fn; \
    static constexpr CMemory::Pattern name##_pattern = { pat }\
    

#define HOOK_APPLY_NO_MEM(name) name##_mem.Detour((void*) name##_hook, (void**) &name##_orig); \
    RegisterHook(name##_mem); \
    Log::Debug << "Hooking " << #name << " function..." << Log::Endl

#define HOOK_APPLY(name) auto name##_mem = name##_pattern.Search(); \
    HOOK_APPLY_NO_MEM(name)

#define MANYARGS_T(type)  type va_arg1, type va_arg2, type va_arg3, type va_arg4, type va_arg5, type va_arg6, type va_arg7, type va_arg8
#define MANYARGS     va_arg1, va_arg2, va_arg3, va_arg4, va_arg5, va_arg6, va_arg7, va_arg8