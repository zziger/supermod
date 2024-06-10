﻿#pragma once
#include <supermod/pch.hpp>

#include <d3d8/d3d8helpers.h>
#include <lodepng.h>
#include <supermod/game/textures/TextureLoader.hpp>
#include <supermod/game/DirectX.hpp>
#include <tga.h>

namespace sm::game::loaders
{
class PngLoader
{

public:
    static std::optional<std::vector<byte>> ReadPng(std::filesystem::path path, vector2ui& size)
    {
        std::vector<uint8_t> buf;
        uint32_t width, height;

        const auto readRes = lodepng::decode(buf, width, height, path.string());
        if (readRes != 0)
        {
            return {};
        }

        size = {width, height};

        return buf;
    }

    static LPDIRECT3DTEXTURE8 LoadPng(std::filesystem::path path, vector2ui& size, vector2 canvasSizeMultiplier)
    {
        size = {256, 256};

        auto textureData = ReadPng(path, size);
        if (!textureData)
        {
            return nullptr;
        }

        return TextureLoader::LoadFromRgbaPixelData(*game::DirectX::d3dDevice, size, canvasSizeMultiplier,
                                                    textureData->data());
    }

    static LPDIRECT3DTEXTURE8 LoadPngBuf(const std::vector<byte>& inBuf, vector2ui& size, vector2 canvasSizeMultiplier)
    {
        size = {256, 256};

        std::vector<uint8_t> buf;
        uint32_t width, height;

        const auto readRes = lodepng::decode(buf, width, height, inBuf);
        if (readRes != 0)
        {
            return nullptr;
        }

        size = {width, height};

        return TextureLoader::LoadFromRgbaPixelData(*game::DirectX::d3dDevice, size, canvasSizeMultiplier, buf.data());
    }
};
} // namespace sm::game::loaders