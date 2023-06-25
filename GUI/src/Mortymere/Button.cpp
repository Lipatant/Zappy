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
    if (!_texture.loadFromFile("GUI/" + filepath))
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
    return _value == -1 && _selected;
}

void BUTTON::reset(void)
{
    _hovered = false;
    _selected = false;
    _value = -2;
    if (_textureRect.top == 0)
        return;
    _textureRect.top = 0;
    setTextureRect(_textureRect);
}

Mortymere::Button const &BUTTON::update(sf::Vector2f const &mouseUI, bool \
    const input)
{
    bool pressed = false;
    sf::FloatRect bounds = getGlobalBounds();

    if (bounds.left <= mouseUI.x && \
        mouseUI.x <= bounds.left + bounds.width && \
        bounds.top <= mouseUI.y && mouseUI.y <= bounds.top + bounds.height)
        _hovered += (_hovered < 10) ? 1 : 0;
    else
        _hovered = 0;
    if (input)
        pressed = true;
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
    if (_value < 0 && !_hovered)
        _selected = false;
    if (_value == 1 && _hovered)
        _selected = true;
    _textureRect.top = (_selected && _hovered && _value > 0) ? \
        _textureRect.height : 0;
    setTextureRect(_textureRect);
    return *this;
}
