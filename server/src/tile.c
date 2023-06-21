/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tile
*/

#include "struct.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * @brief the function to init the tile part 2
 * @param tile the structure tile
 * @param den the structure density
 * @return tile return the tile
 */
static tile_t init_tile_2(tile_t tile, density_t *den)
{
    if (((double)rand() / RAND_MAX) > 0.5 && den->mendiane_d > 0) {
        tile.mendiane = 1;
        den->mendiane_d--;
    }
    if (((double)rand() / RAND_MAX) > 0.5 && den->phiras_d > 0) {
        tile.phiras = 1;
        den->phiras_d--;
    }
    if (((double)rand() / RAND_MAX) > 0.5 && den->sibur_d > 0) {
        tile.sibur = 1;
        den->sibur_d--;
    }
    if (((double)rand() / RAND_MAX) > 0.5 && den->thystame_d > 0) {
        tile.thystame = 1;
        den->thystame_d--;
    }
    return tile;
}

/**
 * @brief the function to init the tile
 * @param tile the structure tile
 * @param den the structure density
 * @return tile_t return the tile
 */
static tile_t init_tile(tile_t tile, density_t *den)
{
    if (((double)rand() / RAND_MAX) > 0.5 && den->player_d) {
        tile.player = 1;
        den->player_d--;
    }
    if (((double)rand() / RAND_MAX) > 0.5 && den->food_d > 0) {
        tile.food = 1;
        den->food_d--;
    }
    if (((double)rand() / RAND_MAX) > 0.5 && den->deraumere_d > 0) {
        tile.deraumere = 1;
        den->deraumere_d--;
    }
    if (((double)rand() / RAND_MAX) > 0.5 && den->linemate_d > 0) {
        tile.linemate = 1;
        den->linemate_d--;
    }
    return init_tile_2(tile, den);
}

/**
 * @brief the function to init the density
 * @param den the structure density
 * @param max_x the max x of the map
 * @param max_y the max y of the map
 * @param nb_player the number of player
 * @return density_t return the density
 */
static density_t *init_density(density_t *den, int max_x, int max_y, int nb_player)
{
    den = malloc(sizeof(density_t));

    den->nb_case = max_x * max_y;
    den->food_d = den->nb_case * 0.5;
    den->linemate_d = den->nb_case * 0.3;
    den->deraumere_d = den->nb_case * 0.15;
    den->sibur_d = den->nb_case * 0.1;
    den->mendiane_d = den->nb_case * 0.1;
    den->phiras_d = den->nb_case * 0.08;
    den->thystame_d = den->nb_case * 0.05;
    den->player_d = nb_player;
    return den;
}

/**
 * @brief the function to init the map
 * @param map the structure map
 * @param nb_player the number of player
 * @return map_t return the map
 */
map_t *init_map(map_t *map, int nb_player)
{
    density_t *den = NULL;
    map->tile = malloc(sizeof(tile_t *) * map->max_x + 1);

    srand(time(NULL));
    den = init_density(den, map->max_x, map->max_y, nb_player);
    for (int i = 0; i <= map->max_x; i++)
        map->tile[i] = malloc(sizeof(tile_t) * map->max_y + 1);
    for (int i = 0; i <= map->max_x; i++)
        for(int j = 0; j <= map->max_y; j++)
            map->tile[i][j] = init_tile(map->tile[i][j], den);
    return map;
}
