#pragma once
#include <supermod/pch.hpp>

#include "BaseLoader.hpp"

namespace sm::modloader
{
class TextureLoader final : public BaseLoader
{
    bool Load(const std::filesystem::path& path) override;

    [[nodiscard]] std::vector<std::string> GetExtensions() const override { return {".jpg", ".jpeg", ".png", ".tga"}; }
};
} // namespace sm::modloader