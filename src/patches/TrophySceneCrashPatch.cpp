/// The game has a problem with memory overflow that leads to crash after opening trophy scene
/// The problem is related to system uptime, "UB" state starts after ~65 sec uptime.
/// Each second adds ~4 bytes offset to the read of a 256 bytes long buffer,
/// after some uptime it either enters read-restricted zone or leaves process memory,
/// effectively leading to a access violation crash.
/// This patch fixes the issue by limiting the value of the affected function so it does not leave the buffer

#include "Utils.h"
#include "events/EventManager.h"
#include "memory/HookManager.h"

HOOK_FN(inline int, set_random_seed, ARGS(int seed))
{
    return set_random_seed_orig(seed % 65535);
}

inline EventManager::Ready $trophy_scene_crash_patch([] {
    const Memory::Pattern pat("E8 ? ? ? ? 83 C4 ? 6A ? E8 ? ? ? ? 83 C4 ? C7 05 ? ? ? ? ? ? ? ? E8");
    HookManager::RegisterHook(pat.Search().GoToNearCall(), HOOK_REF(set_random_seed));
});
