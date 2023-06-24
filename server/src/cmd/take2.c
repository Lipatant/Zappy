/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** take
*/

#include <string.h>
#include <stdio.h>
#include "cmd.h"
#include "our_time.h"

/**
 * @brief function to take mendiane to check
 * if the player is trying to take a mendiane
 * @param d the struct of data_t
 * @return int
 */
static data_t *take_thystame(data_t *d)
{
    if (strcmp(d->args[1], "thystame") == 0) {
        if (d->map->tile[d->player->posx][d->player->posy].thystame > 0) {
            d->map->tile[d->player->posx][d->player->posy].thystame -= 1;
            d->player->thystame += 1;
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ko\n");
            return d;
        }
    }
    usleep(7 / d->freq * CONVERT_SEC);
    dprintf(d->fd, "ko\n");
    return d;
}

/**
 * @brief function to take sibur to check
 * if the player is trying to take a sibur
 * @param d the struct of data_t
 * @return int
 */
data_t *take_phiras(data_t *d)
{
    if (strcmp(d->args[1], "phiras") == 0) {
        if (d->map->tile[d->player->posx][d->player->posy].phiras > 0) {
            d->map->tile[d->player->posx][d->player->posy].phiras -= 1;
            d->player->phiras += 1;
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ko\n");
            return d;
        }
    }
    return take_thystame(d);
}
