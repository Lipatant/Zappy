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

typedef struct player_s {
    char *name;
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
} player_t;

typedef struct map_s {
    int max_x;
    int max_y;
    int x;
    int y;
    char **map;
} map_t;

void init_struct(char **av, player_t *players, map_t *map);
int init_tab(map_t *maps);

#endif /* !MY_H_ */
