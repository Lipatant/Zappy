/*
** EPITECH PROJECT, 2023
** Citadel/Playlist.hpp
** File description:
** -
*/

/// @file
/// @brief Class containg everything required for displaying a music playlist

#include <map>
#include <queue>
#include <string>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Mortymere/Button.hpp"

#pragma once

namespace Citadel {

class Playlist {

private: // PRIVATE MEMBERS
    std::map<std::string, sf::Texture> _textures;

protected: // PROTECTED MEMBERS
    sf::Font _font;
    /// @brief If _font is loaded
    bool _isFontLoaded = false;
    /// @brief If _music is loaded
    bool _isMusicLoaded = false;
    sf::Music _music;
    std::vector<size_t> _queue;

public: // PROTECTED MEMBERS
    /// @param id (size_t const) ID of the music in ENTIRE PLAYLIST to play
    void _playAtID(size_t const id);

public: // PUBLIC FUNCTIONS
    /// Next Music
    void next(void);

public: // CONSTRUCTOR
    Playlist(void);

};

};
