/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <netinet/in.h>
    #include <stdbool.h>
    #include <stddef.h>

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
    int nb_clients;
    player_t *player;
} team_t;

typedef struct data_s {
    int fd;
    int socket;
    int port;
    char **args;
    char *ip;
    bool connect;
    player_t *player;
} data_t;

typedef struct server_s {
    int port;
    int fd;
    int queue;
    int client;
    struct sockaddr_in addr;
    socklen_t size_addr;
    socklen_t size_sock;
} server_t;

typedef struct client_s {
    int fd;
    struct sockaddr_in addr;
    fd_set read_fd;
    fd_set active_fd;
    data_t **data;
} client_t;

typedef struct args_s {
    int port;
    int width;
    int height;
    char **names;
    int clients;
    int freq;
} args_t;

#endif /* !STRUCT_H_ */
