/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** init
*/

#include "my.h"
#include "server.h"
#include <string.h>

/**
 * @brief the function for freeing the struct
 *
 * @param player the struct containing info about the player
 * @param map the struct containing info about the map
 * @param team_list the struct containing info about the team_list
 */
void free_struct(player_t *player, map_t maps, team_list_t team_list)
{
    for (int i = 0; i < maps.max_y; i++)
        free(maps.tile[i]);
    free(team_list.team->player);
    free(maps.tile);
    free(player);
    free(team_list.team);
}

/**
 * @brief the function for setting the team
 *
 * @param args the struct containing info about the args
 * @param team the struct containing info about the team
 */
static void set_team(args_t args, team_t *team)
{
    int i = 0;
    for (i = 0; args.names[i] != NULL; i++);

    for (int j = 0; j < i; j++) {
        team[j].name = args.names[j];
        team[j].nb_clients = args.clients;
    }
}

static pos_t *inside_for(pos_t *pos, map_t *map, int i, int j)
{
    if (map->tile[i][j].player == 1) {
        pos->x = i;
        pos->y = j;
    }
    return pos;
}

static pos_t *init_pos(pos_t *pos, map_t *map, int nb_player)
{
    int a = 0;

    pos = malloc(sizeof(pos_t) * nb_player + 1);
    for (int i = 0; i < map->max_x; i++) {
        for (int j = 0; j < map->max_y; j++) {
            pos = inside_for(pos, map, i, j);
        }
    }
    return pos;
}

/**
 * @brief the function for initializing the struct
 *
 * @param args the struct containing info about the args
 * @param team_list the struct containing info about the team_list
 * @param map the struct containing info about the map
 *
 */
void init_struct(args_t args, team_list_t *team_list, map_t *maps)
{
    int i = 0;
    for (i = 0; args.names[i] != NULL; i++);
    team_list->team = malloc(sizeof(team_t) * i);
    if (team_list->team)
        memset(team_list->team, 0, sizeof(team_t) * i);
    team_list->team->player = malloc(sizeof(player_t) * (args.clients + 1));
    for (int j = 0; j <= i ; j++)
        team_list->team[j].player = malloc(sizeof(player_t) *
            (args.clients + 1));
    maps->max_x = args.width;
    maps->max_y = args.height;
    maps = init_map(maps, i * args.clients);
    team_list->pos = init_pos(team_list->pos, maps, i * args.clients);
    set_team(args, team_list->team);
}
