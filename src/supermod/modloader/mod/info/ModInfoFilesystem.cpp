#include <supermod/modloader/mod/info/ModInfoFilesystem.hpp>
#include <supermod/pch.hpp>

#include <supermod/events/StartExecutionEvent.hpp>
#include <supermod/sdk/DirectX.hpp>

namespace sm::modloader
{
void ModInfoFilesystem::FromPath(const std::filesystem::path& path)
{
    if (!exists(path))
        throw ModFileError("Папка мода не найдена по пути " + path.string());

    const auto manifestPath = path / MANIFEST_FILENAME;
    if (!exists(manifestPath))
        throw ModFileError("Манифест мода (manifest.yml) не найден по пути " + manifestPath.string());

    // TODO handle when this throws
    auto manifest = YAML::LoadFile(manifestPath.string());
    Parse(manifest);
    basePath = path;
    UpdateIcon();
}

void ModInfoFilesystem::UpdateIcon()
{
    const auto id = GetID();
    if (!id.empty() && *sdk::DirectX::d3dDevice && exists(basePath / ICON_FILENAME))
    {
        const auto assetPool = game::AssetPool::Instance();
        const auto iconAsset =
            assetPool->LoadAsset(basePath / ICON_FILENAME, assetPool->MakeAssetKeyUnique("$mod:icon:" + id));
        SetIcon(ModIcon(assetPool->MakeOwned(iconAsset)));
    }
}

void ModInfoFilesystem::OpenFolder() const
{
    ShellExecuteW(nullptr, L"explore", basePath.wstring().c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}
} // namespace sm::modloader
