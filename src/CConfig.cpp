#include "CConfig.h"

#include <filesystem>
#include <iostream>

using namespace nlohmann;

void CConfig::Initialize(std::filesystem::path cwd) {
    cfgPath = (cwd / std::string("modcfg.json")).string();
    std::ifstream fstream(cfgPath);
    
    if (fstream.good()) {
        cfg = json::parse(fstream);
        fstream.close();
        return;
    }
    
    fstream.close();
        
    cfg = json::parse("{}");
    EnsureModuleArr();
}

void CConfig::EnsureModuleArr() {
    if (!cfg.contains("modules")) cfg["modules"] = { "WIDESCREEN_FIX", "ALLOW_MULTIPLE_INSTANCES", "RENDER_UNFOCUSED" };
}

void CConfig::Save() const {
    std::ofstream fstream(cfgPath);
    fstream << cfg.dump();
    fstream.close();
}


std::vector<std::string> CConfig::GetModules() {
    EnsureModuleArr();
    return cfg["modules"].get<std::vector<std::string>>();
}

void CConfig::AddModule(const std::string& name) {
    if (std::find(cfg["modules"].begin(), cfg["modules"].end(), name) == cfg["modules"].end())
        cfg["modules"].push_back(name);
    Save();
}

void CConfig::RemoveModule(const std::string& name) {
    auto v = cfg["modules"].get<std::vector<std::string>>();
    const auto itr = std::find(v.begin(), v.end(), name);
    if (itr != v.end()) v.erase(itr);
    cfg["modules"] = v;
    Save();
}