#include "RegistryManager.hpp"

#include <basen.hpp>
#include <nlohmann/json.hpp>
#include <supermod/Utils.hpp>
#include <supermod/game/Game.hpp>
#include <supermod/game/textures/PngLoader.hpp>
#include <supermod/io/Async.hpp>
#include <supermod/io/Http.hpp>
#include <supermod/modloader/mod/info/ModInfoRegistry.hpp>
#include <supermod/pch.hpp>
#include <supermod/registry/RegistryManager.hpp>
#include <supermod/ui/NotificationManager.hpp>

sm::registry::RegistryManager::User::User(nlohmann::json json)
{
    id = json["id"].get<int>();
    name = json["name"].get<std::string>();
    const auto roleStr = json["role"].get<std::string>();
    if (roleStr == "ADMIN")
        role = ADMIN;
    else if (roleStr == "TRUSTED")
        role = TRUSTED;
    else
        role = USER;
}

sm::registry::RegistryManager::EntryVersion::EntryVersion(const std::string& modId, nlohmann::json json)
{
    this->modId = modId;
    version = semver::version::parse(json["version"].get<std::string>(), false);
    prerelease = json["prerelease"].get<bool>();
    verified = json["verified"].get<bool>();
}

async::task<bool> sm::registry::RegistryManager::EntryVersion::SetVerified(const bool verified)
{
    auto versionStr = version.str();
    auto modIdStr = modId;
    try
    {
        const auto jsonBody = std::string("{\"verified\":") + (verified ? "true" : "false") + "}";
        co_await io::Http::Patch(cpr::Url{API_URL "mods/" + modId + "/versions/" + version.str()}, cpr::Body{jsonBody},
                                 cpr::Header{{"Content-Type", "application/json"}}, GetBearer());
        this->verified = verified;
        co_await FetchEntries();
    }
    catch (std::exception& e)
    {
        ui::NotificationManager::Notify(
            std::format("Не удалось изменить мод {}/{}: {}", modIdStr, versionStr, e.what()));
        co_return false;
    }

    co_return true;
}

sm::registry::RegistryManager::Entry::Entry(nlohmann::json json) : uploader(json["uploader"])
{
    spdlog::trace("is it {}", json.dump(4));
    id = json["id"].get<std::string>();
    latestVersionValue = semver::version::parse(json["latestVersionValue"].get<std::string>(), false);
    for (const auto& version : json["versions"])
        versions.push_back(std::make_shared<EntryVersion>(id, version));
    latestVersion = {};
    latestVersion.FromJson(json["latestVersion"]);
}

async::task<bool> sm::registry::RegistryManager::Entry::SetUploaderId(int newUploader)
{
    auto modIdStr = id;

    try
    {
        const auto jsonBody = nlohmann::json::object({{"uploaderId", newUploader}}).dump();
        co_await io::Http::Patch(cpr::Url{API_URL "mods/" + id}, cpr::Body{jsonBody},
                                 cpr::Header{{"Content-Type", "application/json"}}, GetBearer());
        co_await FetchEntries();
    }
    catch (std::exception& e)
    {
        ui::NotificationManager::Notify(std::format("Не удалось изменить мод {}: {}", id, e.what()));
        co_return false;
    }

    co_return true;
}

void sm::registry::RegistryManager::Initialize()
{
    token = "";
    if (exists(game::Game::GetAppdataPath() / SESSION_FILENAME))
    {
        std::ifstream file(game::Game::GetAppdataPath() / SESSION_FILENAME);
        nlohmann::json json;
        file >> json;
        {
            if (json["token"].is_string())
                token = json["token"];
        }
    }

    if (!token.empty())
    {
        async::awaitable_then(FetchUser(), [](async::awaitable_result<void> result) {
            try
            {
                result();
            }
            catch (NetworkError& e)
            {
                if (e.statusCode == NetworkError::UNAUTHORIZED)
                    io::Async::Schedule([] { Logout(false); });
            }
        });

        FetchEntries();
    }
}

async::task<void> sm::registry::RegistryManager::AuthorizeWithDiscord()
{
    assert(io::Async::IsMainThread());

    if (authorizing)
        co_return;

    authorizing = true;
    authStopSource = {};
    const auto stopToken = authStopSource.get_token();

    try
    {
        auto [authRequestInfo, _] = co_await io::Http::PostJson(cpr::Url{API_URL "auth/discord"});
        utils::open_url(authRequestInfo["url"].get<std::string>());

        const auto infoUrl = cpr::Url{API_URL "auth/discord/" + authRequestInfo["state"].get<std::string>()};
        const auto timeout = std::chrono::system_clock::now() + std::chrono::minutes(5);
        std::string newToken;

        while (std::chrono::system_clock::now() < timeout)
        {
            if (stopToken.stop_requested())
                throw Error("Authorization cancelled");

            auto [authInfo, _] = co_await io::Http::GetJson(infoUrl);
            if (authInfo["token"].is_string())
            {
                newToken = authInfo["token"].get<std::string>();
                break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        spdlog::info("got token {}", newToken);

        co_await io::Async::ToMain();
        token = newToken;
        SaveToken();
        co_await FetchUser();
    }
    catch (std::exception& e)
    {
        spdlog::error("Failed to authorize with discord: {}", e.what());
        authorizing = false;
        throw;
    }

    authorizing = false;

    FetchEntries();

    co_return;
}

void sm::registry::RegistryManager::Logout(bool invalidateToken)
{
    if (invalidateToken && !token.empty())
    {
        io::Http::Get(cpr::Url{API_URL "auth/logout"}, GetBearer()); // ignore errors
    }

    token = "";
    user = std::nullopt;
    SaveToken();
    FetchEntries();
}

async::task<void> sm::registry::RegistryManager::FetchEntries()
{
    try
    {
        auto [data, _] = co_await io::Http::GetJson(cpr::Url{API_URL "mods"}, GetBearer());
        auto [atlasData, __] = co_await io::Http::GetJson(cpr::Url{API_URL "atlas"}, GetBearer());

        auto imageStr = atlasData["image"]["data"].get<std::string>();
        if (imageStr.starts_with("data:image/png;base64,"))
            imageStr = imageStr.substr(22);

        std::vector<byte> decoded;
        bn::decode_b64(imageStr.begin(), imageStr.end(), std::back_inserter(decoded));

        co_await io::Async::ToMain();

        auto size =
            vector2ui{atlasData["image"]["width"].get<uint32_t>(), atlasData["image"]["height"].get<uint32_t>()};
        const auto tex = game::loaders::PngLoader::LoadPngBuf(decoded, size, {1, 1});
        const auto asset = game::AssetPool::Instance()->LoadAsset(
            tex, game::AssetPool::Instance()->MakeAssetKeyUnique("$builtin:registry_atlas"), true, size);
        atlasTexture = game::AssetPool::Instance()->MakeOwned(asset);

        std::map<std::string, Entry> newEntries;
        for (const auto& entry : data)
        {
            auto entryInstance = Entry(entry);
            if (atlasData["icons"].contains(entryInstance.id))
            {
                auto atlasEntry = atlasData["icons"][entryInstance.id];
                entryInstance.latestVersion.icon = {atlasTexture,
                                                    {atlasEntry[0].get<float>(), atlasEntry[1].get<float>(),
                                                     atlasEntry[2].get<float>(), atlasEntry[3].get<float>()}};
            }
            newEntries.insert_or_assign(entryInstance.id, entryInstance);
        }

        entries = std::move(newEntries);
    }
    catch (std::exception& e)
    {
        spdlog::error("Failed to fetch entries: {}", e.what());
    }

    co_return;
}

cpr::Bearer sm::registry::RegistryManager::GetBearer()
{
    return cpr::Bearer{token};
}

async::task<void> sm::registry::RegistryManager::FetchUser()
{
    try
    {
        auto [data, _] = co_await io::Http::GetJson(cpr::Url{API_URL "me"}, GetBearer());
        spdlog::info("{}", data.dump(4));
        user = User(data["user"]);
    }
    catch (std::exception& e)
    {
        spdlog::error("Failed to fetch user: {}", e.what());
        user = std::nullopt;
    }
}

void sm::registry::RegistryManager::SaveToken()
{
    const auto path = game::Game::GetAppdataPath() / SESSION_FILENAME;
    if (token.empty())
    {
        if (exists(path))
            remove(path);
    }
    else
    {
        std::ofstream file(game::Game::GetAppdataPath() / SESSION_FILENAME);
        nlohmann::json json;
        json["token"] = token;
        file << json.dump();
    }
}