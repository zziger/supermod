#include "ModStateWaitingDependentsUnload.h"

#include <modloader/ModManager.h>

#include "ModStateDisabled.h"
#include "ModStateWaitingDependenciesLoad.h"

using namespace std::chrono;

void modloader::ModStateWaitingDependentsUnload::Init(Mod& mod)
{
    if (Check(mod)) mod.SetState<ModStateDisabled>();
}

void modloader::ModStateWaitingDependentsUnload::Update(Mod& mod)
{
    if (mod.IsEnabled())
    {
        mod.SetState<ModStateWaitingDependenciesLoad>();
        return;
    }

    if (Check(mod)) mod.SetState<ModStateDisabled>();
}

std::string modloader::ModStateWaitingDependentsUnload::GetIcon()
{
    auto animatedIcon = ICON_MD_HOURGLASS_TOP;
    if (duration_cast<seconds>(system_clock::now().time_since_epoch()).count() % 2 == 0)
        animatedIcon = ICON_MD_HOURGLASS_BOTTOM;

    return std::string(ICON_MD_FORMAT_LIST_BULLETED) + animatedIcon;
}

bool modloader::ModStateWaitingDependentsUnload::Check(const Mod& mod)
{
    auto modID = mod.GetInfo()->GetID();
    return std::ranges::none_of(ModManager::GetModDependents(modID), [](const std::shared_ptr<Mod>& iterMod) -> bool {
        return iterMod->IsActive();
    });
}
