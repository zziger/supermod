#include <supermod/modloader/install/ModInstallRequestZip.hpp>
#include <supermod/pch.hpp>

#include <supermod/events/EventManager.hpp>
#include <supermod/events/TickEvent.hpp>
#include <supermod/game/textures/PngLoader.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/install/ModInstaller.hpp>
#include <supermod/modloader/mod/info/ModInfoFilesystem.hpp>
#include <supermod/sdk/DirectX.hpp>
#include <supermod/sdk/Game.hpp>
#include <supermod/utils/TempManager.hpp>

namespace modloader
{
void ModInstallRequestZip::Install()
{
    state = State::INSTALLING;
    error = "";

    auto path = TempManager::GetTempDir();

    progress.show = true;
    progress.message = "Распаковка...";
    progressValue = -1.f;

    std::thread([this, path] {
        try
        {
            auto zip = this->zip;
            auto zipPath = this->zipPath;

            auto files = std::vector<miniz_cpp::zip_info>();
            for (auto& info : zip->zip->infolist())
            {
                if (!info.filename.starts_with(zipPath))
                    continue;
                files.push_back(info);
            }

            auto floatSize = static_cast<float>(files.size());
            for (auto i = 0; i < files.size(); i++)
            {
                progressValue = std::min(static_cast<float>(i) / floatSize, 1.f);
                auto info = files[i];

                auto filename = info.filename.substr(zipPath.size());
                auto file = path / filename;
                auto directory = file.parent_path();

                if (!exists(directory))
                    create_directories(directory);

                std::fstream stream(file, std::ios::binary | std::ios::out);
                stream << zip->zip->open(info).rdbuf();
            }
            progressValue = 1.f;

            EventManager::Once<BeforeTickEvent>([this, path] {
                try
                {
                    ModInstaller::InstallMod(modInfo, path);
                    state = State::FINISHED;
                }
                catch (const std::exception& err)
                {
                    spdlog::error("Failed to install zip mod: {}", err.what());
                    TempManager::RemoveTempDir(path);
                    error = err.what();
                    state = State::IDLE;
                }
                catch (...)
                {
                    spdlog::error("Failed to install zip mod: Unknown error");
                    TempManager::RemoveTempDir(path);
                    error = "Unknown error";
                    state = State::IDLE;
                }
            });
        }
        catch (std::exception& e)
        {
            state = State::IDLE;
            std::lock_guard lock(mutex);
            error = e.what();
        }
    }).detach();
}

void ModInstallRequestZip::Cancel()
{
    state = State::FINISHED;
}

std::string ModInstallRequestZip::GetError()
{
    std::lock_guard lock(mutex);
    return error;
}

ModInstallRequest::Progress ModInstallRequestZip::GetProgress()
{
    auto progressCopy = progress;
    progressCopy.progress = progressValue;
    if (state != State::INSTALLING)
        progressCopy.show = false;
    return progressCopy;
}

std::vector<std::shared_ptr<ModInstallRequest>> ModInstallRequestZip::FromZip(const std::filesystem::path& path,
                                                                              bool remove)
{
    auto res = std::vector<std::shared_ptr<ModInstallRequest>>{};
    auto zip = std::make_shared<OwnedZip>(path.string(), remove);

    for (auto& info : zip->zip->infolist())
    {
        if (!info.filename.ends_with(ModInfoFilesystem::MANIFEST_FILENAME))
            continue;
        auto rootPath = info.filename.substr(0, info.filename.size() - ModInfoFilesystem::MANIFEST_FILENAME.size());

        auto manifestContent = std::stringstream{};
        manifestContent << zip->zip->open(info).rdbuf();
        auto manifest = YAML::Load(manifestContent.str());
        const auto modInfo = std::make_shared<ModInfo>();
        modInfo->Parse(manifest);

        auto iconPath = rootPath + std::string(ModInfoFilesystem::ICON_FILENAME);
        if (zip->zip->has_file(iconPath))
        {
            auto iconContent = std::stringstream{};
            auto data = zip->zip->read(iconPath);
            std::vector<byte> bytes(data.begin(), data.end());
            // TODO: limit icon size

            const auto assetPool = game::AssetPool::Instance();
            vector2ui iconSize{};
            if (const auto iconTex = PngLoader::LoadPngBuf(bytes, iconSize, {1, 1}))
            {
                const auto asset = assetPool->LoadAsset(
                    iconTex, assetPool->MakeAssetKeyUnique("$mod:icon:" + modInfo->GetID()), false, iconSize);
                modInfo->SetIcon(ModIcon(assetPool->MakeOwned(asset)));
            }
        }

        res.push_back(std::make_shared<ModInstallRequestZip>(modInfo, zip, rootPath));
    }

    return res;
}
} // namespace modloader
