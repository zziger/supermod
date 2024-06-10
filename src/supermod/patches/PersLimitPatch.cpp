/// This patch extends pers.txt limit from 16 to 127

#include <supermod/pch.hpp>

#include <supermod/events/EventManager.hpp>
#include <supermod/memory/Memory.hpp>

using namespace sm;

constexpr int limit = 127;

static char persNames[limit * 64 * 2];
static char persTextureNames[limit * 64];
static uintptr_t persTextures[limit];

inline EventManager::Ready $pers_limit_patch([] {
    constexpr Memory::Pattern pushPersNames(
        "68 ? ? ? ? E8 ? ? ? ? 83 C4 ? C7 05 ? ? ? ? ? ? ? ? 68 ? ? ? ? FF 15 ? ? ? ? 6A ? 8D 85");
    constexpr Memory::Pattern addPersNames("81 C2 ? ? ? ? 52 E8 ? ? ? ? 83 C4 ? 8B 85 ? ? ? ? 83 C0");
    constexpr Memory::Pattern addPersNames2("81 C1 ? ? ? ? 51 E8 ? ? ? ? 83 C4 ? 85 C0 75 ? 8B 55 ? 8B 04 95");
    constexpr Memory::Pattern addPersTextureNames("81 C2 ? ? ? ? 52 E8 ? ? ? ? 83 C4 ? A1");
    constexpr Memory::Pattern movPersTextureNames("8A 94 4A ? ? ? ? 88");
    constexpr Memory::Pattern movPersTextures("89 04 8D ? ? ? ? EB ? 68 ? ? ? ? FF 15 ? ? ? ? 8B 4D");
    constexpr Memory::Pattern movPersTextures2("85 C0 75 ? 8B 55 ? 8B 04 95 ? ? ? ? EB ? EB ? 33 C0 8B E5");
    constexpr Memory::Pattern movPersTextures3("8B 04 85 ? ? ? ? 5D C3 CC 55 8B EC 6A");
    constexpr Memory::Pattern cmpPersLimit("83 3D ? ? ? ? ? 7C ? EB");
    pushPersNames.Search().Add(1).Put((int32_t)&persNames);
    addPersNames.Search().Add(2).Put((int32_t)&persNames);
    addPersNames2.Search().Add(2).Put((int32_t)&persNames);
    addPersTextureNames.Search().Add(2).Put((int32_t)&persTextureNames);
    movPersTextureNames.Search().Add(3).Put((int32_t)&persTextureNames);
    movPersTextures.Search().Add(3).Put((int32_t)&persTextures);
    movPersTextures2.Search().Add(10).Put((int32_t)&persTextures);
    movPersTextures3.Search().Add(3).Put((int32_t)&persTextures);
    cmpPersLimit.Search().Add(6).Put((uint8_t)limit);
});
