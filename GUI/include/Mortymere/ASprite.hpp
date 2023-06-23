/*
** EPITECH PROJECT, 2023
** Mortymere/ASprite.hpp
** File description:
** -
*/

/// @file
/// @brief Class inheriting from ISprite

#pragma once

#include "Mortymere/ISprite.hpp"

namespace Mortymere {

class ASprite : public Mortymere::ISprite {

protected: // PROTECTED MEMBERS
    Mortymere::SpritePositionType _anchor = {0, 0, 0};
    Mortymere::SpriteLayerType _layer = 0;
    sf::Color _fillColor = sf::Color::White;
    sf::Color _outlineColor = sf::Color::Transparent;

public: // PUBLIC FUNCTIONS
    Mortymere::SpritePositionType anchor(void) const override;
    Mortymere::SpritePositionType &anchor(void) override;
    Mortymere::SpriteLayerType layer(void) const override;
    Mortymere::SpriteLayerType &layer(void) override;
    bool drawOn(Mortymere::Instance &instance) override;
    bool drawOn(Mortymere::Instance &instance, sf::RenderStates const \
        &states) override;
    bool setCharacterRotation(Mortymere::CharacterRotation const \
        characterRotation) override;
    void setFillColor(sf::Color const color) override;
    void setOutlineColor(sf::Color const color) override;

};

};
