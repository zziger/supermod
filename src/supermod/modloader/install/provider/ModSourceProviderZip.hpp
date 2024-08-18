#pragma once
#include <async/task_canceled.h>
#include <supermod/game/textures/PngLoader.hpp>
#include <supermod/io/OwnedZip.hpp>
#include <supermod/modloader/install/ModInstaller.hpp>
#include <supermod/modloader/install/provider/ModSourceProvider.hpp>
#include <supermod/modloader/mod/info/ModInfoFilesystem.hpp>
#include <utility>

namespace sm::modloader
{
class ModSourceProviderZip : public ModSourceProvider
{
    std::string filename;
    std::shared_ptr<io::OwnedZip> zip;

public:
    struct ModInstallSourceZip : ModInstallSource
    {
        std::string filename;
        std::shared_ptr<ModInfo> modInfo;
        std::shared_ptr<io::OwnedZip> zip;
        std::string zipPath;
        std::string label;

        std::mutex messageMutex;
        std::atomic<float> installProgress;
        std::optional<std::string> installMessage;
        std::optional<std::string> installError;

        ModInstallSourceZip(const std::weak_ptr<ModInstallRequest>& req, const std::shared_ptr<ModInfo>& modInfo,
                            std::string filename, const std::shared_ptr<io::OwnedZip>& zip, std::string zipPath)
            : ModInstallSource(req),
              filename(std::move(filename)),
              modInfo(modInfo),
              zip(zip),
              zipPath(std::move(zipPath))
        {
        }

        void Update() override;

        std::string GetLabel() override { return label; }

        std::shared_ptr<ModInfo> GetModInfo() override { return modInfo; }

        std::optional<std::string> GetInstallMessage() override
        {
            std::lock_guard lock(messageMutex);
            return installMessage;
        }

        std::optional<std::string> GetInstallError() override
        {
            std::lock_guard lock(messageMutex);
            return installError;
        }

        float GetInstallProgress() override { return installProgress; }

        async::task<void> Install() override;
    };

    ModSourceProviderZip(std::string filename, std::shared_ptr<io::OwnedZip> zip)
        : filename(std::move(filename)),
          zip(std::move(zip))
    {
    }

    async::task<void> DiscoverMods(std::stop_token stopToken) override;

    std::string GetName() override { return filename; }
};
} // namespace sm::modloader