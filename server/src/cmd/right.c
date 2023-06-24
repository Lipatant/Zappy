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
data_t *right(data_t *data)
{
    switch (data->player->orientation) {
        case UP:
            data->player->orientation = RIGHT;
            break;
        case RIGHT:
            data->player->orientation = DOWN;
            break;
        case DOWN:
            data->player->orientation = LEFT;
            break;
        case LEFT:
            data->player->orientation = UP;
            break;
    }
    dprintf(data->fd, "ok\n");
    return data;
}
