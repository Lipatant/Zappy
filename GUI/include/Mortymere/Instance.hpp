/*
** EPITECH PROJECT, 2023
** Mortymere/Instance.hpp
** File description:
** -
*/

/// @file
/// @brief Base instance of the engine

#pragma once

#include <list>
#include "Mortymere/Camera.hpp"
#include "Mortymere/Ground.hpp"
#include "Mortymere/SpritePtr.hpp"
#include "Mortymere/Window.hpp"

namespace Mortymere {

class Instance {

public: // PUBLIC MEMBERS required to be initialized before PRIVATE MEMBERS
    /// @brief Window to use
    Mortymere::Window window;
    /// @brief Camera used for display information
    Mortymere::Camera camera;

private: // PRIVATE MEMBERS
    /// @brief Ground to display
    Mortymere::Ground _ground;
    /// @brief List of copies to the sprites
    std::list<Mortymere::SpritePtr> _objects;

public: // PUBLIC FUNCTIONS
    /// @brief Adds a SpritePtr to _objects
    /// @param objectPtr (Mortymere::SpritePtr) Pointer to the object
    void addObject(Mortymere::SpritePtr objectPtr);
    /// @return Returns true, or false if the window is closed
    bool udpate(void);

public: // OPERATORS
    /// @brief Adds a SpritePtr to _objects. Equivalent of addObject
    /// @param objectPtr (Mortymere::SpritePtr) Pointer to the object
    void operator<<(Mortymere::SpritePtr objectPtr);

public: // CONSTRUCTOR
    Instance(void);

};

};
