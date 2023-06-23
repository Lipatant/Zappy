/*
** EPITECH PROJECT, 2023
** Mortymere/Button.cpp
** File description:
** -
*/

#include "Mortymere/Button.hpp"

#define BUTTON Mortymere::Button

BUTTON::Button(std::string const &filepath)
{
    if (!_texture.loadFromFile("GUI" + filepath))
        if (!_texture.loadFromFile(filepath))
            return;
    setTexture(_texture);
    _isTextureLoaded = true;
    _textureRect = getTextureRect();
    _textureRect.height /= 2;
    setTextureRect(_textureRect);
}

bool BUTTON::hasBeenPressed(void) const
{
    return _value == -1;
}

void BUTTON::reset(void)
{
    _value = -2;
}

Mortymere::Button const &BUTTON::update(sf::Vector2f const &mouseUI, bool \
    const input)
{
    bool pressed = false;
    sf::FloatRect bounds = getGlobalBounds();

    if (input && _value > 0)
        pressed = true;
    else if (input)
        pressed = bounds.left <= mouseUI.x && \
            mouseUI.x <= bounds.left + bounds.width && \
            bounds.top <= mouseUI.y && mouseUI.y <= bounds.top + bounds.height;
    if (!pressed) {
        if (_value > -1)
            _value = -1;
        else if (_value > -10)
            _value--;
    } else {
        if (_value < 1)
            _value = 1;
        else if (_value < 10)
            _value++;
    }
    _textureRect.top = (_value > 1) ? _textureRect.height : 0;
    setTextureRect(_textureRect);
    return *this;
}
