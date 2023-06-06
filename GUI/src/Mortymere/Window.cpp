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
#define SCREENSIZE_X 1000
#define SCREENSIZE_Y 1000

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

static sf::Vector2f getWindowRatio(sf::Window const &window)
{
    sf::Vector2u size(window.getSize());
    sf::Vector2f ratio(1, 1);

    if (size.x > size.y)
        ratio.x = (float)size.y / size.x;
    else
        ratio.y = (float)size.x / size.y;
    return ratio;
}

void Mortymere::Window::update(void)
{
    sf::Vector2f windowRatio(getWindowRatio(*this));
    sf::View view(getView());
    sf::FloatRect viewport;

    view.setSize(SCREENSIZE_X, SCREENSIZE_Y);
    viewport = sf::FloatRect(1, 1, windowRatio.x, windowRatio.y);
    viewport.left = (1 - viewport.width) / 2;
    viewport.top = (1 - viewport.height) / 2;
    view.setCenter(0, 0);
    view.setViewport(viewport);
    setView(view);
}
