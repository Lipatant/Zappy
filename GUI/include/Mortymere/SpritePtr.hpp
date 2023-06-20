/*
** EPITECH PROJECT, 2023
** Mortymere/SpritePtr.hpp
** File description:
** -
*/

/// @file
/// @brief Weak pointer to a ISprite

#pragma once

#include <memory>
#include "Mortymere/ISprite.hpp"

namespace Mortymere {

class ISprite;

/// @brief Weak pointer to a ISprite, used alongside Sprite
using SpritePtr = std::weak_ptr<Mortymere::ISprite>;

};
