#pragma once
#include <filesystem>
#include <string>

#include <thirdparty/directx/d3d8.h>
#include <yaml-cpp/node/node.h>

#include "thirdparty/LuaContext.h"
#include <semver.hpp>


struct ModInfo {
    std::string id;
    std::string title;
    std::string author;
    std::string version;
    std::string description;
    semver::version sdkVersion;
    std::filesystem::path basePath;
    std::string luaScript;
    std::optional<std::filesystem::path> zipFile; // used only for zipmod installation
    std::string zipRoot = ""; // used only for zipmod installation
    std::vector<uint64_t> gameVersions {}; // empty if no version restrictions
    std::map<std::string, std::string> socialLinks {}; // social icons
    bool compatible = true;

    bool hasIcon = false;
    std::vector<byte> iconData {};
    uint32_t iconWidth = 0;
    uint32_t iconHeight = 0;
    LPDIRECT3DTEXTURE8 icon = nullptr;
    
    HMODULE dll = nullptr;
    bool internal = false;

    void ReadManifest(YAML::Node node);
    void ReadManifest();
    void ReadIcon();
    
    void EnsureIcon();
    void ReleaseIcon();
    
    ModInfo();
    
    explicit ModInfo(const std::string& manifestContent);
    explicit ModInfo(std::filesystem::path modPath);
    
    explicit ModInfo(std::string id, std::string title, std::string description, std::string author, std::string version);

    std::string ToString() const {
        return std::format("Mod<{}>", id);
    }
    
    void RegisterLuaType(LuaContext* ctx) {
        if (ctx->isTypeRegistered<ModInfo>()) return;
        ctx->registerConstMember("id", &ModInfo::id);
        ctx->registerConstMember("title", &ModInfo::title);
        ctx->registerConstMember("description", &ModInfo::description);
        ctx->registerConstMember("author", &ModInfo::author);
        ctx->registerConstMember("version", &ModInfo::version);
        ctx->registerConstMember("basePath", &ModInfo::basePath);
        ctx->registerConstMember("luaScript", &ModInfo::luaScript);
        ctx->registerConstMember("gameVersions", &ModInfo::gameVersions);
        ctx->registerConstMember("compatible", &ModInfo::compatible);
        ctx->registerConstMember("internal", &ModInfo::internal);
        ctx->registerToStringFunction(&ModInfo::ToString);
        // todo icon
    }
};
