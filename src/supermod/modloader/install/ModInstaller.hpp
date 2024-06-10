#pragma once
#include <supermod/pch.hpp>

#include <supermod/modloader/install/ModInstallRequest.hpp>
#include <supermod/modloader/install/ZipModDropTarget.hpp>
#include <supermod/modloader/mod/Mod.hpp>

namespace sm::modloader
{
class ModInstaller
{
    inline static std::vector<std::shared_ptr<ModInstallRequest>> install_requests{};
    inline static ZipModDropTarget dropTarget{};

public:
    static void Init();
    static void ScanCmdline();

    static void RequestInstall(const std::shared_ptr<ModInstallRequest>& request)
    {
        install_requests.push_back(request);
    }
    static void RequestInstall(const std::vector<std::shared_ptr<ModInstallRequest>>& requests)
    {
        for (const auto& request : requests)
            install_requests.push_back(request);
    }
    static const std::vector<std::shared_ptr<ModInstallRequest>>& GetInstallRequests() { return install_requests; }
    static void ClearInstallRequests() { install_requests.clear(); }
    static ZipModDropTarget& GetDropTarget() { return dropTarget; }

    static std::shared_ptr<Mod> InstallMod(const std::shared_ptr<ModInfo>& info, const std::filesystem::path& path);
};
} // namespace sm::modloader