/*
** EPITECH PROJECT, 2023
** Mortymere/Camera.cpp
** File description:
** -
*/

#include <cmath>
#include "Mortymere/Camera.hpp"

#define CAMERA Mortymere::Camera

CAMERA::Camera(Mortymere::Window const &window) : _window(window)
{
    center.x = 0; center.y = 0; center.z = 0;
}

sf::Vector2f CAMERA::inSpaceToOnScreen(sf::Vector2f const position) const
{
    return inSpaceToOnScreen(sf::Vector3f(position.x, 0, position.y));
}

sf::Vector2f CAMERA::inSpaceToOnScreen(sf::Vector3f const position) const
{
    sf::Vector2f windowSize = _window.getView().getSize();
    sf::Vector2f returned(100, 100);
    sf::Vector3f pos(position + center);

    pos.x *= 1.5;
    returned.x *= pos.x;
    returned.y *= pos.y + pos.z * 0.4;
    returned.x += returned.x * pos.z * 0.1;
    returned.y += returned.y * pos.z * 0.05;
    returned.x += /*returned.x * windowSize.x +*/ windowSize.x / 2;
    returned.y += /*returned.y * windowSize.y +*/ windowSize.y / 2;
    return returned;
}
