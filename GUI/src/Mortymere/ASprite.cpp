/*
** EPITECH PROJECT, 2023
** Mortymere/ASprite.cpp
** File description:
** -
*/

#include "Flags.hpp"
#include "Mortymere/ASprite.hpp"

#define ASPRITE Mortymere::ASprite

Mortymere::SpritePositionType ASPRITE::anchor(void) const
{
    return _anchor;
}

Mortymere::SpritePositionType &ASPRITE::anchor(void)
{
    return _anchor;
}

bool ASPRITE::drawOn(Mortymere::Instance &instance)
{
    return drawOn(instance, sf::RenderStates::Default);
}

bool ASPRITE::drawOn(FLAG_UNUSED Mortymere::Instance &instance, FLAG_UNUSED \
    sf::RenderStates const &states)
{
    return true;
}

bool ASPRITE::setCharacterRotation(FLAG_UNUSED Mortymere::CharacterRotation \
    const characterRotation)
{
    return false;
}
