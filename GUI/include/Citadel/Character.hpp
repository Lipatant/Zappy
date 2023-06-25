/*
** EPITECH PROJECT, 2023
** Citadel/Character.hpp
** File description:
** -
*/

/// @file
/// @brief Class representing a character

#pragma once

#include <string>
#include <SFML/System/Clock.hpp>
#include "Citadel/Character/Usings.hpp"
#include "Citadel/Inventory.hpp"
#include "Citadel/Sprites/Items.hpp"
#include "Mortymere/Sprite.hpp"

#define MORTYMERE_CHARACTER_CONSTRUCTOR_ARGS(N, X, Y, O, L, TEAM) \
    Citadel::CharacterNumber const N, \
    Citadel::CharacterPosition const X, Citadel::CharacterPosition const Y, \
    Citadel::CharacterRotation const O, Citadel::CharacterLevel const L, \
    Citadel::CharacterTeam const &TEAM

namespace Citadel {

/// @brief Class representing a character
class Character {

private: // PRIVATE MEMBERS
    /// @brief Name of the character
    std::string _name;
    /// @brief Filepath of the character sprite
    std::string _filepath;
    /// @brief Clock measuring time since the last movement
    sf::Clock _movementTransitionClock;
    /// @brief If the character is currently moving
    bool _isInMovementTransition = false;

protected: // PROTECTED MEMBERS
    Citadel::CharacterNumber _number;
    Citadel::CharacterPosition _positionX;
    Citadel::CharacterPosition _positionY;
    float _positionXOld;
    float _positionYOld;
    Citadel::CharacterRotation _rotation;
    Citadel::CharacterLevel _level;
    Citadel::CharacterTeam _team;

public: // PUBLIC MEMBERS
    Citadel::Inventory inventory;
    Mortymere::Sprite sprite;
    sf::Sprite spritePortrait;
    std::vector<std::string> spritePortraitTextures;

public: // PUBLIC FUNCTIONS
    /// @return Value of _level
    Citadel::CharacterLevel getLevel(void);
    /// @return Value of _name
    std::string const &getName(void);
    /// @return Value of _team
    Citadel::CharacterTeam getTeam(void);
    /// @return Value of _positionX
    Citadel::CharacterPosition getPositionX(void);
    /// @return Value of _positionY
    Citadel::CharacterPosition getPositionY(void);
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
    /// @brief
    void update(void);

public: // CONSTRUCTOR
    Character(MORTYMERE_CHARACTER_CONSTRUCTOR_ARGS(n, x, y, o, l, t));

};

};
