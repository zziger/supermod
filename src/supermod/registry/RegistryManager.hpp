#pragma once
#include <supermod/pch.hpp>

#include <async/awaitable_get.h>
#include <async/task.h>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <semver/semver.hpp>
#include <supermod/modloader/mod/info/ModInfoRegistry.hpp>

#define API_URL "https://supermod.zziger.me/api/v1/"

namespace sm::registry
{
class RegistryManager
{
public:
    struct User
    {
        enum Role
        {
            USER,
            TRUSTED,
            ADMIN
        };

        explicit User(nlohmann::json json);

        int id;
        std::string name;
        Role role;
    };

    struct EntryVersion
    {
        explicit EntryVersion(nlohmann::json json);

        semver::version version;
        bool prerelease;
        bool verified;
    };

    struct Entry
    {
        explicit Entry(nlohmann::json json);

        std::string id;
        semver::version latestVersionValue;
        std::vector<EntryVersion> versions;
        modloader::ModInfoRegistry latestVersion;
        User uploader;
    };

    static void Initialize();
    static async::task<void> AuthorizeWithDiscord();
    static void Logout(bool invalidateToken = true);

    static std::optional<User> GetUser() { return user; }
    static bool IsAuthorizing() { return authorizing; }
    static void CancelAuth() { authStopSource.request_stop(); }

    static async::task<void> FetchEntries();
    static std::map<std::string, Entry>& GetEntries() { return entries; }
    static bool CanManageMod(const Entry& entry)
    {
        if (!user)
            return false;
        return user->role == User::ADMIN || user->id == entry.uploader.id;
    }

    static cpr::Bearer GetBearer();

private:
    static inline std::atomic_bool authorizing = false;
    static inline std::stop_source authStopSource;

    static inline std::shared_ptr<game::OwnedAsset> atlasTexture;
    static inline std::string token;
    static inline std::optional<User> user;
    static inline std::map<std::string, Entry> entries;

    static async::task<void> FetchUser();
    static void SaveToken();

    static constexpr std::string_view SESSION_FILENAME = "supermod-session.json";
};
} // namespace sm::registry