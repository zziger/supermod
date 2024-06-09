#include <supermod/game/animations/AnimationPool.hpp>
#include <supermod/pch.hpp>

#include <supermod/memory/Memory.hpp>
#include <supermod/sdk/Game.hpp>

namespace game
{
Animation* AnimationPool::Get(const std::string& name)
{
    for (int i = 0; i < animationCount; i++)
        if (name == animations[i]->name)
            return animations[i];

    return nullptr;
}

Animation* AnimationPool::Reload(const std::filesystem::path& path)
{
    const auto instance = Get(path.filename().string());
    const auto dir = sdk::Game::GetDataPath() / path.parent_path();
    if (!instance)
        return nullptr;

    const auto framesPtr = instance->frames;
    const auto frameMovementsPtr = instance->frameMovements;
    const auto interpolatedFrameMovementsPtr = instance->interpolatedFrameMovements;

    overrideAllocation = instance;

    const auto oldPath = std::filesystem::current_path();
    current_path(dir);
    static constexpr Memory::Pattern pat(
        "55 8B EC 83 EC ? 89 4D ? 8B 45 ? 50 8B 4D ? E8 ? ? ? ? 89 45 ? 83 7D ? ? 74 ? 8B 45 ? E9 ? ? ? ? 8B 4D");
    static auto mem = pat.Search();
    mem.Get<Animation*(__thiscall*)(AnimationPool*, const char*)>()(this, path.filename().string().c_str());
    current_path(oldPath);

    sdk::Game::Free(framesPtr);
    sdk::Game::Free(frameMovementsPtr);
    sdk::Game::Free(interpolatedFrameMovementsPtr);
    return instance;
}

AnimationPool* AnimationPool::Instance()
{
    static constexpr Memory::Pattern pat("B9 ? ? ? ? E8 ? ? ? ? 8B 55 ? 89 82 ? ? ? ? 8B 45 ? C7 80");
    static auto mem = pat.Search();
    return *mem.Get<AnimationPool**>(1);
}
} // namespace game
