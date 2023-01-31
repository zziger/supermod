#pragma once
#include <filesystem>
#include <string>

#include <thirdparty/directx/d3d8.h>

#include "thirdparty/LuaContext.h"
#include "thirdparty/semver.hpp"


struct ModInfo {
    std::string id;
    std::string title;
    std::string author;
    std::string version;
    semver::version sdkVersion;
    std::filesystem::path basePath;
    std::string luaScript;
    std::vector<uint64_t> gameVersions {}; // empty if no version restrictions
    bool compatible = true;
    LPDIRECT3DTEXTURE8 icon = nullptr; // nullptr if no icon
    HMODULE dll = nullptr;
    bool internal = false;

    void ReadManifest();
    bool ReadIcon();
    
    ModInfo();
    
    explicit ModInfo(std::filesystem::path modPath);
    
    explicit ModInfo(std::string id, std::string title, std::string author, std::string version);

    std::string ToString() const {
        return std::format("Mod<{}>", id);
    }
    
    void RegisterLuaType(LuaContext* ctx) {
        if (ctx->isTypeRegistered<ModInfo>()) return;
        ctx->registerConstMember("id", &ModInfo::id);
        ctx->registerConstMember("title", &ModInfo::title);
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
