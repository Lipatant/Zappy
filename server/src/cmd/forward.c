/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** forward
*/

#include "my.h"
#include "cmd.h"
#include "our_time.h"


/**
 * @brief the function for the forward command
 * if the orientation is west, the player will go left
 * @param data the struct data
 * @return
 */
static data_t *forward_west(data_t *d)
{
    switch (d->player->orientation) {
    case LEFT:
        if (d->player->posy == 0) {
            d->map->tile[d->player->posx][d->player->posy].player--;
            d->player->posy = d->map->max_y - 1;
            d->map->tile[d->player->posx][d->player->posy].player++;
        } else {
            d->map->tile[d->player->posx][d->player->posy].player--;
            d->player->posy -= 1;
            d->map->tile[d->player->posx][d->player->posy].player++;
        }
        break;
    }
    return d;
}

/**
 * @brief the function for the forward command
 * if the orientation is south, the player will go down
 * @param data the struct data
 * @return
 */
static data_t *forward_south(data_t *d)
{
    switch (d->player->orientation) {
    case DOWN:
        if (d->player->posy == d->map->max_x - 1) {
            d->map->tile[d->player->posx][d->player->posy].player--;
            d->player->posx = 0;
            d->map->tile[d->player->posx][d->player->posy].player++;
        } else {
            d->map->tile[d->player->posx][d->player->posy].player--;
            d->player->posx += 1;
            d->map->tile[d->player->posx][d->player->posy].player++;
        }
        break;
    default:
        d = forward_west(d);
        break;
    }
    return d;
}

/**
 * @brief the function for the forward command
 * if the orientation is east, the player will go right
 * @param data the struct data
 * @return
 */
static data_t *forward_east(data_t *d)
{
    switch (d->player->orientation) {
    case RIGHT:
        if (d->player->posy == d->map->max_y - 1) {
            d->map->tile[d->player->posx][d->player->posy].player--;
            d->player->posy = 0;
            d->map->tile[d->player->posx][d->player->posy].player++;
        } else {
            d->map->tile[d->player->posx][d->player->posy].player--;
            d->player->posy += 1;
            d->map->tile[d->player->posx][d->player->posy].player++;
        }
        break;
    default:
        d = forward_south(d);
        break;
    }
    return d;
}

/**
 * @brief the function for the forward command
 * if the orientation is north, the player will go up
 * @param data the struct data
 * @return
 */
data_t *forward(data_t *d)
{
    switch (d->player->orientation) {
    case UP:
        if (d->player->posx == 0) {
            d->map->tile[d->player->posx][d->player->posy].player--;
            d->player->posx = d->map->max_x - 1;
            d->map->tile[d->player->posx][d->player->posy].player++;
        } else {
            d->map->tile[d->player->posx][d->player->posy].player--;
            d->player->posx -= 1;
            d->map->tile[d->player->posx][d->player->posy].player++;
        }
        break;
    default:
        d = forward_east(d);
        break;
    }
    usleep(7 / d->freq * CONVERT_SEC);
    dprintf(d->fd, "ok\n");
    return d;
}
