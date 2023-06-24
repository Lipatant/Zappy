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
data_t *left(data_t *data)
{
    switch (data->player->orientation) {
        case UP:
            data->player->orientation = LEFT;
            break;
        case LEFT:
            data->player->orientation = DOWN;
            break;
        case DOWN:
            data->player->orientation = RIGHT;
            break;
        case RIGHT:
            data->player->orientation = UP;
            break;
    }
    dprintf(data->fd, "ok\n");
    return data;
}
