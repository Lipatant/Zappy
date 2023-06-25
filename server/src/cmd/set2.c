/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** set
*/

#include <string.h>
#include <stdio.h>
#include "cmd.h"
#include "struct.h"
#include "our_time.h"

/**
 * @brief the set command for the mendiane
 * @param d the data structure
 * @return
 */
static data_t *set_thystame(data_t *d)
{
    if (strcmp(d->args[1], "thystame") == 0) {
        if (d->player->thystame > 0) {
            d->map->tile[d->player->posx][d->player->posy].thystame += 1;
            d->player->thystame -= 1;
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    usleep(7 / d->freq * CONVERT_SEC);
    dprintf(d->fd, "ko\n");
    return d;
}

/**
 * @brief the set command for the mendiane
 * @param d the data structure
 * @return
 */
data_t *set_phiras(data_t *d)
{
    if (strcmp(d->args[1], "phiras") == 0) {
        if (d->player->phiras > 0) {
            d->map->tile[d->player->posx][d->player->posy].phiras += 1;
            d->player->phiras -= 1;
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ok\n");
        } else {
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ko\n");
        }
    }
    return set_thystame(d);
}
