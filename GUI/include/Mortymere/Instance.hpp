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
#include <SFML/Graphics/RectangleShape.hpp>
#include "Flags.hpp"
#include "Mortymere/Camera.hpp"
#include "Mortymere/Ground.hpp"
#include "Mortymere/SpritePtr.hpp"
#include "Mortymere/Window.hpp"

#define MORTYMERE_INSTANCE_DISPLAY_MODULE(FUNCTION) \
    void FUNCTION(Mortymere::Instance &instance, void *data)
#define MORTYMERE_INSTANCE_DISPLAY_MODULE_NODATA(FUNCTION) \
    void FUNCTION(Mortymere::Instance &instance, FLAG_UNUSED void *data)

namespace Mortymere {

/// @brief Display module function
using InstanceDisplayModuleType = void (*)(Mortymere::Instance &, void *);

/// @brief Display module function
using InstanceDisplayModule = struct InstanceDisplayModule_s {
    /// @brief Function
    Mortymere::InstanceDisplayModuleType function;
    /// @brief Type
    std::string type;
    /// @brief Data that can be brough. nullptr by default
    void *data;
};

class Instance {

public: // PUBLIC MEMBERS required to be initialized before PRIVATE MEMBERS
    /// @brief Window to use
    Mortymere::Window window;
    /// @brief Camera used for display information
    Mortymere::Camera camera;
    /// @brief Module functions displaying additional stuff on top of the
    ///     objects from _objects
    std::list<Mortymere::InstanceDisplayModule> displayModules;

private: // PRIVATE MEMBERS
    /// @brief Ground to display
    Mortymere::Ground _ground;
    /// @brief List of copies to the sprites
    std::list<Mortymere::SpritePtr> _objects;

public: // PUBLIC FUNCTIONS
    /// @brief Adds a Mortymere::InstanceDisplayModuleType to displayModules
    /// @param type (std::string const &) Type of Module (ui)
    /// @param function (Mortymere::InstanceDisplayModuleType)
    /// @param data (void *) (optional)
    void addDisplayModule(std::string const &type, \
        Mortymere::InstanceDisplayModuleType function);
    /// @brief Adds a Mortymere::InstanceDisplayModuleType to displayModules
    /// @param type (std::string const &) Type of Module (ui)
    /// @param function (Mortymere::InstanceDisplayModuleType)
    /// @param data (void *) (optional)
    void addDisplayModule(std::string const &type, \
        Mortymere::InstanceDisplayModuleType function, void *data);
    /// @brief Adds a SpritePtr to _objects
    /// @param objectPtr (Mortymere::SpritePtr) Pointer to the object
    void addObject(Mortymere::SpritePtr objectPtr);
    /// @brief Shape used for covering the entire screen
    sf::RectangleShape screenCover;
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
