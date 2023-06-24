/*
** EPITECH PROJECT, 2023
** Citadel/Sprites/Items.hpp
** File description:
** -
*/

/// @file
/// @brief Class inheriting from Object and representing Items

#pragma once

#include "Citadel/Ground.hpp"
#include "Mortymere/Sprites/Object.hpp"

namespace Citadel { namespace Sprites {

class Items : public Mortymere::Sprites::Object {

protected: // PROTECTED MEMBERS
    /// @brief Pointer to a Citadel::Ground to be based of
    Citadel::Ground const *_ground;
    /// @brief Corresponding tile
    Citadel::GroundInventoryKey const _tile;

public: // PUBLIC FUNCTIONS
    bool drawOn(Mortymere::Instance &instance, sf::RenderStates const \
        &states) override;

public: // CONSTRUCTOR
    Items(Citadel::Ground const *ground, Citadel::GroundInventoryKey const \
        &tile);

};

}};
