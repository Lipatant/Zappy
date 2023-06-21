/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** forward
*/

#include "my.h"
#include "cmd.h"

/**
 * @brief the function for the forward command
 * if the orientation is west, the player will go left
 * @param data the struct data
 * @return
 */
static int forward_west(data_t *d)
{
    switch (d->player->orientation) {
    case WEST:
        if (d->player->posx == 0) {
            d->map->tile[d->player->posy][d->player->posx].player--;
            d->player->posx = d->map->max_x;
            d->map->tile[d->player->posy][d->player->posx].player++;
        } else {
            d->map->tile[d->player->posy][d->player->posx].player--;
            d->player->posx -= 1;
            d->map->tile[d->player->posy][d->player->posx].player++;
        }
        break;
    }
    return 0;
}

/**
 * @brief the function for the forward command
 * if the orientation is south, the player will go down
 * @param data the struct data
 * @return
 */
static int forward_south(data_t *d)
{
    switch (d->player->orientation) {
    case SOUTH:
        if (d->player->posy == d->map->max_y) {
            d->map->tile[d->player->posy][d->player->posx].player--;
            d->player->posy = 0;
            d->map->tile[d->player->posy][d->player->posx].player++;
        } else {
            d->map->tile[d->player->posy][d->player->posx].player--;
            d->player->posy += 1;
            d->map->tile[d->player->posy][d->player->posx].player++;
        }
        break;
    default:
        forward_west(d);
        break;
    }
    return 0;
}

/**
 * @brief the function for the forward command
 * if the orientation is east, the player will go right
 * @param data the struct data
 * @return
 */
static int forward_east(data_t *d)
{
    switch (d->player->orientation) {
    case EAST:
        if (d->player->posx == d->map->max_x) {
            d->map->tile[d->player->posy][d->player->posx].player--;
            d->player->posx = 0;
            d->map->tile[d->player->posy][d->player->posx].player++;
        } else {
            d->map->tile[d->player->posy][d->player->posx].player--;
            d->player->posx += 1;
            d->map->tile[d->player->posy][d->player->posx].player++;
        }
        break;
    default:
        forward_south(d);
        break;
    }
    return 0;
}

/**
 * @brief the function for the forward command
 * if the orientation is north, the player will go up
 * @param data the struct data
 * @return
 */
int forward(data_t *d)
{
    switch (d->player->orientation) {
    case NORTH:
        if (d->player->posy == 0) {
            d->map->tile[d->player->posy][d->player->posx].player--;
            d->player->posy = d->map->max_y;
            d->map->tile[d->player->posy][d->player->posx].player++;
        } else {
            d->map->tile[d->player->posy][d->player->posx].player--;
            d->player->posy -= 1;
            d->map->tile[d->player->posy][d->player->posx].player++;
        }
        break;
    default:
        forward_east(d);
        break;
    }
    dprintf(d->fd, "x = %d y = %d\n", d->player->posx, d->player->posy);
    return 0;
}
