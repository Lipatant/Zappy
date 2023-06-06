/*
** EPITECH PROJECT, 2023
** Mortymere/Sprites/Object.hpp
** File description:
** -
*/

/// @file
/// @brief Class inheriting from ASprites

#pragma once

#include "Mortymere/ASprite.hpp"
#include <SFML/Graphics/ConvexShape.hpp>

namespace Mortymere { namespace Sprites {

class Object : public Mortymere::ASprite {

protected: // PROTECTED MEMBERS
    sf::ConvexShape _convex;

public: // PUBLIC FUNCTIONS
    bool drawOn(Mortymere::Instance &instance, sf::RenderStates const \
        &states) override;

public: // CONSTRUCTOR
    Object(void);

};

}};
