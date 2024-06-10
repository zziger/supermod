#pragma once
#include <filesystem>

namespace sm::modloader
{
class BaseLoader
{
public:
    virtual ~BaseLoader() = default;

    virtual bool Load(const std::filesystem::path& path) = 0;
    [[nodiscard]] virtual std::vector<std::string> GetExtensions() const = 0;
};
} // namespace sm::modloader