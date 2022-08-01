#pragma once
#include <regex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "CGameApis.h"
#include "CModuleManager.h"
#include "Log.h"
#include "Utils.h"

class CConsole {
public:
    
    static void Initialize() {
        AllocConsole();
        FILE* pFile = nullptr;
        freopen_s(&pFile, "CONIN$", "r", stdin);
        freopen_s(&pFile, "CONOUT$", "w", stdout);
        SetConsoleTitle(L"SuperCow mod console");
        SetConsoleOutputCP( CP_UTF8);
        SetConsoleCP( CP_UTF8);
        Log::Info << "Initializing mod..." << Log::Endl;
        
        CreateThread(nullptr, 0, [](LPVOID _) -> DWORD {
            ListenForConsole();
            return 0;
        }, nullptr, 0, nullptr);
    }

    static void Destroy() {
        _listenForConsole = false;
    }

    static void ExecuteCommand(const std::string& string) {
        try {
            const auto cmd = ParseCommand(string);
            HandleCommand(cmd);
        } catch(std::exception& exception) {
            Log::Error << "Error while handling command: " << exception.what() << Log::Endl;
        }
    }

private:
    inline static bool _listenForConsole = true;

    static void HandleCommand(const Command& command) {
        auto [cmd, args, rawArgs] = command;
        
        if (cmd == "show") {
            CGameApis::ShowLowerMessage(U16(rawArgs));
        } else if (cmd == "editor") {
            std::cout << "Editor enabled" << std::endl;
            CGameApis::ToggleEditor(true);
        } else if (cmd == "load") {
            if (!CModuleManager::LoadModule(rawArgs))
                Log::Error << "Failed to load module " << Log::Color::GREEN << rawArgs << Log::Endl; 
        } else if (cmd == "unload") {
            if (!CModuleManager::UnloadModule(rawArgs))
                Log::Error << "Failed to unload module " << Log::Color::GREEN << rawArgs << Log::Endl;
        } else if (cmd == "checkpoint") {
            CGameApis::TriggerCheckpoint();
        } else {
            auto found = false;

            const auto modules = CModuleManager::GetLoadedModules();
            for (auto module : modules) {
                if (!module->HandleCommand(command)) continue;
                found = true;
                break;
            }

            if (!found) std::cout << "Command not found" << std::endl;
        }
    }

    [[nodiscard]] static Command ParseCommand(std::string str) {
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        const auto delimIndex = str.find(' ');

        std::string cmd;
        std::string rawArgs;
        
        if (delimIndex == std::string::npos) {
            cmd = str;
            rawArgs = "";
        } else {
            cmd = str.substr(0, delimIndex);
            rawArgs = str.substr(delimIndex);
            Utils::Trim(rawArgs);
        }
        
        static std::regex re("[^ ]+");
        std::vector<std::string> args;
        
        std::sregex_token_iterator
            begin(rawArgs.begin(), rawArgs.end(), re),
            end;

        std::copy(begin, end, std::back_inserter(args));

        return { cmd, args, rawArgs };
    }

    static void ListenForConsole() {
        while (_listenForConsole) {
            const auto str = Utils::Readline();
            ExecuteCommand(str);
        }
    }
};
