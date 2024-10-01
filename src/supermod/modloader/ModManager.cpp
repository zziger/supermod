#include "install/provider/ModSourceProviderZip.hpp"

#include <supermod/modloader/ModManager.hpp>
#include <supermod/pch.hpp>

#include <supermod/Config.hpp>
#include <supermod/builtin/ModImplBuiltin.hpp>
#include <supermod/events/DxInitEvent.hpp>
#include <supermod/events/TickEvent.hpp>
#include <supermod/exceptions/Error.hpp>
#include <supermod/game/Game.hpp>
#include <supermod/io/logs/Console.hpp>
#include <supermod/modloader/mod/impl/ModImpl.hpp>
#include <supermod/modloader/mod/impl/ModImplLua.hpp>
#include <supermod/modloader/mod/info/ModInfo.hpp>
#include <supermod/modloader/mod/info/ModInfoFilesystem.hpp>
#include <supermod/ui/NotificationManager.hpp>

namespace sm::modloader
{
void ModManager::Init()
{
    if (!exists(game::Game::GetModsPath()))
        create_directories(game::Game::GetModsPath());

    AddInternalMod(builtin::ModImplBuiltin::CreateMod());

    ScanMods(true);
    SaveConfig();
    UpdateRemovedMods();
    Tick();

    EventManager::On<BeforeTickEvent>([] { Tick(); });
}

void ModManager::ScanMods(const bool init)
{
    const auto modsPath = game::Game::GetModsPath();
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
            continue;
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
        mod->Toggle(true);
    }

    for (const auto& file : std::filesystem::directory_iterator(modsPath))
    {
        if (file.is_directory())
            continue;
        if (file.path().extension() != ".zip" && file.path().extension() != ".sprm")
            continue;

        EventManager::On<DxInitEvent>([=] {
            auto zip = std::make_shared<io::OwnedZip>(file.path().string(), true);
            ModInstaller::AddProvider(
                std::make_shared<ModSourceProviderZip>(file.path().filename().string(), std::move(zip)));
        });
    }
}

void ModManager::Tick()
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

std::shared_ptr<Mod> ModManager::FindModByID(const std::string& id)
{
    if (!mods_map.contains(id))
        return nullptr;
    return mods_map[id];
}

const std::vector<std::shared_ptr<Mod>>& ModManager::GetModDependents(const std::string& id)
{
    static constexpr std::vector<std::shared_ptr<Mod>> empty{};
    if (!dependent_mods.contains(id))
        return empty;
    return dependent_mods[id];
}

void ModManager::AddMod(const std::shared_ptr<Mod>& mod)
{
    mods.push_back(mod);
    mods_map[mod->GetInfo()->GetID()] = mod;
    mod->SetFlag(Mod::Flag::EXISTS);
    UpdateDeps();
    SaveConfig();
}

std::shared_ptr<Mod> ModManager::CreateMod(const std::filesystem::path& modPath)
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

void ModManager::RemoveMods(const std::vector<std::shared_ptr<Mod>>& removalList)
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
                std::error_code err;
                std::filesystem::remove_all(info->basePath, err);

                if (err)
                {
                    spdlog::error("Failed to remove {}: FS error {}", info->basePath.string(), err.message());
                    switch (err.value())
                    {
                    case 32:
                        ui::NotificationManager::Notify(
                            std::format("Не удалось удалить папку мода {}, она занята другим процессом. Убедитесь, что "
                                        "файлы мода не открыты в какой-либо другой программе",
                                        info->title));
                        break;
                    default:
                        ui::NotificationManager::Notify(std::format(
                            "Не удалось удалить папку мода {}. Детали ошибки отправлены в консоль", info->title));
                        break;
                    }
                }
            }
            catch (const std::exception& err)
            {
                spdlog::error("Failed to remove {}: {}", info->basePath.string(), err.what());
                ui::NotificationManager::Notify(
                    std::format("Не удалось удалить папку мода {}. Детали ошибки отправлены в консоль", info->title));
            }
        }
    }

    ScanMods();
}

void ModManager::ReorderMods(const std::vector<std::shared_ptr<Mod>>& newMods)
{
    assert(newMods.size() == mods.size() && std::ranges::is_permutation(mods, newMods) &&
           "Reordered mods list is different from mods list");

    mods = newMods;

    SaveConfig();
}

void ModManager::ToggleMod(const std::shared_ptr<Mod>& mod, bool enabled)
{
    const auto state = mod->IsEnabled();
    if (state == enabled)
        return;

    spdlog::info("{} mod {} with dependencies", io::Console::StyleToggle(enabled ? "Enabling" : "Disabling", enabled),
                 io::Console::StyleModName(mod->GetID()));

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

void ModManager::ScheduleModRemoval(const std::shared_ptr<Mod>& mod, const bool remove)
{
    if (remove)
        ToggleMod(mod, false);
    mod->SetFlag(Mod::Flag::REMOVAL_SCHEDULED, remove);
    mod->SetFlag(Mod::Flag::REMOVE_WITH_FILES, remove);
    SaveConfig(mod);
}

void ModManager::ReloadMod(const std::shared_ptr<Mod>& mod)
{
    const auto info = std::dynamic_pointer_cast<ModInfoFilesystem>(mod->GetInfo());
    if (!info)
        return;

    const auto newInfo = std::make_shared<ModInfoFilesystem>();
    newInfo->FromPath(info->basePath);
    mod->SetInfo(newInfo);
    UpdateDeps();
}

void ModManager::SaveConfig(const std::shared_ptr<Mod>& mod)
{
    if (mod->HasFlag(Mod::Flag::INTERNAL))
        return;

    ValidateConfig();

    auto& cfg = Config::GetYaml();
    const auto id = mod->GetID();

    PopulateConfig(mod, cfg["mods"][id]);
    Config::Get().Save();
}

std::optional<std::filesystem::path> ModManager::ExportModDialog(const std::shared_ptr<ModInfoFilesystem>& modInfo)
{
    const auto currPath = std::filesystem::current_path();

    OPENFILENAMEA file;
    char szFileName[MAX_PATH] = "";
    modInfo->GetID().copy(szFileName, MAX_PATH);

    ZeroMemory(&file, sizeof(file));

    file.lStructSize = sizeof(file);
    file.hwndOwner = *game::Game::window;
    file.lpstrFilter = "SuperMod Package (*.sprm)\0*.sprm\0ZIP Package (*.zip)\0*.zip\0";
    file.lpstrFile = szFileName;
    file.nMaxFile = MAX_PATH;
    file.lpstrDefExt = "sprm";
    file.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;

    if (GetSaveFileNameA(&file))
    {
        current_path(currPath);
        return szFileName;
    }

    current_path(currPath);
    return std::nullopt;
}

async::task<bool> ModManager::PackMod(const std::shared_ptr<ModInfoFilesystem> mod, // NOLINT(*-unnecessary-value-param)
                                      const std::filesystem::path targetPath)       // NOLINT(*-unnecessary-value-param)
{
    co_await io::Async::ToBackground();
    try
    {
        miniz_cpp::zip_file zip;

        for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(mod->basePath))
        {
            const auto& absPath = dirEntry.path();
            auto relPath = relative(absPath, mod->basePath);
            auto relPathStr = relPath.generic_string();
            if (dirEntry.is_directory())
                relPathStr.append("/");
            if (relPathStr == ModInfoFilesystem::MANIFEST_FILENAME)
            {
                auto node = YAML::LoadFile(absPath.string());
                mod->Fixup(node);
                std::stringstream ss;
                ss << node;
                zip.writestr(relPathStr, ss.str());
            }
            else
            {
                zip.write(absPath.string(), relPathStr);
            }
        }

        std::ofstream stream(targetPath, std::ios::binary | std::ios::trunc);
        stream.exceptions(std::ofstream::badbit | std::ofstream::failbit);

        zip.save(stream);
        stream.flush();
    }
    catch (std::exception& e)
    {
        ui::NotificationManager::Notify(std::string("Не удалось упаковать мод: ") + e.what());
        co_return false;
    }

    co_return true;
}

void ModManager::UpdateStates()
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

void ModManager::UpdateDeps()
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

void ModManager::UpdateRemovedMods()
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

void ModManager::AddInternalMod(const std::shared_ptr<Mod>& mod)
{
    internal_mods.push_back(mod);
    mods_map[mod->GetInfo()->GetID()] = mod;
    mod->SetFlag(Mod::Flag::EXISTS);
}

void ModManager::ValidateConfig()
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

void ModManager::SaveConfig()
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

void ModManager::PopulateConfig(const std::shared_ptr<Mod>& mod, YAML::Node&& node)
{
    node["enabled"] = mod->IsEnabled();

    if (mod->HasFlag(Mod::Flag::REMOVAL_SCHEDULED) && mod->HasFlag(Mod::Flag::REMOVE_WITH_FILES))
        node["remove"] = true;
    else
        node.remove("remove");
}

#ifdef UNIT_TESTS
void ModManager::Reset()
{
    mods.clear();
    mods_map.clear();
}
#endif
} // namespace sm::modloader