/// Original game has issues rendering multiple platforms in one place
/// I have no idea why but this fixes the issue

#include "Utils.h"
#include "events/EventManager.h"
#include "memory/HookManager.h"

inline void (__thiscall *render_platform_orig)(void*) = nullptr;
inline void __fastcall render_platform(void* this_, void*) {
    return render_platform_orig(this_);
}

inline EventManager::Ready $platform_render_patch([] {
    HookManager::RegisterHook("55 8B EC 81 EC ? ? ? ? 89 8D ? ? ? ? 68 ? ? ? ? 68 ? ? ? ? 68 ? ? ? ? 68 ? ? ? ? 8D 4D ? E8 ? ? ? ? 8B 85 ? ? ? ? 0F B6 88 ? ? ? ? 85 C9 74 ? 8B 15 ? ? ? ? 89 55 ? 8B 85", HOOK_REF_FORCE(render_platform));
});

