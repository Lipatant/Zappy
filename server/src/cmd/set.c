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
 * @param d
 * @return
 */
static data_t *set_mendiane(data_t *d)
{
    if (strcmp(d->args[1], "mendiane") == 0) {
        if (d->player->mendiane > 0) {
            d->map->tile[d->player->posx][d->player->posy].mendiane += 1;
            d->player->mendiane -= 1;
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    return set_phiras(d);
}

/**
 * @brief the set command for the sibur
 * @param d the data structure
 * @return
 */
static data_t *set_sibur(data_t *d)
{
    if (strcmp(d->args[1], "sibur") == 0) {
        if (d->player->sibur > 0) {
            d->map->tile[d->player->posx][d->player->posy].sibur += 1;
            d->player->sibur -= 1;
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    return set_mendiane(d);
}

/**
 * @brief the set command for the deraumere
 * @param d the data structure
 * @return
 */
static data_t *set_deraumere(data_t *d)
{
    if (strcmp(d->args[1], "deraumere") == 0) {
        if (d->player->deraumere > 0) {
            d->map->tile[d->player->posx][d->player->posy].deraumere += 1;
            d->player->deraumere -= 1;
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    return set_sibur(d);
}

/**
 * @brief the set command for the linemate
 * @param d the data structure
 * @return
 */
static data_t *set_linemate(data_t *d)
{
    if (strcmp(d->args[1], "linemate") == 0) {
        if (d->player->linemate > 0) {
            d->map->tile[d->player->posx][d->player->posy].linemate += 1;
            d->player->linemate -= 1;
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    return set_deraumere(d);
}

/**
 * @brief the set command for the food
 * @param d the data structure
 * @return
 */
data_t *set(data_t *d)
{
    if (strcmp(d->args[1], "food") == 0) {
        if (d->player->food > 0) {
            d->map->tile[d->player->posx][d->player->posy].food += 1;
            d->player->food -= 1;
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            usleep(7 / d->freq * CONVERT_SEC);
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    return set_linemate(d);
}
