/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** elevation_second_part
*/

#include "my.h"

void elevation_lvl6(team_t *team)
{
    if (team->player->linemate >= 1 && team->player->deraumere >= 2
    && team->player->sibur >= 3 && team->player->phiras >= 1) {
        team->player->linemate -= 1;
        team->player->deraumere -= 2;
        team->player->sibur -= 3;
        team->player->phiras -= 1;
        team->player->lvl = 6;
    }
}

void elevation_lvl7(team_t *team)
{
    if (team->player->linemate >= 2 && team->player->deraumere >= 2
    && team->player->sibur >= 2 && team->player->phiras >= 2) {
        team->player->linemate -= 1;
        team->player->deraumere -= 2;
        team->player->sibur -= 3;
        team->player->phiras -= 1;
        team->player->lvl = 7;
    }
}

void elevation_lvl8(team_t *team)
{
    if (team->player->linemate >= 2 && team->player->deraumere >= 2
    && team->player->sibur >= 2 && team->player->mendiane >= 2 
    && team->player->phiras >= 2 && team->player->thystame >= 1) {
        team->player->linemate -= 2;
        team->player->deraumere -= 2;
        team->player->sibur -= 2;
        team->player->mendiane -= 2;
        team->player->phiras -= 2;
        team->player->thystame -= 1;
        team->player->lvl = 8;
    }
}