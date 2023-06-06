/*
** EPITECH PROJECT, 2023
** Mortymere/Sprite.hpp
** File description:
** -
*/

/// @file
/// @brief Pointer to an Sprite

#pragma once

#include <memory>
#include "Mortymere/ISprite.hpp"

namespace Mortymere {

class ISprite;

using Sprite = std::shared_ptr<Mortymere::ISprite>;

template <typename T, typename... _Args>
static Mortymere::Sprite createSprite(_Args&&... __args)
{
    return std::make_shared<T>(std::forward<_Args>(__args)...);
}

};
