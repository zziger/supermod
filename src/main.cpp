#include <iostream>
#include <locale>
#include <Windows.h>
#include <thread>

#include "CMemory.h"
#include "Utils.h"
#include "main.h"

#include <filesystem>
#include <memory>

#include "CConfig.h"
#include "CConsole.h"
#include "CGameApis.h"
#include "CGUI.h"
#include "CModLoader.h"
#include "Log.h"

#include "patches/CAllowMultipleInstances.h"
#include "patches/CRenderUnfocused.h"
#include "patches/CWidescreenFix.h"
#include "patches/CAdditionalMusic.h"
#include "patches/CEditor.h"
#include "patches/CFpsLimit.h"

#include "mods/CPowerupsKill.h"
#include "mods/CLadno.h"
#include "mods/CStartupSplash.h"
#include "mods/CEarlyStats.h"
#include "mods/CExtendGroundsLimit.h"

DWORD WINAPI Init() {
    auto cwd = std::filesystem::current_path();
    CConfig::Instance().Initialize(cwd);
    CConsole::Initialize();
    Log::Info << "Initializing SuperMod " << VERSION << " by zziger..." << Log::Endl;
    
    const auto base = (uintptr_t) GetModuleHandle(nullptr);
    
    CMemory::Base() = base;
    CMemory::OnPatternNotFound([](const std::string& pattern) {
        Log::Error << "Failed to find pattern " << pattern << Log::Endl;
    });

    CGameApis::InitializeThis();
    MH_Initialize();
    CMemory::RunHooks();
    
    CModuleManager::RegisterModules({
        new CAllowMultipleInstances,
        new CRenderUnfocused,
        new CFpsLimit,
        new CWidescreenFix,
        // new CEditor,
        new CAdditionalMusic,
        
        new CStartupSplash,
        new CPowerupsKill,
        new CLadno,
        new CEarlyStats,
        new CExtendGroundsLimit
    });
    CModuleManager::Initialize();
    CModuleManager::LogModules();
    CModLoader::Instance().Initialize();
    
    return true;
}

BOOL APIENTRY main(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        Init();
        // CreateThread(0, 0, Init, hModule, 0, 0);

        Log::Info << "Mod initialized!" << Log::Endl;
    }

    if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        CConsole::Destroy();
        ShowWindow(GetConsoleWindow(), SW_HIDE);
    }
    return TRUE;
}