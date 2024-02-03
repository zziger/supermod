#include "ModStateEnabled.h"

#include <Log.h>

#include "ModStateDisabled.h"
#include "../Mod.h"

void modloader::ModStateEnabled::Init(Mod& mod)
{
    mod.GetImpl()->OnEnabled();
    Log::Info << "Mod state enabled" << Log::Endl;
}

void modloader::ModStateEnabled::Update(Mod& mod)
{
    if (mod.IsEnabled()) return;
    mod.SetState(std::make_unique<ModStateDisabled>());
}

std::string modloader::ModStateEnabled::GetLabel()
{
    return "Включен";
}
