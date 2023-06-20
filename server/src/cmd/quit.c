/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** quit
*/

#include "cmd.h"
#include <stdio.h>

/**
 * @brief the function for the command quit
 * @param data the struct data
 * @return
 */
int quit(data_t *data)
{
    dprintf(data->fd, "%s\n", "quit");
    return 1;
}
