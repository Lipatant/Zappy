/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** generate_ressources
*/

#include <stdlib.h>
#include "struct.h"

void init_density(density_t *den, args_t *args)
{
    den = malloc(sizeof(density_t));

    den->nb_case = args->height * args->width;
    den->food_d = den->nb_case * 0.5;
    den->linemate_d = den->nb_case * 0.3;
    den->deraumere_d = den->nb_case * 0.15;
    den->sibur_d = den->nb_case * 0.1;
    den->mendiane_d = den->nb_case * 0.1;
    den->phiras_d = den->nb_case * 0.08;
    den->thystame_d = den->nb_case * 0.05;
}

void verif_rand(density_t *den, map_t *map)
{
    int r = rand() % den->nb_case;

    if (r >= den->linemate_d)
        map->map[map->max_y][map->max_x] = "linemate";
    if (r >= den->deraumere_d)
        map->map[map->max_y][map->max_x] = "deraumere";
    if (r >= den->sibur_d)
        map->map[map->max_y][map->max_x] = "sibur";
    if (r >= den->mendiane_d)
        map->map[map->max_y][map->max_x] = "mendiane";
    if (r >= den->phiras_d)
        map->map[map->max_y][map->max_x] = "phiras";
    if (r >= den->thystame_d)
        map->map[map->max_y][map->max_x] = "thystame";
    if (r >= den->food_d)
        map->map[map->max_y][map->max_x] = "food";
}
