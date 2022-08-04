#pragma once
#include "CMemory.h"
#include "data.h"
#include "directx/d3d8.h"

class CGameApis {
public:
    static inline void* globalThis = nullptr;
    static inline IDirect3DDevice8** d3dDevice = nullptr;

    static void InitializeThis() {
        constexpr CMemory::Pattern movGlobalThis("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? 68 ? ? ? ? 6A ? 6A ?");
        globalThis = *movGlobalThis.Search().Get<void**>(1);
        
        constexpr CMemory::Pattern pushD3dDevicePointer("68 ? ? ? ? 68 ? ? ? ? 6A ? 8B 4D 08");
        d3dDevice = *pushD3dDevicePointer.Search().Get<IDirect3DDevice8***>(1);
    }
    
    
    static char16_t* ShowLowerMessage(char16_t* str) {
        static constexpr CMemory::Pattern showLowerMessagePat("55 8B EC D9 ? ? ? ? ? D8 ? ? ? ? ? DF E0 F6 C4 ? 7A ? C7 05 ? ? ? ? ? ? ? ?");
        static auto fn = showLowerMessagePat.Search();
        return fn.Call<char16_t*>(str);
    }
    
    static int DrawWorldFadingText(vector3 vector, char16_t* text, textDrawType type) {
        static constexpr CMemory::Pattern drawWorldFadingTextPat("55 8B EC 83 EC ? A1 ? ? ? ? C1 E0 ? 05 ? ? ? ?");
        static auto fn = drawWorldFadingTextPat.Search();
        return fn.Call<int>(vector, text, type);
    }

    static int DealDamage(float damage) { 
        static constexpr CMemory::Pattern dealDamagePat("55 8B EC 83 EC ? A1 ? ? ? ? 89 45 F8 89 4D B4");
        static auto fn = dealDamagePat.Search().Get<int (__thiscall *)(void* this_, float dmg)>();
        return fn(globalThis, damage);
    }

    static void Kill() {
        DealDamage(100); // todo get maxHealth
    }

    static void ToggleEditor(bool enable) {
        constexpr CMemory::Pattern editorDisableInstruction("C6 05 ? ? ? ? ? 0F B6 15 ? ? ? ? 85 D2 75 ? C7 05 ? ? ? ? ? ? ? ?");
        auto mem = editorDisableInstruction.Search();
        const auto ptr = *mem.Get<byte**>(2); 
        *ptr = enable ? 1 : 0;
        // *mem.Get<byte*>(6) = enable ? 1 : 0; // todo disable override
    }

    static int TriggerCheckpoint() {
        static constexpr CMemory::Pattern triggerCheckpointPat("55 8B EC 81 EC ? ? ? ? 89 8D 00 FF FF FF");
        typedef int (__thiscall *triggerCheckpointType)(void* this_);
        static auto fn = triggerCheckpointPat.Search().Get<triggerCheckpointType>();
        // todo most likely requires different this, crashes the game now
        return fn(globalThis);        
    }
};
