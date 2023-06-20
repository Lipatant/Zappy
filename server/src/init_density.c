/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** generate_ressources
*/

#include "my.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief the function for initializing the density
 *
 * @param den the struct containing info about the density
 * @param args the struct containing info about the args
 */
void init_density(density_t *den, args_t *args)
{
    den->nb_case = args->height * args->width;
    den->food_d = den->nb_case * 0.5;
    den->linemate_d = den->nb_case * 0.3;
    den->deraumere_d = den->nb_case * 0.15;
    den->sibur_d = den->nb_case * 0.1;
    den->mendiane_d = den->nb_case * 0.1;
    den->phiras_d = den->nb_case * 0.08;
    den->thystame_d = den->nb_case * 0.05;
}

/**
 * @brief the function who check the rand of every ressources
 *
 * @param den the struct containing info about the density
 * @param map the struct containing info about the map
 * @param i the int containing the x position
 * @param j the int containing the y position
 * @return map_t the struct containing info about the map
 */
map_t *verif_rand(density_t *den, map_t *map, int i, int j)
{
    int r = rand() % den->nb_case;

    if (r >= den->linemate_d)
        memcpy(map->map[i][j], "linemate;", 10);
    if (r >= den->deraumere_d)
        memcpy(map->map[i][j], "deraumere;", 10);
    if (r >= den->sibur_d)
        memcpy(map->map[i][j], "sibur;", 7);
    if (r >= den->mendiane_d)
        memcpy(map->map[i][j], "mendiane;", 11);
    if (r >= den->phiras_d)
        memcpy(map->map[i][j], "phiras;", 8);
    if (r >= den->thystame_d)
        memcpy(map->map[i][j], "thystame;", 11);
    if (r >= den->food_d)
        memcpy(map->map[i][j], "food;", 6);
    return map;
}

/**
 * @brief the function for spawning the object
 *
 * @param den the struct containing info about the density
 * @param map the struct containing info about the map
 * @param args the struct containing info about the args
 *
 * @return map_t the struct containing info about the map
 */
map_t *spawn_object(density_t *den, map_t *map)
{
    for (int i = 0; i != map->max_y; i++) {
        for (int j = 0; j != map->max_x; j++) {
            map = verif_rand(den, map, i, j);
        }
    }
    return map;
}
