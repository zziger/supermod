#pragma once
#include <supermod/pch.hpp>

#include <supermod/Utils.hpp>
#include <supermod/data.hpp>

namespace game
{
struct Animation
{
    char name[32];
    int32_t boneCount;
    int32_t frameCount;
    int32_t frameTime;
    int32_t duration;
    int32_t interpolatedFrames;
    float animationMovementTime;
    vector4* frames;
    vector3* frameMovements;
    vector3* interpolatedFrameMovements;
};

class AnimationPool
{
    virtual ~AnimationPool() = default;

public:
    AnimationPool() = delete;

    int animationCount;
    Animation* animations[1024];

    Animation* Get(const std::string& name);
    Animation* Reload(const std::filesystem::path& path);

    static inline Animation* overrideAllocation = nullptr;

    static AnimationPool* Instance();
};

ENSURE_SIZE(AnimationPool, 0x1008);
} // namespace game