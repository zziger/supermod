#include "ModFileResolver.h"
#include "Utils.h"

void ModFileResolver::FileListenerThread() {
    Log::Info << "Listening at " << std::filesystem::current_path().generic_string().c_str() << Log::Endl;
    const HANDLE hDir = CreateFileA(
        std::filesystem::current_path().generic_string().c_str(),
        FILE_LIST_DIRECTORY,
        FILE_SHARE_WRITE | FILE_SHARE_READ | FILE_SHARE_DELETE,
        nullptr, 
        OPEN_EXISTING, 
        FILE_FLAG_BACKUP_SEMANTICS, 
        nullptr);

    byte buf[1024];
    DWORD dwBytesReturned = 0;   

    while(listenerEnabled)
    {
        if(
            ReadDirectoryChangesW(
                hDir,
                &buf,
                sizeof buf,
                true,
                FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_FILE_NAME,
                &dwBytesReturned,
                nullptr,
                nullptr
            )
        )
        {
            BYTE* ptr = buf;
            while(true) {
                const auto info = reinterpret_cast<FILE_NOTIFY_INFORMATION*>(ptr);
                auto filename = std::wstring(info->FileName, info->FileName + info->FileNameLength / sizeof(char16_t));
                
                if (resolvedFilePaths.contains(filename)) {
                    auto normalName = convert.to_bytes((char16_t*) filename.c_str());
                    std::lock_guard lock(_reloadMutex);
                    filesToReload.emplace(normalName);
                }
                
                if (!info->NextEntryOffset) break;
                ptr += info->NextEntryOffset;
            }
        }
        else
        {
            Log::Debug << "FAILED! " << GetLastError() << Log::Endl;   
        }
    }

    Log::Info << "File listener finished" << Log::Endl;
}