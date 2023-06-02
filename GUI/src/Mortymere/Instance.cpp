/*
** EPITECH PROJECT, 2023
** Mortymere/Instance.cpp
** File description:
** -
*/

#include "Mortymere/Instance.hpp"

bool Mortymere::Instance::udpate(void)
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
    if (!window.isFullscreen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            window.setFullscreen(true);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        window.setFullscreen(false);
    window.clear(sf::Color::Black);
    window.display();
    return window.isOpen();
}
