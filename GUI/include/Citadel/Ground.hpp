/*
** EPITECH PROJECT, 2023
** Citadel/Ground.hpp
** File description:
** -
*/

/// @file
/// @brief Class representing the ground of the citadel

#pragma once

#include <list>
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include "Citadel/Character/Usings.hpp"
#include "Citadel/Inventory.hpp"
#include "Mortymere/Sprite.hpp"

namespace Citadel {

using GroundInventoryKey = std::pair<Citadel::CharacterPosition, \
    Citadel::CharacterPosition>;

class Ground {

protected: // PROTECTED MEMBERS
    /// @brief X size of the ground
    std::size_t _sizeX = 0;
    /// @brief Y size of the ground
    std::size_t _sizeY = 0;

public: // PUBLIC MEMBERS
    /// @brief List of sprites composing the ground
    std::list<Mortymere::Sprite> sprites = {};
    /// @brief List of sprites composing the items on the ground
    std::list<Mortymere::Sprite> itemSprites = {};
    /// @brief Map containing data about stuff on the ground
    std::map<Citadel::GroundInventoryKey, Citadel::Inventory> inventories = \
        {};
    /// @brief
    sf::Texture itemTexture;
    /// @brief If itemTexture is loaded
    bool hasItemTexture = false;

public: // PUBLIC FUNCTIONS
    /// @return true, or false if nothing has been changed
    bool changeSize(size_t const x, size_t const y);
    /// @return _sizeX
    std::size_t getSizeX(void);
    /// @return _sizeY
    std::size_t getSizeY(void);

public: // CONSTRUCTOR
    Ground(void);

};

};
