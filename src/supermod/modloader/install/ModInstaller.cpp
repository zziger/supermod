#include <supermod/modloader/install/ModInstaller.hpp>
#include <supermod/pch.hpp>

#include <supermod/events/D3dInitEvent.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/events/TickEvent.hpp>
#include <supermod/game/Game.hpp>
#include <supermod/io/TempManager.hpp>
#include <supermod/logs/Console.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/install/ModInstallRequestZip.hpp>
#include <supermod/modloader/mod/info/ModInfoFilesystem.hpp>
#include <supermod/ui/NotificationManager.hpp>

namespace sm::modloader
{
void ModInstaller::Init()
{
    EventManager::On<D3dInitEvent>([] {
        if (FAILED(OleInitialize(nullptr)))
            spdlog::error("Failed to initialize OLE");
        if (FAILED(RegisterDragDrop(*game::Game::window, &dropTarget)))
            spdlog::error("Failed to register drag and drop target");
        ScanCmdline();
    });
}

void ModInstaller::ScanCmdline()
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

std::shared_ptr<Mod> ModInstaller::InstallMod(const std::shared_ptr<ModInfo>& info, const std::filesystem::path& path)
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
        mod->Toggle(true);
        io::TempManager::RemoveTempDir(tempFile);
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
            io::TempManager::RemoveTempDir(path);
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
} // namespace sm::modloader