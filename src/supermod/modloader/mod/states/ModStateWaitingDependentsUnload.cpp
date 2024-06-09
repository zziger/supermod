
#include <supermod/modloader/mod/states/ModStateWaitingDependentsUnload.hpp>
#include <supermod/pch.hpp>

#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/files/ModFileResolver.hpp>
#include <supermod/modloader/mod/Mod.hpp>
#include <supermod/modloader/mod/states/ModStateDisabled.hpp>
#include <supermod/modloader/mod/states/ModStateWaitingDependenciesLoad.hpp>

using namespace std::chrono;

void modloader::ModStateWaitingDependentsUnload::Init(Mod& mod)
{
    if (Check(mod))
        mod.SetState<ModStateDisabled>();
}

void modloader::ModStateWaitingDependentsUnload::Update(Mod& mod)
{
    if (mod.IsEnabled())
    {
        mod.SetState<ModStateWaitingDependenciesLoad>();
        return;
    }

    if (Check(mod))
        mod.SetState<ModStateDisabled>();
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
    return std::ranges::none_of(ModManager::GetModDependents(modID),
                                [](const std::shared_ptr<Mod>& iterMod) -> bool { return iterMod->IsActive(); });
}
