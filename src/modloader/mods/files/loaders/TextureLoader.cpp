#include <regex>

#include "DirectXUtils.h"
#include "../ModFileResolver.h"
#include "game/AssetPool.h"
#include "sdk/DirectX.h"

void ModFileResolver::LoadTexture(std::filesystem::path texturePath) {
    Log::Debug << "Reloading texture " << texturePath << Log::Endl;
        
    const auto filename = GetPoolFileName(texturePath.filename().generic_string());

    const auto pool = game::AssetPool::GetInstance();
    game::Asset* asset = pool->GetByName(texturePath.filename().generic_string());
    if (!asset) return;

    if ((bool) asset->isTga) {
        asset->Anonymize();
        const auto cwd = std::filesystem::current_path();
        current_path(texturePath.parent_path());

        static constexpr Memory::Pattern loadTex("55 8B EC 51 89 4D ? 6A ? 6A ? 6A");
        static auto mem = loadTex.Search();
        game::Asset* newAsset = mem.Get<game::Asset* (__thiscall *)(game::AssetPool*, const char*)>()(pool, filename.c_str());
        current_path(cwd);
        asset->texture->Release();
        memcpy(asset, newAsset, sizeof(game::Asset));
        memset(newAsset, 0, sizeof(game::Asset));
        pool->assetCount--;
    } else {
        const auto tex = dx_utils::load_jpg(*sdk::DirectX::d3dDevice, texturePath.generic_string().c_str());
        asset->ReplaceTexture(tex);
    }
}