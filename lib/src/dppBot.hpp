#pragma once

#include <dpp/dpp.h>

#include <string>
#include <string_view>
#include <functional>
#include <cstdint>
using dppCallback = std::function<void()>;

class dppEmbed {
public:
    const dpp::message operator()(const dpp::interaction_create_t event) const {
        return dpp::message(event.command.channel_id, embed);
    }

public:
    dppEmbed& Color(uint32_t color) {
        embed.set_color(color);
        return *this;
    }
    dppEmbed& Title(std::string_view title) {
        embed.set_title(title);
        return *this;
    }
    dppEmbed& Url(std::string_view url) {
        embed.set_url(url);
        return *this;
    }
    dppEmbed& Author(std::string_view authorName, std::string_view authorUrl, std::string_view authorLogo) {
        embed.set_author(authorName, authorUrl, authorLogo);
        return *this;
    }
    dppEmbed& description(std::string_view description) {
        embed.set_description(description);
        return *this;
    }
    dppEmbed& thumbnail(std::string_view thumbnailUrl) {
        embed.set_thumbnail(thumbnailUrl);
        return *this;
    }
    dppEmbed& addField(std::string_view title, std::string_view value, bool thing = false) {
        embed.add_field(title, value, thing);
        return *this;
    }
    dppEmbed& image(std::string_view imgUrl) {
        embed.set_image(imgUrl);
        return *this;
    }
    dppEmbed& footer(const dpp::embed_footer& footer) {
        embed.set_footer(footer);
        return *this;
    }
    dppEmbed& footer(std::string_view footerText, std::string_view footerIconUrl) {
        auto footer = dpp::embed_footer();
        embed.set_footer(footer);

        bool hasTxt = footerText.size() > 0;
        bool hasIco = footerIconUrl.size() > 0;

        if (!hasTxt && !hasIco) {
            throw std::invalid_argument("text and icon are empty");
        }
        if (hasTxt) {
            footer.set_text(footerText);
        }
        if (hasIco) {
            footer.set_icon(footerIconUrl);
        }

        embed.set_footer(footer);
        return *this;
    }
    dppEmbed& timestamp() {
        embed.set_timestamp(time(0));
        return *this;
    }

private:
    dpp::embed embed;
};

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
