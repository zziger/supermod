#pragma once
#include <fstream>

#include "json.hpp"

class CConfig {
    CConfig() {};
    
    void EnsureModuleArr();
    std::string cfgPath;

public:
    void Initialize(std::filesystem::path path);
    
    nlohmann::json cfg;

    std::vector<std::string> GetModules();
    void AddModule(const std::string& name);
    void RemoveModule(const std::string& name);
    void Save() const;

    static CConfig& Instance()
    {
        static CConfig instance;
        return instance;
    }
};
