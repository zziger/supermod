#pragma once
#include "BaseLoader.h"
#include <unordered_map>

namespace modloader {
    class SoundLoader : public BaseLoader {
        static inline std::unordered_map<std::string, void*> soundMemory{};

        bool Load(const std::filesystem::path& path) override;

        [[nodiscard]] std::vector<std::string> GetExtensions() const override
        {
            return { ".ogg" };
        }
    };
}
