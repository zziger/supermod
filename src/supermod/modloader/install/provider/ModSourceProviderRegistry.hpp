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
class ModSourceProviderRegistry : public ModSourceProvider
{
    std::string modId;
    std::string version;

public:
    struct ModInstallSourceRegistry : ModInstallSource
    {
        std::string url;
        std::shared_ptr<ModInfo> modInfo;

        std::mutex messageMutex;
        std::atomic<float> installProgress;
        std::optional<std::string> installMessage;
        std::optional<std::string> installError;

        ModInstallSourceRegistry(const std::weak_ptr<ModInstallRequest>& req, const std::shared_ptr<ModInfo>& modInfo,
                                 std::string url)
            : ModInstallSource(req),
              url(std::move(url)),
              modInfo(modInfo)
        {
        }

        void Update() override {}

        std::string GetLabel() override { return "Скачать из источников SuperMod"; }

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

    explicit ModSourceProviderRegistry(std::string modId, std::string version)
        : modId(std::move(modId)),
          version(std::move(version))
    {
    }

    async::task<void> DiscoverMods(std::stop_token stopToken) override;

    std::string GetName() override { return modId; }
};
} // namespace sm::modloader