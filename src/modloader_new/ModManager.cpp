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

        auto mod = std::make_shared<Mod>(modInfo, std::make_unique<TestImpl>(modInfo));
        AddMod(mod);
    }
}

void modloader::ModManager::Tick()
{
    std::vector<std::shared_ptr<Mod>> removalList {};

    for (const auto& mod : mods)
    {
        mod->Tick();
        if (!mod->IsActive() && mod->HasFlag(Mod::Flag::REMOVAL_SCHEDULED)) removalList.push_back(mod);
    }

    if (!removalList.empty())
    {
        mods.erase(
            std::ranges::remove_if(mods, [](const std::shared_ptr<Mod>& mod)
            {
                return !mod->IsActive() && mod->HasFlag(Mod::Flag::REMOVAL_SCHEDULED);
            }).begin(),
            mods.end()
            );

        for (const auto& mod : mods)
        {
            mods_map.erase(mod->GetInfo()->GetID());
        }

        for (const auto& mod : mods)
        {
            if (mod->HasFlag(Mod::Flag::REMOVE_WITH_FILES))
            {
                const auto info = std::dynamic_pointer_cast<ModInfoFilesystem>(mod->GetInfo());
                if (!info) continue;
                Log::Info << "Should delete file " << info->basePath << Log::Endl;
                // TODO: delete from filesystem
            }
        }
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
