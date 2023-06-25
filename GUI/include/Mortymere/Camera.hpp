/*
** EPITECH PROJECT, 2023
** Mortymere/Camera.hpp
** File description:
** -
*/

/// @file
/// @brief Regroups multiple values used for managing the camera

#pragma once

#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include "Mortymere/Window.hpp"

namespace Mortymere {

class Camera {

private: // PRIVATE MEMBERS
    size_t _scaleID;
    Mortymere::Window const &_window;

public: // PUBLIC MEMBERS
    sf::Vector3f center;
    double fov = 10;
    float scale;

public: // PUBLIC FUNCTIONS
    /// @param position (sf::Vector2f const) 2D position (y = 0)
    sf::Vector2f inSpaceToOnScreen(sf::Vector2f const position) const;
    /// @param position (sf::Vector3f const) 3D position
    sf::Vector2f inSpaceToOnScreen(sf::Vector3f const position) const;
    /// @brief Zooms in
    /// @return true, of false if couldn't zoom in
    bool zoomIn(void);
    /// @brief Zooms out
    /// @return true, of false if couldn't zoom out
    bool zoomOut(void);

public: // CONSTRUCTOR
    Camera(Mortymere::Window const &window);

};

};
