/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** elevation_second_part
*/

#include "my.h"

void elevation_lvl6(team_t *team)
{
    if (team->players->linemate == 1 && team->players->deraumere == 2
    && team->players->sibur == 3 && team->players->mendiane == 0 && team->players->phiras == 1
    && team->players->thystame == 0)
        team->players->lvl = 6;
}

void elevation_lvl7(team_t *team)
{
    if (team->players->linemate == 2 && team->players->deraumere == 2
    && team->players->sibur == 2 && team->players->mendiane == 2 && team->players->phiras == 2
    && team->players->thystame == 1)
        team->players->lvl = 7;
}

void elevation_lvl8(team_t *team)
{
    if (team->players->linemate == 0 && team->players->deraumere == 0
    && team->players->sibur == 0 && team->players->mendiane == 0 && team->players->phiras == 0
    && team->players->thystame == 0)
        team->players->lvl = 8;
}