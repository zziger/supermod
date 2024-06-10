/// In the in-game level editor if you start a level test pressing S
/// and then leave it pressing S again before you closed "Let's go!" window
/// editor controls break
/// This seems to be realted to pause state management, and this patch fixes
/// the issue by resetting paused state while in editor

#include <supermod/pch.hpp>

#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/memory/HookManager.hpp>
#include <supermod/memory/Memory.hpp>

using namespace sm;

static inline int* isPaused;

HOOK_FN(inline int, render_editor, ARGS())
{
    *isPaused = 0;
    return render_editor_orig();
}

inline EventManager::Ready $editor_controls_bug_patch([] {
    isPaused = *Memory::Pattern("C6 05 ? ? ? ? ? 0F B6 0D ? ? ? ? 85 C9 75 ? 6A").Search().Get<int**>(2);
    HookManager::RegisterHook("55 8B EC 83 EC ? 89 4D ? D9 05 ? ? ? ? D8 05 ? ? ? ? D9 1D ? ? ? ? C6 05",
                              HOOK_REF_FORCE(render_editor));
});
