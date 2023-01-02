#include "ModFileResolver.h"

#include <regex>

#include "DirectXUtils.h"
#include "../ModManager.h"
#include "events/EventManager.h"
#include "events/ResolveFileEvent.h"
#include "events/TickEvent.h"
#include "game/AssetPool.h"
#include "sdk/DirectX.h"

std::optional<std::filesystem::path> ModFileResolver::ResolveFile(const std::filesystem::path& path) {
    for (const auto& mod : ModManager::GetLoadedMods()) {
        const auto resolvedPath = ResolveModFile(mod, path);
        if (!resolvedPath) continue;

        auto rel = relative(*resolvedPath, sdk::Game::GetDataPath() / "..");
        resolvedFilePaths.emplace(rel.wstring());
        Log::Debug << "Resolved file " << *resolvedPath << Log::Endl;
        return *resolvedPath;
    }

    return std::nullopt;
}

std::optional<std::filesystem::path> ModFileResolver::ResolveModFile(const std::shared_ptr<Mod>& mod, const std::filesystem::path& path) {
    if (!mod || mod->info.internal || !mod->IsLoaded()) return std::nullopt;
    
    const auto filePath = relative(path, sdk::Game::GetDataPath());

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
    EventManager::On<AfterTickEvent>([]() {
        std::lock_guard lock(_reloadMutex);
        for (auto toReload : filesToReload) {
            LoadFile(sdk::Game::GetDataPath() / ".." / toReload);
        }
        filesToReload.clear();
    });
    ToggleFileListener(true);
    _initialized = true;
}

void ModFileResolver::ToggleFileListener(bool state) {
    if (listenerEnabled == state) return;
    if (!state) {
        listenerEnabled = false;
        return;
    }
    
    listenerEnabled = true;
    CreateThread(nullptr, 0, [](LPVOID _) -> DWORD {
        FileListenerThread();
        return 0;
    }, nullptr, 0, nullptr);
}

std::string ModFileResolver::GetPoolFileName(const std::string& filename) {
    return std::regex_replace(filename, std::regex("^_a_(.*?)\\.jpg$"), "$1.tga");
}

void ModFileResolver::LoadFile(const std::filesystem::path filepath) {
    auto extension = filepath.extension().generic_string();
    std::ranges::transform(extension, extension.begin(), tolower);

    Log::Info << "Loading " << filepath << Log::Endl;
    if (extension == ".jpg" || extension == ".png" || extension == ".tga") LoadTexture(filepath);
    else Log::Warn << "Loading of " << extension << " files is not supported" << Log::Endl;
}
