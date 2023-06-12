/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** init
*/

#include "my.h"
#include "server.h"

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

void init_struct(args_t args, team_t *team, map_t *maps, player_t *player)
{
    printf("a\n");
    maps->max_x = args.width;
    printf("b\n");
    maps->max_y = args.height;
    printf("c\n");
    team->players->linemate = 0; // crash
    printf("d\n");
    team->players->deraumere = 0;
    printf("e\n");
    team->players->sibur = 0;
    printf("f\n");
    team->players->mendiane = 0;
    printf("h\n");
    team->players->phiras = 0;
    printf("i\n");
    team->players->thystame = 0;
    printf("j\n");
    team->players->level = 1;
    printf("k\n");

    // give_name_to_player(player, av);
    init_tab(maps);
}
