/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <sys/socket.h>
    #include <netinet/in.h>

enum orientation { NORTH, EAST, SOUTH, WEST };

typedef struct player_s {
    int food;
    int posx;
    int posy;
    int level;
    int life;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int lvl;
    int orientation;
} player_t;

typedef struct map_s {
    int max_x;
    int max_y;
    char **map;
} map_t;

typedef struct team_s {
    char *name;
    player_t *players;
} team_t;

void init_struct(char **av, team_t *team, map_t *map, player_t *player);
int init_tab(map_t *maps);
void make_elevation(team_t *team);
void elevation_lvl2(team_t *team);
void elevation_lvl3(team_t *team);
void elevation_lvl4(team_t *team);
void elevation_lvl5(team_t *team);
void elevation_lvl6(team_t *team);
void elevation_lvl7(team_t *team);
void elevation_lvl8(team_t *team);
void free_struct(player_t *player, map_t *maps, team_t *team);

#endif /* !MY_H_ */
