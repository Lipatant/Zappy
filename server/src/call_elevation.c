/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** call_elevation
*/

#include "my.h"

void make_elevation(team_t *team)
{
    if (team->player->lvl == 1)
        elevation_lvl2(team);
    if (team->player->lvl == 2)
        elevation_lvl3(team);
    if (team->player->lvl == 3)
        elevation_lvl4(team);
    if (team->player->lvl == 4)
        elevation_lvl5(team);
    if (team->player->lvl == 5)
        elevation_lvl6(team);
    if (team->player->lvl == 6)
        elevation_lvl7(team);
    if (team->player->lvl == 7)
        elevation_lvl8(team);
}
