/*
** EPITECH PROJECT, 2023
** Mortymere/Character.cpp
** File description:
** -
*/

#include "Citadel/Character.hpp"
#include "Mortymere/Sprites/Character.hpp"

#define CHARACTER Citadel::Character

CHARACTER::Character(MORTYMERE_CHARACTER_CONSTRUCTOR_ARGS(n, x, y, o, l, t))
{
    _filepath = "graphics/charact/Morty/Base.png";
    sprite = Mortymere::createSprite<Mortymere::Sprites::Character>(_filepath);
    setLevel(l);
    setNumber(n);
    setPosition(x, y);
    setRotation(o);
    setTeam(t);
}

void CHARACTER::setLevel(Citadel::CharacterLevel const level)
{
    _level = level;
}

void CHARACTER::setNumber(Citadel::CharacterNumber const number)
{
    _number = number;
}

void CHARACTER::setPosition(Citadel::CharacterPosition const positionX, \
    Citadel::CharacterPosition const positionY)
{
    _positionX = positionX;
    _positionY = positionY;
    sprite->anchor().x = positionX;
    sprite->anchor().z = positionY;
}

void CHARACTER::setRotation(Citadel::CharacterRotation const rotation)
{
    Mortymere::CharacterRotation characterRotation;

    switch (rotation) {
        case Citadel::CharacterRotation::Up:
            characterRotation = Mortymere::CharacterRotation::Up;
            break;
        case Citadel::CharacterRotation::Left:
            characterRotation = Mortymere::CharacterRotation::Left;
            break;
        case Citadel::CharacterRotation::Right:
            characterRotation = Mortymere::CharacterRotation::Right;
            break;
        default:
            characterRotation = Mortymere::CharacterRotation::Down;
    }
    _rotation = rotation;
    sprite->setCharacterRotation(characterRotation);
}

void CHARACTER::setTeam(Citadel::CharacterTeam const &team)
{
    _team = team;
}
