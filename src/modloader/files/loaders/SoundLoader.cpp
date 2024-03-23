#include "SoundLoader.h"

#include <game/AssetPool.h>
#include <game/SoundHost.h>
#include <modloader/files/ModFileResolver.h>

namespace modloader {
    bool SoundLoader::Load(const std::filesystem::path& path)
    {
        if (!game::SoundHost::initialized)
            return false;

        const auto filename = path.filename().generic_string();
        const auto host = game::SoundHost::GetInstance();
        auto cwd = std::filesystem::current_path();
        const auto index = host->GetSoundIndex(filename.c_str());

        const auto resolvedPath = ModFileResolver::ResolveGameFile(sdk::Game::GetDataPath() / path);
        if (resolvedPath.empty() || !exists(resolvedPath))
        {
            Log::Info << "Файл звука " << filename << " не найден" << Log::Endl;
            return false;
        }

        if (index == -1) {
            Log::Warn << "Звук " << filename << " не найден в игре" << Log::Endl;
            return false;
        }

        auto& sound = host->soundPool[index];
        const auto sample = BASS_SampleLoad(0, resolvedPath.string().c_str(), 0, 0, 255, 0);

        if (!sample) {
            Log::Debug << "Не удалось загрузить файл " << filename << ". Ошибка: " << BASS_ErrorGetCode() << Log::Endl;
            return false;
        }

        BASS_SampleFree(sound.soundSample);
        sound.soundSample = sample;

        Log::Info << "Звук " << filename << " перезагружен" << Log::Endl;
        return true;
    }
}
