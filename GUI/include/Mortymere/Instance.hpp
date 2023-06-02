/*
** EPITECH PROJECT, 2023
** Mortymere/Instance.hpp
** File description:
** -
*/

/// @file
/// @brief Base instance of the engine

#pragma once

#include "Mortymere/Window.hpp"

namespace Mortymere {

class Instance {

public: // PUBLIC MEMBERS
    /// @brief Window to use
    Mortymere::Window window;

public: // PUBLIC FUNCTIONS
    bool udpate(void);

};

};
