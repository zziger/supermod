#pragma once

#include <DbgHelp.h>
#include <supermod/Utils.hpp>
#include <supermod/memory/HookManager.hpp>
#include <supermod/memory/Memory.hpp>

typedef BOOL(WINAPI* MINIDUMPWRITEDUMP)(HANDLE hProcess, DWORD dwPid, HANDLE hFile, MINIDUMP_TYPE DumpType,
                                        PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
                                        PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
                                        PMINIDUMP_CALLBACK_INFORMATION CallbackParam);

inline std::wstring dumpsPath;

static LONG WINAPI HandleError(_EXCEPTION_POINTERS* apExceptionInfo)
{
    const std::time_t ms = std::time(nullptr);
    auto exceptionCode =
        apExceptionInfo ? apExceptionInfo->ExceptionRecord ? apExceptionInfo->ExceptionRecord->ExceptionCode : 0 : 0;
    const auto mhLib = LoadLibraryA("dbghelp.dll");
    const auto pDump = (MINIDUMPWRITEDUMP)GetProcAddress(mhLib, "MiniDumpWriteDump");

    const auto hFile = CreateFileW(std::format(L"{}{:x}-{}.dmp", dumpsPath, exceptionCode, ms).c_str(), GENERIC_WRITE,
                                   FILE_SHARE_WRITE, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

    _MINIDUMP_EXCEPTION_INFORMATION exInfo;

    if (apExceptionInfo)
    {
        exInfo.ThreadId = GetCurrentThreadId();
        exInfo.ExceptionPointers = apExceptionInfo;
        exInfo.ClientPointers = true;
    }

    pDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpNormal, apExceptionInfo ? &exInfo : nullptr,
          nullptr, nullptr);
    CloseHandle(hFile);

    MessageBoxW(nullptr, L"Крашдамп записан в папку crashdumps", L"SuperMod", MB_OK);

    return EXCEPTION_CONTINUE_SEARCH;
}

static void BufferOverflow(int, int)
{
    MessageBoxW(nullptr, L"Произошло переполнение буфера. Игра будет закрыта", L"SuperMod", MB_OK);
    __try
    {
        RaiseException(STATUS_STACK_BUFFER_OVERRUN, EXCEPTION_NONCONTINUABLE, 0, nullptr);
    }
    __except (HandleError(GetExceptionInformation()))
    {
    }
    exit(3);
}

static LONG(WINAPI* set_exception_filter_orig)(LPTOP_LEVEL_EXCEPTION_FILTER) = nullptr;
static LONG WINAPI set_exception_filter(LPTOP_LEVEL_EXCEPTION_FILTER)
{
    set_exception_filter_orig(HandleError);
    return 0;
}

inline void InitCrashHandler()
{
    const auto folder = sdk::Game::GetRootPath() / "crashdumps";
    const auto filePrefix = std::format("{}-", sdk::Game::GetGameVersion());
    dumpsPath = (folder / filePrefix).wstring();
    if (!exists(folder))
        create_directory(folder);

    static constexpr Memory::Pattern movOverrunHandler("A1 ? ? ? ? 33 C9 3B C1"); // mov eax, bufferOverrunHandler
    static auto mem = movOverrunHandler.Search();
    const auto ptr = *mem.Get<void***>(1);
    *ptr = BufferOverflow;
    SetUnhandledExceptionFilter(HandleError);
    static Memory exceptionFilterMem(SetUnhandledExceptionFilter);
    HookManager::RegisterHook(exceptionFilterMem, HOOK_REF(set_exception_filter));
}