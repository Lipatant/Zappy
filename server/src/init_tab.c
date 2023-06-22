/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_tab
*/

#include "struct.h"
#include <stdlib.h>
#include <string.h>

static map_t *init_tab_x(map_t *maps, int i)
{
    for (int j = 0; j < maps->max_x; j++) {
        maps->map[i][j] = malloc(sizeof(char) * 10);
        if (maps->map[i][j] == NULL)
            return NULL;
        strcpy(maps->map[i][j], "0");
    }
    return maps;
}

map_t *init_tab(map_t *maps)
{
    maps->map = malloc(sizeof(char **) * maps->max_y);
    if (maps->map == NULL)
        return NULL;
    for (int i = 0; i < maps->max_y; i++) {
        maps->map[i] = malloc(sizeof(char *) * maps->max_x);
        if (maps->map[i] == NULL)
            return NULL;
        maps = init_tab_x(maps, i);
        if (maps == NULL)
            return NULL;
        maps->map[i][maps->max_x] = NULL;
    }
    maps->map[maps->max_y] = NULL;
    return maps;
}
