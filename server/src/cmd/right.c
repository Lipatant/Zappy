/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** right
*/

#include "my.h"
#include "cmd.h"

/**
 * @brief the function for the right command
 * @param data the struct data
 * @return
 */
int right(data_t *data)
{
    switch (data->player->orientation) {
        case NORTH:
            data->player->orientation = EAST;
            break;
        case EAST:
            data->player->orientation = SOUTH;
            break;
        case SOUTH:
            data->player->orientation = WEST;
            break;
        case WEST:
            data->player->orientation = NORTH;
            break;
    }
    return 0;
}
