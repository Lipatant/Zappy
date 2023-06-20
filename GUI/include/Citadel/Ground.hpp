/*
** EPITECH PROJECT, 2023
** Mortymere/Ground.hpp
** File description:
** -
*/

/// @file
/// @brief Class representing the ground of the citadel

#pragma once

#include <list>
#include "Mortymere/Sprite.hpp"

namespace Citadel {

class Ground {

protected: // PROTECTED MEMBERS
    /// @brief X size of the ground
    std::size_t _sizeX = 0;
    /// @brief Y size of the ground
    std::size_t _sizeY = 0;

public: // PUBLIC MEMBERS
    /// @brief List of sprites composing the ground
    std::list<Mortymere::Sprite> sprites = {};

public: // PUBLIC FUNCTIONS
    /// @return true, or false if nothing has been changed
    bool changeSize(size_t const x, size_t const y);
    /// @return _sizeX
    std::size_t getSizeX(void);
    /// @return _sizeY
    std::size_t getSizeY(void);

};

};
