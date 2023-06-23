/*
** EPITECH PROJECT, 2023
** Mortymere/ISprite.hpp
** File description:
** -
*/

/// @file
/// @brief Abstract class representing a sprite

#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector3.hpp>
#include "Mortymere/Instance.hpp"

namespace Mortymere {

using SpritePositionType = sf::Vector3f;
using SpriteLayerType = short;
using SpriteRotation = float;
enum class CharacterRotation {
    Down,
    Left,
    Up,
    Right,
};

class ISprite {

public: // PUBLIC FUNCTIONS
    virtual Mortymere::SpritePositionType anchor(void) const = 0;
    virtual Mortymere::SpritePositionType &anchor(void) = 0;
    virtual Mortymere::SpriteLayerType layer(void) const = 0;
    virtual Mortymere::SpriteLayerType &layer(void) = 0;
    virtual bool drawOn(Mortymere::Instance &instance) = 0;
    virtual bool drawOn(Mortymere::Instance &instance, \
        sf::RenderStates const &states) = 0;
    /// @return Returns true, or false if no changes have been made
    virtual bool setCharacterRotation(Mortymere::CharacterRotation const \
        characterRotation) = 0;
    /// @param color New fill color to change
    virtual void setFillColor(sf::Color const color) = 0;
    /// @param color New outline color to change
    virtual void setOutlineColor(sf::Color const color) = 0;

public: // DESTRUCTOR
    virtual ~ISprite() = default;

};

};
