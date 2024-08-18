#pragma once
#include <async/task.h>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/mod/info/ModInfo.hpp>
#include <utility>

namespace sm::modloader
{
struct ModInstallRequest;

struct ModInstallSource
{
    explicit ModInstallSource(const std::shared_ptr<ModInstallRequest>& req) : req(req) {}
    virtual ~ModInstallSource() = default;

    virtual void Update() {}
    virtual std::string GetLabel() = 0;
    virtual std::shared_ptr<ModInfo> GetModInfo() = 0;

    virtual async::task<void> Install() = 0;
    virtual std::optional<std::string> GetInstallMessage() = 0;
    virtual std::optional<std::string> GetInstallError() = 0;
    virtual float GetInstallProgress() = 0;

protected:
    std::shared_ptr<ModInstallRequest> req;
};

struct ModInstallRequest
{
    static constexpr int DONT_INSTALL = -1;

    explicit ModInstallRequest(const std::string& id, const bool direct = false)
        : id(id),
          addedDirectly(direct),
          dummyModInfo(std::make_shared<ModInfo>(id))
    {
        dummyModInfo->title = id;
        dummyModInfo->author = "Неизвестный мод";
    }

    const std::string id;
    bool addedDirectly = false; // false if added indirectly for a dependency
    int activeSource = DONT_INSTALL;
    std::shared_ptr<ModInfo> dummyModInfo;
    std::vector<std::shared_ptr<ModInstallSource>> sources{};
    std::vector<std::string> requiredBy{};

    void AddSource(const std::shared_ptr<ModInstallSource>& source)
    {
        if (sources.empty())
            activeSource = 0;
        sources.push_back(source);
    }

    void Update();

    std::shared_ptr<ModInfo> GetModInfo()
    {
        if (sources.empty())
        {
            return dummyModInfo;
        }

        return sources[std::max(0, activeSource)]->GetModInfo();
    }

    std::shared_ptr<ModInstallSource> GetActiveSource()
    {
        if (activeSource == DONT_INSTALL || sources.empty() || activeSource >= sources.size())
            return nullptr;
        return sources[activeSource];
    }

    [[nodiscard]] bool IsCandidate() const;
};
} // namespace sm::modloader