/*
** EPITECH PROJECT, 2023
** Mortymere/Window.cpp
** File description:
** -
*/

#include "Mortymere/Window.hpp"

#define WINDOW_CREATE_GENERIC sf::VideoMode::getDesktopMode(), "Citadel"
#define WINDOW_CREATE_WINDOWED sf::Style::Close | sf::Style::Resize
#define WINDOW_CREATE_FULLSCREEN sf::Style::Close | sf::Style::Fullscreen

Mortymere::Window::Window(void)
{
    _createWindow();
}

bool Mortymere::Window::_createWindow(bool const fullscreen)
{
    if (fullscreen)
        create(WINDOW_CREATE_GENERIC, WINDOW_CREATE_FULLSCREEN);
    else
        create(WINDOW_CREATE_GENERIC, WINDOW_CREATE_WINDOWED);
    setFramerateLimit(60);
    _isFullscreen = fullscreen;
    return isOpen();
}

bool Mortymere::Window::_createWindow(void)
{
    return _createWindow(false);
}

bool Mortymere::Window::isFullscreen(void) const
{
    return _isFullscreen;
}

bool Mortymere::Window::setFullscreen(bool const fullscreen)
{
    return _createWindow(fullscreen);
}

bool Mortymere::Window::setFullscreen(void)
{
    return _createWindow(!_isFullscreen);
}
