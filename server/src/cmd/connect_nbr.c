/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** connect_nbr
*/

#include <stdio.h>
#include "struct.h"
#include "cmd.h"

/**
 * @brief the function for the connect_nbr command
 * @param data the struct data
 * @return the struct data
 */
data_t *connect_nbr(data_t *data)
{
    dprintf(data->fd, "%d\n", data->team->nb_clients);
    return data;
}
