/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** left
*/

#include "my.h"
#include "cmd.h"

/**
 * @brief the function for the left command
 * @param data the struct data
 * @return
 */
int left(data_t *data)
{
    if (!data->connect)
        return 84;
    switch (data->player->orientation) {
        case NORTH:
            data->player->orientation = WEST;
            break;
        case EAST:
            data->player->orientation = NORTH;
            break;
        case SOUTH:
            data->player->orientation = EAST;
            break;
        case WEST:
            data->player->orientation = SOUTH;
            break;
    }
    return 0;
}
