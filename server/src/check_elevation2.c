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
    if (d->player->linemate < 2 || d->player->deraumere < 2
        || d->player->sibur < 2 || d->player->mendiane < 2
        || d->player->phiras < 2 || d->player->thystame < 1 ||
        d->map->tile[d->player->posx][d->player->posy].player < 6)
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
    if (d->player->linemate < 2 || d->player->deraumere < 2
        || d->player->sibur < 2 || d->player->mendiane < 2
        || d->player->phiras < 2 || d->player->thystame < 2 ||
        d->map->tile[d->player->posx][d->player->posy].player < 6)
        return false;
    return true;
}