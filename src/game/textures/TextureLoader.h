#pragma once
#include <cstdint>
#include <format>
#include <vector>

#include "Data.h"
#include "exceptions/Error.h"
#include <d3d8/d3d8helpers.h>

class TextureLoader
{
public:
    static LPDIRECT3DTEXTURE8 LoadFromRgbaPixelData(IDirect3DDevice8* device, vector2ui size,
                                                    vector2 canvasSizeMultiplier, const byte* buf)
    {
        vector2ui surfaceSize{static_cast<uint32_t>(std::round(static_cast<float>(size.x) * canvasSizeMultiplier.x)),
                              static_cast<uint32_t>(std::round(static_cast<float>(size.y) * canvasSizeMultiplier.y))};
        LPDIRECT3DTEXTURE8 sysmemTex = nullptr;
        const auto sysmemRes =
            device->CreateTexture(surfaceSize.x, surfaceSize.y, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, &sysmemTex);

        if (sysmemRes < 0)
            throw Error(std::format("Не удалось создать текстуру. Ошибка: {}", sysmemRes));
        if (sysmemTex == nullptr)
            throw Error("Не удалось создать текстуру");
        D3DLOCKED_RECT bits;

        if (FAILED(sysmemTex->LockRect(0, &bits, nullptr, 0)))
            throw Error("Не удалось создать текстуру. Ошибка: Не удалось заблокировать текстуру для записи");

        for (uint32_t y = 0; y < surfaceSize.y; y++)
        {
            const auto out = ((unsigned char*)bits.pBits + bits.Pitch * y);
            for (uint32_t x = 0; x < surfaceSize.x; x++)
            {
                if (x >= size.x || y >= size.y)
                {
                    out[x * 4 + 3] = 0;
                    out[x * 4 + 2] = 0;
                    out[x * 4 + 1] = 0;
                    out[x * 4 + 0] = 0;
                    continue;
                }

                out[x * 4 + 3] = buf[size.x * 4 * y + x * 4 + 3];
                out[x * 4 + 2] = buf[size.x * 4 * y + x * 4 + 0];
                out[x * 4 + 1] = buf[size.x * 4 * y + x * 4 + 1];
                out[x * 4 + 0] = buf[size.x * 4 * y + x * 4 + 2];
            }
        }

        if (FAILED(sysmemTex->UnlockRect(0)))
            throw Error("Не удалось создать текстуру. Ошибка: Не удалось разблокировать текстуру после записи");

        return sysmemTex;
    }

    static std::vector<byte> GenerateUnknown(const vector2ui size = {256, 256})
    {
        const auto width = size.x;
        const auto height = size.y;
        const auto halfWidth = width / 2;
        const auto halfHeight = height / 2;

        std::vector<byte> data(width * height * 4);

        for (uint32_t y = 0; y < height; y++)
        {
            for (uint32_t x = 0; x < width; x++)
            {
                const auto black = y >= halfHeight && x < halfWidth || y < halfHeight && x >= halfWidth;
                data[y * width * 4 + x * 4] = black ? 0 : 255;
                data[y * width * 4 + x * 4 + 1] = 0;
                data[y * width * 4 + x * 4 + 2] = black ? 0 : 255;
                data[y * width * 4 + x * 4 + 3] = 255;
            }
        }

        return data;
    }

    static LPDIRECT3DTEXTURE8 LoadUnknown(IDirect3DDevice8* device, vector2ui size, vector2 canvasSizeMultiplier)
    {
        const auto data = GenerateUnknown(size);
        return LoadFromRgbaPixelData(device, size, canvasSizeMultiplier, data.data());
    }
};
