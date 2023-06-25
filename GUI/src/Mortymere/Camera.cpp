/*
** EPITECH PROJECT, 2023
** Mortymere/Camera.cpp
** File description:
** -
*/

#include <cmath>
#include "Mortymere/Camera.hpp"

#define CAMERA Mortymere::Camera

static const float CAMERA_SCALES[] = {
    1, 1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3, 3.25, 3.5, 3.75, 4
};
static const size_t CAMERA_SCALES_LENGTH = \
    sizeof(CAMERA_SCALES) / sizeof(CAMERA_SCALES[0]);

CAMERA::Camera(Mortymere::Window const &window) : _scaleID(4), _window(window)
{
    center.x = 0; center.y = 0; center.z = 0;
    scale = CAMERA_SCALES[_scaleID % CAMERA_SCALES_LENGTH];
}

sf::Vector2f CAMERA::inSpaceToOnScreen(sf::Vector2f const position) const
{
    return inSpaceToOnScreen(sf::Vector3f(position.x, 0, position.y));
}

sf::Vector2f CAMERA::inSpaceToOnScreen(sf::Vector3f const position) const
{
    sf::Vector2f windowSize = _window.getView().getSize();
    sf::Vector2f returned(0.05, 0.05);
    sf::Vector3f pos(position - center);
    sf::Vector2f windowSizeRatio(windowSize.x / windowSize.y, \
        windowSize.y / windowSize.x);

    returned.x *= pos.x * scale + pos.z * 0.47 * scale;
    returned.y *= 0 - pos.y * scale + pos.z * 0.47 * scale;
    returned.x += returned.x * windowSize.x;// + windowSize.x / 2;
    returned.y += returned.y * windowSize.y;// + windowSize.y / 2;
    return returned;
}

bool CAMERA::zoomIn(void)
{
    if (_scaleID >= CAMERA_SCALES_LENGTH - 1)
        return false;
    _scaleID += 1;
    scale = CAMERA_SCALES[_scaleID % CAMERA_SCALES_LENGTH];
    return true;
}

bool CAMERA::zoomOut(void)
{
    if (_scaleID <= 0)
        return false;
    _scaleID -= 1;
    scale = CAMERA_SCALES[_scaleID % CAMERA_SCALES_LENGTH];
    return true;
}
