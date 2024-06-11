#pragma once
#include <supermod/pch.hpp>

#include <nlohmann/json.hpp>
#include <supermod/modloader/mod/info/ModInfo.hpp>

namespace sm::modloader
{
struct ModInfoRegistry final : ModInfo
{
    bool verified = true;
    bool prerelease = false;

    void FromJson(const nlohmann::json& json);
};
} // namespace sm::modloader
