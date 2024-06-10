#include <supermod/modloader/mod/states/ModStateDisabled.hpp>
#include <supermod/pch.hpp>

#include <supermod/modloader/files/ModFileResolver.hpp>
#include <supermod/modloader/mod/Mod.hpp>
#include <supermod/modloader/mod/info/ModInfoFilesystem.hpp>
#include <supermod/modloader/mod/states/ModStateWaitingDependenciesLoad.hpp>

namespace sm::modloader
{
void ModStateDisabled::Init(Mod& mod)
{
    mod.GetImpl()->OnDisabled();

    if (const auto info = std::dynamic_pointer_cast<ModInfoFilesystem>(mod.GetInfo()))
    {
        const auto path = info->basePath / "data";
        ModFileResolver::LoadFiles(path);
    }
}

void ModStateDisabled::Update(Mod& mod)
{
    if (!mod.IsEnabled())
        return;
    mod.SetState<ModStateWaitingDependenciesLoad>();
}
} // namespace sm::modloader
