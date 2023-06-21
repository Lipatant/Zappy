/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_player
*/

#include "struct.h"

/**
 * @brief init the player struct
 * @param player the player struct
 * @return player stuct
 */
player_t *init_player(player_t *player, int pos_x, int pos_y, int orientation)
{
    player->food = 10;
    player->linemate = 0;
    player->deraumere = 0;
    player->sibur = 0;
    player->mendiane = 0;
    player->phiras = 0;
    player->thystame = 0;
    player->lvl = 1;
    player->orientation = orientation;
    player->posx = pos_x;
    player->posy = pos_y;
    return player;
}
