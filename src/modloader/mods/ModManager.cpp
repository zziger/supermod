#include "modloader/mods/ModManager.h"

#include "DirectXUtils.h"
#include "exceptions/Error.h"
#include "files/ModFileResolver.h"
#include "mod/InternalMod.h"
#include "scripting/LuaMod.h"
#include "sdk/DirectX.h"
#include "sdk/Game.h"
#include <thirdparty/zip_file.h>

std::shared_ptr<Mod> ModManager::GetInternalMod() {
    return _internalMod;
}

void ModManager::CleanupConfig() {
    const Config cfg;
    if (!cfg.data["disabledMods"]) return;
    if (!cfg.data["installedMods"]) {
        cfg.data.remove("disabledMods");
        return;
    }

    auto installed = cfg.data["installedMods"].as<std::vector<std::string>>();
    auto disabled = cfg.data["disabledMods"].as<std::vector<std::string>>();
    auto remove = std::ranges::remove_if(disabled, [&](const std::string& str) {
        return std::ranges::find(installed, str) == installed.end();
    });
    disabled.erase(remove.begin(), remove.end());
    cfg.data["disabledMods"] = disabled;
}

void ModManager::Init() {
    _mods_folder = std::filesystem::current_path() / "mods";

    const auto ptr = std::make_shared<InternalMod>();
    ptr->Enable(false);
    _mods.push_back(ptr);
    _internalMod = ptr;
}

std::filesystem::path ModManager::GetModsRoot() {
    return _mods_folder;
}

void ModManager::LoadMod(ModInfo info, bool manual) {
    const auto modBase = info.basePath;
    create_mod_fn createMod = nullptr;

    if (exists(modBase / dll_file_name)) {
        const auto module = LoadLibraryExA((modBase / dll_file_name).string().c_str(), nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
        if (module == nullptr) {
            throw Error("Не удалось загрузить файл " + (modBase / dll_file_name).string());
        }

        createMod = (create_mod_fn) (void*) GetProcAddress(module, "create_mod");
        info.dll = module;
    }
    info.EnsureIcon();

    const auto mod = createMod
                         ? createMod(info)
                         : info.luaScript == ""
                         ? std::make_shared<Mod>(info)
                         : std::make_shared<LuaMod>(info);

    const auto id = mod->info.id;
    if (std::ranges::find_if(_mods, [id](std::shared_ptr<Mod>& mod) { return mod->info.id == id; }) != _mods.end()) {
        throw Error(std::format("Мод с ID {} уже существует", id));
    }

    if (mod->ShouldBeEnabled()) mod->Enable(manual);

    _mods.push_back(mod);

    if (!createMod && info.luaScript != "") {
        _luaMods.push_back(static_pointer_cast<LuaMod>(mod));
    }
}

void ModManager::LoadMod(const std::string_view modName, bool manual) {
    std::lock_guard lock(_modMutex);

    const std::filesystem::path modBase = _mods_folder / modName;
    if (!exists(modBase / manifest_file_name)) {
        throw Error("Не удалось найти папку " + (modBase / manifest_file_name).generic_string());
    }

    LoadMod(ModInfo(modBase), manual);
}

void ModManager::UnloadMod(std::shared_ptr<Mod> mod) {
    if (mod->IsEnabled()) mod->Disable(true);
    if (mod->info.dll) FreeLibrary(mod->info.dll);
    const auto id = mod->info.id; 
    auto erase = std::ranges::remove_if(_mods, [id](std::shared_ptr<Mod>& iterMod) {
        return iterMod->info.id == id;
    });
    _mods.erase(erase.begin(), erase.end());
    if (const auto luaMod = std::dynamic_pointer_cast<LuaMod>(mod)) {
        _luaMods.remove(luaMod);
    }
}

void ModManager::ReorderMods(std::vector<std::shared_ptr<Mod>> newOrder) {
    if (sdk::Game::currentTickIsInner) return;
    std::lock_guard lock(_modMutex);
    std::vector<std::shared_ptr<Mod>> modsToReload {};

    auto i = 0;
    for (const auto& mod : GetMods()) {
        if (mod->info.internal) continue;
        if (mod->info.id != newOrder[i]->info.id) modsToReload.push_back(newOrder[i]);
        i++;
    }

    _mods.clear();
    _mods.push_back(_internalMod);
    std::vector<std::string> ids {};
    
    for (auto mod : newOrder) {
        if (mod->info.internal) continue;
        _mods.push_back(mod);
        ids.push_back(mod->info.id);
    }

    for (const auto mod : modsToReload) {
        if (mod->info.internal || !mod->IsEnabled()) continue;
        ModFileResolver::ReloadModFiles(mod->info.basePath / "data");
    }

    const Config cfg;
    cfg.data["installedMods"] = ids;
    CleanupConfig();
}

void ModManager::ReloadMods() {
    const auto mods = _mods;
    for (const auto& mod : mods) {
        if (mod->info.internal) continue;
        UnloadMod(mod);
    }
    InitMods(true);
}

void ModManager::InitMods(bool manual) {
    try {
        std::lock_guard lock(_modMutex);

        const Config cfg;
        const auto installed = cfg.data["installedMods"].as<std::vector<std::string>>(std::vector<std::string>{});

        std::map<std::string, ModInfo> existing{};
        const auto firstIt = std::filesystem::directory_iterator(_mods_folder);
        for (auto& file : firstIt) {
            if (!file.is_directory()) continue;
            if (!exists(file.path() / "manifest.yml")) continue;
            const auto modName = file.path().filename().generic_string();

            try {
                auto info = ModInfo(file);
                existing.emplace(info.id, info);
            } catch (std::exception& e) {
                Log::Error << "Ошибка загрузки мода " << modName << ":" << Log::Endl;
                Log::Error << e.what() << Log::Endl;
            } catch (...) {
                Log::Error << "Неизвестная ошибка загрузки мода " << modName << Log::Endl;
            }
        }

        std::set<std::string> installedExisting{};
        std::vector<std::string> installedExistingVec{};
        for (auto mod : installed) {
            if (!existing.contains(mod)) continue;
            installedExisting.emplace(mod);
            installedExistingVec.push_back(mod);

            try {
                LoadMod(existing[mod], manual);
            } catch (std::exception& e) {
                Log::Error << "Ошибка загрузки мода " << mod << ":" << Log::Endl;
                Log::Error << e.what() << Log::Endl;
            } catch (...) {
                Log::Error << "Неизвестная ошибка загрузки мода " << mod << Log::Endl;
            }
        }

        for (auto modPair : existing) {
            if (installedExisting.contains(modPair.first)) continue;
            _modsToInstall.push_back(modPair.second);
        }

        cfg.data["installedMods"] = installedExistingVec;
        CleanupConfig();
    } catch (std::exception& e) {
        Log::Error << "Ошибка загрузки модов:" << Log::Endl;
        Log::Error << e.what() << Log::Endl;
    } catch (...) {
        Log::Error << "Неизвестная ошибка загрузки модов" << Log::Endl;
    }
}

void ModManager::DeleteMod(std::shared_ptr<Mod> mod) {
    if (sdk::Game::currentTickIsInner) return;
    std::lock_guard lock(_modMutex);

    UnloadMod(mod);
    remove_all(mod->info.basePath);
    mod->info.ReleaseIcon();

    const Config cfg;
    auto installed = cfg.data["installedMods"].as<std::vector<std::string>>();
    auto remove = std::ranges::remove(installed, mod->info.id);
    installed.erase(remove.begin(), remove.end());
    cfg.data["installedMods"] = installed;
    CleanupConfig();
}

std::list<ModInfo>& ModManager::GetModsToInstall() {
    std::lock_guard lock(_modMutex);

    return _modsToInstall;
}

void ModManager::RequestModInstall(ModInfo mod) {
    std::lock_guard lock(_modMutex);

    installError = std::nullopt;
    _modsToInstall.push_back(mod);
}

void ModManager::InstallMod(ModInfo mod, bool state) {
    installError = std::nullopt;
    try {
        const auto inModsFolder = mod.basePath.parent_path() == sdk::Game::GetModsPath();

        if ((inModsFolder || state) && std::ranges::find_if(_mods, [&mod](const std::shared_ptr<Mod>& m) {
            return m->info.id == mod.id;
        }) != _mods.end()) {
            throw Error("Мод с ID " + mod.id + " уже существует");
        }
        
        auto removeIter = std::ranges::remove_if(_modsToInstall, [&mod](const ModInfo& m) {
            return m.id == mod.id;
        });
        _modsToInstall.erase(removeIter.begin(), removeIter.end());
    
        const Config cfg;
    
        if (inModsFolder) {
            if (!state) cfg.data["disabledMods"].push_back(mod.id);
            cfg.data["installedMods"].push_back(mod.id);
            LoadMod(mod, true);
        } else {
            if (!state) return;
            const auto modsPath = sdk::Game::GetModsPath();
            auto folderName = mod.id;
            auto i = 1;
            while (exists(modsPath / folderName)) folderName = mod.id + std::to_string(i++);
            create_directory(modsPath / folderName);
            if (!mod.zipFile) {
                copy(mod.basePath, modsPath / folderName, std::filesystem::copy_options::recursive);
            } else {
                miniz_cpp::zip_file zip {mod.zipFile->string()};
                zip.extractall((modsPath / folderName).string());
            }
            
            cfg.data["installedMods"].push_back(mod.id);
            LoadMod(mod.id, true);
        }
    } catch(std::exception& e) {
        Log::Error << "Ошибка установки мода " << mod.id << ": " << e.what() << Log::Endl;
        installError = e.what();
    }
}

std::list<std::shared_ptr<Mod>> ModManager::GetMods() {
    std::lock_guard lock(_modMutex);

    return _mods;
}

std::list<std::shared_ptr<LuaMod>> ModManager::GetLuaMods() {
    std::lock_guard lock(_modMutex);

    return _luaMods;
}