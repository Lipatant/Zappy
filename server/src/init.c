/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** init
*/

#include "my.h"

void free_struct(player_t *player, map_t *maps, team_t *team)
{
    for (int i = 0; i < maps->max_y; i++)
        free(maps->map[i]);
    free(team->players);
    free(maps->map);
    free(player);
    free(maps);
    free(team);
}

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

void init_struct(char **av, team_t *team, map_t *maps, player_t *player)
{
    maps->max_x = atoi(av[4]);
    maps->max_y = atoi(av[6]);
    team->players->linemate = 0;
    team->players->deraumere = 0;
    team->players->sibur = 0;
    team->players->mendiane = 0;
    team->players->phiras = 0;
    team->players->thystame = 0;
    team->players->level = 1;

    // give_name_to_player(player, av);
    init_tab(maps);
}
