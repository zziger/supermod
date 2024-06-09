#include "UpdateManager.h"

#include <Config.h>
#include <imgui.h>
#include <nlohmann/json.hpp>
#include <sdk/Game.h>
#include <semver/semver.hpp>
#include <spdlog/spdlog.h>
#include <ui/NotificationManager.h>
#include <ui/styles/styles.h>
#include <ui/widgets/widgets.h>
#include <utils/TempManager.h>

std::optional<UpdateManager::AvailableUpdate> UpdateManager::GetAvailableUpdate()
{
    std::lock_guard lock(mutex);
    return availableUpdate;
}

UpdateManager::UpdateState UpdateManager::GetUpdateState()
{
    std::lock_guard lock(mutex);
    return state;
}

void UpdateManager::CheckForUpdates()
{
    std::lock_guard lock(mutex);
    if (state.stage != UpdateState::IDLE && state.stage != UpdateState::FAILED &&
        state.stage != UpdateState::UPDATE_AVAILABLE)
        return;

    state.stage = UpdateState::CHECKING;
    std::thread([] { CheckForUpdatesSync(); }).detach();
}

void UpdateManager::DownloadUpdate()
{
    std::lock_guard lock(mutex);
    if (state.stage != UpdateState::UPDATE_AVAILABLE)
        return;

    state.stage = UpdateState::DOWNLOADING;
    state.progress = 0.0f;
    std::thread([] { DownloadUpdateSync(); }).detach();
}

bool UpdateManager::CheckForUpdatesSync()
{
    // TODO: dont check on local builds
    try
    {
        auto prerelease = Config::Get().updater.usePrerelease;
        cpr::Response r = cpr::Get(cpr::Url{std::string("https://api.github.com/repos/zziger/supercow-mod/releases") +
                                            (prerelease ? "?per_page=1" : "/latest")});
        if (r.status_code == 200)
        {
            // Parse JSON
            nlohmann::json j = nlohmann::json::parse(r.text);
            if (prerelease)
                j = j[0];
            semver::version latestVersion = semver::version::parse(j["tag_name"]);
            semver::version currentVersion = semver::version::parse(SUPERMOD_VERSION);

            std::lock_guard lock(mutex);

            state.stage = UpdateState::IDLE;

            if (latestVersion > currentVersion)
            {
                auto assets = j["assets"];
                for (auto& asset : assets)
                {
                    if (asset["name"].get<std::string>() != DLL_NAME)
                        continue;
                    availableUpdate =
                        AvailableUpdate{latestVersion, j["assets"][0]["browser_download_url"].get<std::string>()};
                    state.stage = UpdateState::UPDATE_AVAILABLE;
                    ui::NotificationManager::Notify("Доступна новая версия: " + latestVersion.str(),
                                                    ui::Notification::INFO, "Обновление SuperMod");
                }

                spdlog::error("Failed to find matching dll from latest release");
                throw std::runtime_error("Текущая версия SuperMod устарела. Скачайте новую версию с GitHub");
            }

            return true;
        }

        auto details = "";
        if (r.status_code == 404)
            details = "\nВероятно, версия SuperMod сильно устарела. Пожалуйста, загрузите новую версию с GitHub";
        if (r.status_code == 403 && r.header["X-Ratelimit-Remaining"] == "0")
        {
            using namespace std::chrono;
            auto timePoint = std::chrono::duration_cast<seconds>(
                system_clock::from_time_t(std::stoll(r.header["X-Ratelimit-Reset"])) - system_clock::now());
            details =
                std::format("\nВы проверяете обновления слишком часто. Повторите попытку через {:%H:%M:%S}", timePoint)
                    .c_str();
        }
        throw std::runtime_error("HTTP " + std::to_string(r.status_code) + details);
    }
    catch (std::exception& e)
    {
        spdlog::error("Failed to check for updates: " + std::string(e.what()));
        std::lock_guard lock(mutex);
        state.stage = UpdateState::FAILED;
        state.message = e.what();
        return false;
    }
}

bool UpdateManager::DownloadUpdateSync()
{
    auto availableUpdate = GetAvailableUpdate();
    assert(availableUpdate && "DownloadUpdateSync called but no update available object was found");

    auto temp = TempManager::GetTempDir(true);
    std::ofstream file(temp / "update.dll", std::ios::binary);

    try
    {
        cpr::Response r = Download(
            file, cpr::Url{availableUpdate->downloadUrl},
            cpr::ProgressCallback([&](cpr::cpr_off_t downloadTotal, cpr::cpr_off_t downloadNow,
                                      cpr::cpr_off_t uploadTotal, cpr::cpr_off_t uploadNow, intptr_t userdata) -> bool {
                std::lock_guard lock(mutex);
                state.progress = static_cast<float>(downloadNow) / static_cast<float>(downloadTotal);
                return true;
            }));

        if (r.status_code == 200)
        {
            {
                std::lock_guard lock(mutex);
                state.stage = UpdateState::INSTALLING;
            }

            file.close();
            InstallUpdate(temp);
            return true;
        }

        throw std::runtime_error("HTTP " + std::to_string(r.status_code));
    }
    catch (std::exception& e)
    {
        ui::NotificationManager::Notify(std::string("Не удалось загрузить обновление: ") + e.what());
        spdlog::error("Failed to download update: " + std::string(e.what()));
        std::lock_guard lock(mutex);
        state.stage = UpdateState::FAILED;
        state.message = e.what();
        return false;
    }
}

void UpdateManager::InstallUpdate(const std::filesystem::path& tempPath)
{
    auto newDll = tempPath / "update.dll";
    auto backupDll = tempPath / "backup.dll";
    auto oldDll = utils::get_module_name();
    assert(std::filesystem::exists(newDll) && "InstallUpdate called but no update file was found");

    std::filesystem::rename(oldDll, backupDll);
    try
    {
        std::filesystem::rename(newDll, oldDll);

        {
            std::lock_guard lock(mutex);
            state.stage = UpdateState::RESTART_REQUIRED;
        }
    }
    catch (std::exception& e)
    {
        std::filesystem::rename(backupDll, oldDll);
        ui::NotificationManager::Notify(std::string("Не удалось установить обновление: ") + e.what());
        spdlog::error("Failed to install update: " + std::string(e.what()));
        std::lock_guard lock(mutex);
        state.stage = UpdateState::FAILED;
        state.message = e.what();
    }
}

void UpdateManager::RenderMessage()
{
    auto updateState = GetUpdateState();

    switch (updateState.stage)
    {
    case UpdateState::FAILED:
        ui::styles::danger::PanelText(std::format("Ошибка при проверке обновлений: {}", updateState.message).c_str());
        ImGui::Spacing();
        if (ImGui::Button("Проверить обновления"))
            CheckForUpdates();
        break;

    case UpdateState::IDLE:
        ImGui::Text("Новых обновлений не найдено. Текущая версия: %s", SUPERMOD_VERSION);
        ImGui::Spacing();
        if (ImGui::Button("Проверить обновления"))
            CheckForUpdates();
        break;

    case UpdateState::CHECKING:
        ImGui::Text("Проверка обновлений...");
        ImGui::Spacing();
        ui::widgets::ProgressBar(static_cast<float>(ImGui::GetTime()) * -0.5f);
        break;

    case UpdateState::UPDATE_AVAILABLE: {
        auto availableUpdate = GetAvailableUpdate();
        assert(availableUpdate && "State was UPDATE_AVAILABLE but no update available object was found");
        if (availableUpdate)
        {
            ImGui::Text("Доступно новое обновление: %s", availableUpdate->newVersion.str().c_str());
            ImGui::Spacing();
            if (ImGui::Button("Обновить"))
                DownloadUpdate();
            ImGui::SameLine();
            if (ImGui::Button("Проверить обновления"))
                CheckForUpdates();
        }
        break;
    }

    case UpdateState::DOWNLOADING: {
        ImGui::Text("Загрузка обновления...");
        ImGui::Spacing();
        ui::widgets::ProgressBar(updateState.progress < 0 ? static_cast<float>(ImGui::GetTime()) * -0.5f
                                                          : updateState.progress);
        break;
    }

    case UpdateState::INSTALLING: {
        ImGui::Text("Установка обновления...");
        ImGui::Spacing();
        ui::widgets::ProgressBar(static_cast<float>(ImGui::GetTime()) * -0.5f);
        break;
    }

    case UpdateState::RESTART_REQUIRED: {
        ImGui::Text("Обновление установлено, нужен перезапуск игры");
        ImGui::Spacing();
        if (ImGui::Button("Перезапустить игру"))
            sdk::Game::Restart();

        break;
    }
    }
}