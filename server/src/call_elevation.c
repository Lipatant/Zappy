/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** call_elevation
*/

#include "my.h"

/**
 * @brief the function for checking if the player can level up
 *
 * @param team the struct containing info about the team
 */
data_t *make_elevation(data_t *data)
{
    if (team->player->lvl == 1)
        elevation_lvl2(data);
    if (team->player->lvl == 2)
        elevation_lvl3(data);
    if (team->player->lvl == 3)
        elevation_lvl4(data);
    if (team->player->lvl == 4)
        elevation_lvl5(data);
    if (team->player->lvl == 5)
        elevation_lvl6(data);
    if (team->player->lvl == 6)
        elevation_lvl7(data);
    if (team->player->lvl == 7)
        elevation_lvl8(data);
    return (data);
}


