/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** elevation_firstpart
*/

#include "my.h"

/**
 * @brief the function for making the elevation lvl 2
 *
 * @param team the struct containing info about the team
 */
void elevation_lvl2(team_t *team)
{
    if (team->player->linemate >= 1 && team->player->deraumere >= 1
    && team->player->sibur >= 1) {
        team->player->linemate -= 1;
        team->player->deraumere -= 1;
        team->player->sibur -= 1;
        team->player->lvl = 2;
    }
}

/**
 * @brief the function for making the elevation lvl 3
 *
 * @param team the struct containing info about the team
 */
void elevation_lvl3(team_t *team)
{
    if (team->player->linemate >= 2 && team->player->sibur >= 1
    && team->player->phiras >= 2) {
        team->player->linemate -= 2;
        team->player->sibur -= 1;
        team->player->phiras -= 2;
        team->player->lvl = 3;
    }
}

/**
 * @brief the function for making the elevation lvl 4
 *
 * @param team the struct containing info about the team
 */
void elevation_lvl4(team_t *team)
{
    if (team->player->linemate >= 1 && team->player->deraumere >= 1
    && team->player->sibur >= 2 && team->player->phiras >= 1) {
        team->player->linemate -= 1;
        team->player->deraumere -= 1;
        team->player->sibur -= 2;
        team->player->phiras -= 1;
        team->player->lvl = 4;
    }
}

/**
 * @brief the function for making the elevation lvl 5
 *
 * @param team the struct containing info about the team
 */
void elevation_lvl5(team_t *team)
{
    if (team->player->linemate >= 1 && team->player->deraumere >= 2
    && team->player->sibur >= 1 && team->player->mendiane >= 3) {
        team->player->linemate -= 1;
        team->player->deraumere -= 2;
        team->player->sibur -= 1;
        team->player->mendiane -= 3;
        team->player->lvl = 5;
    }
}
