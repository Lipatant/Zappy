/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** take
*/

#include "cmd.h"
#include "struct.h"
#include <string.h>
#include <stdio.h>

/**
 * @brief function to take mendiane to check
 * if the player is trying to take a mendiane
 * @param d the struct of data_t
 * @return int
 */
static data_t *take_mendiane(data_t *d)
{
    if (strcmp(d->args[1], "mendiane") == 0) {
        if (d->map->tile[d->player->posx][d->player->posy].mendiane > 0) {
            d->map->tile[d->player->posx][d->player->posy].mendiane -= 1;
            d->player->mendiane += 1;
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    return take_phiras(d);
}

/**
 * @brief function to take sibur to check
 * if the player is trying to take a sibur
 * @param d the struct of data_t
 * @return int
 */
static data_t *take_sibur(data_t *d)
{
    if (strcmp(d->args[1], "sibur") == 0) {
        if (d->map->tile[d->player->posx][d->player->posy].sibur > 0) {
            d->map->tile[d->player->posx][d->player->posy].sibur -= 1;
            d->player->sibur += 1;
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    return take_mendiane(d);
}

/**
 * @brief function to take deraumere to check
 * if the player is trying to take a deraumere
 * @param d the struct of data_t
 * @return int
 */
static data_t *take_deraumere(data_t *d)
{
    if (strcmp(d->args[1], "deraumere") == 0) {
        if (d->map->tile[d->player->posx][d->player->posy].deraumere > 0) {
            d->map->tile[d->player->posx][d->player->posy].deraumere -= 1;
            d->player->deraumere += 1;
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    return take_sibur(d);
}

/**
 * @brief function to take linemate to check
 * if the player is trying to take a linemate
 * @param d the struct of data_t
 * @return int
 */
static data_t *take_linemate(data_t *d)
{
    if (strcmp(d->args[1], "linemate") == 0) {
        if (d->map->tile[d->player->posx][d->player->posy].linemate > 0) {
            d->map->tile[d->player->posx][d->player->posy].linemate -= 1;
            d->player->linemate += 1;
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    return take_deraumere(d);
}

/**
 * @brief function to take food to check
 * if the player is trying to take a food
 * @param d the struct of data_t
 * @return int
 */
data_t *take(data_t *d)
{
    if (strcmp(d->args[1], "food") == 0) {
        if (d->map->tile[d->player->posx][d->player->posy].food > 0) {
            d->map->tile[d->player->posx][d->player->posy].food -= 1;
            d->player->food += 1;
            dprintf(d->fd, "ok\n");
            return d;
        } else {
            dprintf(d->fd, "ko\n");
            return NULL;
        }
    }
    return take_linemate(d);
}
