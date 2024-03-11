#include "ModManager.h"

#include <Config.h>
#include <Log.h>
#include <mod/InternalMod.h>
#include <sdk/Game.h>

#include "mod/impl/TestImpl.h"

void modloader::ModManager::Init()
{
    AddInternalMod(ModImplInternal::CreateMod());

    ScanMods();
    SaveConfig();

    EventManager::On<BeforeTickEvent>([]
    {
       Tick();
    });
}

void modloader::ModManager::ScanMods()
{
    const auto modsPath = sdk::Game::GetRootPath() / MODS_DIRECTORY;

    std::map<std::string, std::shared_ptr<Mod>> foundMods {};

    for (const auto& file : std::filesystem::directory_iterator(modsPath))
    {
        if (!file.is_directory()) continue; // TODO maybe zipmod support?
        if (!exists(file.path() / ModInfoFilesystem::MANIFEST_FILENAME)) continue;

        auto modInfo = std::make_shared<ModInfoFilesystem>();
        modInfo->FromPath(file.path());

        auto info = std::make_unique<TestImpl>(modInfo);
        const auto mod = std::make_shared<Mod>(modInfo, std::move(info));
        foundMods[mod->GetID()] = mod;
    }

    const Config cfg;

    for (const auto& pair : cfg.data["mods"])
    {
        const auto key = pair.first.as<std::string>();
        const auto& node = pair.second;
        if (!foundMods.contains(key)) continue;

        auto mod = foundMods[key];
        mod->Toggle(node["enabled"].as<bool>(false));
        AddMod(mod);
    }
}

void modloader::ModManager::Tick()
{
    UpdateStates();

    if (IsDirty(DirtyFlag::DEPS))
    {
        UpdateDeps();
        ClearDirty(DirtyFlag::DEPS);
    }

    std::vector<std::shared_ptr<Mod>> removalList {};

    for (const auto& mod : mods)
    {
        mod->Tick();
        if (!mod->IsActive() && mod->HasFlag(Mod::Flag::REMOVAL_SCHEDULED)) removalList.push_back(mod);
    }

    if (!removalList.empty())
    {
        RemoveMods(removalList);
    }
}

std::shared_ptr<modloader::Mod> modloader::ModManager::FindModByID(const std::string& id)
{
    if (!mods_map.contains(id)) return nullptr;
    return mods_map[id];
}

const std::vector<std::shared_ptr<modloader::Mod>>& modloader::ModManager::GetModDependents(const std::string& id)
{
    if (!dependent_mods.contains(id)) return std::vector<std::shared_ptr<Mod>>{};
    return dependent_mods[id];
}

void modloader::ModManager::AddMod(const std::shared_ptr<Mod>& mod)
{
    mods.push_back(mod);
    mods_map[mod->GetInfo()->GetID()] = mod;
    mod->SetFlag(Mod::Flag::EXISTS);
    UpdateDeps();
    SaveConfig();
}

void modloader::ModManager::RemoveMods(const std::vector<std::shared_ptr<Mod>>& removalList)
{
    mods.erase(
        std::ranges::remove_if(mods, [](const std::shared_ptr<Mod>& mod)
        {
            return !mod->IsActive() && mod->HasFlag(Mod::Flag::REMOVAL_SCHEDULED);
        }).begin(),
        mods.end()
    );
    for (const auto& mod : removalList)
        mods_map.erase(mod->GetInfo()->GetID());

    UpdateDeps();
    SaveConfig();

    for (const auto& mod : removalList)
    {
        mod->ClearFlag(Mod::Flag::EXISTS);

        if (mod->HasFlag(Mod::Flag::REMOVE_WITH_FILES))
        {
            const auto info = std::dynamic_pointer_cast<ModInfoFilesystem>(mod->GetInfo());
            if (!info) continue;
            Log::Info << "Should delete file " << info->basePath << Log::Endl;
            // TODO: delete from filesystem
        }
    }
}

void modloader::ModManager::ReorderMods(const std::vector<std::shared_ptr<Mod>>& newMods)
{
    assert(newMods.size() == mods.size() && std::ranges::is_permutation(mods, newMods) && "Reordered mods list is different from mods list");

    mods = newMods;

    SaveConfig();
}

void modloader::ModManager::SaveConfig(const std::shared_ptr<Mod>& mod)
{
    if (mod->HasFlag(Mod::Flag::INTERNAL)) return;

    ValidateConfig();

    const Config cfg;

    const auto id = mod->GetID();

    cfg.data["mods"][id]["enabled"] = mod->IsEnabled();
}

void modloader::ModManager::UpdateStates()
{
    uint8_t tickCounter = 0;
    do
    {
        ClearDirty(DirtyFlag::STATES);
        for (const auto& mod : mods)
        {
            mod->Update();
        }
        tickCounter++;
    } while(IsDirty(DirtyFlag::STATES) && tickCounter < MAX_STATE_UPDATE_TICKS);

    if (tickCounter >= MAX_STATE_UPDATE_TICKS)
        Log::Warn << "Reached mod state update tick limit per script tick. Calculated "
                  << static_cast<int>(tickCounter) << " update ticks in 1 script tick" << Log::Endl;
}

void modloader::ModManager::UpdateDeps()
{
    dependent_mods.clear();

    for (const auto& mod : mods)
    {
        auto id = mod->GetID();
        auto dependents = std::vector<std::shared_ptr<Mod>>();
        std::ranges::copy_if(mods, std::back_inserter(dependents), [&](const std::shared_ptr<Mod>& innerMod)
        {
            return innerMod->GetInfo()->deps.contains(id);
        });

        dependent_mods[id] = dependents;
    }
}

void modloader::ModManager::AddInternalMod(const std::shared_ptr<Mod>& mod)
{
    internal_mods.push_back(mod);
    mods_map[mod->GetInfo()->GetID()] = mod;
    mod->SetFlag(Mod::Flag::EXISTS);
}

void modloader::ModManager::ValidateConfig()
{
    const Config cfg;

    if (!cfg.data["mods"].IsMap())
    {
        if (cfg.data["mods"]) Log::Warn << "'mods' in modcfg.yml was not a map. Overriding with an empty map instead" << Log::Endl;
        cfg.data["mods"] = YAML::Node(YAML::NodeType::Map);
    }
}

void modloader::ModManager::SaveConfig()
{
    ValidateConfig();

    const Config cfg;

    auto oldTree = cfg.data["mods"];
    auto tree = YAML::Node();

    for (const auto& mod : mods)
    {
        const auto id = mod->GetID();

        if (oldTree[id].IsMap()) tree[id] = oldTree[id];
        tree[id]["enabled"] = mod->IsEnabled();
    }

    cfg.data["mods"] = tree;
}

#ifdef UNIT_TESTS
void modloader::ModManager::Reset()
{
    mods.clear();
    mods_map.clear();
}
#endif
