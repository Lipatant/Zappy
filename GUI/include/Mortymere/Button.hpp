/*
** EPITECH PROJECT, 2023
** Mortymere/Button.hpp
** File description:
** -
*/

/// @file
/// @brief Class representing a Button

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#pragma once

namespace Mortymere {

using ButtonValue = int;

/// @brief Class inheriting from sf::Sprite
class Button : public sf::Sprite {

private: // PRIVATE MEMBERS
    /// @brief
    unsigned char _hovered = 0;
    /// @brief If _texture is laoded
    bool _isTextureLoaded = false;
    /// @brief
    bool _selected = false;
    /// @brief Texture of the sprite
    sf::Texture _texture;
    /// @brief Texture rect of the sprite
    sf::IntRect _textureRect;
    /// @brief Current pressing value
    Mortymere::ButtonValue _value = -2;

public: // PUBLIC FUNCTIONS
    bool hasBeenPressed(void) const;
    void reset(void);
    Mortymere::Button const &update(sf::Vector2f const &mouseUI, bool const \
        input);

public: // CONSTRUCTOR
    Button(std::string const &filepath);

};

};
