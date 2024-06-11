#include <supermod/modloader/mod/info/ModInfoRegistry.hpp>
#include <supermod/pch.hpp>

void sm::modloader::ModInfoRegistry::FromJson(const nlohmann::json& json)
{
    id = json["modId"].get<std::string>();
    title = json["title"].is_string() ? json["title"].get<std::string>() : id;
    author = json["author"].is_string() ? json["author"].get<std::string>() : "unknown";
    version = semver::version::parse(json["version"].is_string() ? json["version"].get<std::string>() : "0.0.0", false);
    description = json["description"].is_string() ? json["description"].get<std::string>() : "";
    if (json["sdkVersion"].is_string())
        sdkVersion = semver::version::parse(json["sdkVersion"].get<std::string>(), false);
    verified = json["verified"].get<bool>();
    prerelease = json["prerelease"].get<bool>();
}