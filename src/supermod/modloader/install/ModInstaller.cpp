#include "provider/ModSourceProviderRegistry.hpp"

#include <supermod/constants.hpp>
#include <supermod/events/DxInitEvent.hpp>
#include <supermod/game/Game.hpp>
#include <supermod/io/TempManager.hpp>
#include <supermod/io/logs/Console.hpp>
#include <supermod/modloader/install/ModInstaller.hpp>
#include <supermod/modloader/install/provider/ModSourceProviderZip.hpp>
#include <uri.hpp>

namespace sm::modloader
{
std::shared_ptr<Mod> ModInstaller::InstallMod(const std::shared_ptr<ModInfo>& info, const std::filesystem::path& path,
                                              const bool enable)
{
    auto mod = ModManager::FindModByID(info->GetID());
    if (!mod)
    {
        auto newPath = game::Game::GetModsPath() / info->GetID();
        for (auto i = 1; exists(newPath);)
            newPath = game::Game::GetModsPath() / std::format("{}-{}", info->GetID(), i++);

        try
        {
            std::filesystem::rename(path, newPath);
            const auto newMod = ModManager::CreateMod(newPath);
            newMod->Toggle(true);
            ModManager::AddMod(newMod);
            return newMod;
        }
        catch (...)
        {
            if (exists(newPath))
                remove_all(newPath);
            throw;
        }
    }

    const auto infoFilesystem = std::static_pointer_cast<ModInfoFilesystem>(mod->GetInfo());
    if (mod->IsActive())
    {
        throw Error("Обновляемый мод должен быть выключен");
    }

    mod->Toggle(false);
    const auto tempFile = io::TempManager::GetTempDir(false);
    std::filesystem::rename(infoFilesystem->basePath, tempFile);

    try
    {
        std::filesystem::rename(path, infoFilesystem->basePath);
        ModManager::ReloadMod(mod);
        mod->Toggle(enable);
        io::TempManager::RemoveTempDir(tempFile);
        ModManager::SaveConfig();
    }
    catch (const std::exception& err)
    {
        ui::NotificationManager::Notify(std::format("Не удалось обновить мод {}.\n{}", info->GetID(), err.what()));
        spdlog::debug("Failed to install mod {}, attempting to recover state: {}",
                      io::Console::StyleModName(info->GetID()), err.what());

        try
        {
            if (exists(infoFilesystem->basePath))
                remove_all(infoFilesystem->basePath);
            std::filesystem::rename(tempFile, infoFilesystem->basePath);
            io::TempManager::RemoveTempDir(path);
        }
        catch (const std::exception& errInner)
        {
            ui::NotificationManager::Notify(
                std::format("Не удалось вернуть мод {} в прежнее состояние.\n{}", info->GetID(), err.what()));
            spdlog::error("Failed to recover previous mod {}: {}", io::Console::StyleModName(info->GetID()),
                          errInner.what());
        }
        throw;
    }

    return mod;
}

void ModInstaller::InvokeURI(const std::string& uriCommand)
{
    const auto uri = ::uri(uriCommand);
    assert(uri.get_scheme() == Constants::URI_PROTOCOL);
    auto command = uri.get_host();
    auto query = uri.get_query_dictionary();

    if (command == "install")
    {
        AddProvider(std::make_shared<ModSourceProviderRegistry>(query["id"], query["version"]));
        return;
    }

    ui::NotificationManager::Notify(std::format("Неизвестная URI команда {}", command));
}

void ModInstaller::Init()
{
    EventManager::On<DxInitEvent>([] {
        if (FAILED(OleInitialize(nullptr)))
            spdlog::error("Failed to initialize OLE");
        if (FAILED(RegisterDragDrop(*game::Game::window, &dropTarget)))
            spdlog::error("Failed to register drag and drop target");

        // In DX init because this initializes mod icons
        const auto cmdline = GetCommandLineW();
        int argvCount = 0;
        const auto argv = CommandLineToArgvW(cmdline, &argvCount);
        for (auto i = 0; i < argvCount; i++)
        {
            auto str = utils::wstr_to_str(argv[i]);
            if (str.starts_with(Constants::URI_PROTOCOL))
            {
                InvokeURI(str);
                continue;
            }

            auto path = std::filesystem::path(argv[i]);
            if (path.extension() != ".zip" && path.extension() != ".sprm")
                continue;

            auto zip = std::make_shared<io::OwnedZip>(path.string(), false);
            AddProvider(std::make_shared<ModSourceProviderZip>(path.filename().string(), zip));
        }
    });
}
} // namespace sm::modloader