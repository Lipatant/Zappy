/*
** EPITECH PROJECT, 2023
** Mortymere/Window.hpp
** File description:
** -
*/

/// @file
/// @brief Encapsulation of a SFML Window

#pragma once

#include <SFML/Graphics.hpp>

namespace Mortymere {

class Window : public sf::RenderWindow {

private: // PRIVATE MEMBERS
    /// @brief
    bool _isFullscreen = false;

private: // PRIVATE FUNCTIONS
    /// @param fullscreen (bool const) If the window has to be fullscreen
    ///     (optional, false by default)
    /// @return true, or false if a problem is encountered
    bool _createWindow(bool const fullscreen);
    /// @param fullscreen (bool const) If the window has to be fullscreen
    ///     (optional, false by default)
    /// @return true, or false if a problem is encountered
    bool _createWindow(void);

public: // PUBLIC MEMBERS
    /// @brief
    bool hasFocus = true;

public: // PUBLIC FUNCTIONS
    /// @return true/false
    bool isFullscreen(void) const;
    /// @param fullscreen (bool const) If the window has to be fullscreen
    ///     (true) or windowed (false) (optional, inverted by default)
    /// @return true, or false if a problem is encountered
    bool setFullscreen(bool const fullscreen);
    /// @param fullscreen (bool const) If the window has to be fullscreen
    ///     (true) or windowed (false) (optional, inverted by default)
    /// @return true, or false if a problem is encountered
    bool setFullscreen(void);

public: // CONSTRUCTORS
    /// @brief Default constructor
    Window(void);
};

};
