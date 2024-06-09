#include <supermod/game/SoundHost.hpp>
#include <supermod/pch.hpp>

#include <supermod/memory/Memory.hpp>

namespace game
{
SoundHost* SoundHost::GetInstance()
{
    static constexpr Memory::Pattern pat("68 ? ? ? ? E8 ? ? ? ? 83 C4 ? 5D C3 CC CC CC CC CC 55 8B EC 83 EC ? A1");
    static auto mem = pat.Search();
    return *mem.Get<SoundHost**>(1);
}

int SoundHost::GetMusicIndex(const char* name) const
{
    for (auto i = 0; i < loadedMusic; i++)
    {
        if (!strcmp(loadedMusicNames[i], name))
            return i;
    }

    return -1;
}

int SoundHost::GetSoundIndex(const char* name) const
{
    for (auto i = 0; i < loadedSounds; i++)
    {
        if (!strcmp(soundPool[i].name, name))
            return i;
    }

    return -1;
}

void SoundHost::RemoveMusic(int index)
{
    --loadedMusic;
    const auto ptr = musicPool[index];
    for (auto i = index; i < loadedMusic - 1; i++)
    {
        strcpy_s(loadedMusicNames[i], 32, loadedMusicNames[i + 1]);
        musicPool[i] = musicPool[i + 1];
    }
    BASS_StreamFree(ptr);
}

void SoundHost::LoadMusic(const std::string& name, HSTREAM stream)
{
    musicPool[loadedMusic] = stream;
    name.copy(loadedMusicNames[loadedMusic], 32);
    loadedMusic++;
}

void SoundHost::ReplaceMusic(int index, HSTREAM steam)
{
    const auto old = musicPool[index];
    BASS_StreamFree(old);
    musicPool[index] = steam;
}

void SoundHost::LoadMusic(const char* name)
{
    static constexpr Memory::Pattern pat("55 8B EC 68 ? ? ? ? 8B 45 ? 50 E8");
    static auto mem = pat.Search();
    mem.Get<char*(__cdecl*)(const char*)>()(name);
}

void SoundHost::LoadSound(const char* name)
{
    static constexpr Memory::Pattern pat("55 8B EC 81 3D ? ? ? ? ? ? ? ? 7C ? E9 ? ? ? ? 8B 45");
    static auto mem = pat.Search();
    mem.Get<char*(__cdecl*)(const char*)>()(name);
}
} // namespace game