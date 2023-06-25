/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** spawn
*/

#include "struct.h"
#include <stdlib.h>

static tile_t add_ressource_tile(tile_t tile)
{
    double prob = (double)rand() / RAND_MAX;

    if (prob > 0.5)
        tile.food += 1;
    if (prob > 0.3)
        tile.linemate += 1;
    if (prob > 0.15)
        tile.deraumere += 1;
    if (prob > 0.1)
        tile.sibur += 1;
    if (prob > 0.1)
        tile.mendiane += 1;
    if (prob > 0.08)
        tile.phiras += 1;
    if (prob > 0.05)
        tile.thystame += 1;
    return tile;
}

map_t *spawn_ressource(map_t *map)
{
    for (int i = 0; i < map->max_x; i++)
        for (int j = 0; j < map->max_y; j++)
            map->tile[i][j] = add_ressource_tile(map->tile[i][j]);
    return map;
}
