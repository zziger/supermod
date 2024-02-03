#include "ModInfoFilesystem.h"

#include <yaml-cpp/node/parse.h>

void modloader::ModInfoFilesystem::FromPath(const std::filesystem::path& path)
{
    if (!exists(path)) throw ModFileError("Папка мода не найдена по пути " + path.string());

    const auto manifestPath = path / MANIFEST_FILENAME;
    if (!exists(manifestPath)) throw ModFileError("Манифест мода (manifest.yml) не найден по пути " + manifestPath.string());

    // TODO can this throw?
    const auto manifest = YAML::LoadFile(manifestPath.string());
    Parse(manifest);

    basePath = path;
}
