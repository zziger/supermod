#include "ModStateWaitingDependantsUnload.h"

#include <modloader_new/ModManager.h>

#include "ModStateDisabled.h"
#include "ModStateWaitingDependenciesLoad.h"

void modloader::ModStateWaitingDependantsUnload::Init(Mod& mod)
{
    if (Check(mod)) mod.SetState<ModStateDisabled>();
}

void modloader::ModStateWaitingDependantsUnload::Update(Mod& mod)
{
    if (mod.IsEnabled())
    {
        mod.SetState<ModStateWaitingDependenciesLoad>();
        return;
    }

    if (Check(mod)) mod.SetState<ModStateDisabled>();
}

bool modloader::ModStateWaitingDependantsUnload::Check(const Mod& mod)
{
    auto modID = mod.GetInfo()->GetID();
    return std::ranges::none_of(ModManager::GetMods(), [&modID](const std::shared_ptr<Mod>& iterMod) -> bool {
        return iterMod->IsActive() && iterMod->GetInfo()->deps.contains(modID);
    });
}
