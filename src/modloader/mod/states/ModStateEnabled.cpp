#include "ModStateEnabled.h"

#include <Log.h>
#include <modloader/files/ModFileResolver.h>

#include "ModStateDisabled.h"
#include "ModStateWaitingDependentsUnload.h"
#include "../Mod.h"

void modloader::ModStateEnabled::Init(Mod& mod)
{
    if (const auto info = std::dynamic_pointer_cast<ModInfoFilesystem>(mod.GetInfo()))
    {
        const auto path = info->basePath / "data";
        ModFileResolver::LoadFiles(path);
    }

    mod.GetImpl()->OnEnabled();
}

void modloader::ModStateEnabled::Update(Mod& mod)
{
    if (mod.IsEnabled()) return;
    mod.SetState<ModStateWaitingDependentsUnload>();
}
