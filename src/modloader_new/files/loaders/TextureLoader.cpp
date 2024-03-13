#include "TextureLoader.h"

#include <game/AssetPool.h>
#include <sdk/DirectX.h>

namespace modloader {
    bool TextureLoader::Load(const std::filesystem::path& path)
    {
        return game::AssetPool::Instance()->ReloadGameAsset(path.filename().string());
    }

    std::vector<std::string> TextureLoader::GetExtensions() const
    {
        return { ".jpg", ".jpeg", ".png", ".tga" };
    }
}
