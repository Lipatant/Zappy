/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** quit
*/

#include "cmd.h"
#include "struct.h"
#include <stdio.h>

int quit(data_t *data)
{
    dprintf(data->fd, "%s\n", "quit");
    return 1;
}
