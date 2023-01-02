#pragma once
#include "thirdparty/directx/d3d8.h"

namespace game
{
    struct Asset {
        const char name[128];
        int width;
        int height;
        IDirect3DTexture8* texture;
        byte isTga;
        byte isPoolDefault;
        D3DFORMAT format;

        void Anonymize() {
            const_cast<char*>(name)[0] = '\0';
        }

        void ReplaceTexture(IDirect3DTexture8* tex) {
            texture->Release();
            texture = tex;
        }
    };
}