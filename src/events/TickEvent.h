#pragma once
#include "EventManager.h"
#include "Utils.h"
#include "memory/HookManager.h"
#include "memory/Memory.h"

struct BeforeTickEvent final : IEvent<"beforeTick", BeforeTickEvent> {};
struct AfterTickEvent final : IEvent<"afterTick", AfterTickEvent> {};
struct EarlyTickEvent final : IEvent<"earlyTick", EarlyTickEvent> {};

typedef BeforeTickEvent TickEvent;

inline int (__thiscall *render_orig)(void* this_) = nullptr;
inline int  __fastcall render(void* this_, void*) {
    EventManager::Emit(TickEvent());
    auto res = render_orig(this_);
    EventManager::Emit(AfterTickEvent());
    return res;
}
inline int (__thiscall *main_loop_orig)(void* this_) = nullptr;
inline int  __fastcall main_loop(void* this_, void*) {
    EventManager::Emit(EarlyTickEvent());
    return main_loop_orig(this_);
}

inline EventManager::Ready $tick_event_hook([] {
    HookManager::RegisterHook("55 8B EC 51 E8 ? ? ? ? 6A ?", HOOK_REF_FORCE(render));
    HookManager::RegisterHook("55 8B EC 83 3D ? ? ? ? ? 75 ? 68", HOOK_REF_FORCE(main_loop));
});