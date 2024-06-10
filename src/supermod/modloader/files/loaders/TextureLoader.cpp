#include <supermod/modloader/files/loaders/TextureLoader.hpp>

#include <supermod/game/AssetPool.hpp>
#include <supermod/game/DirectX.hpp>

namespace sm::modloader
{
bool TextureLoader::Load(const std::filesystem::path& path)
{
    return game::AssetPool::Instance()->ReloadGameAsset(path.filename().string());
}
} // namespace sm::modloader
