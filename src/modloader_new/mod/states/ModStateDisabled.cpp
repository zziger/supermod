#include "ModStateDisabled.h"

#include <Log.h>
#include <modloader_new/files/ModFileResolver.h>

#include "ModStateEnabled.h"
#include "ModStateWaitingDependenciesLoad.h"
#include "../Mod.h"

void modloader::ModStateDisabled::Init(Mod& mod)
{
    mod.GetImpl()->OnDisabled();

    if (const auto info = std::dynamic_pointer_cast<ModInfoFilesystem>(mod.GetInfo()))
    {
        const auto path = info->basePath / "data";
        ModFileResolver::LoadFiles(path);
    }
}

void modloader::ModStateDisabled::Update(Mod& mod)
{
    if (!mod.IsEnabled()) return;
    mod.SetState<ModStateWaitingDependenciesLoad>();
}
