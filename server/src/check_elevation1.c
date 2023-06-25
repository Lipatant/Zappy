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
    if (d->map->tile[d->player->posx][d->player->posy].linemate < 1
        || d->map->tile[d->player->posx][d->player->posy].player < 1)
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
    if (d->map->tile[d->player->posx][d->player->posy].linemate < 1
        || d->map->tile[d->player->posx][d->player->posy].sibur < 1
        || d->map->tile[d->player->posx][d->player->posy].phiras < 1
        || d->map->tile[d->player->posx][d->player->posy].player < 2)
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
    if (d->map->tile[d->player->posx][d->player->posy].linemate < 2
        || d->map->tile[d->player->posx][d->player->posy].sibur < 1
        || d->map->tile[d->player->posx][d->player->posy].phiras < 2
        || d->map->tile[d->player->posx][d->player->posy].player < 2)
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
    if (d->map->tile[d->player->posx][d->player->posy].linemate < 1
        || d->map->tile[d->player->posx][d->player->posy].deraumere < 1
        || d->map->tile[d->player->posx][d->player->posy].sibur < 2
        || d->map->tile[d->player->posx][d->player->posy].phiras < 1
        || d->map->tile[d->player->posx][d->player->posy].player < 4)
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
    if (d->map->tile[d->player->posx][d->player->posy].linemate < 1
        || d->map->tile[d->player->posx][d->player->posy].deraumere < 2
        || d->map->tile[d->player->posx][d->player->posy].sibur < 1
        || d->map->tile[d->player->posx][d->player->posy].mendiane < 3
        || d->map->tile[d->player->posx][d->player->posy].player < 4)
        return false;
    return true;
}
