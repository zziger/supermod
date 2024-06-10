#pragma once
#include <supermod/pch.hpp>

#include "BaseLoader.hpp"

namespace sm::modloader
{
class SoundLoader final : public BaseLoader
{
    bool Load(const std::filesystem::path& path) override;

    [[nodiscard]] std::vector<std::string> GetExtensions() const override { return {".ogg"}; }
};
} // namespace sm::modloader
