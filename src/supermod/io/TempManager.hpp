#pragma once
#include <supermod/pch.hpp>

#include <random>

namespace sm::io
{
class TempManager
{
    static inline std::mt19937 rand{}; // NOLINT(*-msc51-cpp)

    static std::filesystem::path GetTempRoot();

public:
    static constexpr std::string_view TEMP_DIR = "temp";
    static constexpr int TEMP_LENGTH = 8;

    static void Init();

    static std::filesystem::path GetTempDir(bool create = true);

    static void RemoveTempDir(const std::filesystem::path& path);

    static void Cleanup();
};
} // namespace sm::io