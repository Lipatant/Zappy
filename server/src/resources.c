/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** resource_time.c
*/

#include "server.h"

void consume_food(team_list_t *team)
{
    for (size_t i = 0; i < team->length; i++) {
        for (int k = 0; k < team->team[i].nb_clients; k++) {
            team->team[i].player[k].food -= 1;
        }
    }
}
