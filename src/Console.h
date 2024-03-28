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
    
    static void Initialize();

    inline static bool enabled = false;
    inline static FILE* stdinFile = nullptr;
    inline static FILE* stdoutFile = nullptr;

    static void Enable();

    static void Disable();
};
