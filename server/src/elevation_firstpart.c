/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** elevation_firstpart
*/

#include "my.h"

/**
 * @brief the function for making the elevation lvl 2
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl2(data_t *data)
{
    if (data->player->linemate >= 1 && data->player->deraumere >= 1
    && data->player->sibur >= 1 &&
    data->map->tiles[data->player->y][data->player->x].players == 1) {
        dprintf(data->player->fd, "Elevation underway\n");
        //function who make incantation and wait 3 sec
        data->player->linemate -= 1;
        data->player->deraumere -= 1;
        data->player->sibur -= 1;
        data->player->lvl = 2;
        //call function take object for lvl 2 and lvl 2 in that function

    }
    dprintf(data->player->fd, "Current level: %d\n", data->player->lvl);
    return (data);
}

/**
 * @brief the function for making the elevation lvl 3
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl3(data_t *data)
{
    if (data->player->linemate >= 2 && data->player->sibur >= 1
    && data->player->phiras >= 2 &&
    data->map->tiles[data->player->y][data->player->x].players == 2) {
        data->player->linemate -= 2;
        data->player->sibur -= 1;
        data->player->phiras -= 2;
        data->player->lvl = 3;
        //call function take object for lvl 3
    }
    return (data);
}

/**
 * @brief the function for making the elevation lvl 4
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl4(data_t *data)
{
    if (data->player->linemate >= 1 && data->player->deraumere >= 1
    && data->player->sibur >= 2 && data->player->phiras >= 1 &&
    data->map->tiles[data->player->y][data->player->x].players == 2) {
        data->player->linemate -= 1;
        data->player->deraumere -= 1;
        data->player->sibur -= 2;
        data->player->phiras -= 1;
        data->player->lvl = 4;
        //call function take object for lvl 4
    }
    return (data);
}

/**
 * @brief the function for making the elevation lvl 5
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl5(data_t *data)
{
    if (data->player->linemate >= 1 && data->player->deraumere >= 2
    && data->player->sibur >= 1 && data->player->mendiane >= 3 &&
    data->map->tiles[data->player->y][data->player->x].players == 4) {
        data->player->linemate -= 1;
        data->player->deraumere -= 2;
        data->player->sibur -= 1;
        data->player->mendiane -= 3;
        data->player->lvl = 5;
        //call function take object for lvl 5
    }
    return (data);
}
