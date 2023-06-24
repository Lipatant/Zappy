/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_player
*/

#include "struct.h"
#include <stdlib.h>

/**X
 * @brief init the player struct
 * @param player the player struct
 * @return player stuct
 */
player_t *init_player(player_t *player,server_t *server)
{
    player = malloc(sizeof(player_t));
    int i = server->nb_player;

    player->posx = server->map->player_pos[i].x;
    player->posy = server->map->player_pos[i].y;
    player->id = i;
    server->nb_player--;
    player->food = 10;
    player->linemate = 0;
    player->deraumere = 0;
    player->sibur = 0;
    player->mendiane = 0;
    player->phiras = 0;
    player->thystame = 0;
    player->lvl = 1;
    player->orientation = rand() % 4;
    return player;
}
