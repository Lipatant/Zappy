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

Mortymere::Window::Window(void) : mouse(0, 0), mouseUI(0, 0)
{
    if (_icon.loadFromFile("GUI/graphics/Icon.png") || \
        _icon.loadFromFile("graphics/Icon.png"))
        _iconIsLoaded = true;
    _createWindow();
}

bool Mortymere::Window::_createWindow(bool const fullscreen)
{
    if (fullscreen)
        create(WINDOW_CREATE_GENERIC, WINDOW_CREATE_FULLSCREEN);
    else
        create(WINDOW_CREATE_GENERIC, WINDOW_CREATE_WINDOWED);
    if (_iconIsLoaded)
        setIcon(_icon.getSize().x, _icon.getSize().y, _icon.getPixelsPtr());
    setFramerateLimit(60);
    setViewCenter(0, 0);
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
#include <iostream>
void Mortymere::Window::update(void)
{
    sf::Vector2f windowRatio(getWindowRatio(*this));
    sf::View view(getView());
    sf::Vector2f viewCenter(view.getCenter());
    sf::FloatRect viewport;
    sf::Vector2i positionPixels = sf::Mouse::getPosition(*this);

    view.setSize(SCREENSIZE_X, SCREENSIZE_Y);
    viewport = sf::FloatRect(1, 1, windowRatio.x, windowRatio.y);
    viewport.left = (1 - viewport.width) / 2;
    viewport.top = (1 - viewport.height) / 2;
    view.setCenter(0, 0);
    mouseUI = mapPixelToCoords(positionPixels, view);
    if (mouseUI.x > SCREENSIZE_X * 0.5)
        mouseUI.x = SCREENSIZE_X * 0.5;
    if (mouseUI.x < SCREENSIZE_X * -0.5)
        mouseUI.x = SCREENSIZE_X * -0.5;
    if (mouseUI.y > SCREENSIZE_Y * 0.5)
        mouseUI.y = SCREENSIZE_Y * 0.5;
    if (mouseUI.y < SCREENSIZE_Y * -0.5)
        mouseUI.y = SCREENSIZE_Y * -0.5;
    view.setCenter(viewCenter);
    mouse = mapPixelToCoords(positionPixels, view);
    view.setViewport(viewport);
    setView(view);
}

void Mortymere::Window::setViewCenter(float const x, float const y)
{
    sf::View view(getView());

    view.setCenter(x, y);
    setView(view);
}

void Mortymere::Window::setViewCenter(sf::Vector2f const center)
{
    sf::View view(getView());

    view.setCenter(center);
    setView(view);
}
