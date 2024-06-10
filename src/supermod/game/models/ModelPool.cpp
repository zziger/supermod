#include <supermod/game/models/ModelPool.hpp>
#include <supermod/pch.hpp>

#include <supermod/memory/Memory.hpp>
#include <supermod/game/Game.hpp>

namespace sm::game
{
void Model::Free() const
{
    game::Game::Free(bones);
    game::Game::Free(boneVecs);
    game::Game::Free(vertLinks);
    game::Game::Free(indxFaces);
    game::Game::Free(dword44);
    indexBuffer->Release();
    game::Game::Free(unk16);
    game::Game::Free(dword58);
    game::Game::Free(dword5C);
    game::Game::Free(dword50);
    game::Game::Free(dword54);
    vertexBuffer->Release();
}

Model* ModelPool::Get(const std::string& name)
{
    for (int i = 0; i < modelCount; i++)
        if (name == models[i]->name)
            return models[i];

    return nullptr;
}

Model* ModelPool::Reload(const std::filesystem::path& path)
{
    auto instance = Get(path.filename().string());
    const auto dir = game::Game::GetDataPath() / path.parent_path();
    if (!instance)
        return nullptr;

    overrideAllocation = instance;
    instance->Free();

    const auto oldPath = std::filesystem::current_path();
    current_path(dir);
    static constexpr Memory::Pattern pat("55 8B EC 83 EC ? 56 89 4D ? 8B 45 ? 50 8B 4D ? E8 ? ? ? ? 89 45");
    static auto mem = pat.Search();
    mem.Get<Model*(__thiscall*)(ModelPool*, const char*)>()(this, path.filename().string().c_str());
    current_path(oldPath);

    return instance;
}

ModelPool* ModelPool::Instance()
{
    static constexpr Memory::Pattern pat("B9 ? ? ? ? E8 ? ? ? ? 8B 4D ? 89 81 ? ? ? ? 8B 55 ? 83 C2");
    static auto mem = pat.Search();
    return *mem.Get<ModelPool**>(1);
}
} // namespace sm::game
