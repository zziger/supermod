#include "ModStateWaitingDependencies.h"

#include <modloader_new/mod/Mod.h>

#include "ModStateDisabled.h"
#include "ModStateEnabled.h"

std::string modloader::ModStateWaitingDependencies::GetLabel()
{
    return "Ожидание зависимостей...";
}

void modloader::ModStateWaitingDependencies::Update(Mod& mod)
{
    if (!mod.IsEnabled())
    {
        mod.SetState(std::make_unique<ModStateDisabled>());
        return;
    }

    // TODO check for deps

    mod.SetState(std::make_unique<ModStateEnabled>());
}
