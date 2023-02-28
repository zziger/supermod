#include "DirectXUtils.h"

#include <format>
#include <vector>
#include <fstream>

#include "exceptions/Error.h"
#include <thirdparty/lodepng/lodepng.h>
#include <objidl.h>
#include <gdiplus.h>

#include "data.h"
#include "Log.h"
#include "Utils.h"
#include "thirdparty/nanojpeg.h"
#include <Shlwapi.h>

#include "events/EventManager.h"
#include "events/TickEvent.h"
#include "sdk/DirectX.h"
#include "sdk/Game.h"

namespace dx_utils
{
    LPDIRECT3DTEXTURE8 load_png(IDirect3DDevice8* device, const char* filename) {
        std::vector<uint8_t> buf;
        uint32_t width, height;

        const auto readRes = lodepng::decode(buf, width, height, filename);
        if (readRes != 0) throw Error("Не удалось прочитать файл " + std::string(filename));
        
        return load_argb_pixel_data(device, width, height, buf.data());
    }
    
    LPDIRECT3DTEXTURE8 load_png_data(IDirect3DDevice8* device, const byte* data, int32_t size) {
        std::vector<uint8_t> buf;
        uint32_t width, height;

        const auto readRes = lodepng::decode(buf, width, height, data, size);
        if (readRes != 0) throw Error("Не удалось прочитать PNG");

        return load_argb_pixel_data(device, width, height, buf.data());
    }
    
    LPDIRECT3DTEXTURE8 load_argb_pixel_data(IDirect3DDevice8* device, uint32_t width, uint32_t height, const byte* buf) {
        LPDIRECT3DTEXTURE8 texture = nullptr;
        const auto res = device->CreateTexture(width, height, 1, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &texture);

        if (res < 0) throw Error(std::format("Не удалось создать текстуру. Ошибка: {}", res));
        if (texture == nullptr) throw Error("Не удалось создать текстуру");
        D3DLOCKED_RECT bits;

        if (FAILED(texture->LockRect(0, &bits, nullptr, 0))) throw Error("Не удалось создать текстуру. Ошибка: Не удалось заблокировать текстуру для записи");

        for (uint32_t y = 0; y < height; y++)
        {
            const auto out = ((unsigned char *) bits.pBits + bits.Pitch * y);
            for (uint32_t x = 0; x < width; x++) {
                out[x * 4 + 3] = buf[width * 4 * y + x * 4 + 3];
                out[x * 4 + 2] = buf[width * 4 * y + x * 4 + 0];
                out[x * 4 + 1] = buf[width * 4 * y + x * 4 + 1];
                out[x * 4 + 0] = buf[width * 4 * y + x * 4 + 2];
            } 
        }
        
        if (FAILED(texture->UnlockRect(0))) throw Error("Не удалось создать текстуру. Ошибка: Не удалось разблокировать текстуру после записи");

        return texture;
    }

    LPDIRECT3DTEXTURE8 load_jpg(IDirect3DDevice8* device, const char* filename) {
        // std::vector<uint8_t> buf;

        std::ifstream fstream{ filename, std::ios::binary | std::ios::ate };
        int size = fstream.tellg();
        fstream.seekg(0, std::ios::beg);
        std::vector<char> buffer;
        buffer.resize(size);
        fstream.read(buffer.data(), size);


        const auto readRes = njDecode(buffer.data(), buffer.size());
        if (readRes != 0) throw Error(std::format("Не удалось прочитать файл {}. Ошибка: {}", filename, (int) readRes));

        uint32_t width = njGetWidth(), height = njGetHeight();
        auto buf = njGetImage();

        LPDIRECT3DTEXTURE8 texture = nullptr;
        const auto res = device->CreateTexture(width, height, 0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, &texture);

        if (res < 0) throw Error(std::format("Не удалось создать текстуру. Ошибка: {}", res));
        if (texture == nullptr) throw Error("Не удалось создать текстуру");
        D3DLOCKED_RECT bits;

        if (FAILED(texture->LockRect(0, &bits, nullptr, 0))) throw Error("Не удалось создать текстуру. Ошибка: Не удалось заблокировать текстуру для записи");

        for (uint32_t i = 0; i < width * height; i++) {
            const auto out = (uint8_t*) bits.pBits;
            out[i * 4 + 3] = 255;
            out[i * 4 + 2] = buf[i * 3 + 0];
            out[i * 4 + 1] = buf[i * 3 + 1];
            out[i * 4 + 0] = buf[i * 3 + 2];
        }

        if (FAILED(texture->UnlockRect(0))) throw Error("Не удалось создать текстуру. Ошибка: Не удалось разблокировать текстуру после записи");

        return texture;
    }

    Gdiplus::Bitmap* load_image_no_lock(const WCHAR* fileName) {
        using namespace Gdiplus;
        Bitmap src( fileName );
        if ( src.GetLastStatus() != Ok ) {
            return 0;
        }
        Bitmap *dst = new Bitmap(src.GetWidth(), src.GetHeight(), PixelFormat32bppARGB);

        BitmapData srcData;
        BitmapData dstData;
        Rect rc(0, 0, src.GetWidth(), src.GetHeight());

        if (src.LockBits(& rc, ImageLockModeRead, PixelFormat32bppARGB, & srcData) == Ok)
        {
            if ( dst->LockBits(& rc, ImageLockModeWrite, PixelFormat32bppARGB, & dstData) == Ok ) {
                uint8_t * srcBits = (uint8_t *) srcData.Scan0;
                uint8_t * dstBits = (uint8_t *) dstData.Scan0;
                unsigned int stride;
                if (srcData.Stride > 0) { 
                    stride = srcData.Stride;
                } else {
                    stride = - srcData.Stride;
                }
                memcpy(dstBits, srcBits, src.GetHeight() * stride);

                dst->UnlockBits(&dstData);
            }
            src.UnlockBits(&srcData);
        }
        return dst;
    }

    bool get_image_dimensions(const std::string& filename, int& x, int& y) {
        const auto img = load_image_no_lock((const wchar_t*) convert.from_bytes(filename).c_str());
        if (!img) return false;
        x = (int) img->GetWidth();
        y = (int) img->GetHeight();
        return true;
    }

    void force_render_tick() {
        static tagMSG msg {};
        
        sdk::Game::currentTickIsInner = true;
        (*sdk::DirectX::d3dDevice)->Clear(0, nullptr, D3DCLEAR_TARGET, 0xFF121212, 0, 0);
        EventManager::Emit(BeforeTickEvent{});
        (*sdk::DirectX::d3dDevice)->Present(nullptr, nullptr, nullptr, nullptr);
        EventManager::Emit(AfterTickEvent{});
        sdk::Game::currentTickIsInner = false;
        
        if ( PeekMessageA(&msg, nullptr, 0, 0, 1u) ) {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

    }
}