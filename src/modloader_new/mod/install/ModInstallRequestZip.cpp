#include "ModInstallRequestZip.h"

#include <events/EventManager.h>
#include <events/TickEvent.h>
#include <modloader_new/ModManager.h>
#include <sdk/DirectX.h>
#include <sdk/Game.h>
#include <yaml-cpp/yaml.h>

namespace modloader {
    void ModInstallRequestZip::Install()
    {
        installing = true;
        error = "";

        auto path = sdk::Game::GetModsPath();
        auto counter = 1;
        auto folder = modInfo->GetID();
        while (exists(path / folder))
            folder = std::format("{}-{}", modInfo->GetID(), counter++);
        path /= folder;
        create_directories(path);

        progress.show = true;
        progress.message = "Распаковка...";
        progressValue = -1.f;

        std::thread([this, path]
        {
            try
            {
                auto zip = this->zip;
                auto zipPath = this->zipPath;

                auto files = std::vector<miniz_cpp::zip_info>();
                for (auto& info : zip->zip->infolist())
                {
                    if (!info.filename.starts_with(zipPath)) continue;
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

                EventManager::Once<BeforeTickEvent>([this, path]
                {
                    const auto mod = ModManager::CreateMod(path);
                    if (!mod)
                    {
                        finished = false;
                        installing = false;
                        std::lock_guard lock(mutex);
                        error = "Не удалось создать мод";
                        return;
                    }

                    (*mod)->Toggle(true);
                    ModManager::AddMod(*mod);
                    finished = true;
                    installing = false;
                });
            }
            catch(std::exception& e)
            {
                finished = false;
                installing = false;
                std::lock_guard lock(mutex);
                error = std::format("Ошибка установки: {}", e.what());
            }
        }).detach();
    }

    void ModInstallRequestZip::Cancel()
    {
        finished = true;
    }

    std::string ModInstallRequestZip::GetError()
    {
        std::lock_guard lock(mutex);
        return error;
    }

    ModInstallRequest::Progress ModInstallRequestZip::GetProgress()
    {
        progress.progress = progressValue;
        return progress;
    }

    std::vector<std::shared_ptr<ModInstallRequestZip>> ModInstallRequestZip::FromZip(const std::filesystem::path& path, bool remove)
    {
        auto res = std::vector<std::shared_ptr<ModInstallRequestZip>> {};
        auto zip = std::make_shared<OwnedZip>(path.string(), remove);

        for (auto& info : zip->zip->infolist())
        {
            if (!info.filename.ends_with(ModInfoFilesystem::MANIFEST_FILENAME)) continue;
            auto rootPath = info.filename.substr(0, info.filename.size() - ModInfoFilesystem::MANIFEST_FILENAME.size());

            auto manifestContent = std::stringstream {};
            manifestContent << zip->zip->open(info).rdbuf();
            auto manifest = YAML::Load(manifestContent.str());
            const auto modInfo = std::make_shared<ModInfo>();
            modInfo->Parse(manifest);

            res.push_back(std::make_shared<ModInstallRequestZip>(modInfo, zip, rootPath));
        }

        return res;
    }
}
