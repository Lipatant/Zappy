/*
** EPITECH PROJECT, 2023
** Mortymere/Ground.hpp
** File description:
** -
*/

/// @file
/// @brief Class representing a Ground

#pragma once

#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Mortymere/Camera.hpp"

namespace Mortymere {

class Instance;

class Ground : public sf::Drawable {

private: // INHERITED PRIVATE MEMBERS
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private: // PRIVATE MEMBERS
    sf::ConvexShape _convex;

public: // PUBLIC MEMBERS

public: // PUBLIC FUNCTIONS
    /// @param camera (Mortymere::Camera const &)
    void drawOn(Mortymere::Camera const &camera, sf::RenderTarget &target);
    /// @param camera (Mortymere::Camera const &)
    void drawOn(Mortymere::Camera const &camera, sf::RenderTarget &target, \
        sf::RenderStates states);

public: // CONSTRUCTORS
    /// @brief Default constructor
    Ground(void);

};

};
