#include "ModStateWaitingDependenciesLoad.h"

#include <Log.h>
#include <modloader_new/ModManager.h>
#include <modloader_new/mod/Mod.h>

#include "ModStateDisabled.h"
#include "ModStateEnabled.h"
#include "ModStateWaitingDependantsUnload.h"

void modloader::ModStateWaitingDependenciesLoad::Init(Mod& mod)
{
    if (Check(mod)) mod.SetState<ModStateEnabled>();
}

void modloader::ModStateWaitingDependenciesLoad::Update(Mod& mod)
{
    if (!mod.IsEnabled())
    {
        mod.SetState<ModStateWaitingDependantsUnload>();
        return;
    }

    if (Check(mod)) mod.SetState<ModStateEnabled>();
}

bool modloader::ModStateWaitingDependenciesLoad::Check(const Mod& mod)
{
    auto deps = mod.GetInfo()->deps;
    if (deps.empty()) return true;
    return std::ranges::all_of(deps, [](const std::string& modID) -> bool {
        const auto mod = ModManager::FindModByID(modID);
        return mod && mod->IsActive();
    });
}
