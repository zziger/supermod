#include "CModLoader.h"

#include <filesystem>
#include <fstream>

#include "CGameApis.h"
#include "Log.h"
#include "Utils.h"

void* __cdecl CModLoader::resolveFile_hook(PCSTR lpFileName, SIZE_T *outBuf, char isCritical) {
    const auto curPath = std::filesystem::current_path();
    const auto relPath = relative(curPath, CGameApis::GetDataPath());
    const auto relPathStr = relPath.generic_string();
    bool changed = false;
    
    if (relPathStr.size() < 2 || relPathStr[0] != '.' && relPathStr[1] != '.') {
        for (const auto& loadedMod : Instance()._loadedMods) {
            const auto modPath = CGameApis::GetModsPath() / loadedMod / relPath;
            if (exists(modPath / lpFileName)) {
                Log::Debug << "Loaded mod file " << lpFileName << Log::Endl;
                current_path(modPath);
                changed = true;
                break;
            }
        }
    }
    const auto ptr = resolveFile_orig(lpFileName, outBuf, isCritical);
    if (changed) current_path(curPath);
    return ptr;
}

void CModLoader::Initialize() {
    Log::Debug << "Searching for external mods..." << Log::Endl;
    if (!exists(CGameApis::GetModsPath())) {
        Log::Warn << "Mods folder not found" << Log::Endl;
        return;
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
std::filesystem::path CModLoader::ResolveFilePath(char* file) {
    auto curPath = std::filesystem::current_path();
    const auto relPath = relative(curPath, CGameApis::GetDataPath());
    const auto relPathStr = relPath.generic_string();
    
    if (relPathStr.size() < 2 || relPathStr[0] != '.' && relPathStr[1] != '.') {
        for (const auto& loadedMod : Instance()._loadedMods) {
            const auto modPath = CGameApis::GetModsPath() / loadedMod / relPath;
            if (exists(modPath / file)) {
                return modPath / file;
            }
        }
    }
    return curPath;
}