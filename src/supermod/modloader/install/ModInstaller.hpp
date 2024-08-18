#pragma once
#include <supermod/io/Async.hpp>
#include <supermod/modloader/install/ModInstallRequest.hpp>
#include <supermod/modloader/install/ZipModDropTarget.hpp>
#include <supermod/modloader/install/provider/ModSourceProvider.hpp>
#include <supermod/ui/NotificationManager.hpp>
#include <vector>

namespace sm::modloader
{
class ModInstaller
{
    static inline std::vector<std::shared_ptr<ModInstallRequest>> requests{};
    static inline std::vector<std::shared_ptr<ModInstallRequest>> candidateRequests{};
    static inline std::vector<std::shared_ptr<ModSourceProvider>> providers{};
    static inline std::stop_source stopSource{};
    static inline ZipModDropTarget dropTarget{};

    static inline std::atomic_bool installing = false;
    static inline std::atomic_int installingCurrentRequest = 0;

public:
    static inline std::vector<std::string> providerErrors{};

    static ZipModDropTarget& GetDropTarget() { return dropTarget; }

    static bool IsInstallerActive() { return !requests.empty() || !providers.empty(); }
    static bool IsInstalling() { return installing; }

    static std::vector<std::shared_ptr<ModSourceProvider>>& GetProviders() { return providers; }
    static std::vector<std::shared_ptr<ModInstallRequest>>& GetRequests() { return requests; }
    static std::vector<std::shared_ptr<ModInstallRequest>>& GetCandidateRequests() { return candidateRequests; }

    static int GetCurrentInstallingRequestIndex() { return installingCurrentRequest; }
    static std::shared_ptr<ModInstallRequest> GetCurrentInstallingRequest()
    {
        if (candidateRequests.empty() || installingCurrentRequest < 0 ||
            installingCurrentRequest >= candidateRequests.size())
            return nullptr;
        return candidateRequests[installingCurrentRequest];
    }

    static void UpdateCandidates()
    {
        candidateRequests.clear();
        for (auto& request : requests)
        {
            request->Update();
        }
        for (auto& request : requests)
        {
            if (!request->IsCandidate())
                continue;
            candidateRequests.push_back(request);
        }
    }

    static std::shared_ptr<ModInstallRequest> GetRequest(const std::string& modId, bool direct)
    {
        const auto existing = std::ranges::find_if(
            requests, [&](const std::shared_ptr<ModInstallRequest>& req) { return req->id == modId; });

        if (existing != requests.end())
        {
            if (direct)
                (*existing)->addedDirectly = true;
            return *existing;
        }

        auto newRequest = std::make_shared<ModInstallRequest>(modId, direct);
        requests.push_back(newRequest);
        return newRequest;
    }

    static async::task<void> AddProviders(const std::initializer_list<std::shared_ptr<ModSourceProvider>>& newProviders)
    {
        try
        {
            for (auto& provider : newProviders)
                providers.push_back(provider);
            stopSource = std::stop_source{};
            for (auto& provider : newProviders)
            {
                try
                {
                    co_await provider->DiscoverMods(stopSource.get_token());
                }
                catch (std::exception& e)
                {
                    providerErrors.push_back("Произошла ошибка при добавлении модов из " + provider->GetName() +
                                             ": \n" + e.what());
                }
            }
            co_await io::Async::ToMain();
            UpdateCandidates();
        }
        catch (std::exception& e)
        {
            providerErrors.emplace_back(e.what());
        }
        co_return;
    }

    static async::task<void> AddProvider(const std::shared_ptr<ModSourceProvider>& newProvider)
    {
        try
        {
            providers.push_back(newProvider);
            stopSource = std::stop_source{};
            try
            {
                co_await newProvider->DiscoverMods(stopSource.get_token());
            }
            catch (std::exception& e)
            {
                providerErrors.push_back("Произошла ошибка при добавлении модов из " + newProvider->GetName() + ": \n" +
                                         e.what());
            }
            co_await io::Async::ToMain();
            UpdateCandidates();
        }
        catch (std::exception& e)
        {
            providerErrors.emplace_back(e.what());
        }
        co_return;
    }

    static async::task<void> Install()
    {
        installing = true;
        installingCurrentRequest = 0;

        UpdateCandidates();
        try
        {
            for (int i = 0; i < candidateRequests.size(); i++)
            {
                installingCurrentRequest = i;
                auto source = candidateRequests[i]->GetActiveSource();
                if (source == nullptr)
                    continue;
                co_await source->Install();
            }
        }
        catch (std::exception& e)
        {
            installing = false;
            ui::NotificationManager::Notify("Ошибка при установке модов: " + std::string(e.what()));
        }
        catch (...)
        {
            installing = false;
            ui::NotificationManager::Notify("Неизвестная ошибка при установке модов");
        }

        Reset();

        installing = false;
    }

    static void Reset()
    {
        providers.clear();
        requests.clear();
        candidateRequests.clear();
        providerErrors.clear();
        stopSource.request_stop();
    }
    static std::shared_ptr<Mod> InstallMod(const std::shared_ptr<ModInfo>& info, const std::filesystem::path& path);

    static void Init();
};
} // namespace sm::modloader