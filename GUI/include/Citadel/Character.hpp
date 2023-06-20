/*
** EPITECH PROJECT, 2023
** Mortymere/Character.hpp
** File description:
** -
*/

/// @file
/// @brief Class representing a character

#pragma once

#include <string>
#include "Mortymere/Sprite.hpp"

#define MORTYMERE_CHARACTER_CONSTRUCTOR_ARGS(N, X, Y, O, L, TEAM) \
    Citadel::CharacterNumber const N, \
    Citadel::CharacterPosition const X, Citadel::CharacterPosition const Y, \
    Citadel::CharacterRotation const O, Citadel::CharacterLevel const L, \
    Citadel::CharacterTeam const &TEAM

namespace Citadel {

using CharacterNumber = std::size_t;
using CharacterPosition = int;
using CharacterLevel = std::size_t;
using CharacterTeam = std::string;
enum class CharacterRotation {
    Up = 1,
    Right = 2,
    Down = 3,
    Left = 4,
};

/// @brief Class representing a character
class Character {

private: // PRIVATE MEMBERS
    std::string _filepath;

protected: // PROTECTED MEMBERS
    Citadel::CharacterNumber _number;
    Citadel::CharacterPosition _positionX;
    Citadel::CharacterPosition _positionY;
    Citadel::CharacterRotation _rotation;
    Citadel::CharacterLevel _level;
    Citadel::CharacterTeam _team;

public: // PUBLIC MEMBERS
    Mortymere::Sprite sprite;
    sf::Sprite spritePortrait;
    std::vector<std::string> spritePortraitTextures;

public: // PUBLIC FUNCTIONS
    /// @param level (Citadel::CharacterLevel const) New value of
    ///     _level
    void setLevel(Citadel::CharacterLevel const level);
    /// @param number (Citadel::CharacterNumber const) New value of
    ///     _number
    void setNumber(Citadel::CharacterNumber const number);
    /// @param positionX (Citadel::CharacterPosition const) New value of
    ///     _positionX
    /// @param positionY (Citadel::CharacterPosition const) New value of
    ///     _positionY
    void setPosition(Citadel::CharacterPosition const positionX, \
        Citadel::CharacterPosition const positionY);
    /// @param rotation (Citadel::CharacterNumber const) New value of
    ///     _rotation
    void setRotation(Citadel::CharacterRotation const rotation);
    /// @param team (Citadel::CharacterLevel const) New value of
    ///     _team
    void setTeam(Citadel::CharacterTeam const &team);

public: // CONSTRUCTOR
    Character(MORTYMERE_CHARACTER_CONSTRUCTOR_ARGS(n, x, y, o, l, t));

};

};
