#include <supermod/modloader/install/ModInstallRequest.hpp>
#include <supermod/modloader/install/ModInstaller.hpp>

void sm::modloader::ModInstallRequest::Update()
{
    for (auto& source : sources)
    {
        source->Update();
    }

    requiredBy.clear();
    auto& requests = ModInstaller::GetRequests();
    for (auto& request : requests)
    {
        auto modInfo = request->GetModInfo();
        auto deps = modInfo->dependencies;
        if (std::ranges::find_if(deps, [&](const ModInfo::Dependency& dep) { return dep.id == id; }) != deps.end())
        {
            requiredBy.push_back(modInfo->GetID());
        }
    }
}

bool sm::modloader::ModInstallRequest::IsCandidate() const
{
    if (addedDirectly)
        return true;
    if (ModManager::FindModByID(id) != nullptr)
        return false;

    auto& requests = ModInstaller::GetRequests();
    if (std::ranges::find_if(requests, [&](const std::shared_ptr<ModInstallRequest>& req) {
            if (req->activeSource == DONT_INSTALL)
                return false;
            auto& deps = req->GetModInfo()->dependencies;
            return std::ranges::find_if(deps, [&](const ModInfo::Dependency& dep) { return dep.id == id; }) !=
                   deps.end();
        }) == requests.end())
    {
        return false;
    }

    return true;
}