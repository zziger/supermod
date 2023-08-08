#pragma once
#include <string>

#include "Memory.h"

class HookManager {
public:
    struct RegisteredHook
    {
        int32_t id;
        Memory mem;
        explicit RegisteredHook(const int32_t id, const Memory mem) : id(id), mem(mem) {  }
        
        bool operator==(const RegisteredHook &other) const {
            return id == other.id;
        }
    };

    static inline uint32_t lastId = 0;
    
    template <class T, std::size_t Size>
    static RegisteredHook RegisterHook(const char(& pattern)[Size], T* fn, T** orig) {
        static Memory::Pattern pat(pattern); // todo constexpr
        static auto mem = pat.Search();
        return RegisterHook(mem, fn, orig);
    }
    
    template <class T>
    static RegisteredHook RegisterHook(Memory mem, T* fn, T** orig) {
        const auto id = lastId++;
        mem.Detour(fn, orig, id);
        return RegisteredHook(id, mem);
    }

    static void UnregisterHook(RegisteredHook hook);

    static void AddToLua(LuaContext& ctx) {
        ctx.writeFunction("__createHook", std::function([=](uint32_t ptr, uint32_t proc, uint32_t orig) -> uint32_t {
            auto idx = lastId++;
            auto createStatus = MH_CreateHookEx(idx, (void*) ptr, (void*) proc, (void**) orig);
            if (createStatus != MH_OK) throw std::exception(std::format("Не удалось создать хук. Статус MinHook: {}", (int) createStatus).c_str());
            auto enableStatus = MH_EnableHookEx(idx, (void*) ptr);
            if (enableStatus != MH_OK) throw std::exception(std::format("Не удалось активировать хук. Статус MinHook: {}", (int) enableStatus).c_str());
            return idx;
        }));
        ctx.writeFunction("__removeHook", std::function([=](uint32_t ptr, uint32_t idx) {
            auto disableStatus = MH_DisableHookEx(idx, (void*) ptr);
            if (disableStatus != MH_OK) throw std::exception(std::format("Не удалось деактивировать хук. Статус MinHook: {}", (int) disableStatus).c_str());
            auto removeStatus = MH_RemoveHookEx(idx, (void*) ptr);
            if (removeStatus != MH_OK) throw std::exception(std::format("Не удалось удалить хук. Статус MinHook: {}", (int) removeStatus).c_str());
        }));
    }
};
    
template <>
struct std::hash<HookManager::RegisteredHook> {
    auto operator()(const HookManager::RegisteredHook &mem) const noexcept -> size_t {
        return mem.id;
    }
};