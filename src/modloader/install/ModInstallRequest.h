#pragma once
#include <memory>
#include <optional>
#include <string>

namespace modloader
{
class ModInstallRequest
{
protected:
    std::shared_ptr<ModInfo> modInfo{};

public:
    struct Progress
    {
        bool show = false;
        float progress = 0.0f;
        std::optional<std::string> message;
    };

    virtual ~ModInstallRequest() = default;
    explicit ModInstallRequest(const std::shared_ptr<ModInfo>& modInfo) : modInfo(modInfo) {}

    std::shared_ptr<ModInfo> GetModInfo() { return modInfo; }
    virtual Progress GetProgress() { return {}; }
    virtual std::string GetError() { return ""; }
    virtual std::string GetInstallActionLabel() { return "Установить"; }
    virtual std::string GetCancelActionLabel() { return "Не устанавливать"; }

    virtual bool IsInstalling() { return false; }
    virtual bool IsFinished() = 0;

    virtual void Install() = 0;
    virtual void Cancel() {}
};
} // namespace modloader
