/*
** EPITECH PROJECT, 2023
** Citadel/Sprites/Items.cpp
** File description:
** -
*/

#include "Citadel/Sprites/Items.hpp"

#define ITEMS Citadel::Sprites::Items

ITEMS::Items(Citadel::Ground const *ground, Citadel::GroundInventoryKey \
    const &tile) : _ground(ground), _tile(tile)
{
    _anchor = {static_cast<float>(tile.first), 0, \
        static_cast<float>(tile.second)};
    _anchor.z += 0.3;
    if (ground && ground->hasItemTexture)
        _sprite.setTexture(&(ground->itemTexture));
}

bool ITEMS::drawOn(Mortymere::Instance &instance, sf::RenderStates const \
    &states)
{
    if (!_ground || !_ground->hasItemTexture) return false;
    Citadel::InventoryCount inventorySize = 0;
    for (size_t i = 0; i < CITADEL_INVENTORY_SIZE; i++)
        inventorySize += _ground->inventories.at(_tile)[i];
    if (inventorySize < 1) return true;

    Mortymere::SpritePositionType tempAnchor = _anchor;
    float height = 0.3;
    Mortymere::SpritePositionType cornerAnchorA;
    Mortymere::SpritePositionType cornerAnchorB;
    size_t eleID = 0;
    sf::IntRect textureRect = _sprite.getTextureRect();
    sf::Vector2f cornerA;
    sf::Vector2f cornerB;
    sf::Vector2f scale = _sprite.getScale();

    textureRect.width = textureRect.height;
    _sprite.setFillColor(_fillColor);
    for (size_t resID = 0; resID < CITADEL_INVENTORY_SIZE; resID++) {
        textureRect.left = textureRect.width * resID;
        _sprite.setTextureRect(textureRect);
        for (Citadel::InventoryCount count = 0; count < _ground->inventories.at(_tile)[resID]; count++) {
            tempAnchor.x = _anchor.x + (1.0 / (inventorySize + 1)) * \
                (static_cast<float>(eleID + 1)) - 0.5f;
            cornerAnchorA = tempAnchor;
            cornerAnchorB = tempAnchor;
            cornerAnchorA.x -= 0.15;
            cornerAnchorB.x += 0.15; cornerAnchorB.y += height;
            cornerA = instance.camera.inSpaceToOnScreen(cornerAnchorA);
            cornerB = instance.camera.inSpaceToOnScreen(cornerAnchorB);
            cornerA.x *= scale.x; cornerA.y *= scale.y;
            cornerB.x *= scale.x; cornerB.y *= scale.y;
            _sprite.setPosition(cornerA + sf::Vector2f(-2.5, 5));
            _sprite.setSize(cornerB - cornerA);
            instance.window.draw(_sprite, states);
            eleID++;
        }
    }
    return true;
}
