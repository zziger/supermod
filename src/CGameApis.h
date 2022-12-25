#pragma once
#include "memory/Memory.h"
#include "data.h"
#include <thirdparty/directx/d3d8.h>
#include <filesystem>
#include <optional>

#include "Utils.h"
#include "Log.h"

class CGameApis {
public:
    static inline void* globalThis = nullptr;
    static inline IDirect3DDevice8** d3dDevice = nullptr;
    static inline HWND* window = nullptr;
    static inline bool* resumeGame = nullptr;
    static inline bool cursorState = true;

    static void InitializeThis() {
        constexpr Memory::Pattern movGlobalThis("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? 68 ? ? ? ? 6A ? 6A ?");
        globalThis = *movGlobalThis.Search().Get<void**>(1);
        
        constexpr Memory::Pattern pushD3dDevicePointer("68 ? ? ? ? 68 ? ? ? ? 6A ? 8B 4D 08");
        d3dDevice = *pushD3dDevicePointer.Search().Get<IDirect3DDevice8***>(1);
        
        constexpr Memory::Pattern movWindow("A3 ? ? ? ? 83 3D ? ? ? ? ? 74 ? 68 ? ? ? ? E8 ? ? ? ?");
        window = *movWindow.Search().Get<HWND**>(1);

        constexpr Memory::Pattern resumeGamePtr("C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? FF 15");
        resumeGame = *resumeGamePtr.Search().Get<bool**>(2);
    }
    
    
    static char16_t* ShowLowerMessage(char16_t* str) {
        static constexpr Memory::Pattern showLowerMessagePat("55 8B EC D9 ? ? ? ? ? D8 ? ? ? ? ? DF E0 F6 C4 ? 7A ? C7 05 ? ? ? ? ? ? ? ?");
        static auto fn = showLowerMessagePat.Search();
        return fn.Call<char16_t*>(str);
    }
    
    static int DrawWorldFadingText(vector3 vector, char16_t* text, textDrawType type) {
        static constexpr Memory::Pattern drawWorldFadingTextPat("55 8B EC 83 EC ? A1 ? ? ? ? C1 E0 ? 05 ? ? ? ?");
        static auto fn = drawWorldFadingTextPat.Search();
        return fn.Call<int>(vector, text, type);
    }

    static int DealDamage(float damage) { 
        static constexpr Memory::Pattern dealDamagePat("55 8B EC 83 EC ? A1 ? ? ? ? 89 45 F8 89 4D B4");
        static auto fn = dealDamagePat.Search().Get<int (__thiscall *)(void* this_, float dmg)>();
        return fn(globalThis, damage);
    }

    static void Kill() {
        DealDamage(100); // todo get maxHealth
    }

    static void ToggleEditor(bool enable) {
        constexpr Memory::Pattern editorDisableInstruction("C6 05 ? ? ? ? ? 0F B6 15 ? ? ? ? 85 D2 75 ? C7 05 ? ? ? ? ? ? ? ?");
        auto mem = editorDisableInstruction.Search();
        const auto ptr = *mem.Get<byte**>(2); 
        *ptr = enable ? 1 : 0;
        // *mem.Get<byte*>(6) = enable ? 1 : 0; // todo disable override
    }

    static int TriggerCheckpoint() {
        static constexpr Memory::Pattern triggerCheckpointPat("55 8B EC 81 EC ? ? ? ? 89 8D 00 FF FF FF");
        typedef int (__thiscall *triggerCheckpointType)(void* this_);
        static auto fn = triggerCheckpointPat.Search().Get<triggerCheckpointType>();
        // todo most likely requires different this, crashes the game now
        return fn(globalThis);        
    }

    inline static std::filesystem::path* dataPath = nullptr;
    static std::filesystem::path GetDataPath() {
        if (dataPath) return *dataPath; 
        static constexpr Memory::Pattern pathToDataPat("68 ? ? ? ? FF 15 ? ? ? ? 68 ? ? ? ? 6A ? 6A ?");
        std::string strPath;
        auto strPtr = *pathToDataPat.Search().Get<char**>(1);
        strPath.assign(strPtr, std::find(strPtr, strPtr + 256, '\0'));
        static auto pathToData = strPath.empty() ? std::filesystem::current_path() / "data" : std::filesystem::path(strPath);
        dataPath = new std::filesystem::path(pathToData);
        return pathToData;
    }

    static std::filesystem::path GetModsPath() {
        return GetDataPath() / ".." / "mods";
    }

    static void Restart() {
        char buf[MAX_PATH];
        GetModuleFileNameA(nullptr, buf, MAX_PATH);
        current_path(GetDataPath() / "..");
        
        STARTUPINFOA si(0);
        si.cb = sizeof(STARTUPINFOA);
        PROCESS_INFORMATION	pi(nullptr);
        
        CreateProcessA(nullptr, buf, nullptr, nullptr, false, 0, nullptr, nullptr, &si, &pi);
        ExitProcess(0);
    }
};
