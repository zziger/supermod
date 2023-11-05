#include "../ModFileResolver.h"
#include "events/ResolveFileEvent.h"
#include "game/AssetPool.h"
#include "sdk/DirectX.h"


void ModFileResolver::LoadTexture(std::filesystem::path texturePath) {
    bool alpha;
    const auto fileKey = game::AssetPool::TrimFileName(texturePath.filename().string(), alpha);
    const auto poolId = alpha ? fileKey + "#" : fileKey;
    const auto pool = game::AssetPool::Instance();
    
	const auto asset = pool->GetByName(poolId);
    if (!asset) return;

    vector2ui size;
    
    const auto texture = game::AssetPool::TryLoadTexture(texturePath.parent_path(), fileKey, asset->hasAlpha, size, asset->meta->canvasSizeMultiplier);
    if (!texture)
    {
        Log::Error << "Не удалось перезагрузить текстуру " << texturePath << " (" + poolId + ")" << Log::Endl;
        return;
    }

    sdk::DirectX::RemoveTexture(asset->texture);
    asset->texture = texture;
    asset->width = size.x;
    asset->height = size.y;

    Log::Info << "Текстура " << texturePath << " (" + poolId + ") перезагружена" << Log::Endl;
}