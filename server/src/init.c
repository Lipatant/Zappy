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
    free(team->player);
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

static player_t init_player(player_t player, args_t args)
{
    player.food = 10;
    player.linemate = 0;
    player.deraumere = 0;
    player.sibur = 0;
    player.mendiane = 0;
    player.phiras = 0;
    player.thystame = 0;
    player.posx = rand() % args.width;
    player.posy = rand() % args.height;

    return player;
}

void init_struct(args_t args, team_t *team, map_t *maps, player_t *player)
{
    int i = 0;
    for (i = 0; args.names[i] != '\0'; i++);
    maps = malloc(sizeof(map_t));
    team = malloc(sizeof(team_t) * i);
    player = malloc(sizeof(player_t) * (args.clients + 1));
    for (int j = 0; j <= i ; i++) {
        team[j].player = malloc(sizeof(player_t) * (args.clients + 1));
        for (int k = 0; k <= args.clients; k++)
            team[j].player[k] = init_player(team[j].player[k], args);
    }
    maps->max_x = args.width;
    maps->max_y = args.height;
    init_tab(maps);
}

