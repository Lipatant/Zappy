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
    sf::Vector2f returned(0.05, 0.05);
    sf::Vector3f pos(position + center);
    sf::Vector2f windowSizeRatio(windowSize.x / windowSize.y, \
        windowSize.y / windowSize.x);

    returned.x *= pos.x * 1.5 + pos.z * 0.7;
    returned.y *= pos.y * 1.5 + pos.z * 0.7;
//    returned.x *= pos.z * 0.70710678118;
//    returned.y *= pos.z * 0.70710678118;
//    returned.x *= pos.x + pos.z * 0.70710678118;
//    returned.y *= pos.y + pos.z * 0.70710678118;
//    returned.x += returned.x * pos.z * 0.02;
//    returned.y += returned.y * pos.z * 0.05;
//    returned.x += (returned.x - 0.5) * windowSizeRatio.x;
//    returned.y += (returned.y - 0.5) * windowSizeRatio.y;
    returned.x += returned.x * windowSize.x;// + windowSize.x / 2;
    returned.y += returned.y * windowSize.y;// + windowSize.y / 2;
    return returned;
}
