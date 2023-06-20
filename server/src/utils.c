/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** utils
*/

#include "server.h"
#include <string.h>

/**
 * @brief the function to get the number of a team
 * @param server
 * @param name
 * @param nb_team
 * @return
 * i the team nb
 * -1 no team named
 */
int get_team_by_name(server_t *server, char *name, int nb_team)
{
    for (int i = 0; i != nb_team; i++) {
        if (strncmp(server->team_list->team[i].name, name,
            strlen(server->team_list->team[i].name)) == 0) {
            return i;
        }
    }
    return -1;
}
