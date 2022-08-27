#include "CModLoader.h"

#include <filesystem>
#include <fstream>

#include "CGameApis.h"
#include "Log.h"
#include "Utils.h"
void* __cdecl CModLoader::resolveFile_hook(PCSTR lpFileName, SIZE_T *outBuf, char isCritical) {
    const auto fullPath = std::filesystem::current_path() / lpFileName;
    const auto relPath = relative(fullPath, CGameApis::GetDataPath());
    const auto relPathStr = relPath.generic_string();
    auto modPathStr = std::string(lpFileName);
            
    if (relPathStr.size() < 2 || relPathStr[0] != '.' && relPathStr[1] != '.') {
        for (const auto& loadedMod : Instance()._loadedMods) {
            const auto modPath = CGameApis::GetModsPath() / loadedMod / relPath;
            if (exists(modPath)) {
                modPathStr = relative(modPath, std::filesystem::current_path()).generic_string();
                Log::Debug << "Loaded mod file " << relPathStr << Log::Endl;   
            }
        }
    }
    
    return resolveFile_orig(modPathStr.c_str(), outBuf, isCritical);  
}

void CModLoader::Initialize() {
    Log::Debug << "Searching for external mods..." << Log::Endl;
    if (!exists(CGameApis::GetModsPath())) {
        Log::Warn << "Mods folder not found" << Log::Endl;
        return
    }
    for (const auto& entry : std::filesystem::directory_iterator(CGameApis::GetModsPath())) {
        if (!entry.is_directory()) continue;
        auto name = entry.path().filename().generic_string();
        _loadedMods.push_back(name);
        Log::Debug << "Found external mod " << name << Log::Endl;
    }

    auto resolveFile_mem = resolveFile_pattern.Search();
    resolveFile_mem.Detour(resolveFile_hook, &resolveFile_orig);
}