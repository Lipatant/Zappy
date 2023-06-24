/*
** EPITECH PROJECT, 2023
** Citadel/Playlist.cpp
** File description:
** -
*/

#include <stdlib.h>
#include "Citadel/Playlist.hpp"

#define PLAYLIST Citadel::Playlist
#define LOAD_FROM_FILE(OBJECT, PATH) \
    (OBJECT.loadFromFile(std::string("GUI/") + PATH) || \
    OBJECT.loadFromFile(PATH))
#define OPEN_FROM_FILE(OBJECT, PATH) \
    (OBJECT.openFromFile(std::string("GUI/") + PATH) || \
    OBJECT.openFromFile(PATH))

using PlaylistBgm = struct PlaylistBgm_s {
    std::string title;
    std::string artist;
    std::string album;
    std::string musicpath;
    std::string artistpath;
    std::string albumpath;
};

#define PLAYLIST_SPACEMUSICTOTRIPTO(TRACK) \
    {TRACK, "The Hugo Collective", "Space Music To Trip To", \
    std::string("bgm/Space Music To Trip To/") + TRACK + ".wav", \
    "graphics/bgm/TheHugoCollective.jpeg", \
    "graphics/bgm/SpaceMusicToTripTo.jpg"}
#define PLAYLIST_NODISCOUNTS(TRACK) \
    {TRACK, "The Hugo Collective", "No discounts", \
    std::string("bgm/No discounts/") + TRACK + ".wav", \
    "graphics/bgm/TheHugoCollective.jpeg", \
    "graphics/bgm/NoDiscounts.jpeg"}
#define PLAYLIST_SILENTSCREAMING(TRACK) \
    {TRACK, "The Hugo Collective (feat. Dark Forest)", "Silent Screaming", \
    std::string("bgm/Silent Screaming/") + TRACK + ".wav", \
    "graphics/bgm/TheHugoCollective.jpeg", \
    "graphics/bgm/SilentScreaming.jpeg"}

static const PlaylistBgm ENTIRE_PLAYLIST[] = {
    PLAYLIST_SPACEMUSICTOTRIPTO("Moon Creep"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Atmospheric Pressure"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Incoming Transmission"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Time Warp"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Space Walk"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Space Mall"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Galaxy"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Bonus Track: InfraRed Fuzz"),
    PLAYLIST_NODISCOUNTS("Rocket Surgery"),
    PLAYLIST_SILENTSCREAMING("Silent Screaming")
};

static const size_t ENTIRE_PLAYLIST_LENGTH = \
    sizeof(ENTIRE_PLAYLIST) / sizeof(ENTIRE_PLAYLIST[0]);

PLAYLIST::Playlist(void) : buttonNext("graphics/buttons/MusicNext.png"), \
    buttonPause("graphics/buttons/MusicPause.png")
{
//    if (LOAD_FROM_FILE(spriteAlbum, "graphics/gbm"))
    spriteAlbum.setFillColor(sf::Color::Black);
    spriteAlbum.setOutlineColor(sf::Color::Black);
    spriteAlbum.setOutlineThickness(3);
    if (LOAD_FROM_FILE(_font, "fonts/AileronBold.otf"))
        _isFontLoaded = true;
    if (_isFontLoaded) {
        textTitle.setFont(_font);
        textTitle.setString("");
        textTitle.setCharacterSize(24);
        textTitle.setOutlineThickness(4);
        textTitle.setFillColor(sf::Color::White);
        textTitle.setOutlineColor(sf::Color::Black);
        textArtist.setFont(_font);
        textArtist.setString("");
        textArtist.setCharacterSize(20);
        textArtist.setOutlineThickness(4);
        textArtist.setFillColor(sf::Color::White);
        textArtist.setOutlineColor(sf::Color::Black);
        textAlbum.setFont(_font);
        textAlbum.setString("");
        textAlbum.setCharacterSize(16);
        textAlbum.setOutlineThickness(4);
        textAlbum.setFillColor(sf::Color::White);
        textAlbum.setOutlineColor(sf::Color::Black);
    }
}

void PLAYLIST::_playAtID(size_t const id)
{
    size_t const trackID = id % ENTIRE_PLAYLIST_LENGTH;

    if (OPEN_FROM_FILE(_music, ENTIRE_PLAYLIST[trackID].musicpath)) {
        textTitle.setString(ENTIRE_PLAYLIST[trackID].title);
        textArtist.setString(ENTIRE_PLAYLIST[trackID].artist);
        textAlbum.setString(ENTIRE_PLAYLIST[trackID].album);
        _isMusicLoaded = true;
        textTitle.setFillColor(sf::Color::White);
        textArtist.setFillColor(sf::Color::White);
        textAlbum.setFillColor(sf::Color::White);
        _isMusicPause = false;
        _music.play();
        if (_textures.find(ENTIRE_PLAYLIST[trackID].albumpath) == \
            _textures.end()) {
            _textures[ENTIRE_PLAYLIST[trackID].albumpath] = sf::Texture();
            if (!LOAD_FROM_FILE(_textures[ENTIRE_PLAYLIST[trackID \
                ].albumpath], ENTIRE_PLAYLIST[trackID].albumpath))
                _textures.erase(_textures.find(ENTIRE_PLAYLIST[trackID \
                ].albumpath));
        }
        if (_textures.find(ENTIRE_PLAYLIST[trackID].albumpath) == \
            _textures.end()) {
            spriteAlbum.setFillColor(sf::Color::Black);
            spriteAlbum.setTexture(NULL);
        } else {
            spriteAlbum.setTextureRect({0, 0, static_cast<int>( \
                _textures[ENTIRE_PLAYLIST[trackID].albumpath].getSize().x), \
                static_cast<int>(_textures[ENTIRE_PLAYLIST[trackID].albumpath \
                ].getSize().y)});
            spriteAlbum.setFillColor(sf::Color::White);
            spriteAlbum.setTexture(&_textures[ENTIRE_PLAYLIST[trackID \
            ].albumpath]);
        }
    } else {
        textTitle.setString("");
        textArtist.setString("");
        textAlbum.setString("");
        _isMusicLoaded = false;
    }
}

void PLAYLIST::next(void)
{
    size_t queueID;

    if (ENTIRE_PLAYLIST_LENGTH < 1)
        return;
    if (_queue.size() < 1)
        for (size_t i = 0; i < ENTIRE_PLAYLIST_LENGTH; i++)
            _queue.push_back(i);
    queueID = rand() % _queue.size();
    _playAtID(_queue[queueID]);
    _queue.erase(_queue.begin() + queueID);
}

void PLAYLIST::pause(void)
{
    if (!_isMusicLoaded)
        return;
    if (_isMusicPause) {
        _music.play();
        textTitle.setFillColor(sf::Color::White);
        textArtist.setFillColor(sf::Color::White);
        textAlbum.setFillColor(sf::Color::White);
    } else {
        _music.pause();
        textTitle.setFillColor(sf::Color::Blue);
        textArtist.setFillColor(sf::Color::Blue);
        textAlbum.setFillColor(sf::Color::Blue);
    }
    _isMusicPause = !_isMusicPause;
}

void PLAYLIST::update(void)
{
    if (_music.getStatus() == sf::Music::Stopped)
        next();
}
