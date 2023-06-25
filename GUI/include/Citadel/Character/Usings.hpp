/*
** EPITECH PROJECT, 2023
** Citadel/Character/Usings.hpp
** File description:
** -
*/

/// @file
/// @brief Using used for Characters

#pragma once

#include <string>

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

};
