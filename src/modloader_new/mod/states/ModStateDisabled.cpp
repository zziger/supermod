#include "ModStateDisabled.h"

#include <Log.h>

#include "ModStateEnabled.h"
#include "../Mod.h"

void modloader::ModStateDisabled::Init(Mod& mod)
{
    mod.GetImpl()->OnDisabled();
    Log::Info << "Mod state disabled" << Log::Endl;
}

void modloader::ModStateDisabled::Update(Mod& mod)
{
    if (!mod.IsEnabled()) return;
    mod.SetState(std::make_unique<ModStateEnabled>());
}

std::string modloader::ModStateDisabled::GetLabel()
{
    return "Выключен";
}
