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
    OBJECT.loadFromFile(std::string("GUI/") + PATH) || \
    OBJECT.loadFromFile(PATH)
#define OPEN_FROM_FILE(OBJECT, PATH) \
    OBJECT.openFromFile(std::string("GUI/") + PATH) || \
    OBJECT.openFromFile(PATH)

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
    "graphics/bgm/SpaceMusicToTripTo.jpeg"}

static const PlaylistBgm ENTIRE_PLAYLIST[] = {
    PLAYLIST_SPACEMUSICTOTRIPTO("Moon Creep"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Atmospheric Pressure"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Incoming Transmission"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Time Warp"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Space Walk"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Space Mall"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Galaxy"),
    PLAYLIST_SPACEMUSICTOTRIPTO("Bonus Track: InfraRed Fuzz"),
};

static const size_t ENTIRE_PLAYLIST_LENGTH = \
    sizeof(ENTIRE_PLAYLIST) / sizeof(ENTIRE_PLAYLIST[0]);

PLAYLIST::Playlist(void)
{
    if (LOAD_FROM_FILE(_font, "fonts/Aileron-Bold.otf"))
        _isFontLoaded = true;
}

void PLAYLIST::_playAtID(size_t const id)
{
    size_t const trackID = id % ENTIRE_PLAYLIST_LENGTH;

    if (OPEN_FROM_FILE(_music, ENTIRE_PLAYLIST[trackID].musicpath)) {
        _isMusicLoaded = true;
        _music.play();
    } else {
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
