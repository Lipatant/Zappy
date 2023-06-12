/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** forward
*/

#include "my.h"
#include "server.h"
#include "cmd.h"

int forward(data_t *data)
{
    if (!data->connect)
        return 84;
    switch (data->player->orientation) {
        case NORTH:
            data->player->posy -= 1;
            break;
        case EAST:
            data->player->posx += 1;
            break;
        case SOUTH:
            data->player->posy += 1;
            break;
        case WEST:
            data->player->posx -= 1;
            break;
    }
    return 0;
}
