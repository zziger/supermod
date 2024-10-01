#include "ModManager.hpp"

#include <supermod/io/Async.hpp>
#include <supermod/io/Http.hpp>
#include <supermod/io/TempManager.hpp>
#include <supermod/modloader/ModPublisher.hpp>
#include <supermod/registry/RegistryManager.hpp>
#include <supermod/ui/NotificationManager.hpp>
#include <supermod/ui/windows/main_views/views.hpp>
#include <supermod/ui/windows/windows.hpp>

async::task<void> sm::modloader::ModPublisher::Publish(const std::shared_ptr<Mod>& mod)
{
    auto id = mod->GetID();
    auto fsInfo = std::dynamic_pointer_cast<ModInfoFilesystem>(mod->GetInfo());
    if (fsInfo == nullptr)
    {
        ui::NotificationManager::Notify(std::format("Не удалось опубликовать мод {}: Неверный тип мода", mod->GetID()));
    }

    publishing = true;
    publishProgress = 0.0f;

    try
    {
        auto tempDir = io::TempManager::GetTempDir();
        auto zipPath = tempDir / "mod.zip";
        co_await ModManager::PackMod(fsInfo, zipPath);
        publishProgress = 0.1f;

        co_await io::Http::Post(
            cpr::Url{API_URL "upload"}, cpr::Body{cpr::File{zipPath.string()}}, registry::RegistryManager::GetBearer(),
            cpr::ProgressCallback([](cpr::cpr_off_t downloadTotal, cpr::cpr_off_t downloadNow,
                                     cpr::cpr_off_t uploadTotal, cpr::cpr_off_t uploadNow, intptr_t userdata) -> bool {
                // Rescale values to have first 10% for the packing process
                publishProgress = static_cast<float>(uploadNow) / static_cast<float>(uploadTotal) * 0.9 + 0.1;
                return true;
            }));
        publishProgress = 1.0f;
        publishing = false;
        ui::NotificationManager::Notify("Мод опубликован успешно", ui::Notification::INFO);
        co_await io::Async::ToMain();
        ui::windows::WindowsState::publishModOpened = false;
        ui::windows::main::MainWindowState::currentView = ui::windows::main::REGISTRY;
        ui::windows::main::MainWindowState::activeRegistryMod = id;
        io::TempManager::RemoveTempDir(tempDir);
    }
    catch (NetworkError& e)
    {
        ui::NotificationManager::Notify(std::format("Не удалось опубликовать мод {}: {}", id, e.what()));
        spdlog::error(e.body);
    }
    catch (std::exception& e)
    {
        ui::NotificationManager::Notify(std::format("Не удалось опубликовать мод {}: {}", id, e.what()));
    }

    try
    {
        co_await registry::RegistryManager::FetchEntries();
    }
    catch (std::exception& e)
    {
        spdlog::error(e.what());
    }

    co_return;
}