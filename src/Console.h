#pragma once
#include <regex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "Config.h"
#include "data.h"
#include "Log.h"
#include "Utils.h"

class Console {
public:
    
    static void Initialize() {
        if (Config::Get()["console"].as<bool>(false)) Enable();
    }

    inline static bool enabled = false;
    inline static FILE* stdinFile = nullptr;
    inline static FILE* stdoutFile = nullptr;

    static void Enable() {
        if (enabled) return;
        enabled = true;
        AllocConsole();
        if (stdinFile == nullptr) freopen_s(&stdinFile, "CONIN$", "r", stdin);
        if (stdoutFile == nullptr) freopen_s(&stdoutFile, "CONOUT$", "w", stdout);
        SetConsoleTitle(L"SuperCow mod console");
        SetConsoleOutputCP( CP_UTF8);
        SetConsoleCP( CP_UTF8);
        auto wnd = GetConsoleWindow();
        if (wnd != nullptr) {
            ShowWindow(wnd, SW_RESTORE);
        }
    }

    static void Disable() {
        if (!enabled) return;
        enabled = false;
        auto wnd = GetConsoleWindow();
        if (wnd != nullptr) {
            ShowWindow(wnd, SW_HIDE);
        }
        
    }
};
