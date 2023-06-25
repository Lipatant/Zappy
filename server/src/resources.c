/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** resource_time.c
*/

#include "server.h"

team_list_t *consume_food(team_list_t *team)
{
    for (size_t i = 0; i < team->length; i++) {
        for (int k = 0; k < team->team[i].player_use; k++) {
            team->team[i].player[k].food -= 1;
        }
    }
    return team;
}
