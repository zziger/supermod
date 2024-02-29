#include "InternalMod.h"

#include <modloader_new/mod/Mod.h>

void ModImplInternal::OnEnabled()
{
    adaptive_resolution_module.Init();
}

void ModImplInternal::OnDisabled()
{
}

void ModImplInternal::OnTick()
{
}

void ModImplInternal::RenderUI()
{
    adaptive_resolution_module.Render();
}

std::shared_ptr<modloader::Mod> ModImplInternal::CreateMod()
{
    auto info = std::make_shared<modloader::ModInfo>("$internal");
    info->title = "SuperMod";
    info->author = "zziger";
    info->version = VERSION;
    info->description = "Встроенные в мод патчи игры";

    auto mod = std::make_shared<modloader::Mod>(info, std::make_unique<ModImplInternal>());
    mod->SetFlag(modloader::Mod::Flag::INTERNAL);
    mod->Toggle(true);
    mod->Update();

    return mod;
}


