#pragma once
#include <supermod/pch.hpp>

#include <tga.h>

namespace sm::game::loaders
{
class TgaFileInterface final : public tga::FileInterface
{
public:
    explicit TgaFileInterface(const std::filesystem::path& path);
    ~TgaFileInterface() override;

    [[nodiscard]] bool ok() const override;
    size_t tell() override;
    void seek(size_t absPos) override;
    uint8_t read8() override;
    void write8(uint8_t value) override;

private:
    bool isOk = true;
    FILE* file = nullptr;
};
} // namespace sm::game::loaders