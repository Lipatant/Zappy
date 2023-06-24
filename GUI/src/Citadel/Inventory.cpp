/*
** EPITECH PROJECT, 2023
** Citadel/Inventory.cpp
** File description:
** -
*/

#include "Citadel/Inventory.hpp"

#define INVENTORY Citadel::Inventory

INVENTORY::Inventory(void)
{ }

INVENTORY::Inventory(Citadel::InventoryCount const \
    ressources[CITADEL_INVENTORY_SIZE])
{
    for (size_t i = 0; i < CITADEL_INVENTORY_SIZE; i++)
        operator[](ressources[i]);
}

INVENTORY::Inventory(Citadel::Inventory const &other)
{
    for (size_t i = 0; i < CITADEL_INVENTORY_SIZE; i++)
        operator[](other[i]);
}

Citadel::Inventory &INVENTORY::operator=(Citadel::Inventory const &other)
{
    for (size_t i = 0; i < CITADEL_INVENTORY_SIZE; i++)
        operator[](other[i]);
    return *this;
}

Citadel::InventoryCount &INVENTORY::operator[](size_t const id)
{
    switch (id % CITADEL_INVENTORY_SIZE) {
    case 0:
        return food;
    case 1:
        return linemate;
    case 2:
        return deraumere;
    case 3:
        return sibur;
    case 4:
        return mendiane;
    case 5:
        return phiras;
    case 6:
        return thystame;
    default:
        return food;
    }
}

Citadel::InventoryCount INVENTORY::operator[](size_t const id) const
{
    switch (id % CITADEL_INVENTORY_SIZE) {
    case 0:
        return food;
    case 1:
        return linemate;
    case 2:
        return deraumere;
    case 3:
        return sibur;
    case 4:
        return mendiane;
    case 5:
        return phiras;
    case 6:
        return thystame;
    default:
        return food;
    }
}
