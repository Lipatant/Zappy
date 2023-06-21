/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** take
*/

#include "cmd.h"
#include "struct.h"
#include <string.h>

/**
 * @brief function to take mendiane to check
 * if the player is trying to take a mendiane
 * @param d the struct of data_t
 * @return int
 */
static int take_thystame(data_t *d)
{
    if (strcmp(d->args[1], "thystame") == 0) {
        if (d->map->map[d->player->posx][d->player->posy]->thystame > 0) {
            d->map->map[d->player->posx][d->player->posy]->thystame -= 1;
            d->player->thystame += 1;
            dprintf(d->fd, "ok\n");
            return 0;
        } else {
            dprintf(d->fd, "ko\n");
            return 0;
        }
    }
    dprintf(d->fd, "ko\n");
    return 0;
}

/**
 * @brief function to take sibur to check
 * if the player is trying to take a sibur
 * @param d the struct of data_t
 * @return int
 */
int take_phiras(data_t *d)
{
    if (strcmp(d->args[1], "phiras") == 0) {
        if (d->map->map[d->player->posx][d->player->posy]->phiras > 0) {
            d->map->map[d->player->posx][d->player->posy]->phiras -= 1;
            d->player->phiras += 1;
            dprintf(d->fd, "ok\n");
        } else
            dprintf(d->fd, "ko\n");
    }
    return take_thystame(d);
}
