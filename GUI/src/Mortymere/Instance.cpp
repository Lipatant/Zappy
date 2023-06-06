/*
** EPITECH PROJECT, 2023
** Mortymere/Instance.cpp
** File description:
** -
*/

#include "Mortymere/Instance.hpp"
#include "Mortymere/Sprites.hpp"

#define INSTANCE Mortymere::Instance

#define ANCHOR_UNIT 0.05
sf::Vector3f daAnchor = {0, 0, 0};

INSTANCE::Instance(void) : camera(window), _sprite(Mortymere::createSprite<Mortymere::Sprites::Character>("graphics/charact/Morty/Base.png"))
{ }

bool INSTANCE::udpate(void)
{
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::LostFocus)
            window.hasFocus = false;
        if (event.type == sf::Event::GainedFocus)
            window.hasFocus = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _sprite->setCharacterRotation(Mortymere::CharacterRotation::Left);
        daAnchor.x -= ANCHOR_UNIT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _sprite->setCharacterRotation(Mortymere::CharacterRotation::Right);
        daAnchor.x += ANCHOR_UNIT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _sprite->setCharacterRotation(Mortymere::CharacterRotation::Down);
        daAnchor.z += ANCHOR_UNIT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _sprite->setCharacterRotation(Mortymere::CharacterRotation::Up);
        daAnchor.z -= ANCHOR_UNIT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
    if (!window.isFullscreen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            window.setFullscreen(true);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        window.setFullscreen(false);
    window.update();
    window.clear(sf::Color::Black);
    _ground.drawOn(camera, window);
    window.draw(_ground);
    _sprite->anchor() = daAnchor;
    _sprite->drawOn(*this);
    window.display();
    return window.isOpen();
}
