/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** elevation_firstpart
*/

#include "my.h"

void elevation_lvl2(team_t *team)
{
    if (team->players->linemate >= 1 && team->players->deraumere >= 1
    && team->players->sibur >= 1) {
        team->players->linemate -= 1;
        team->players->deraumere -= 1;
        team->players->sibur -= 1;
        team->players->lvl = 2;
    }
}

void elevation_lvl3(team_t *team)
{
    if (team->players->linemate >= 2 && team->players->sibur >= 1
    && team->players->phiras >= 2) {
        team->players->linemate -= 2;
        team->players->sibur -= 1;
        team->players->phiras -= 2;
        team->players->lvl = 3;
    }
}

void elevation_lvl4(team_t *team)
{
    if (team->players->linemate >= 1 && team->players->deraumere >= 1
    && team->players->sibur >= 2 && team->players->phiras >= 1) {
        team->players->linemate -= 1;
        team->players->deraumere -= 1;
        team->players->sibur -= 2;
        team->players->phiras -= 1;
        team->players->lvl = 4;
    }
}

void elevation_lvl5(team_t *team)
{
    if (team->players->linemate >= 1 && team->players->deraumere >= 2
    && team->players->sibur >= 1 && team->players->mendiane >= 3) {
        team->players->linemate -= 1;
        team->players->deraumere -= 2;
        team->players->sibur -= 1;
        team->players->mendiane -= 3;
        team->players->lvl = 5;
    }
}