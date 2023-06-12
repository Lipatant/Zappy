/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** left
*/

#include "my.h"
#include "server.h"
#include "cmd.h"

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
