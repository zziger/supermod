#pragma once
#include <string>

namespace game
{
    struct CachedFile {
        char filename[128];
        int size;
        void* content;
        int unk1;
    };

    class CachedFilePool {
    public:
        CachedFile* files[1024];
        int filesCount;

        static CachedFilePool* GetInstance();

        [[nodiscard]] CachedFile* GetByName(const std::string& name) const;
    };
}