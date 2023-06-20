/*
** EPITECH PROJECT, 2023
** Mortymere/Ground.cpp
** File description:
** -
*/

#include "Citadel/Ground.hpp"
#include "Mortymere/Sprites/Tile.hpp"

#define GROUND Citadel::Ground
#define GROUND_TILE_COLOR \
    sf::Color::Blue, sf::Color::White, -2

bool GROUND::changeSize(size_t const x, size_t const y)
{
    if (_sizeX == x && _sizeY == y)
        return false;
    sprites.clear();
    for (size_t i = 0; i < x; i++) {
        for (size_t j = 0; j < y; j++) {
            sprites.push_back(Mortymere::createSprite< \
                Mortymere::Sprites::Tile>(GROUND_TILE_COLOR));
            sprites.back()->layer() = -1;
            sprites.back()->anchor().x = i;
            sprites.back()->anchor().z = j;
        }
    }
    _sizeX = x;
    _sizeY = y;
    return true;
}

std::size_t GROUND::getSizeX(void)
{
    return _sizeX;
}

std::size_t GROUND::getSizeY(void)
{
    return _sizeY;
}
