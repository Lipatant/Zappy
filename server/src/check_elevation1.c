/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** check_elevation1
*/

#include "my.h"

/**
 * @brief the function for checking if the player is still on the tile
 *
 * @param data the struct containing info about list of data
 * @return true if nothing happen during the incantation
 * @return false if a eject cmd is use during the incantation
 */
bool check_lvl2(data_t *d)
{
    if (d->player->linemate < 1 || d->player->deraumere < 1
        || d->player->sibur < 1 ||
        d->map->tiles[d->player->posy][d->player->posx].players < 1)
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
bool check_lvl3(data_t *d)
{
    if (data->player->linemate < 2 || data->player->sibur < 1
        || data->player->phiras < 2 ||
        data->map->tiles[data->player->y][data->player->x].players < 2)
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
bool check_lvl4(data_t *d)
{
    if (data->player->linemate < 1 || data->player->deraumere < 1
        || data->player->sibur < 2 || data->player->phiras < 1 ||
        data->map->tiles[data->player->y][data->player->x].players < 2)
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
bool check_lvl5(data_t *d)
{
    if (data->player->linemate < 1 || data->player->deraumere < 2
        || data->player->sibur < 1 || data->player->mendiane < 3 ||
        data->map->tiles[data->player->y][data->player->x].players < 4)
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
bool check_lvl6(data_t *d)
{
    if (data->player->linemate < 1 || data->player->deraumere < 2
        || data->player->sibur < 3 || data->player->phiras < 1 ||
        data->map->tiles[data->player->y][data->player->x].players < 4)
        return false;
    return true;
}
