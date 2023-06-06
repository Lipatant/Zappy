/*
** EPITECH PROJECT, 2023
** Mortymere/Sprites/Character.cpp
** File description:
** -
*/

#include <iostream>
#include "Mortymere/Sprites/Character.hpp"

#define CHARACTER Mortymere::Sprites::Character

CHARACTER::Character(std::string const &filepath) : _filepath(filepath)
{
    _characterRotation = Mortymere::CharacterRotation::Up;
    if (!_texture.loadFromFile(filepath)) {
        std::cerr << "Couldn't load a texture from '" << filepath << '\'' \
            << std::endl;
        return;
    }
    _convex.setTexture(&_texture);
    _textureRect = _convex.getTextureRect();
    setCharacterRotation(Mortymere::CharacterRotation::Down);
}

bool CHARACTER::setCharacterRotation(Mortymere::CharacterRotation const \
    characterRotation)
{
    sf::Vector2i spriteSize;

    if (characterRotation == _characterRotation)
        return false;
    spriteSize.x = (_textureRect.width - 4 * 5) / 4;
    spriteSize.y = (_textureRect.height - 4 * 4) / 3;
    if (characterRotation == Mortymere::CharacterRotation::Right) {
        _convex.setScale(-1.0f, 1.0f);
        _textureRectTransformed.top = 4 + static_cast<int>( \
            Mortymere::CharacterRotation::Left) * (spriteSize.y + 4);
    } else {
        _convex.setScale(1.0f, 1.0f);
        _textureRectTransformed.top = 4 + static_cast<int>( \
            characterRotation) * (spriteSize.y + 4);
    }
    _textureRectTransformed.left = 4;
    _textureRectTransformed.width = spriteSize.x;
    _textureRectTransformed.height = spriteSize.y;
    _convex.setTextureRect(_textureRectTransformed);
    _characterRotation = characterRotation;
    return true;
}
