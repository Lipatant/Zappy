/*
** EPITECH PROJECT, 2023
** Citadel/Inventory.hpp
** File description:
** -
*/

/// @file
/// @brief Class representing an inventory

#include <stddef.h>

#define CITADEL_INVENTORY_SIZE 7

#pragma once

namespace Citadel {

/// @brief Amount of a ressource
using InventoryCount = size_t;

/// @brief Inventory of a Character or a Tile
class Inventory {

public: // PUBLIC MEMBERS
    /// @brief Ressource q0
    Citadel::InventoryCount food = 0;
    /// @brief Ressource q1
    Citadel::InventoryCount linemate = 0;
    /// @brief Ressource q2
    Citadel::InventoryCount deraumere = 0;
    /// @brief Ressource q3
    Citadel::InventoryCount sibur = 0;
    /// @brief Ressource q4
    Citadel::InventoryCount mendiane = 0;
    /// @brief Ressource q5
    Citadel::InventoryCount phiras = 0;
    /// @brief Ressource q6
    Citadel::InventoryCount thystame = 0;
    /// @brief Amount of ressource types in an Inventory
    size_t const size = CITADEL_INVENTORY_SIZE;

public: // OPERATORS
    Citadel::Inventory &operator=(Citadel::Inventory const &other);
    Citadel::InventoryCount &operator[](size_t const id);
    Citadel::InventoryCount operator[](size_t const id) const;

public: // CONSTURCTORS
    Inventory(void);
    Inventory(Citadel::InventoryCount const \
        ressources[CITADEL_INVENTORY_SIZE]);
    Inventory(Citadel::Inventory const &other);

};

};
