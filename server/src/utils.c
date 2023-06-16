/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** utils
*/

#include "server.h"
#include "struct.h"
#include <string.h>
#include <stdio.h>

int get_team_by_name(server_t *server, char *name, int nb_team)
{
    printf("%d\n", nb_team);
    printf("%s\n", server->team_list->team[0].name);
    for (int i = 0; i <= nb_team; i++) {
        if (strcmp(server->team_list->team[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
