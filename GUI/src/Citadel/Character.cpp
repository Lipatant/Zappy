/*
** EPITECH PROJECT, 2023
** Mortymere/Character.cpp
** File description:
** -
*/

#include <exception>
#include <filesystem>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Citadel/Character.hpp"
#include "Mortymere/Sprites/Character.hpp"

static const std::string VARIANCES[] = {
    "Morty/",
    "Rick/",
    "Jerry/",
};
static const std::size_t VARIANCES_LENGTH = \
    sizeof(VARIANCES) / sizeof(VARIANCES[0]);

#define CHARACTER Citadel::Character

CHARACTER::Character(MORTYMERE_CHARACTER_CONSTRUCTOR_ARGS(n, x, y, o, l, t))
{
    std::vector<std::string> paths = {};

    try {
        for (auto const &directory: VARIANCES)
            for (auto const &file: std::filesystem::directory_iterator( \
                "graphics/charact/" + directory))
                paths.push_back(file.path());
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    if (paths.size() >= 1) {
        _filepath = paths[rand() % paths.size()];
        sprite = Mortymere::createSprite<Mortymere::Sprites::Character>( \
            _filepath);
    } else {
        std::cerr << "No file found for a character sprite" << std::endl;
        sprite = nullptr;
    }
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
    if (sprite) {
        sprite->anchor().x = positionX;
        sprite->anchor().z = positionY;
    }
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
    if (sprite)
        sprite->setCharacterRotation(characterRotation);
}

void CHARACTER::setTeam(Citadel::CharacterTeam const &team)
{
    _team = team;
}
