#include "ModStateWaitingDependantsUnload.h"

#include <modloader_new/ModManager.h>

#include "ModStateDisabled.h"
#include "ModStateWaitingDependenciesLoad.h"

using namespace std::chrono;

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

std::string modloader::ModStateWaitingDependantsUnload::GetIcon()
{
    auto animatedIcon = ICON_MD_HOURGLASS_TOP;
    if (duration_cast<seconds>(system_clock::now().time_since_epoch()).count() % 2 == 0)
        animatedIcon = ICON_MD_HOURGLASS_BOTTOM;

    return std::string(ICON_MD_FORMAT_LIST_BULLETED) + animatedIcon;
}

bool modloader::ModStateWaitingDependantsUnload::Check(const Mod& mod)
{
    auto modID = mod.GetInfo()->GetID();
    return std::ranges::none_of(ModManager::GetMods(), [&modID](const std::shared_ptr<Mod>& iterMod) -> bool {
        return iterMod->IsActive() && iterMod->GetInfo()->deps.contains(modID);
    });
}
