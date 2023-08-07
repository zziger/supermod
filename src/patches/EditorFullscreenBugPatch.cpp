/// In the in-game level editor if you start a level test pressing F5
/// even when leaving fullscreen mode game window remains topmost.
/// This is caused by developers setting HWND_TOPMOST at SetWindowPos,
/// but when fullscreen is left it does not get cancelled.
/// This patch hooks respective fullscreen cancel function and
/// applies HWND_NOTOPMOST.

#include "Utils.h"
#include "events/EventManager.h"
#include "memory/HookManager.h"
#include "sdk/Game.h"

HOOK_FN(inline void, editor_leave_fullscreen, ARGS()) {
	editor_leave_fullscreen_orig();
	SetWindowPos(*sdk::Game::window, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
}

inline EventManager::Ready $editor_fullscreen_bug_patch([] {
	HookManager::RegisterHook("55 8B EC C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? 68 ? ? ? ? 6A", HOOK_REF_FORCE(editor_leave_fullscreen));
});

