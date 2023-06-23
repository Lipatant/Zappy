/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** elevation_second_part
*/

#include "my.h"

/**
 * @brief the function for making the elevation lvl 6
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl6(data_t *data)
{
    if (data->player->linemate >= 1 && data->player->deraumere >= 2
    && data->player->sibur >= 3 && data->player->phiras >= 1 &&
    data->map->tile[data->player->posx][data->player->posy].player == 4) {
        dprintf(data->fd, "Elevation underway\n");
        for (float i = 0; i <= 3 || check_lvl6(data) == true; i += 0.5);
        data->player->linemate -= 1;
        data->player->deraumere -= 2;
        data->player->sibur -= 3;
        data->player->phiras -= 1;
        data->player->lvl = 6;
    }
    dprintf(data->fd, "Current level: %ld\n", data->player->lvl);
    return (data);
}

/**
 * @brief the function for making the elevation lvl 7
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl7(data_t *data)
{
    if (data->player->linemate >= 2 && data->player->deraumere >= 2
    && data->player->sibur >= 2 && data->player->mendiane >= 2
    && data->player->phiras >= 2 && data->player->thystame >= 1 &&
    data->map->tile[data->player->posx][data->player->posy].player == 6) {
        dprintf(data->fd, "Elevation underway\n");
        for (float i = 0; i <= 3 || check_lvl7(data) == true; i += 0.5);
        data->player->linemate -= 2;
        data->player->deraumere -= 2;
        data->player->sibur -= 2;
        data->player->mendiane -= 2;
        data->player->phiras -= 2;
        data->player->thystame -= 1;
        data->player->lvl = 7;
    }
    dprintf(data->fd, "Current level: %ld\n", data->player->lvl);
    return (data);
}

/**
 * @brief the function for making the elevation lvl 8
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl8(data_t *data)
{
    if (data->player->linemate >= 2 && data->player->deraumere >= 2
    && data->player->sibur >= 2 && data->player->mendiane >= 2
    && data->player->phiras >= 2 && data->player->thystame >= 2 &&
    data->map->tile[data->player->posx][data->player->posy].player == 6) {
        dprintf(data->fd, "Elevation underway\n");
        for (float i = 0; i <= 3 || check_lvl8(data) == true; i += 0.5);
        data->player->linemate -= 2;
        data->player->deraumere -= 2;
        data->player->sibur -= 2;
        data->player->mendiane -= 2;
        data->player->phiras -= 2;
        data->player->thystame -= 2;
        data->player->lvl = 8;
    }
    dprintf(data->fd, "Current level: %ld\n", data->player->lvl);
    return (data);
}
