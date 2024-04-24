#include <cpr/cpr.h>
#include <semver/semver.hpp>

class UpdateManager {
public:
    struct AvailableUpdate
    {
        semver::version newVersion;
        std::string downloadUrl;
    };

    struct UpdateState
    {
        enum Stage
        {
            IDLE,
            FAILED,
            CHECKING,
            UPDATE_AVAILABLE,
            DOWNLOADING,
            INSTALLING,
            RESTART_REQUIRED
        };

        Stage stage = IDLE;
        float progress = 0.0f;
        std::string message;
    };

private:
    static inline std::mutex mutex;
    static inline std::optional<AvailableUpdate> availableUpdate = std::nullopt;
    static inline UpdateState state;

    static bool CheckForUpdatesSync();
    static bool DownloadUpdateSync();
    static void InstallUpdate(const std::filesystem::path& tempPath);

public:
    static std::optional<AvailableUpdate> GetAvailableUpdate();
    static UpdateState GetUpdateState();
    static void CheckForUpdates();
    static void DownloadUpdate();
    static void RenderMessage();
    static void RenderPopup();
};
