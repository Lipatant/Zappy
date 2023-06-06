/*
** EPITECH PROJECT, 2023
** Mortymere/Citadel.hpp
** File description:
** -
*/

/// @file
/// @brief Base instance of the GUI logic

#pragma once

#include <map>
#include "Citadel/Character.hpp"

namespace Citadel {

/// @brief Class representing a Citadel for the game to take place
class Instance {

protected: // PROTECTED MEMBERS
    std::map<std::size_t, Citadel::Character> _characters;

public: // PUBLIC MEMBERS

public: // PUBLIC FUNCTIONS

public: // PUBLIC MEMBERS
    Instance(void);

};

};
