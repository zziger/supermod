#include "CModuleManager.h"

#include "Log.h"

void CModuleManager::RegisterModules(std::vector<IModule*> vec) {
    for (auto& module : vec) {
        _modules[module->GetName()] = module;
    } 
}

bool CModuleManager::LoadModule(const std::string& module) {
    if (_loadedModules.count(module)) return true;
    if (!_modules.count(module)) return false;
    _modules[module]->Load();
    _loadedModules.insert(module);
    CConfig::Instance().AddModule(module);
    return true;
}

auto CModuleManager::UnloadModule(const std::string module) -> bool {
    if (!_loadedModules.count(module)) return false;
    if (!_modules.count(module)) return false;
    _modules[module]->Unload();
    _loadedModules.erase(module);
    CConfig::Instance().RemoveModule(module);
    return true;
}

std::vector<IModule*> CModuleManager::GetLoadedModules() {
    std::vector<IModule*> vec;
    for (const auto& loadedModule : _loadedModules) vec.push_back(_modules[loadedModule]);
    return vec;
}

void CModuleManager::LogModules() {
    Log::Info << "Available modules:" << Log::Endl;
    for (auto [ key, module ] : _modules) {
        const auto loaded = _loadedModules.count(module->GetName());
        Log::Instance() << Log::Color::GRAY << "- " << (loaded ? Log::Color::LIGHT_GREEN : Log::Color::LIGHT_RED) << module->GetName() << Log::Endl;
        module->LogDescription(loaded);
    }
}

void CModuleManager::Initialize() {
    for (const auto& module : CConfig::Instance().GetModules()) {
        _modules[module]->Load();
        _loadedModules.insert(module);
    }
}