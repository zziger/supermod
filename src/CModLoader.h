#pragma once
#include <filesystem>
#include <string>
#include <vector>

#include "CMemory.h"

class CModLoader {
    std::vector<std::string> _loadedMods;
    static inline constexpr CMemory::Pattern resolveFile_pattern = { "55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 89 45 EC 8B 45 08" };
    static inline void* (* __cdecl resolveFile_orig)(PCSTR lpFileName, SIZE_T *outBuf, char isCritical) = nullptr;
    static void* __cdecl resolveFile_hook(PCSTR lpFileName, SIZE_T *outBuf, char isCritical);
    
public:
    void Initialize();
    
    static CModLoader& Instance()
    {
        static CModLoader instance;
        return instance;
    }

    static std::filesystem::path ResolveFilePath(char* file);
};
