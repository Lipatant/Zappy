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
#include <SFML/Graphics/RectangleShape.hpp>
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
    /// @brief If _music is playing
    bool _isMusicPause = false;
    sf::Music _music;
    std::vector<size_t> _queue;

public: // PUBLIC MEMBERS
    /// @brief Button used for skipping the current track
    Mortymere::Button buttonNext;
    /// @brief Button used for pausing and resuming the music
    Mortymere::Button buttonPause;
    /// @brief Displayed album cover of the music
    sf::RectangleShape spriteAlbum;
    /// @brief Displayed album of the music
    sf::Text textAlbum;
    /// @brief Displayed artist of the music
    sf::Text textArtist;
    /// @brief Displayed title of the music
    sf::Text textTitle;

protected: // PROTECTED FUNCTIONS
    /// @param id (size_t const) ID of the music in ENTIRE PLAYLIST to play
    void _playAtID(size_t const id);

public: // PUBLIC FUNCTIONS
    /// @brief Next music
    void next(void);
    /// @brief Pause current music
    void pause(void);
    /// @brief Updates the current music for some detections
    void update(void);

public: // CONSTRUCTOR
    Playlist(void);

};

};
