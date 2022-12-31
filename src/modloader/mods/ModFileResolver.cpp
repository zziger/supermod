#include "ModFileResolver.h"

#include <regex>

#include "ModManager.h"
#include "events/EventManager.h"
#include "events/ResolveFileEvent.h"
#include "events/TickEvent.h"
#include "game/AssetPool.h"

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

void ReloadTexture(std::filesystem::path texturePath) {
    auto cwd = std::filesystem::current_path();

    Log::Debug << "Reloading texture " << texturePath << Log::Endl;
        
    auto filename = std::regex_replace(texturePath.filename().generic_string(), std::regex("^_a_(.*?)\\.jpg$"), "$1.tga");
    Log::Debug << "Filename was " << filename << Log::Endl;

    auto pool = game::AssetPool::GetInstance();
    game::Asset* asset = pool->GetByName(texturePath.filename().generic_string());
    if (!asset) {
        Log::Debug << "Texture not found bruh" << Log::Endl;
        return;
    }

    asset->Anonymize();
    Log::Debug << "IsTGA" << (bool) asset->isTga << Log::Endl;
    current_path(texturePath.parent_path());
    game::Asset* newAsset;
    
    // if ((bool) asset->isTga) {
    static constexpr Memory::Pattern loadTex("55 8B EC 51 89 4D ? 6A ? 6A ? 6A");
    static auto mem = loadTex.Search();
    newAsset = mem.Get<game::Asset* (__thiscall *)(game::AssetPool*, const char*)>()(pool, filename.c_str());
    // } else {
    //     static constexpr Memory::Pattern loadTex("55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 89 45 ? 89 8D ? ? ? ? C7 45");
    //     static auto mem = loadTex.Search();
    //     Log::Debug << "Before call" << Log::Endl;
    //     newAsset = mem.Get<game::Asset* (__thiscall *)(game::AssetPool*, const char*, char a3)>()(pool, filename.c_str(), 1);
    //     Log::Debug << filename << " After call " << std::hex << (int) newAsset << Log::Endl;
    // }
    current_path(cwd);
    asset->texture->Release();
    memcpy(asset, newAsset, sizeof(game::Asset));
    memset(newAsset, 0, sizeof(game::Asset));
    pool->assetCount--;
    
    Log::Debug << std::hex << (int) asset->texture << " " << std::hex << (int) newAsset->texture << Log::Endl;

    Log::Debug << pool->assetCount << Log::Endl;
    // for (auto i = 0; i < pool->assetCount; i++) {
    //     Log::Debug << pool->assets[i]->name << Log::Endl;
    // }
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
            ReloadTexture(sdk::Game::GetDataPath() / ".." / toReload);
        }
        filesToReload.clear();
    });
    CreateThread(nullptr, 0, [](LPVOID _) -> DWORD {
        FileListenerThread();
        return 0;
    }, nullptr, 0, nullptr);
    _initialized = true;
}

void ModFileResolver::FileListenerThread() {
    Log::Debug << "Listening at " << std::filesystem::current_path().generic_string().c_str() << Log::Endl;
    HANDLE hDir = CreateFileA(
        std::filesystem::current_path().generic_string().c_str(),
        FILE_LIST_DIRECTORY,
        FILE_SHARE_WRITE | FILE_SHARE_READ | FILE_SHARE_DELETE,
        NULL, 
        OPEN_EXISTING, 
        FILE_FLAG_BACKUP_SEMANTICS, 
        NULL);

    int nCounter = 0;
    byte buf[1024];
    DWORD dwBytesReturned = 0;   

    while(TRUE)
    {
        if(
            ReadDirectoryChangesW(
                hDir,
                &buf,
                sizeof buf,
                true,
                FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_FILE_NAME,
                &dwBytesReturned,
                NULL,
                NULL
            )
        )
        {
            BYTE* ptr = buf;
            while(true) {
                FILE_NOTIFY_INFORMATION* info = reinterpret_cast<FILE_NOTIFY_INFORMATION*>(ptr);
                auto filename = std::wstring(info->FileName, info->FileName + info->FileNameLength / sizeof(char16_t));
                
                // for (auto resolvedFilePath : resolvedFilePaths) {
                //     Log::Debug << convert.to_bytes((char16_t*) resolvedFilePath.c_str()) << " " << resolvedFilePath.size() << Log::Endl;
                // }
                
                if (resolvedFilePaths.contains(filename)) {
                    auto normalName = convert.to_bytes((char16_t*) filename.c_str());
                    Log::Debug << "File changed: " << normalName << Log::Endl;
                    {
                        std::lock_guard lock(_reloadMutex);
                        filesToReload.emplace(normalName);
                    }
                }
                if (!info->NextEntryOffset) break;
                ptr += info->NextEntryOffset;
            }
        }
        else
        {
            Log::Debug << "FAILED! " << GetLastError() << Log::Endl;   
        }
    }
}