#include "ModStateEnabled.h"

#include <modloader/files/ModFileResolver.h>

#include "../Mod.h"
#include "ModStateDisabled.h"
#include "ModStateWaitingDependentsUnload.h"

void modloader::ModStateEnabled::Init(Mod& mod)
{
    if (const auto info = std::dynamic_pointer_cast<ModInfoFilesystem>(mod.GetInfo()))
    {
        const auto path = info->basePath / "data";
        ModFileResolver::LoadFiles(path);
    }

    try
    {
        mod.GetImpl()->OnEnabled();
    }
    catch (std::exception& e)
    {
        mod.Toggle(false);
        mod.SetLoadingError(e.what());
        Update(mod);
    }
}

void modloader::ModStateEnabled::Update(Mod& mod)
{
    if (mod.IsEnabled())
        return;
    mod.SetState<ModStateWaitingDependentsUnload>();
}
