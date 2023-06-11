/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** right
*/

#include "my.h"
#include "server.h"
#include "cmd.h"

int right(data_t *data, char *arg)
{
    if (!data->connect)
        return 84;
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
