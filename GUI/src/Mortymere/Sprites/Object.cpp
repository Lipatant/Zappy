/*
** EPITECH PROJECT, 2023
** Mortymere/Sprites/Object.cpp
** File description:
** -
*/

#include "Mortymere/Sprites/Object.hpp"

#define OBJECT Mortymere::Sprites::Object

OBJECT::Object(void)
{ }

bool OBJECT::drawOn(Mortymere::Instance &instance, sf::RenderStates const \
    &states)
{
    float height = 1.296;
    sf::Vector2f scale = _sprite.getScale();
    Mortymere::SpritePositionType cornerAnchorA = _anchor;
    Mortymere::SpritePositionType cornerAnchorB = _anchor;
    sf::Vector2f cornerA;
    sf::Vector2f cornerB;

    _sprite.setFillColor(_fillColor);
    cornerAnchorA.x -= 0.5; cornerAnchorB.x += 0.5; cornerAnchorB.y += height;
    if (scale.x < 0) {
        cornerAnchorA.x += 1;
        cornerAnchorB.x += 1;
    }
    cornerA = instance.camera.inSpaceToOnScreen(cornerAnchorA);
    cornerB = instance.camera.inSpaceToOnScreen(cornerAnchorB);
//    cornerA.x *= scale.x; cornerA.y *= scale.y;
//    cornerB.x *= scale.x; cornerB.y *= scale.y;
    _sprite.setPosition(cornerA + sf::Vector2f(-3, 5));
    _sprite.setSize(cornerB - cornerA);
    instance.window.draw(_sprite, states);
    return true;
}
