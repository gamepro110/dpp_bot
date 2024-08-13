#include "dppBot.hpp"

#include <iostream>
#include <filesystem>
#include <cstdio>

dppBot::dppBot() :
    bot("")
{
    bot.on_log(dpp::utility::cout_logger());
}

bool dppBot::GetLineFromFile(std::string_view fileName, std::string& tknStr) const {
    if (!std::filesystem::exists(fileName.data())) {
        fprintf(stderr, "%s (%s %s)\n", "file not found", std::filesystem::current_path().c_str(), fileName.data());
        return false;
    }

    std::ifstream in{ fileName.data(), std::ios_base::in };

    if (in.bad()) {
        fprintf(stderr, "%s (%s)\n", "error opening file", fileName.data());
        return false;
    }

    getline(in, tknStr);

    return true;
}

void dppBot::Run() {
    if (!SetToken()) {
        return;
    }
    SetupSlashCommands();

    bot.on_ready([&](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "ping pong!", bot.me.id));
        }
    });

    try {
       bot.start(false);
    }
    catch(const dpp::exception& e) {
        fprintf(stderr, "%s\n", e.what());
    }
}

void dppBot::SetupSlashCommands() {
    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("pong");
        }
    });
}

bool dppBot::SetToken() {
    std::string tkn{ "" };

    if (!GetLineFromFile("token.tkn", tkn)) {
        return false;
    }

    // printf("%s\n", "token found");
    bot.token = tkn;
    return true;
}
