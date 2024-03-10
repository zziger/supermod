#include "ModStateWaitingDependenciesLoad.h"

#include <Log.h>
#include <modloader_new/ModManager.h>
#include <modloader_new/mod/Mod.h>

#include "ModStateDisabled.h"
#include "ModStateEnabled.h"
#include "ModStateWaitingDependantsUnload.h"

using namespace std::chrono;

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

std::string modloader::ModStateWaitingDependenciesLoad::GetIcon()
{
    auto animatedIcon = ICON_MD_HOURGLASS_TOP;
    if (duration_cast<seconds>(system_clock::now().time_since_epoch()).count() % 2 == 0)
        animatedIcon = ICON_MD_HOURGLASS_BOTTOM;

    return std::string(ICON_MD_FORMAT_LIST_BULLETED) + animatedIcon;
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
