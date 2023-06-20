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
    /// @brief Window's icon
    sf::Image _icon;
    /// @brief If _icon has been loaded
    bool _iconIsLoaded = false;

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
    /// @brief Mouse position relative to the camera
    sf::Vector2f mouse;
    /// @brief Absolute mouse position
    sf::Vector2f mouseUI;

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
    /// @brief
    void update(void);
    /// @brief Sets the center of the window's view
    void setViewCenter(float const x, float const y);
    /// @brief Sets the center of the window's view
    void setViewCenter(sf::Vector2f const center);

public: // CONSTRUCTORS
    /// @brief Default constructor
    Window(void);
};

};
