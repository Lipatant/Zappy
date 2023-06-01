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
    int id;
    int x;
    int y;
    int level;
    int inventory[7];
    int orientation;
    int team;
} player_t;

typedef struct map_s {
    int x;
    int y;
    int **map;
} map_t;

typedef struct server_s {
    player_s *players;
    map_s *map;
} server_t;

#endif /* !MY_H_ */
