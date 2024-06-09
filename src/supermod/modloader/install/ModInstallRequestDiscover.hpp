#pragma once
#include <supermod/modloader/install/ModInstallRequestDiscover.hpp>
#include <supermod/pch.hpp>

#include <supermod/modloader/install/ModInstallRequest.hpp>
#include <supermod/modloader/mod/Mod.hpp>

namespace modloader
{
class ModInstallRequestDiscover final : public ModInstallRequest
{
    bool finished = false;
    std::shared_ptr<Mod> mod;

public:
    explicit ModInstallRequestDiscover(const std::shared_ptr<Mod>& mod) : ModInstallRequest(mod->GetInfo()), mod(mod) {}

private:
    void Install() override;
    void Cancel() override;
    bool IsFinished() override { return finished; }
    std::string GetInstallActionLabel() override { return "Включить"; }
    std::string GetCancelActionLabel() override { return "Не включать"; }
};
} // namespace modloader