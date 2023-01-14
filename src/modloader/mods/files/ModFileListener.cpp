#include "ModFileResolver.h"
#include "Utils.h"
#include "sdk/Game.h"

void ModFileResolver::FileListenerThread() {
    const auto modsPath = sdk::Game::GetModsPath();

    HANDLE hDir = nullptr;

    try {
        if (exists(modsPath) && !is_directory(modsPath))
            remove(modsPath);
        
        if (!exists(modsPath))
            create_directory(modsPath);
        
        hDir = CreateFileA(
            modsPath.generic_string().c_str(),
            FILE_LIST_DIRECTORY,
            FILE_SHARE_WRITE | FILE_SHARE_READ,
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
                    auto widePath = std::wstring(info->FileName, info->FileName + info->FileNameLength / sizeof(char16_t));
                    auto path = std::filesystem::path(convert.to_bytes((char16_t*) widePath.c_str()));
                    auto newPath = std::filesystem::path();

                    auto foundData = false;
                    for(const auto& el : path) {
                        if (el != "data" && !foundData) continue;
                        foundData = true;
                        newPath = newPath / el;
                    }
                    if (!foundData) continue;
                
                    std::lock_guard lock(_reloadMutex);
                    filesToReload.emplace(newPath.generic_string());
                
                    if (!info->NextEntryOffset) break;
                    ptr += info->NextEntryOffset;
                }
            }
            else
            {
                auto error = GetLastError();

                if (error == ERROR_INVALID_HANDLE) {
                
                }
            
                Log::Error << "Ошибка обработки изменения файлов: " << error << Log::Endl;
                Sleep(100);
            }
        }
    } catch(std::exception& e) {
        Log::Error << "Ошибка обработки изменения файлов: " << e.what() << Log::Endl;
    } catch(...) {
        Log::Error << "Неизвестная ошибка обработки изменения файлов" << Log::Endl;
    }

    CloseHandle(hDir);

    Log::Info << "Поток обработки изменения файлов завершен" << Log::Endl;
}