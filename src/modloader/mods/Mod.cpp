#include "modloader/mods/Mod.h"

#include "Config.h"
#include "events/ModEvent.h"
#include "exceptions/Error.h"
#include "modloader/mods/files/ModFileResolver.h"
#include "sdk/Game.h"

std::shared_ptr<Module> Mod::AddModule(std::shared_ptr<Module> module) {
    modules += module;
    return module;
}

std::shared_ptr<Module> Mod::RemoveModule(std::shared_ptr<Module> module) {
    modules -= module;
    return module;
}

void Mod::OnEnable() {}

void Mod::OnDisable() {}

Mod::Mod(ModInfo info): modules(info), incompatibleSdk(info.sdkVersion > sdk::Game::GetSdkVersion()), info(std::move(info)) {
}

void Mod::RenderUI() {}
void Mod::Render() {}

static const char* config_key = "disabledMods";

void Mod::Enable(bool manual) {
    if (sdk::Game::currentTickIsInner) return;
    if (_enabled) return;
    try {
        if (incompatibleSdk) throw Error("Неподдерживаемая версия SuperMod");
        OnEnable();
        modules.LoadNeeded();
        _enabled = true;
        if (manual && !info.internal) ModFileResolver::ReloadModFiles(info.basePath / "data");
        EventManager::Emit(ModLoadEvent(info));
        Log::Info << "Мод " << info.title << " загружен" << Log::Endl;
        const Config cfg;
        const auto& node = cfg.data[config_key];
        if (manual && node.IsSequence()) {
            std::vector<std::string> newList = {};
            for (const auto& value : node) {
                const auto& id = value.as<std::string>("");
                if (id != info.id) newList.push_back(id);
            }
            cfg.data[config_key] = newList;
        }
    } catch(std::exception& e) {
        Log::Error << "Ошибка загрузки мода " << info.id << ":" << Log::Endl;
        Log::Error << e.what() << Log::Endl;
        loadingError = std::format("Ошибка загрузки: {}", e.what());
    }
}

void Mod::Disable(bool manual) {
    if (sdk::Game::currentTickIsInner) return;
    if (!_enabled) return;
    _enabled = false;
    try {
        if (manual) {
            const Config cfg;
            if (!cfg.data[config_key].IsSequence()) cfg.data[config_key] = YAML::Node(YAML::NodeType::Sequence);
            cfg.data[config_key].push_back(info.id);
        }
        UnloadEvents();
        UnloadHooks();
        OnDisable();
        modules.Unload();
        if (manual && !info.internal) ModFileResolver::ReloadModFiles(info.basePath / "data");
        EventManager::Emit(ModUnloadEvent(info));
        Log::Info << "Мод " << info.title << " выгружен" << Log::Endl;
    } catch(std::exception& e) {
        Log::Error << "Ошибка выгрузки мода " << info.id << ":" << Log::Endl;
        Log::Error << e.what() << Log::Endl;
        loadingError = std::format("Ошибка выгрузки: {}", e.what());
    }
}

void Mod::Reload() {
    if (sdk::Game::currentTickIsInner || !_enabled || info.internal) return;
    try {
        UnloadEvents();
        UnloadHooks();
        OnDisable();
        modules.Unload();
        EventManager::Emit(ModUnloadEvent(info));
        OnEnable();
        modules.LoadNeeded();
        ModFileResolver::ReloadModFiles(info.basePath / "data");
        EventManager::Emit(ModLoadEvent(info));
        Log::Info << "Мод " << info.title << " перезагружен" << Log::Endl;
    } catch(std::exception& e) {
        Log::Error << "Ошибка перезагрузки мода " << info.id << ":" << Log::Endl;
        Log::Error << e.what() << Log::Endl;
        loadingError = std::format("Ошибка перезагрузки: {}", e.what());
    }
}
void Mod::UnloadModule() {
    if (!info.dll) return;
    if (!FreeLibrary(info.dll)) MessageBoxA(nullptr, "Не удалось выгрузить модуль", "SuperMod", MB_OK);
    info.dll = nullptr;
}


bool Mod::IsEnabled() const {
    return _enabled;
}

bool Mod::ShouldBeEnabled() const {
    if (incompatibleSdk) return false;
    
    const auto& node = Config::Get()[config_key];
    if (node.IsSequence()) {
        for (auto mod : node) {
            if (mod.as<std::string>("") == info.id) return false;
        }
    }

    return true;
}
