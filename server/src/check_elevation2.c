/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** check_elevation2
*/

#include "my.h"

/**
 * @brief the function for checking if the player is still on the tile
 *
 * @param data the struct containing info about list of data
 * @return true if nothing happen during the incantation
 * @return false if a eject cmd is use during the incantation
 */
bool check_lvl7(data_t *d)
{
    if (data->player->linemate < 2 || data->player->deraumere < 2
        || data->player->sibur < 2 || data->player->mendiane < 2
        || data->player->phiras < 2 || data->player->thystame < 1 ||
        data->map->tiles[data->player->y][data->player->x].players < 6)
        return false;
    return true;
}

/**
 * @brief the function for checking if the player is still on the tile
 *
 * @param data the struct containing info about list of data
 * @return true if nothing happen during the incantation
 * @return false if a eject cmd is use during the incantation
 */
bool check_lvl8(data_t *d)
{
    if (data->player->linemate < 2 || data->player->deraumere < 2
        || data->player->sibur < 2 || data->player->mendiane < 2
        || data->player->phiras < 2 || data->player->thystame < 2 ||
        data->map->tiles[data->player->y][data->player->x].players < 6)
        return false;
    return true;
}