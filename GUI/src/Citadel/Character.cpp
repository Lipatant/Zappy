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
#include "Utility/Regex.hpp"

#define REGEX_BASE_VARIANCE "Base" //\\/[Bb][Aa][Ss][Ee]\\.\\w+[\"']?$

struct Variance_s {
    std::string name;
    std::string path;
    int weigth;
    bool forceVariance;
};

static const Variance_s VARIANCES[] = {
    {"Rick", "Rick/", 55, false},
    {"Morty", "Morty/", 25, false},
    {"Jerry", "Jerry/", 10, false},
    {"Summer", "Summer/", 6, false},
    {"Beth", "Beth/", 2, false},
    {"???", "Other/", 2, true},
};
static const std::size_t VARIANCES_LENGTH = \
    sizeof(VARIANCES) / sizeof(VARIANCES[0]);
static const int VARIANCES_TOTAL_WEIGTH = 100;

#define CHARACTER Citadel::Character

CHARACTER::Character(MORTYMERE_CHARACTER_CONSTRUCTOR_ARGS(n, x, y, o, l, t))
{
    Variance_s variance = {"", "", 0, false};
    bool variant = true;
    int varianceWeigth = rand() % VARIANCES_TOTAL_WEIGTH;
    int varianceWeigthCumulated = 0;
    std::vector<std::string> paths = {};
    std::string portraitPath = "";

    for (Variance_s const &selectedVariance: VARIANCES) {
        variance = selectedVariance;
        varianceWeigthCumulated += variance.weigth;
        if (varianceWeigth < varianceWeigthCumulated)
            break;
    }
    if (!variance.forceVariance)
        variant = (rand() % 100 < 30);
    try {
        for (auto const &file: std::filesystem::directory_iterator( \
            "graphics/charact/" + variance.path)) {
            if (variant || file.path() == "graphics/charact/" + variance.path \
                + "Base.png")
                paths.push_back(file.path());
        }
    } catch (...) { }
    try {
        for (auto const &file: std::filesystem::directory_iterator( \
            "GUI/graphics/charact/" + variance.path)) {
            if (variant || file.path() == "GUI/graphics/charact/" + \
                variance.path + "Base.png")
                paths.push_back(file.path());
        }
    } catch (...) { }
    if (paths.size() >= 1) {
        _filepath = paths[rand() % paths.size()];
        sprite = Mortymere::createSprite<Mortymere::Sprites::Character>( \
            _filepath);
        portraitPath = _filepath;
        std::size_t portraitPathFetch = portraitPath.find("/charact/");
        if (portraitPathFetch != std::string::npos) {
            portraitPath.replace(portraitPathFetch, 9, "/portrait/");
            spritePortraitTextures.push_back(portraitPath);
        }
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
