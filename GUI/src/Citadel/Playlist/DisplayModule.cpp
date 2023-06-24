/*
** EPITECH PROJECT, 2023
** Playlist/Instance.cpp
** File description:
** -
*/

#include "Citadel/Instance.hpp"
#include "Citadel/Playlist.hpp"

#define PLAYLIST citadel->playlist
#define WINDOW instance.window

#define APPLY_POSTION(OBJECT) \
    OBJECT.setPosition(positionX + positionXBase, positionY + positionYBase)
#define APPLY_POSTION_ADD(OBJECT, X, Y) \
    OBJECT.setPosition(positionX + positionXBase + X, \
    positionY + positionYBase + Y)
#define WIDTH(OBJECT) OBJECT.getGlobalBounds().width
#define HEIGHT(OBJECT) OBJECT.getGlobalBounds().height

MORTYMERE_INSTANCE_DISPLAY_MODULE(playlistDisplayModuleBase)
{
    if (!data) return;
    Citadel::Instance *citadel = reinterpret_cast<Citadel::Instance *>(data);
    sf::Vector2f const windowSize = WINDOW.getView().getSize();
    float positionX = 0;
    float const positionXBase = windowSize.x / 2 - 1;
    float positionY = 0;
    float const positionYBase = windowSize.y / -2 + 1;
    float const scale = 0.6;
    float positionLeft[2];
    float positionTop[2];

    PLAYLIST.update();
    // PLAYLIST.buttonPause
    PLAYLIST.buttonPause.setScale(scale, scale);
    positionX = -WIDTH(PLAYLIST.buttonPause);
    positionLeft[0] = positionX;
    positionTop[0] = positionY + HEIGHT(PLAYLIST.buttonPause) / 2;
    APPLY_POSTION(PLAYLIST.buttonPause);
    // PLAYLIST.buttonNext
    positionY += HEIGHT(PLAYLIST.buttonPause);
    PLAYLIST.buttonNext.setScale(scale, scale);
    positionX = -WIDTH(PLAYLIST.buttonNext);
    positionLeft[1] = positionX;
    positionTop[1] = positionY + HEIGHT(PLAYLIST.buttonNext) / 2;
    APPLY_POSTION(PLAYLIST.buttonNext);
    // BUTTONS
    if (PLAYLIST.buttonPause.update(WINDOW.mouseUI, WINDOW.hasFocus && \
        sf::Mouse::isButtonPressed(sf::Mouse::Left)).hasBeenPressed())
        PLAYLIST.pause();
    if (PLAYLIST.buttonNext.update(WINDOW.mouseUI, WINDOW.hasFocus && \
        sf::Mouse::isButtonPressed(sf::Mouse::Left)).hasBeenPressed())
        PLAYLIST.next();
    // PLAYLIST.textTitle
    positionX = positionLeft[0];
    positionY = positionTop[0];
    APPLY_POSTION_ADD(PLAYLIST.textTitle, -WIDTH(PLAYLIST.textTitle), \
        -HEIGHT(PLAYLIST.textTitle) / 2);
    // PLAYLIST.textArtist
    positionX = positionLeft[1];
    positionY = positionTop[1];
    APPLY_POSTION_ADD(PLAYLIST.textArtist, -WIDTH(PLAYLIST.textArtist), \
        -HEIGHT(PLAYLIST.textArtist));
    // PLAYLIST.textAlbum
    APPLY_POSTION_ADD(PLAYLIST.textAlbum, -WIDTH(PLAYLIST.textAlbum), 0);
    // WINDOW.DRAW
    WINDOW.draw(PLAYLIST.textArtist);
    WINDOW.draw(PLAYLIST.textAlbum);
    WINDOW.draw(PLAYLIST.textTitle);
    WINDOW.draw(PLAYLIST.buttonNext);
    WINDOW.draw(PLAYLIST.buttonPause);
}
