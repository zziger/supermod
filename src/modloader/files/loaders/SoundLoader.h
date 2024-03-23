#pragma once
#include "BaseLoader.h"
#include <unordered_map>

namespace modloader {
    class SoundLoader final : public BaseLoader {
        bool Load(const std::filesystem::path& path) override;

        [[nodiscard]] std::vector<std::string> GetExtensions() const override
        {
            return { ".ogg" };
        }
    };
}
