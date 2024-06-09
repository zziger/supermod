#pragma once
#include <supermod/pch.hpp>

#include <bass.h>
#include <xstring>

namespace game
{
struct Sound
{
    HSAMPLE soundSample;
    char name[32];
    float countdown;
};

#pragma pack(push, 1)
class SoundHost
{
public:
    static inline bool initialized = false;

    char stringRelatedToAudio[256];
    char loadedMusicNames[32][32];
    float unk1;

private:
    char pad[4];

public:
    Sound soundPool[1024];
    wchar_t wstringRelatedToAudio[512];
    HSTREAM musicPool[32];
    int loadedMusic;
    int loadedSounds;

    static SoundHost* GetInstance();
    int GetMusicIndex(const char* name) const;
    int GetSoundIndex(const char* name) const;
    void RemoveMusic(int index);
    void LoadMusic(const std::string& name, HSTREAM stream);
    void ReplaceMusic(int index, HSTREAM steam);
    void LoadMusic(const char* name);
    void LoadSound(const char* name);
};
#pragma pack(pop)
} // namespace game