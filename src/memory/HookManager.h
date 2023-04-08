#pragma once
#include <string>

#include "Memory.h"

class HookManager {
public:
    template <class T, std::size_t Size>
    static Memory RegisterHook(const char(& pattern)[Size], T* fn, T** orig) {
        static Memory::Pattern pat(pattern); // todo constexpr
        static auto mem = pat.Search();
        mem.Detour(fn, orig);
        return mem;
    }
    
    template <class T>
    static Memory RegisterHook(Memory mem, T* fn, T** orig) {
        mem.Detour(fn, orig);
        return mem;
    }

    static Memory UnregisterHook(Memory mem);

    static void AddToLua(LuaContext& ctx) {
        ctx.writeFunction("__createHook", std::function([=](uint32_t ptr, uint32_t proc, uint32_t orig) {
            auto createStatus = MH_CreateHook((void*) ptr, (void*) proc, (void**) orig);
            if (createStatus != MH_OK) throw std::exception(std::format("Не удалось создать хук. Статус MinHook: {}", (int) createStatus).c_str());
            auto enableStatus = MH_EnableHook((void*) ptr);
            if (enableStatus != MH_OK) throw std::exception(std::format("Не удалось активировать хук. Статус MinHook: {}", (int) enableStatus).c_str());
        }));
        ctx.writeFunction("__removeHook", std::function([=](uint32_t ptr) {
            auto disableStatus = MH_DisableHook((void*) ptr);
            if (disableStatus != MH_OK) throw std::exception(std::format("Не удалось деактивировать хук. Статус MinHook: {}", (int) disableStatus).c_str());
            auto removeStatus = MH_RemoveHook((void*) ptr);
            if (removeStatus != MH_OK) throw std::exception(std::format("Не удалось удалить хук. Статус MinHook: {}", (int) removeStatus).c_str());
        }));
    }
};