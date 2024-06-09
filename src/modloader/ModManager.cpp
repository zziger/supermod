#include "ModManager.h"

#include <Config.h>
#include <events/D3dInitEvent.h>
#include <events/TickEvent.h>
#include <logs/Console.h>
#include <mod/ModImplInternal.h>
#include <sdk/Game.h>
#include <spdlog/fmt/bundled/color.h>
#include <spdlog/spdlog.h>
#include <ui/NotificationManager.h>

#include "install/ModInstallRequestDiscover.h"
#include "install/ModInstallRequestZip.h"
#include "install/ModInstaller.h"
#include "install/ZipModDropTarget.h"
#include "mod/impl/ModImplLua.h"
#include "mod/impl/TestImpl.h"

void modloader::ModManager::Init()
{
    if (!exists(sdk::Game::GetModsPath()))
        create_directories(sdk::Game::GetModsPath());

    AddInternalMod(ModImplInternal::CreateMod());

    ScanMods(true);
    SaveConfig();
    UpdateRemovedMods();
    Tick();

    EventManager::On<BeforeTickEvent>([] { Tick(); });
}

void modloader::ModManager::ScanMods(const bool init)
{
    const auto modsPath = sdk::Game::GetModsPath();
    if (!exists(modsPath))
    {
        spdlog::warn("Skipped mods scanning: Mods folder does not exist");
        return;
    }

    std::map<std::string, std::shared_ptr<Mod>> foundMods{};
    std::set<std::string> foundIDs{};

    for (const auto& file : std::filesystem::directory_iterator(modsPath))
    {
        if (!file.is_directory() || file.path().filename().string().starts_with("."))
            continue;

        std::shared_ptr<Mod> mod;
        try
        {
            mod = CreateMod(file.path());
        }
        catch (const std::exception& err)
        {
            spdlog::error("Failed to create mod from {}: {}", file.path().string(), err.what());
            ui::NotificationManager::Notify(
                std::format("Не удалось загрузить мод из {}.\n{}", file.path().string(), err.what()));
        }

        auto id = mod->GetID();

        if (foundIDs.contains(id))
        {
            spdlog::warn("Found multiple mods with same ID: {}. Disabling mod at {}", id, file.path().string());
            std::filesystem::rename(file.path(), file.path().parent_path() / ("." + file.path().filename().string()));
            ui::NotificationManager::Notify(std::format("Найдено несколько модов с ID {}. Мод {} был выключен", id,
                                                        file.path().filename().string()),
                                            ui::Notification::WARN);
            continue;
        }

        foundIDs.insert(id);

        if (mods_map.contains(id))
        {
            ReloadMod(mods_map[id]);
            continue;
        }

        foundMods[mod->GetID()] = mod;
    }

    auto& cfg = Config::GetYaml();

    if (init)
    {
        auto modsArr = Clone(cfg["mods"]);
        for (const auto& pair : modsArr)
        {
            const auto key = pair.first.as<std::string>();
            const auto& node = pair.second;
            if (!foundMods.contains(key))
                continue;

            auto mod = foundMods[key];
            mod->Toggle(node["enabled"].as<bool>(false));
            if (node["remove"].as<bool>(false))
            {
                mod->Toggle(false);
                mod->SetFlag(Mod::Flag::REMOVAL_SCHEDULED);
                mod->SetFlag(Mod::Flag::REMOVE_WITH_FILES);
            }

            AddMod(mod);
        }
    }
    else
    {
        for (const auto& mod : mods)
        {
            if (!foundIDs.contains(mod->GetID()))
            {
                ToggleMod(mod, false);
                mod->SetFlag(Mod::Flag::REMOVAL_SCHEDULED);
            }
        }
    }

    for (const auto& [key, mod] : foundMods)
    {
        if (cfg["mods"][key])
            continue;

        AddMod(mod);
        ModInstaller::RequestInstall(std::make_shared<ModInstallRequestDiscover>(mod));
    }

    for (const auto& file : std::filesystem::directory_iterator(modsPath))
    {
        if (file.is_directory())
            continue;
        if (file.path().extension() != ".zip")
            continue;
        ModInstaller::RequestInstall(ModInstallRequestZip::FromZip(file.path(), true));
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

    for (const auto& mod : mods)
    {
        mod->Tick();
    }

    UpdateRemovedMods();
}

std::shared_ptr<modloader::Mod> modloader::ModManager::FindModByID(const std::string& id)
{
    if (!mods_map.contains(id))
        return nullptr;
    return mods_map[id];
}

const std::vector<std::shared_ptr<modloader::Mod>>& modloader::ModManager::GetModDependents(const std::string& id)
{
    static constexpr std::vector<std::shared_ptr<Mod>> empty{};
    if (!dependent_mods.contains(id))
        return empty;
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

std::shared_ptr<modloader::Mod> modloader::ModManager::CreateMod(const std::filesystem::path& modPath)
{
    if (!is_directory(modPath))
        throw Error(std::format("Path {} is not a directory", modPath.string()));

    if (!exists(modPath / ModInfoFilesystem::MANIFEST_FILENAME))
        throw Error(std::format("Failed to find manifest.yml in {}", modPath.string()));

    auto modInfo = std::make_shared<ModInfoFilesystem>();
    modInfo->FromPath(modPath);

    std::unique_ptr<ModImpl> info;
    switch (modInfo->scriptType)
    {
    case ModInfo::ScriptType::LUA:
        info = std::make_unique<ModImplLua>(modInfo);
        break;
    default:
        info = std::make_unique<ModImpl>();
        break;
    }

    return std::make_shared<Mod>(modInfo, std::move(info));
}

void modloader::ModManager::RemoveMods(const std::vector<std::shared_ptr<Mod>>& removalList)
{
    mods.erase(std::ranges::remove_if(mods,
                                      [](const std::shared_ptr<Mod>& mod) {
                                          return !mod->IsActive() && mod->HasFlag(Mod::Flag::REMOVAL_SCHEDULED);
                                      })
                   .begin(),
               mods.end());
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
            if (!info)
                continue;
            try
            {
                remove_all(info->basePath);
            }
            catch (const std::exception& err)
            {
                spdlog::error("Failed to remove {}: {}", info->basePath.string(), err.what());
                ui::NotificationManager::Notify(
                    std::format("Не удалось удалить папку {}.\n{}", info->basePath.string(), err.what()));
            }
        }
    }
}

void modloader::ModManager::ReorderMods(const std::vector<std::shared_ptr<Mod>>& newMods)
{
    assert(newMods.size() == mods.size() && std::ranges::is_permutation(mods, newMods) &&
           "Reordered mods list is different from mods list");

    mods = newMods;

    SaveConfig();
}

void modloader::ModManager::ToggleMod(const std::shared_ptr<Mod>& mod, bool enabled)
{
    const auto state = mod->IsEnabled();
    if (state == enabled)
        return;

    spdlog::info("{} mod {} with dependencies", Console::StyleToggle(enabled ? "Enabling" : "Disabling", enabled),
                 Console::StyleModName(mod->GetID()));

    if (enabled)
    {
        std::function<void(const std::shared_ptr<Mod>&, int)> enable;
        enable = [&](const std::shared_ptr<Mod>& targetMod, int depth = 0) {
            if (depth < 5)
            {
                const auto& info = targetMod->GetInfo();
                for (const auto& innerMod : GetMods())
                    if (!innerMod->IsEnabled() && info->HasDependency(innerMod->GetID()))
                        enable(innerMod, depth + 1);
            }
            targetMod->Toggle(true);
        };
        enable(mod, 0);
    }
    else
    {
        std::function<void(const std::shared_ptr<Mod>&, int)> disable;
        disable = [&](const std::shared_ptr<Mod>& targetMod, int depth = 0) {
            if (depth < 5)
            {
                const auto dependents = GetModDependents(targetMod->GetID());
                for (const auto& innerMod : dependents)
                    if (innerMod->IsEnabled())
                        disable(innerMod, depth + 1);
            }
            targetMod->Toggle(false);
        };
        disable(mod, 0);
    }

    SaveConfig();
}

void modloader::ModManager::ScheduleModRemoval(const std::shared_ptr<Mod>& mod, const bool remove)
{
    if (remove)
        ToggleMod(mod, false);
    mod->SetFlag(Mod::Flag::REMOVAL_SCHEDULED, remove);
    mod->SetFlag(Mod::Flag::REMOVE_WITH_FILES, remove);
    SaveConfig(mod);
}

void modloader::ModManager::ReloadMod(const std::shared_ptr<Mod>& mod)
{
    const auto info = std::dynamic_pointer_cast<ModInfoFilesystem>(mod->GetInfo());
    if (!info)
        return;

    const auto newInfo = std::make_shared<ModInfoFilesystem>();
    newInfo->FromPath(info->basePath);
    mod->SetInfo(newInfo);
    UpdateDeps();
}

void modloader::ModManager::SaveConfig(const std::shared_ptr<Mod>& mod)
{
    if (mod->HasFlag(Mod::Flag::INTERNAL))
        return;

    ValidateConfig();

    auto& cfg = Config::GetYaml();
    const auto id = mod->GetID();

    PopulateConfig(mod, cfg["mods"][id]);
    Config::Get().Save();
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
    } while (IsDirty(DirtyFlag::STATES) && tickCounter < MAX_STATE_UPDATE_TICKS);

    if (tickCounter >= MAX_STATE_UPDATE_TICKS)
        spdlog::warn("Reached mod state update tick limit per script tick. Calculated {} update ticks in 1 script tick",
                     tickCounter);
}

void modloader::ModManager::UpdateDeps()
{
    dependent_mods.clear();

    for (const auto& mod : mods)
    {
        auto id = mod->GetID();
        auto dependents = std::vector<std::shared_ptr<Mod>>();
        std::ranges::copy_if(mods, std::back_inserter(dependents), [&](const std::shared_ptr<Mod>& innerMod) {
            return innerMod->GetInfo()->HasDependency(id);
        });

        dependent_mods[id] = dependents;
    }
}

void modloader::ModManager::UpdateRemovedMods()
{
    std::vector<std::shared_ptr<Mod>> removalList{};
    for (const auto& mod : mods)
    {
        if (!mod->IsActive() && mod->HasFlag(Mod::Flag::REMOVAL_SCHEDULED))
            removalList.push_back(mod);
    }

    if (!removalList.empty())
        RemoveMods(removalList);
}

void modloader::ModManager::AddInternalMod(const std::shared_ptr<Mod>& mod)
{
    internal_mods.push_back(mod);
    mods_map[mod->GetInfo()->GetID()] = mod;
    mod->SetFlag(Mod::Flag::EXISTS);
}

void modloader::ModManager::ValidateConfig()
{
    auto& cfg = Config::GetYaml();

    if (!cfg["mods"].IsMap())
    {
        if (cfg["mods"] && !cfg["mods"].IsNull())
            spdlog::warn("'mods' in modcfg.yml was not a map. Overriding with an empty map instead");
        cfg["mods"] = YAML::Node(YAML::NodeType::Map);
    }

    Config::Get().Save();
}

void modloader::ModManager::SaveConfig()
{
    ValidateConfig();

    auto& cfg = Config::GetYaml();

    auto oldTree = cfg["mods"];
    auto tree = YAML::Node();

    for (const auto& mod : mods)
    {
        const auto id = mod->GetID();

        if (oldTree[id].IsMap())
            tree[id] = oldTree[id];
        PopulateConfig(mod, tree[id]);
    }

    cfg["mods"] = tree;
    Config::Get().Save();
}

void modloader::ModManager::PopulateConfig(const std::shared_ptr<Mod>& mod, YAML::Node&& node)
{
    node["enabled"] = mod->IsEnabled();

    if (mod->HasFlag(Mod::Flag::REMOVAL_SCHEDULED) && mod->HasFlag(Mod::Flag::REMOVE_WITH_FILES))
        node["remove"] = true;
    else
        node.remove("remove");
}

#ifdef UNIT_TESTS
void modloader::ModManager::Reset()
{
    mods.clear();
    mods_map.clear();
}
#endif
