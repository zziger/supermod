#include "HookManager.h"

void HookManager::UnregisterHook(RegisteredHook hook) {
    hook.mem.DeactivateDetour(hook.id);
}

