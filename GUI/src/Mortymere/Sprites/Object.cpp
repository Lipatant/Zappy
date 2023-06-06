/*
** EPITECH PROJECT, 2023
** Mortymere/Sprites/Object.cpp
** File description:
** -
*/

#include "Mortymere/Sprites/Object.hpp"

#define OBJECT Mortymere::Sprites::Object

OBJECT::Object(void)
{
    _convex.setPointCount(4);
}

bool OBJECT::drawOn(Mortymere::Instance &instance, sf::RenderStates const \
    &states)
{
    float height = 1.296;
    float points[4][3] = \
        {{-0.5, 0, 0}, {-0.5, height, 0}, {0.5, height, 0}, {0.5, 0, 0}};
    sf::Vector2f scale = _convex.getScale();
    sf::Vector2f point;

    for (unsigned char i = 0; i < 4; i++) {
        point = instance.camera.inSpaceToOnScreen({ \
            _anchor.x + points[i][0], \
            _anchor.y + points[i][1], \
            _anchor.z + points[i][2]});
        point.x *= scale.x;
        point.y *= scale.y;
        _convex.setPoint(i, point);
    }
    _convex.setFillColor(sf::Color::White);
    instance.window.draw(_convex, states);
    return true;
}
