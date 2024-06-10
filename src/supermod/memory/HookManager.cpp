#include <supermod/memory/HookManager.hpp>

namespace sm
{
void HookManager::UnregisterHook(RegisteredHook hook)
{
    if (hook.id == -1)
        hook.mem.DeactivateExclusiveDetour();
    else
        hook.mem.DeactivateDetour(hook.id);
}
} // namespace sm