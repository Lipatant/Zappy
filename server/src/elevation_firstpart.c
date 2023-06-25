/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** elevation_firstpart
*/

#include "my.h"

/**
 * @brief the function for making the elevation lvl 2
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl2(data_t *d)
{
    float i = 0;
    bool check = true;

    if ((d->map->tile[d->player->posx][d->player->posy].linemate >= 1
        && d->map->tile[d->player->posx][d->player->posy].player >= 1)) {
        dprintf(d->fd, "Elevation underway\n");
        for (float i = 0; i <= 3 || check == true; i += 0.5)
            check = check_lvl2(d);
        if (i >= 3 && check == true) {
            d->map->tile[d->player->posx][d->player->posy].linemate -= 1;
            d->player->lvl = 2;
            dprintf(d->fd, "Current level: %ld\n", d->player->lvl);
        } else
            dprintf(d->fd, "ko\n");
    }
    return (d);
}

/**
 * @brief the function for making the elevation lvl 3
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl3(data_t *d)
{
    bool check = true;
    float i = 0;

    if (d->map->tile[d->player->posx][d->player->posy].linemate >= 1
        && d->map->tile[d->player->posx][d->player->posy].deraumere >= 1
        && d->map->tile[d->player->posx][d->player->posy].sibur >= 1
        && d->map->tile[d->player->posx][d->player->posy].player >= 2) {
        dprintf(d->fd, "Elevation underway\n");
        for (i = 0; i <= 3 || check_lvl3(d) == true; i += 0.5)
            check = check_lvl3(d);
        if (i >= 3 && check == true) {
            d->map->tile[d->player->posx][d->player->posy].linemate -= 1;
            d->map->tile[d->player->posx][d->player->posy].deraumere -= 1;
            d->map->tile[d->player->posx][d->player->posy].sibur -= 1;
            d->player->lvl = 3;
            dprintf(d->fd, "Current level: %ld\n", d->player->lvl);
        } else
            dprintf(d->fd, "ko\n");
    }
    return (d);
}

/**
 * @brief the function for making the elevation lvl 4
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl4(data_t *d)
{
    float i = 0;
    bool check = true;

    if (check_ressource_lvl4(d)) {
        dprintf(d->fd, "Elevation underway\n");
        for (float i = 0; i <= 3 || check == true; i += 0.5)
            check = check_lvl4(d);
        if (i >= 3 && check == true) {
            d->map->tile[d->player->posx][d->player->posy].linemate -= 2;
            d->map->tile[d->player->posx][d->player->posy].phiras -= 2;
            d->map->tile[d->player->posx][d->player->posy].sibur -= 1;
            d->player->lvl = 4;
            dprintf(d->fd, "Current level: %ld\n", d->player->lvl);
        } else
            dprintf(d->fd, "ko\n");
    }
    return (d);
}

/**
 * @brief the function for making the elevation lvl 5
 *
 * @param data the struct containing info about list of data
 * @return data_t* the struct containing info about list of data
 */
data_t *elevation_lvl5(data_t *d)
{
    float i = 0;
    bool check = true;

    if (check_ressource_lvl5(d)) {
        dprintf(d->fd, "Elevation underway\n");
        for (i = 0; i <= 3 || check == true; i += 0.5)
            check = check_lvl5(d);
        if (i >= 3 && check == true) {
            d->map->tile[d->player->posx][d->player->posy].linemate -= 1;
            d->map->tile[d->player->posx][d->player->posy].deraumere -= 1;
            d->map->tile[d->player->posx][d->player->posy].sibur -= 2;
            d->map->tile[d->player->posx][d->player->posy].phiras -= 1;
            d->player->lvl = 5;
            dprintf(d->fd, "Current level: %ld\n", d->player->lvl);
        } else
            dprintf(d->fd, "ko\n");
    }
    return (d);
}
