#include "ModManager.h"

#include <Log.h>
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

        auto modInfo = std::make_shared<ModInfoFilesystem>();
        modInfo->FromPath(file.path());

        auto mod = std::make_unique<Mod>(modInfo, std::make_unique<TestImpl>(modInfo));
        AddMod(std::move(mod));
    }
}

void modloader::ModManager::Tick()
{
    for (const auto& mod : mods)
    {
        mod->Tick();
    }
}

std::shared_ptr<modloader::Mod> modloader::ModManager::FindModByID(const std::string& id)
{
    if (!mods_map.contains(id)) return nullptr;
    return mods_map[id];
}

void modloader::ModManager::AddMod(const std::shared_ptr<Mod>& mod)
{
    mods.push_back(mod);
    mods_map[mod->GetInfo()->GetID()] = mod;
}

#ifdef UNIT_TESTS
void modloader::ModManager::Reset()
{
    mods.clear();
    mods_map.clear();
}
#endif
