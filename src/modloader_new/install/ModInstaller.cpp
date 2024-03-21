#include "ModInstaller.h"

#include <events/D3dInitEvent.h>
#include <events/EventManager.h>
#include <events/TickEvent.h>
#include <modloader_new/ModManager.h>
#include <sdk/Game.h>
#include <utils/TempManager.h>

#include "ModInstallRequestZip.h"

void modloader::ModInstaller::Init()
{
    EventManager::On<D3dInitEvent>([]
    {
        if (FAILED(OleInitialize(nullptr))) Log::Error << "Failed to initialize OLE" << Log::Endl;
        if (FAILED(RegisterDragDrop(*sdk::Game::window, &dropTarget))) Log::Error << "Failed to register Drag'n'Drop" << Log::Endl;
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
        if (path.extension() != ".zip") continue;
        RequestInstall(ModInstallRequestZip::FromZip(path, false));
    }
}

std::shared_ptr<modloader::Mod> modloader::ModInstaller::InstallMod(const std::shared_ptr<ModInfo>& info, const std::filesystem::path& path)
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
        catch(...)
        {
            if (exists(newPath))
                remove_all(newPath);
            throw;
        }
    }

    const auto infoFilesystem = std::static_pointer_cast<ModInfoFilesystem>(mod->GetInfo());
    if (mod->IsActive())
    {
        throw Error("Mod should be disabled");
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
    catch(const std::exception& err)
    {
        Log::Debug << "Failed to install mod " << info->GetID() << ", attempting to recover state:" << err.what() << Log::Endl;

        try
        {
            if (exists(infoFilesystem->basePath))
                remove_all(infoFilesystem->basePath);
            std::filesystem::rename(tempFile, infoFilesystem->basePath);
            TempManager::RemoveTempDir(path);
        }
        catch(const std::exception& errInner)
        {
            Log::Error << "Failed to recover initial mod state: " << errInner.what() << Log::Endl;
        }
        throw;
    }

    return mod;
}
