#include "ModInstaller.h"

#include <events/D3dInitEvent.h>
#include <events/EventManager.h>
#include <events/TickEvent.h>
#include <logs/Console.h>
#include <modloader/ModManager.h>
#include <sdk/Game.h>
#include <spdlog/spdlog.h>
#include <ui/NotificationManager.h>
#include <utils/TempManager.h>

#include "ModInstallRequestZip.h"

void modloader::ModInstaller::Init()
{
    EventManager::On<D3dInitEvent>([] {
        if (FAILED(OleInitialize(nullptr)))
            spdlog::error("Failed to initialize OLE");
        if (FAILED(RegisterDragDrop(*sdk::Game::window, &dropTarget)))
            spdlog::error("Failed to register drag and drop target");
        ScanCmdline();
    });
}

void modloader::ModInstaller::ScanCmdline()
{
    const auto cmdline = GetCommandLineW();
    int argvCount = 0;
    const auto argv = CommandLineToArgvW(cmdline, &argvCount);
    for (auto i = 0; i < argvCount; i++)
    {
        auto path = std::filesystem::path(argv[i]);
        if (path.extension() != ".zip")
            continue;
        RequestInstall(ModInstallRequestZip::FromZip(path, false));
    }
}

std::shared_ptr<modloader::Mod> modloader::ModInstaller::InstallMod(const std::shared_ptr<ModInfo>& info,
                                                                    const std::filesystem::path& path)
{
    auto mod = ModManager::FindModByID(info->GetID());
    if (!mod)
    {
        auto newPath = sdk::Game::GetModsPath() / info->GetID();
        for (auto i = 1; exists(newPath);)
            newPath = sdk::Game::GetModsPath() / std::format("{}-{}", info->GetID(), i++);

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
    const auto tempFile = TempManager::GetTempDir(false);
    std::filesystem::rename(infoFilesystem->basePath, tempFile);

    try
    {
        std::filesystem::rename(path, infoFilesystem->basePath);
        ModManager::ReloadMod(mod);
        mod->Toggle(true);
        TempManager::RemoveTempDir(tempFile);
    }
    catch (const std::exception& err)
    {
        ui::NotificationManager::Notify(std::format("Не удалось обновить мод {}.\n{}", info->GetID(), err.what()));
        spdlog::debug("Failed to install mod {}, attempting to recover state: {}", Console::StyleModName(info->GetID()),
                      err.what());

        try
        {
            if (exists(infoFilesystem->basePath))
                remove_all(infoFilesystem->basePath);
            std::filesystem::rename(tempFile, infoFilesystem->basePath);
            TempManager::RemoveTempDir(path);
        }
        catch (const std::exception& errInner)
        {
            ui::NotificationManager::Notify(
                std::format("Не удалось вернуть мод {} в прежнее состояние.\n{}", info->GetID(), err.what()));
            spdlog::error("Failed to recover previous mod {}: {}", Console::StyleModName(info->GetID()),
                          errInner.what());
        }
        throw;
    }

    return mod;
}
