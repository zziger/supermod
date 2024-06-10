#pragma once
#include <supermod/pch.hpp>

#include <d3d8/d3d8helpers.h>
#include <supermod/game/textures/TextureLoader.hpp>
#include <supermod/game/textures/TgaFileInterface.hpp>
#include <supermod/game/DirectX.hpp>
#include <tga.h>

namespace sm::game::loaders
{
class TgaLoader
{

public:
    static std::optional<std::vector<byte>> ReadTga(const std::filesystem::path& path, vector2ui& size)
    {
        TgaFileInterface file(path);
        if (!file.ok())
            return {};

        tga::Decoder decoder(&file);
        tga::Header header;
        if (!decoder.readHeader(header))
            return {};

        size = {header.width, header.height};

        tga::Image image;
        image.bytesPerPixel = header.bytesPerPixel();
        image.rowstride = header.width * header.bytesPerPixel();

        std::vector<byte> buffer(image.rowstride * header.height);
        image.pixels = &buffer[0];

        if (!decoder.readImage(header, image, nullptr))
            return {};

        // Optional post-process to fix the alpha channel in
        // some TGA files where alpha=0 for all pixels when
        // it shouldn't.
        decoder.postProcessImage(header, image);

        auto bytesPerPixel = image.rowstride / header.width;

        if (bytesPerPixel == 3)
        {
            std::vector<byte> newBuffer(image.rowstride * header.height / 3 * 4);

            for (auto y = 0; y < header.height; y++)
            {
                for (auto x = 0; x < header.width; x++)
                {
                    newBuffer[y * header.width * 4 + x * 4] = buffer[y * header.width * 3 + x * 3];
                    newBuffer[y * header.width * 4 + x * 4 + 1] = buffer[y * header.width * 3 + x * 3 + 1];
                    newBuffer[y * header.width * 4 + x * 4 + 2] = buffer[y * header.width * 3 + x * 3 + 2];
                    newBuffer[y * header.width * 4 + x * 4 + 3] = 255;
                }
            }

            return newBuffer;
        }

        if (bytesPerPixel < 3)
        {
            spdlog::warn("Failed to load {}: TGA with less than 3 bytes per pixel is not supported", path.string());
            return {};
        }

        return buffer;
    }

    static LPDIRECT3DTEXTURE8 LoadTga(std::filesystem::path path, vector2ui& size, vector2 canvasSizeMultiplier)
    {
        size = {256, 256};

        auto textureData = ReadTga(path, size);
        if (!textureData)
        {
            return nullptr;
            // textureData = TextureLoader::GenerateUnknown(width, height);
        }

        return TextureLoader::LoadFromRgbaPixelData(*game::DirectX::d3dDevice, size, canvasSizeMultiplier,
                                                    textureData->data());
    }
};
} // namespace sm::game::loaders