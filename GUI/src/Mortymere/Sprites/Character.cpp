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
    _sprite.setTexture(&_texture);
    _textureRect = _sprite.getTextureRect();
    setCharacterRotation(Mortymere::CharacterRotation::Down);
}

bool CHARACTER::setCharacterRotation(Mortymere::CharacterRotation const \
    characterRotation)
{
    sf::Vector2i spriteSize;
    int gap = 4;

    if (characterRotation == _characterRotation)
        return false;
    if (_textureRect.width == 525)
        gap = 5;
    spriteSize.x = (_textureRect.width - gap * 5) / 4;
    spriteSize.y = (_textureRect.height - gap * 4) / 3;
    if (characterRotation == Mortymere::CharacterRotation::Right) {
        _sprite.setScale(-1.0f, 1.0f);
        _textureRectTransformed.top = gap + static_cast<int>( \
            Mortymere::CharacterRotation::Left) * (spriteSize.y + gap);
    } else {
        _sprite.setScale(1.0f, 1.0f);
        _textureRectTransformed.top = gap + static_cast<int>( \
            characterRotation) * (spriteSize.y + gap);
    }
    _textureRectTransformed.left = gap;
    _textureRectTransformed.width = spriteSize.x;
    _textureRectTransformed.height = spriteSize.y;
    _sprite.setTextureRect(_textureRectTransformed);
    _characterRotation = characterRotation;
    return true;
}
