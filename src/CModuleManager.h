#pragma once
#include <set>
#include <map>

#include "CConfig.h"
#include "module/IModule.h"

class CModuleManager {
    inline static std::map<std::string, IModule*> _modules = {};
    inline static std::set<std::string> _loadedModules = {};
public:
    
    static void RegisterModules(std::vector<IModule*> vec);
    static bool LoadModule(const std::string& module);
    static bool UnloadModule(std::string module);
    static std::vector<IModule*> GetLoadedModules();
    static void LogModules();

    static void Initialize();
};
