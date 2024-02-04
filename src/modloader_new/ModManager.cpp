#include "ModManager.h"

#include <sdk/Game.h>

#include "mod/impl/TestImpl.h"

void modloader::ModManager::Init()
{
    ScanMods();
}

void modloader::ModManager::ScanMods()
{
    const auto modsPath = sdk::Game::GetRootPath() / MODS_DIRECTORY;

    for (const auto& file : std::filesystem::directory_iterator(modsPath))
    {
        if (!file.is_directory()) continue; // TODO maybe zipmod support?
        if (!exists(file.path() / ModInfoFilesystem::MANIFEST_FILENAME)) continue;

        auto modInfo = std::make_unique<ModInfoFilesystem>();
        modInfo->FromPath(file.path());

        auto mod = std::make_unique<Mod>(std::move(modInfo), std::make_unique<TestImpl>());
        mods.push_back(std::move(mod));
    }
}

void modloader::ModManager::Tick()
{
    for (const auto& mod : mods)
    {
        mod->Tick();
    }
}
