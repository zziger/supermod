#include <supermod/events/EventManager.hpp>
#include <supermod/io/Http.hpp>
#include <supermod/io/TempManager.hpp>
#include <supermod/modloader/install/provider/ModSourceProviderRegistry.hpp>
#include <supermod/registry/RegistryManager.hpp>

async::task<void> sm::modloader::ModSourceProviderRegistry::ModInstallSourceRegistry::Install()
{
    auto donwloadTempDir = io::TempManager::GetTempDir();
    auto downloadPath = donwloadTempDir / "mod.zip";

    {
        auto downloadFile = std::make_shared<std::ofstream>(downloadPath, std::ios::binary);

        installProgress = 0;
        installMessage = "Загрузка...";

        co_await io::Http::Download(downloadFile, cpr::Url{url}, registry::RegistryManager::GetBearer(),
                                    cpr::ProgressCallback([this](cpr::cpr_off_t downloadTotal,
                                                                 cpr::cpr_off_t downloadNow, cpr::cpr_off_t uploadTotal,
                                                                 cpr::cpr_off_t uploadNow, intptr_t userdata) -> bool {
                                        installProgress =
                                            static_cast<float>(downloadNow) / static_cast<float>(downloadTotal);
                                        return true;
                                    }));

        {
            std::lock_guard lock(messageMutex);
            installMessage = "Распаковка...";
            installProgress = 0;
        }
        downloadFile->close();
    }

    auto unpackTempDir = io::TempManager::GetTempDir();
    auto zip = std::make_shared<io::OwnedZip>(downloadPath.string(), true);

    try
    {

        const auto& files = zip->zip->infolist();

        auto floatSize = static_cast<float>(files.size());
        for (auto i = 0; i < files.size(); i++)
        {
            installProgress = std::min(static_cast<float>(i) / floatSize, 1.f);
            auto info = files[i];

            auto filename = info.filename;
            auto file = unpackTempDir / filename;
            auto directory = file.parent_path();

            if (!exists(directory))
                create_directories(directory);

            std::fstream stream(file, std::ios::binary | std::ios::out);
            stream << zip->zip->open(info).rdbuf();
        }
        installProgress = 1.f;
    }
    catch (std::exception& e)
    {
        std::lock_guard lock(messageMutex);
        installError = e.what();
    }

    co_await io::Async::ToMain();
    installMessage = "Установка...";
    installProgress = -1;
    io::TempManager::RemoveTempDir(donwloadTempDir);

    auto enable = req.expired() ? true : req.lock()->enableAfterInstall;

    try
    {
        ModInstaller::InstallMod(modInfo, unpackTempDir, enable);
    }
    catch (const std::exception& err)
    {
        io::TempManager::RemoveTempDir(unpackTempDir);
        installError = err.what();
        throw;
    }

    io::TempManager::RemoveTempDir(unpackTempDir);
    co_return;
}
async::task<void> sm::modloader::ModSourceProviderRegistry::DiscoverMods(std::stop_token stopToken)
{
    if (version.empty())
    {
        auto [json, response] =
            co_await io::Http::GetJson(cpr::Url{API_URL "mods/" + modId}, registry::RegistryManager::GetBearer());
        version = json["latestVersionValue"];
    }

    auto [json, response] = co_await io::Http::GetJson(cpr::Url{API_URL "mods/" + modId + "/versions/" + version},
                                                       registry::RegistryManager::GetBearer());
    auto modInfo = std::make_shared<ModInfoRegistry>();
    modInfo->FromJson(json);

    if (json["cdnIconUrl"].is_string())
    {
        auto iconResponse = co_await io::Http::Get(cpr::Url{json["cdnIconUrl"]});
        auto decoded = std::vector<byte>(iconResponse.text.begin(), iconResponse.text.end());

        io::Async::Schedule([=, modInfoWeak = std::weak_ptr(modInfo)]() {
            if (modInfoWeak.expired())
                return;

            auto modInfo = modInfoWeak.lock();
            vector2ui size{};
            const auto tex = game::loaders::PngLoader::LoadPngBuf(decoded, size, {1, 1});
            const auto asset = game::AssetPool::Instance()->LoadAsset(
                tex, game::AssetPool::Instance()->MakeAssetKeyUnique("$builtin:registry:mod:" + modId + ":" + version),
                true, size);
            modInfo->icon = ModIcon{game::AssetPool::Instance()->MakeOwned(asset)};
        });
    }

    auto request = ModInstaller::GetRequest(modId, true);
    request->AddSource(std::make_shared<ModInstallSourceRegistry>(request, modInfo, json["cdnContentUrl"]));
    co_return;
}