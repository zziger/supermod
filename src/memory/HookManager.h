#pragma once
#include <format>
#include <modloader/mod/impl/lua/lua.h>
#include <string>

#include "Memory.h"

class HookManager
{
public:
    struct RegisteredHook
    {
        int32_t id;
        Memory mem;
        explicit RegisteredHook(const int32_t id, const Memory mem) : id(id), mem(mem) {}

        bool operator==(const RegisteredHook& other) const { return id == other.id; }
    };

    static inline uint32_t lastId = 0;

    template <class T, std::size_t Size>
    static RegisteredHook RegisterHook(const char (&pattern)[Size], T* fn, T** orig)
    {
        static Memory::Pattern pat(pattern); // todo constexpr
        static auto mem = pat.Search();
        return RegisterHook(mem, fn, orig);
    }

    template <class T>
    static RegisteredHook RegisterHook(Memory mem, T* fn, T** orig)
    {
        const auto id = lastId++;
        mem.Detour(fn, orig, id);
        return RegisteredHook(id, mem);
    }

    template <class T, std::size_t Size>
    static RegisteredHook RegisterHookExclusive(const char (&pattern)[Size], T* fn, T** orig)
    {
        static Memory::Pattern pat(pattern); // todo constexpr
        static auto mem = pat.Search();
        return RegisterHookExclusive(mem, fn, orig);
    }

    template <class T>
    static RegisteredHook RegisterHookExclusive(Memory mem, T* fn, T** orig)
    {
        mem.ExclusiveDetour(fn, orig);
        return RegisteredHook(-1, mem);
    }

    static void UnregisterHook(RegisteredHook hook);

    static void AddLuaIntrinsics(sol::table table)
    {
        table["__createHook"] = sol::as_function([](uint32_t ptr, uint32_t proc, uint32_t orig) -> uint32_t {
            auto idx = lastId++;
            auto createStatus = MH_CreateHookEx(idx, (void*)ptr, (void*)proc, (void**)orig);
            if (createStatus != MH_OK)
                throw std::exception(
                    std::format("Не удалось создать хук. Статус MinHook: {}", (int)createStatus).c_str());
            auto enableStatus = MH_EnableHookEx(idx, (void*)ptr);
            if (enableStatus != MH_OK)
                throw std::exception(
                    std::format("Не удалось активировать хук. Статус MinHook: {}", (int)enableStatus).c_str());
            return idx;
        });
        table["__removeHook"] = sol::as_function([](uint32_t ptr, uint32_t idx) {
            auto disableStatus = MH_DisableHookEx(idx, (void*)ptr);
            if (disableStatus != MH_OK)
                throw std::exception(
                    std::format("Не удалось деактивировать хук. Статус MinHook: {}", (int)disableStatus).c_str());
            auto removeStatus = MH_RemoveHookEx(idx, (void*)ptr);
            if (removeStatus != MH_OK)
                throw std::exception(
                    std::format("Не удалось удалить хук. Статус MinHook: {}", (int)removeStatus).c_str());
        });
    }

    static void RemoveLuaIntrinsics(sol::table table)
    {
        table["__createHook"] = sol::nil;
        table["__removeHook"] = sol::nil;
    }
};

template <>
struct std::hash<HookManager::RegisteredHook>
{
    auto operator()(const HookManager::RegisteredHook& mem) const noexcept -> size_t { return mem.id; }
};