/*
** EPITECH PROJECT, 2023
** Mortymere/Ground.cpp
** File description:
** -
*/

#include "Mortymere/Ground.hpp"

#include "Flags.hpp"

Mortymere::Ground::Ground(void)
{
    _convex.setPointCount(4);
}

void Mortymere::Ground::draw(sf::RenderTarget &target, sf::RenderStates \
    states) const
{
    target.draw(_convex, states);
}

void Mortymere::Ground::drawOn(Mortymere::Camera const &camera, \
    sf::RenderTarget &target)
{
    return drawOn(camera, target, sf::RenderStates());
}

void Mortymere::Ground::drawOn(Mortymere::Camera const &camera, \
    sf::RenderTarget &target, sf::RenderStates states)
{
    sf::Color colors[3] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue};

    for (float x = -5; x < 5; x += 1) {
        for (float y = -5; y < 5; y += 1) {
            _convex.setPoint(0, camera.inSpaceToOnScreen({x, y}));
            _convex.setPoint(1, camera.inSpaceToOnScreen({x + 1, y}));
            _convex.setPoint(2, camera.inSpaceToOnScreen({x + 1, y + 1}));
            _convex.setPoint(3, camera.inSpaceToOnScreen({x, y + 1}));
            _convex.setFillColor(colors[static_cast<size_t>(x + y + 10) % 3]);
            if (x == -5 && y == -5)
                _convex.setFillColor(sf::Color::White);
            target.draw(_convex, states);
        }
    }
}
