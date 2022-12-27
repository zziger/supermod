#pragma once
#include <regex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "Config.h"
#include "Log.h"
#include "Utils.h"

class CConsole {
public:
    
    static void Initialize() {
        if (!Config::Get()["console"].as<bool>(true)) return;
        AllocConsole();
        FILE* pFile = nullptr;
        freopen_s(&pFile, "CONIN$", "r", stdin);
        freopen_s(&pFile, "CONOUT$", "w", stdout);
        SetConsoleTitle(L"SuperCow mod console");
        SetConsoleOutputCP( CP_UTF8);
        SetConsoleCP( CP_UTF8);
        
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
        Log::Warn << "Commands are temporarily disabled" << Log::Endl;
        
        
        // auto [cmd, args, rawArgs] = command;
        // bool found = true;
        
        // if (cmd == "show") {
        //     CGameApis::ShowLowerMessage(U16(rawArgs));
        // } else if (cmd == "editor") {
        //     std::cout << "Editor enabled" << std::endl;
        //     CGameApis::ToggleEditor(true);
        // } else if (cmd == "checkpoint") {
        //     CGameApis::TriggerCheckpoint();
        // } else {
        //     found = false;
        //
        //     if (!found) std::cout << "Command not found" << std::endl;
        // }
        //
        // if (found) std::cout << "Command executed successfully" << std::endl;
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
            utils::trim(rawArgs);
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
            const auto str = utils::readline();
            ExecuteCommand(str);
        }
    }
};
