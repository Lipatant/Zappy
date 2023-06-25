/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** check_ressource
*/

#include "my.h"

/**
 * @brief the function for checking the ressource for lvl 4
 *
 * @param data the struct containing info about list of data
 * @return bool true or false
 */
bool check_ressource_lvl4(data_t *d)
{
    if (d->map->tile[d->player->posx][d->player->posy].linemate >= 2
        && d->map->tile[d->player->posx][d->player->posy].sibur >= 1
        && d->map->tile[d->player->posx][d->player->posy].phiras >= 2
        && d->map->tile[d->player->posx][d->player->posy].player >= 2)
        return (true);
    else
        return (false);
}

/**
 * @brief the function for checking the ressource for lvl 5
 *
 * @param data the struct containing info about list of data
 * @return bool true or false
 */
bool check_ressource_lvl5(data_t *d)
{
    if ((d->map->tile[d->player->posx][d->player->posy].linemate >= 1 &&
        d->map->tile[d->player->posx][d->player->posy].deraumere >= 1 &&
        d->map->tile[d->player->posx][d->player->posy].sibur >= 2 &&
        d->map->tile[d->player->posx][d->player->posy].phiras >= 1 &&
        d->map->tile[d->player->posx][d->player->posy].player >= 4))
        return (true);
    else
        return (false);
}

/**
 * @brief the function for checking the ressource for lvl 6
 *
 * @param data the struct containing info about list of data
 * @return bool true or false
 */
bool check_ressource_lvl6(data_t *d)
{
    if (d->map->tile[d->player->posx][d->player->posy].linemate >= 1 &&
        d->map->tile[d->player->posx][d->player->posy].deraumere >= 2 &&
        d->map->tile[d->player->posx][d->player->posy].sibur >= 1 &&
        d->map->tile[d->player->posx][d->player->posy].mendiane >= 3 &&
        d->map->tile[d->player->posx][d->player->posy].player >= 4)
        return (true);
    else
        return (false);
}

/**
 * @brief the function for checking the ressource for lvl 7
 *
 * @param data the struct containing info about list of data
 * @return bool true or false
 */
bool check_ressource_lvl7(data_t *d)
{
    if (d->map->tile[d->player->posx][d->player->posy].linemate >= 1 &&
        d->map->tile[d->player->posx][d->player->posy].deraumere >= 2 &&
        d->map->tile[d->player->posx][d->player->posy].sibur >= 3 &&
        d->map->tile[d->player->posx][d->player->posy].phiras >= 1 &&
        d->map->tile[d->player->posx][d->player->posy].player >= 6)
        return (true);
    else
        return (false);
}

/**
 * @brief the function for checking the ressource for lvl 8
 *
 * @param data the struct containing info about list of data
 * @return bool true or false
 */
bool check_ressource_lvl8(data_t *d)
{
    if (d->map->tile[d->player->posx][d->player->posy].linemate >= 2 &&
        d->map->tile[d->player->posx][d->player->posy].deraumere >= 2 &&
        d->map->tile[d->player->posx][d->player->posy].sibur >= 2 &&
        d->map->tile[d->player->posx][d->player->posy].mendiane >= 2 &&
        d->map->tile[d->player->posx][d->player->posy].phiras >= 2 &&
        d->map->tile[d->player->posx][d->player->posy].thystame >= 1 &&
        d->map->tile[d->player->posx][d->player->posy].player >= 6)
        return (true);
    else
        return (false);
}
