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


map_t *verif_rand(density_t *den, map_t *map, int i, int j, int r)
{
    // int r = rand() % 10;

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
        memcpy(map->map[i][j], "thystame;", 10);
    if (r >= den->food_d)
        memcpy(map->map[i][j], "food;", 6);

    // printf("%s\n", map->map[i][j]);
    // printf("%d\n", r);

    return map;
}

map_t *spawn_object(density_t *den, map_t *map, args_t *args)
{
    for (int i = 0; i != args->width; i++) {
        for (int j = 0; j != args->height; j++) {
            int r = rand() % 10;
            map = verif_rand(den, map, i, j, r);
        }
    }
    return map;
}

