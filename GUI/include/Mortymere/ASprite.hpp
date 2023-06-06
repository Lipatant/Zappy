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

public: // PUBLIC FUNCTIONS
    Mortymere::SpritePositionType anchor(void) const override;
    Mortymere::SpritePositionType &anchor(void) override;
    bool drawOn(Mortymere::Instance &instance) override;
    bool drawOn(Mortymere::Instance &instance, sf::RenderStates const \
        &states) override;
    bool setCharacterRotation(Mortymere::CharacterRotation const \
        characterRotation) override;

};

};
