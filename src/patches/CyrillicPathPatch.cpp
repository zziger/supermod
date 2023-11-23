/// By default game uses ANSI file system methods, and because of that
/// game will not start if it's located in a folder with cyrillic name
/// on a system that has non-cyrillic language set as default.
/// This patch replaces WINAPI ANSI methods with C++ methods, that have
/// UTF-8 encoding enabled.

#include "Utils.h"
#include "events/EventManager.h"
#include "memory/HookManager.h"

BOOL (__stdcall *SetCurrentDirectoryAOrig)(LPCSTR lpPathName) = nullptr;
BOOL __stdcall SetCurrentDirectoryAHook(LPCSTR lpPathName)
{
    try
    {
        std::filesystem::current_path(lpPathName);
        return true;
    } catch(...)
    {
        return false;
    }
}

DWORD (__stdcall *GetCurrentDirectoryAOrig)(DWORD nBufferLength, LPSTR lpBuffer) = nullptr;
DWORD __stdcall GetCurrentDirectoryAHook(DWORD nBufferLength, LPSTR lpBuffer)
{
    try
    {
        const auto cwd = std::filesystem::current_path();
        if (lpBuffer)
        {
            auto len = cwd.string().size();
            if (len > nBufferLength)
            {
                return len;
            }
            memcpy(lpBuffer, cwd.string().c_str(), len);
            lpBuffer[len] = '\0';
        }
        return cwd.string().size();
    } catch(...)
    {
        return 0;
    }
}

inline EventManager::Ready $cyrillic_path_patch([] {
    HookManager::RegisterHook(Memory(SetCurrentDirectoryA), SetCurrentDirectoryAHook, &SetCurrentDirectoryAOrig);
    HookManager::RegisterHook(Memory(GetCurrentDirectoryA), GetCurrentDirectoryAHook, &GetCurrentDirectoryAOrig);
});

