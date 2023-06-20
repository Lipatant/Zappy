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
    char ***map;
} map_t;

typedef struct team_s {
    char *name;
    int nb_clients;
    int player_use;
    player_t *player;
} team_t;

typedef struct team_list_s {
    size_t length;
    team_t *team;
} team_list_t;

typedef struct data_s {
    int fd;
    int socket;
    int port;
    char **args;
    char *ip;
    bool connect;
    player_t *player;
    map_t *map;
} data_t;

typedef struct server_s {
    int port;
    int fd;
    int queue;
    int client;
    struct sockaddr_in addr;
    socklen_t size_addr;
    socklen_t size_sock;
    team_list_t *team_list;
    map_t *map;
    int nb_team;
} server_t;

typedef struct client_s {
    int fd;
    struct sockaddr_in addr;
    fd_set read_fd;
    fd_set active_fd;
    data_t **data;
    bool GUI;
    int team_nb;
    player_t *player;
    map_t *map;
} client_t;

typedef struct args_s {
    int port;
    int width;
    int height;
    char **names;
    int clients;
    int freq;
} args_t;

typedef struct density_s {
    int nb_case;
    size_t food_d;
    size_t linemate_d;
    size_t deraumere_d;
    size_t sibur_d;
    size_t mendiane_d;
    size_t phiras_d;
    size_t thystame_d;
} density_t;


#endif /* !STRUCT_H_ */
