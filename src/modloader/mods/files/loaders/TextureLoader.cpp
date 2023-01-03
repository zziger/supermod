#include <regex>

#include "DirectXUtils.h"
#include "Utils.h"
#include "../ModFileResolver.h"
#include "events/ResolveFileEvent.h"
#include "game/AssetPool.h"
#include "game/CachedFilePool.h"
#include "sdk/DirectX.h"

game::Asset* (__thiscall * readJpg_orig)(game::AssetPool* this_, char* name, int width, int height) = nullptr;
game::Asset* __fastcall readJpg(game::AssetPool* this_, void*, char* name, int width, int height) {
    auto asset = readJpg_orig(this_, name, width, height);
    asset->constTex = 1;
    return asset;
}
game::Asset* (__thiscall * readJpg2_orig)(game::AssetPool* this_, char* name, int width, int height) = nullptr;
game::Asset* __fastcall readJpg2(game::AssetPool* this_, void*, char* name, int width, int height) {
    auto asset = readJpg_orig(this_, name, width, height);
    asset->constTex = 2;
    return asset;
}

void ModFileResolver::LoadTexture(std::filesystem::path texturePath) {
    // Log::Debug << "Reloading texture " << texturePath << Log::Endl;

    const auto filename = GetPoolFileName(texturePath.filename().generic_string());

    const auto pool = game::AssetPool::GetInstance();
    game::Asset* asset = pool->GetByName(texturePath.filename().generic_string());
    if (!asset) return;

    asset->Anonymize();
    const auto cwd = std::filesystem::current_path();
    current_path(texturePath.parent_path());

    auto cachedFile = game::CachedFilePool::GetInstance()->GetByName(filename);
    if (cachedFile) {
        int size;
        cachedFile->content = utils::read_file(filename, size);
        cachedFile->size = size;
    }
    game::Asset* newAsset;
    set_should_resolve_files(false);
    if (asset->constTex == 1) {
        newAsset = game::AssetPool::GetReadConstJpgMem().Get<game::Asset* (__thiscall *)(game::AssetPool*, const char*, int, int)>()(pool, filename.c_str(), asset->width, asset->height);
    } else if (asset->constTex == 2) {
        newAsset = game::AssetPool::GetReadConstSurfaceMem().Get<game::Asset* (__thiscall *)(game::AssetPool*, const char*, int, int)>()(pool, filename.c_str(), asset->width, asset->height);
    } else {
        static constexpr Memory::Pattern loadTex("55 8B EC 51 89 4D ? 6A ? 6A ? 6A");
        static auto mem = loadTex.Search();
        newAsset = mem.Get<game::Asset* (__thiscall *)(game::AssetPool*, const char*)>()(pool, filename.c_str());
    }
    set_should_resolve_files(true);
    // } else {
    // }
    current_path(cwd);
    asset->texture->Release();
    memcpy(asset, newAsset, sizeof(game::Asset));
    memset(newAsset, 0, sizeof(game::Asset));
    pool->assetCount--;

}

inline EventManager::Ready $debug([] {
    
    HookManager::RegisterHook(game::AssetPool::GetReadConstJpgMem(), HOOK_REF_FORCE(readJpg));
    HookManager::RegisterHook(game::AssetPool::GetReadConstSurfaceMem(), HOOK_REF_FORCE(readJpg2));
}) ;