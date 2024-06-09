#include <supermod/modloader/files/ModFileResolver.hpp>
#include <supermod/pch.hpp>

#include <supermod/events/EventManager.hpp>
#include <supermod/events/ResolveFileEvent.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/files/loaders/MusicLoader.hpp>
#include <supermod/modloader/files/loaders/SoundLoader.hpp>
#include <supermod/modloader/files/loaders/TextureLoader.hpp>
#include <supermod/modloader/mod/info/ModInfoFilesystem.hpp>

namespace modloader
{
void ModFileResolver::InitLoader(const std::shared_ptr<BaseLoader>& loader)
{
    const auto extensions = loader->GetExtensions();
    for (const auto& ext : extensions)
    {
        loaders[ext].push_back(loader);
    }
}

void ModFileResolver::Init()
{
    InitLoader<TextureLoader>();
    InitLoader<MusicLoader>();
    InitLoader<SoundLoader>();

    EventManager::On<ResolveFileEvent>([](auto& evt) {
        if (const std::optional<std::filesystem::path> path = ModFileResolver::ResolveGameFileInMods(evt.absolutePath))
            evt.SetResolvedPath(*path);
    });

    initialized = true;
}

std::optional<std::filesystem::path> ModFileResolver::ResolveGameFileInMods(const std::filesystem::path& path)
{
    const auto mods = ModManager::GetMods();
    for (const auto& mod : mods | std::ranges::views::reverse)
    {
        if (mod->HasFlag(Mod::Flag::INTERNAL) || !mod->IsEnabled())
            continue;

        const auto resolvedPath = ResolveGameFileInMod(mod, path);
        if (!resolvedPath)
            continue;

        return *resolvedPath;
    }

    return std::nullopt;
}

std::filesystem::path ModFileResolver::ResolveGameFile(const std::filesystem::path& path)
{
    const auto resolvedPath = ResolveGameFileInMods(path);
    return resolvedPath ? *resolvedPath : path;
}

std::optional<std::filesystem::path> ModFileResolver::GetGameFileInMod(const std::shared_ptr<Mod>& mod,
                                                                       const std::filesystem::path& path)
{
    if (!mod || mod->HasFlag(Mod::Flag::INTERNAL) || !mod->IsActive())
        return {};
    const auto filePath = relative(path, sdk::Game::GetDataPath());
    const auto info = std::dynamic_pointer_cast<ModInfoFilesystem>(mod->GetInfo());
    if (!info)
        return {};
    return info->basePath / "data" / filePath;
}

std::optional<std::filesystem::path> ModFileResolver::ResolveGameFileInMod(const std::shared_ptr<Mod>& mod,
                                                                           const std::filesystem::path& path)
{
    const auto filePath = GetGameFileInMod(mod, path);
    if (filePath && exists(*filePath))
        return *filePath;
    return std::nullopt;
}

void ModFileResolver::LoadFile(const std::filesystem::path& path)
{
    if (!initialized)
        return;
    auto extension = path.extension().generic_string();
    std::ranges::transform(extension, extension.begin(), tolower);

    if (extension.empty())
        return;

    if (!loaders.contains(extension))
    {
        spdlog::trace("No loader found for file {}", path.string());
        return;
    }

    const auto extensionLoaders = loaders[extension];
    for (const auto& loader : extensionLoaders)
    {
        if (loader->Load(path))
            return;
    }

    spdlog::debug("All loaders failed to laod file {}", path.string());
}

void ModFileResolver::LoadFiles(const std::filesystem::path& path)
{
    if (!initialized)
        return;
    if (!exists(path) || !is_directory(path))
        return;

    const auto it = std::filesystem::recursive_directory_iterator(path);
    for (const auto& file : it)
    {
        if (file.is_directory())
            continue;
        auto relPath = relative(file.path(), path);
        if (relPath.empty() || relPath.native()[0] == '.')
            continue;

        LoadFile(relPath);
    }
}
} // namespace modloader
