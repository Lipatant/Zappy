/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** elevation_second_part
*/

#include "my.h"

/**
 * @brief the function for making the elevation lvl 6
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl6(data_t *d)
{
    float i = 0;
    bool check = true;

    if (check_ressource_lvl6(d)) {
        dprintf(d->fd, "Elevation underway\n");
        for (i = 0; i <= 3 || check == true; i += 0.5)
            check = check_lvl6(d);
        if (i >= 3 && check == true) {
            d->map->tile[d->player->posx][d->player->posy].linemate -= 1;
            d->map->tile[d->player->posx][d->player->posy].deraumere -= 2;
            d->map->tile[d->player->posx][d->player->posy].sibur -= 1;
            d->map->tile[d->player->posx][d->player->posy].mendiane -= 3;
            d->player->lvl = 6;
            dprintf(d->fd, "Current level: %ld\n", d->player->lvl);
        } else
            dprintf(d->fd, "ko\n");
    }
    return (d);
}

/**
 * @brief the function for making the elevation lvl 7
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl7(data_t *d)
{
    float i = 0;
    bool check = true;

    if (check_ressource_lvl7(d)) {
        dprintf(d->fd, "Elevation underway\n");
        for (i = 0; i <= 3 || check == true; i += 0.5)
            check = check_lvl7(d);
        if (i >= 3 && check == true) {
            d->map->tile[d->player->posx][d->player->posy].linemate -= 1;
            d->map->tile[d->player->posx][d->player->posy].deraumere -= 2;
            d->map->tile[d->player->posx][d->player->posy].sibur -= 3;
            d->map->tile[d->player->posx][d->player->posy].phiras -= 1;
            d->player->lvl = 7;
            dprintf(d->fd, "Current level: %ld\n", d->player->lvl);
        } else
            dprintf(d->fd, "ko\n");
    }
    return (d);
}

/**
 * @brief the function for making the elevation lvl 8
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl8(data_t *d)
{
    float i = 0;
    bool check = true;

    if (check_ressource_lvl8(d)) {
        dprintf(d->fd, "Elevation underway\n");
        for (float i = 0; i <= 3 || check == true; i += 0.5)
            check = check_lvl8(d);
        if (i >= 3 && check == true) {
            d->map->tile[d->player->posx][d->player->posy].linemate -= 2;
            d->map->tile[d->player->posx][d->player->posy].deraumere -= 2;
            d->map->tile[d->player->posx][d->player->posy].sibur -= 2;
            d->map->tile[d->player->posx][d->player->posy].mendiane -= 2;
            d->map->tile[d->player->posx][d->player->posy].phiras -= 2;
            d->map->tile[d->player->posx][d->player->posy].thystame -= 1;
            d->player->lvl = 8;
            dprintf(d->fd, "Current level: %ld\n", d->player->lvl);
        } else
            dprintf(d->fd, "ko\n");
    }
    return (d);
}
