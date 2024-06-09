/// Fixes crashes when rendering of large ground area and
/// and randomly disappearing background.
/// This patch disables function causing both issues,
/// not sure why does it exist, disabling it doesn't
/// seem to break anything. (at least not known yet)

#include "Utils.h"
#include "events/EventManager.h"
#include "memory/HookManager.h"

HOOK_FN(char, prepare_levelback_stuff, ARGS())
{
    return 0;
}

inline EventManager::Ready $levelback_render_patch([] {
    HookManager::RegisterHook(
        "55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 89 45 ? 68 ? ? ? ? 6A ? 68 ? ? ? ? E8 ? ? ? ? 83 C4 ? 0F B6 05",
        HOOK_REF_FORCE(prepare_levelback_stuff));
});
