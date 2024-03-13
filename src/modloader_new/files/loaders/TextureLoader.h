#pragma once
#include "BaseLoader.h"

namespace modloader {
    class TextureLoader final : public BaseLoader {
        bool Load(const std::filesystem::path& path) override;
        [[nodiscard]] std::vector<std::string> GetExtensions() const override;
    };
}