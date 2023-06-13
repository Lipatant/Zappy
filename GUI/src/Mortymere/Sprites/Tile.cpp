/*
** EPITECH PROJECT, 2023
** Mortymere/Sprites/Tile.cpp
** File description:
** -
*/

#include "Mortymere/Sprites/Tile.hpp"

#define TILE Mortymere::Sprites::Tile

TILE::Tile(void)
{
    _convex.setPointCount(4);
}

TILE::Tile(sf::Color const &color)
{
    _convex.setPointCount(4);
    _convex.setFillColor(color);
}

TILE::Tile(sf::Color const &fillColor, sf::Color const &outlineColor, \
    float const outlineThickness)
{
    _convex.setPointCount(4);
    _convex.setFillColor(fillColor);
    _convex.setOutlineColor(outlineColor);
    _convex.setOutlineThickness(outlineThickness);
}

bool TILE::drawOn(Mortymere::Instance &instance, sf::RenderStates const \
    &states)
{
    float points[4][3] = \
        {{-0.5, 0, -0.5}, {-0.5, 0, 0.5}, {0.5, 0, 0.5}, {0.5, 0, -0.5}};
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
    instance.window.draw(_convex, states);
    return true;
}
