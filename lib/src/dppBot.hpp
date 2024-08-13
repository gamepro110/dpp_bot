#pragma once

#include <dpp/dpp.h>

#include <string>
#include <string_view>
#include <functional>

using dppCallback = std::function<void()>;

class dppBot {
public:
    dppBot();

public:
    bool GetLineFromFile(std::string_view fileName, std::string& tknStr) const;
    void Run();
    void SetupSlashCommands();

private:
    bool SetToken();
    void RegisterCommand(std::string_view name, std::string_view description, dppCallback callback){} //TODO implement
    void RegisterSlashCommand(std::string_view name, std::string_view description, dppCallback callback){} //TODO implement

private:
    dpp::cluster bot;
};
