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
    int r = rand() % 10;

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
    // if (r >= den->thystame_d)
    //     memcpy(map->map[i][j], "thystame;", 10);
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
map_t *spawn_object(density_t *den, map_t *map, args_t *args)
{
    for (int i = 0; i != args->width - 1; i++) {
        for (int j = 0; j != args->height - 1; j++) {
            map = verif_rand(den, map, i, j);
            printf("%s", map->map[i][j]);
        }
    }
    return map;
}

int main(void)
{
    density_t *den = malloc(sizeof(density_t));
    map_t *map = malloc(sizeof(map_t));
    args_t args = {4242, 15, 10, NULL, 0, 0};
    map->max_x = args.width;
    map->max_y = args.height;
    init_density(den, &args);
    map = init_tab(map);
    map = spawn_object(den, map, &args);

    for (int i = 0; i != map->max_y; i++) {
        for (int j = 0; j != map->max_x; j++) {
            printf("%s", map->map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
