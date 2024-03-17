#include "ModInstaller.h"

#include <events/D3dInitEvent.h>
#include <events/EventManager.h>
#include <sdk/Game.h>

#include "ModInstallRequestZip.h"

void modloader::ModInstaller::Init()
{
    ScanCmdline();
    EventManager::On<D3dInitEvent>([]
    {
        if (FAILED(OleInitialize(nullptr))) Log::Error << "Failed to initialize OLE" << Log::Endl;
        if (FAILED(RegisterDragDrop(*sdk::Game::window, &dropTarget))) Log::Error << "Failed to register Drag'n'Drop" << Log::Endl;
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