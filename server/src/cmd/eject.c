/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** eject
*/

#include "server.h"
#include "cmd.h"
#include <stdio.h>

void eject_other_player(int x, int y, team_list_t *team_list, data_t *d)
{
    player_t *player = NULL;

    for (int i = 0; i < team_list->length; i++)
        for (int j = 0; j < d->nb_client; j++)
            if (team_list->team[i].player[j].posx == x &&
                team_list->team[i].player[j].posy == y &&
                team_list->team[i].player[j].id != d->player->id)
                    player = &team_list->team[i].player[j];
    if (player != NULL) {
        d->map->tile[player->posx][player->posy].player -= 1;
        if (d->player->orientation == 1)
            player->posy -= 1;
        if (d->player->orientation == 2)
            player->posx += 1;
        if (d->player->orientation == 3)
            player->posy += 1;
        if (d->player->orientation == 4)
            player->posx -= 1;
        d->map->tile[player->posx][player->posy].player += 1;
        dprintf(player->fd, "eject: %d\n", d->player->orientation);
    }
}

data_t *eject(data_t *d)
{
    if (d->map->tile[d->player->posx][d->player->posy].player > 1) {
        while (d->map->tile[d->player->posx][d->player->posy].player > 1) {
            eject_other_player(d->player->posx, d->player->posy,
                d->team_list, d);
        }
        d->map->tile[d->player->posx][d->player->posy].egg = 0;
        dprintf(d->fd, "ok\n");
    }
    else
        dprintf(d->fd, "ko\n");
    return d;
}