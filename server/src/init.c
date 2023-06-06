/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** init
*/

#include "my.h"

int init_tab(map_t *maps)
{
    maps->map = malloc(sizeof(char *) * (maps->max_y + 1));

    if (maps->map == NULL)
        return 84;
    for (int i = 0; i < maps->max_y; i++) {
        maps->map[i] = malloc(sizeof(char) * (maps->max_x + 1));
        if (maps->map[i] == NULL)
            return 84;
        for (int j = 0; j < maps->max_x; j++)
            maps->map[i][j] = '0';
        maps->map[i][maps->max_x] = '\0';
    }
    return 0;
}

void init_struct(char **av, player_t *player, map_t *maps)
{
    maps->max_x = atoi(av[4]);
    maps->max_y = atoi(av[6]);
    player->linemate = 0;
    player->deraumere = 0;
    player->sibur = 0;
    player->mendiane = 0;
    player->phiras = 0;
    player->thystame = 0;

    // give_name_to_player(player, av);
    init_tab(maps);
}

