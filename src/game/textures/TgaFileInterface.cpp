#include "TgaFileInterface.h"

TgaFileInterface::TgaFileInterface(const std::filesystem::path& path)
{
    if (fopen_s(&file, path.string().c_str(), "rb"))
        isOk = false;
}

TgaFileInterface::~TgaFileInterface()
{
    if (file)
    {
        fclose(file);
        file = nullptr;
    }
}

bool TgaFileInterface::ok() const
{
    return isOk;
}

size_t TgaFileInterface::tell()
{
    return ftell(file);
}

void TgaFileInterface::seek(const size_t absPos)
{
    fseek(file, static_cast<long>(absPos), SEEK_SET);
}

uint8_t TgaFileInterface::read8()
{
    const int value = fgetc(file);
    if (value != EOF)
    {
        return static_cast<uint8_t>(value);
    }

    isOk = false;
    return 0;
}

void TgaFileInterface::write8(const uint8_t value)
{
  fputc(value, file);
}
