#include "ModFileResolver.h"

#include "ModManager.h"
#include "events/EventManager.h"
#include "events/ResolveFileEvent.h"

std::optional<std::filesystem::path> ModFileResolver::ResolveFile(const std::filesystem::path& path) {
    for (const auto& mod : ModManager::GetLoadedMods()) {
        const auto resolvedPath = ResolveModFile(mod, path);
        if (!resolvedPath) continue;

        return *resolvedPath;
    }

    return std::nullopt;
}

std::optional<std::filesystem::path> ModFileResolver::ResolveModFile(const std::shared_ptr<Mod>& mod, const std::filesystem::path& path) {
    if (!mod || mod->info.internal || !mod->IsLoaded()) return std::nullopt;
    
    const auto filePath = relative(path, CGameApis::GetDataPath());

    const auto modFilePath = mod->info.basePath / "data" / filePath;
        
    if (exists(modFilePath)) return modFilePath;
    return std::nullopt;
}

void ModFileResolver::Init() {
    if (_initialized) return;
    EventManager::On<ResolveFileEvent>([](auto& evt) {
        auto path = ResolveFile(evt.absolutePath);
        if (path) evt.SetResolvedPath(*path);
    });
    _initialized = true;
}

