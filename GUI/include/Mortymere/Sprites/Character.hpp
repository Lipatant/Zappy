/*
** EPITECH PROJECT, 2023
** Mortymere/Sprites/Character.hpp
** File description:
** -
*/

/// @file
/// @brief Class inheriting from Object and representing a Character

#pragma once

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "Mortymere/Sprites/Object.hpp"

namespace Mortymere { namespace Sprites {

class Character : public Mortymere::Sprites::Object {

protected: // PROTECTED MEMBERS
    std::string _filepath;
    sf::Texture _texture;
    sf::IntRect _textureRect;
    sf::IntRect _textureRectTransformed;
    Mortymere::CharacterRotation _characterRotation;

public: // PUBLIC FUNCTIONS
    bool setCharacterRotation(Mortymere::CharacterRotation const \
        characterRotation) override;

public: // CONSTRUCTOR
    Character(void);
    Character(std::string const &filepath);

};

}};
