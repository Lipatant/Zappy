/*
** EPITECH PROJECT, 2023
** Mortymere/Instance.cpp
** File description:
** -
*/

#include "Mortymere/Instance.hpp"
#include "Mortymere/Sprite.hpp"
#include "Mortymere/Sprites/Character.hpp"

#define INSTANCE Mortymere::Instance

INSTANCE::Instance(void) : camera(window)
{ }

void INSTANCE::addObject(Mortymere::SpritePtr objectPtr)
{
    _objects.push_back(objectPtr);
}

void INSTANCE::operator<<(Mortymere::SpritePtr objectPtr)
{
    _objects.push_back(objectPtr);
}

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
    for (auto object = _objects.begin(); object != _objects.end();) {
        if (Mortymere::Sprite sprite = object->lock())
            sprite->drawOn(*this);
        else
            _objects.erase(object++);
        object++;
    }
    window.display();
    return window.isOpen();
}
