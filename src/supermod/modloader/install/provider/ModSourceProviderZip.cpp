#include <supermod/events/EventManager.hpp>
#include <supermod/io/TempManager.hpp>
#include <supermod/modloader/install/provider/ModSourceProviderZip.hpp>

void sm::modloader::ModSourceProviderZip::ModInstallSourceZip::Update()
{
    auto& providers = ModInstaller::GetProviders();
    auto countProviders = std::ranges::count_if(providers, [&](const std::shared_ptr<ModSourceProvider>& provider) {
        return std::dynamic_pointer_cast<ModSourceProviderZip>(provider) != nullptr;
    });
    auto countSources =
        req.expired()
            ? 0
            : std::ranges::count_if(req.lock()->sources, [&](const std::shared_ptr<ModInstallSource>& source) {
                  auto zipPtr = std::dynamic_pointer_cast<ModInstallSourceZip>(source);
                  return zipPtr != nullptr && zipPtr->filename == filename;
              });

    if (countProviders > 1)
    {
        if (countSources > 1)
            label = "Установить из " + filename + " " + zipPath;
        else
            label = "Установить из " + filename;
    }
    else
    {
        if (countSources > 1)
            label = "Установить из архива " + zipPath;
        else
            label = "Установить из архива";
    }
}

async::task<void> sm::modloader::ModSourceProviderZip::ModInstallSourceZip::Install()
{
    installProgress = -1;
    installMessage = "Распаковка...";
    auto path = io::TempManager::GetTempDir();

    co_await io::Async::ToBackground();
    try
    {

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
            installProgress = std::min(static_cast<float>(i) / floatSize, 1.f);
            auto info = files[i];

            auto filename = info.filename.substr(zipPath.size());
            auto file = path / filename;
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

    try
    {
        ModInstaller::InstallMod(modInfo, path);
    }
    catch (const std::exception& err)
    {
        io::TempManager::RemoveTempDir(path);
        installError = err.what();
        throw;
    }

    co_return;
}

async::task<void> sm::modloader::ModSourceProviderZip::DiscoverMods(std::stop_token stopToken)
{
    bool found = false;

    for (auto& info : zip->zip->infolist())
    {
        if (stopToken.stop_requested())
            throw async::task_canceled{};
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
            if (const auto iconTex = game::loaders::PngLoader::LoadPngBuf(bytes, iconSize, {1, 1}))
            {
                const auto asset = assetPool->LoadAsset(
                    iconTex, assetPool->MakeAssetKeyUnique("$mod:icon:" + modInfo->GetID()), false, iconSize);
                modInfo->SetIcon(ModIcon(assetPool->MakeOwned(asset)));
            }
        }

        found = true;
        {
            auto req = ModInstaller::GetRequest(modInfo->GetID(), true);
            req->AddSource(std::make_shared<ModInstallSourceZip>(req, modInfo, filename, zip, rootPath));
        }
        for (const auto& dependency : modInfo->dependencies)
        {
            auto depReq = ModInstaller::GetRequest(dependency.id, false);
            if (!dependency.name.empty())
                depReq->dummyModInfo->title = dependency.name;
        }
    }

    if (!found)
    {
        throw std::exception("Не удалось найти моды SuperMod в указанном архиве");
    }

    co_return;
}