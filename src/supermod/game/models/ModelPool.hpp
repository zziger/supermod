#pragma once
#include <supermod/pch.hpp>

#include <d3d8/d3d8.hpp>
#include <supermod/Utils.hpp>

namespace sm::game
{
struct Model
{
    char name[32];
    int numVerts;
    int numBones;
    void* boneVecs;
    void* bones;
    void* vertLinks;
    void* indxFaces;
    int indexCount;
    void* unk16;
    int vertexCount;
    void* dword44;
    IDirect3DIndexBuffer8* indexBuffer;
    IDirect3DVertexBuffer8* vertexBuffer;
    void* dword50;
    void* dword54;
    void* dword58;
    void* dword5C;

    void Free() const;
};

class ModelPool
{
    virtual ~ModelPool() = default;

public:
    ModelPool() = delete;

    int modelCount;
    Model* models[512];

    Model* Get(const std::string& name);
    Model* Reload(const std::filesystem::path& path);

    static inline Model* overrideAllocation = nullptr;

    static ModelPool* Instance();
};

ENSURE_SIZE(ModelPool, 0x808);
} // namespace sm::game
