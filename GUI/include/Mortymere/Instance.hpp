/*
** EPITECH PROJECT, 2023
** Mortymere/Instance.hpp
** File description:
** -
*/

/// @file
/// @brief Base instance of the engine

#pragma once

#include "Mortymere/Camera.hpp"
#include "Mortymere/Ground.hpp"
#include "Mortymere/Window.hpp"

namespace Mortymere {

//class Ground;

class Instance {

public: // PUBLIC MEMBERS required to be initialized before PRIVATE MEMBERS
    /// @brief Window to use
    Mortymere::Window window;

private: // PRIVATE MEMBERS
    /// @brief Ground to display
    Mortymere::Ground _ground;
    /// @brief Camera used for display information
    Mortymere::Camera _camera;

public: // PUBLIC MEMBERS

public: // PUBLIC FUNCTIONS
    bool udpate(void);

public: // CONSTRUCTOR
    Instance(void);

};

};
