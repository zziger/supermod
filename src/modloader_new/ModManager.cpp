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
        Log::Info << "Emitting tick for " << mod->GetInfo()->id << Log::Endl;
        mod->Tick();
    }
}

void modloader::ModManager::LogStates()
{
    Log::Info << "== STATES BEG ==" << Log::Endl;
    for (const auto& mod : mods)
    {
        Log::Info << mod->GetInfo()->id << ": " << mod->IsEnabled() << " " << mod->IsActive() << " " << mod->GetState()->GetLabel() << Log::Endl;
    }
    Log::Info << "== STATES END ==" << Log::Endl;
}

modloader::Mod* modloader::ModManager::FindModByID(std::string id)
{
    // TODO optimize
    for (const auto& mod : mods)
    {
        if (mod->GetInfo()->id == id)
        {
            return mod.get();
        }
    }

    return nullptr;
}

void modloader::ModManager::AddMod(std::unique_ptr<Mod>&& mod)
{
    mods.push_back(std::move(mod));
}

#ifdef UNIT_TESTS
void modloader::ModManager::Reset()
{
    mods.clear();
}
#endif
