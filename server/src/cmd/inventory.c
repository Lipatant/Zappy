/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** inventory
*/

#include "my.h"
#include "cmd.h"
#include "our_time.h"

/**
 * @brief the function for the inventory command
 * @param data the struct data
 * @return
 */
data_t *inventory(data_t *data)
{
    char *msg = NULL;
    int size = 0;
    size = snprintf(NULL, 0, inv_1 inv_2, data->player->linemate,\
        data->player->deraumere, data->player->sibur, data->player->mendiane,\
        data->player->phiras, data->player->thystame, data->player->food);
    msg = malloc(sizeof(char) * (size + 1));
    snprintf(msg, size + 1, inv_1 inv_2, data->player->linemate,\
        data->player->deraumere, data->player->sibur, data->player->mendiane,\
        data->player->phiras, data->player->thystame, data->player->food);
    usleep(7 / data->freq * CONVERT_SEC);
    dprintf(data->fd, "%s\n", msg);
    return data;
}
