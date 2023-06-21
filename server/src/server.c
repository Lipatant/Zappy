/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief function to set variable for the server
 * @param s the server struct
 * @return
 */
static server_t *set_var_server(server_t *s)
{
    s->addr.sin_addr.s_addr = INADDR_ANY;
    s->addr.sin_family = PF_INET;
    s->addr.sin_port = htons(s->port);
    s->size_addr = sizeof(s->addr);
    s->size_sock = sizeof(s->fd);
    if (bind(s->fd, (struct sockaddr *)&s->addr, s->size_addr) == -1)
        return error("bind");
    return s;
}

/**
 * @brief the init function for the server
 *
 * @param s the server structure
 * @param argv the arguments
 * @return int the return value
 */
static int init_server(server_t *s, args_t args, team_list_t team_list,
    map_t map)
{
    int i = 0;
    int opt = 1;
    for (i = 0; args.names[i] != NULL; i++);
    s->port = args.port;
    s->client = 0;
    s->fd = socket(PF_INET, SOCK_STREAM, 0);
    setsockopt(s->fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
    &opt, sizeof(opt));
    if (s->fd == -1)
        return error("socket");
    s = set_var_server(s);
    s->queue = listen(s->fd, 1024);
    if (s->queue == -1)
        return error("listen");
    s->team_list = &team_list;
    s->map = &map;
    s->nb_team = i;
    s->nb_player = args.clients * i;
    return 0;
}

/**
 * @brief the function for starting the server
 *
 * @param s the server structure
 * @param c the client structure
 * @return int the return value
 */
static int start_server(server_t *s, client_t *c, team_list_t team_list,
    map_t map)
{
    c->data = NULL;
    FD_ZERO(&c->active_fd);
    FD_SET(s->fd, &c->active_fd);
    while (1) {
        c->read_fd = c->active_fd;
        if (select(FD_SETSIZE, &c->read_fd, NULL, NULL, NULL) < 0) {
            perror("select");
            break;
        }
        s->team_list = &team_list;
        s->map = &map;
        if (in_loop(c, s) == 84)
            break;
    }
    close(s->fd);
    return 0;
}

/**
 * @brief the main function for the server
 *
 * @param argc the number of arguments
 * @param argv the arguments
 * @return int the return value
 */
int server(args_t args, team_list_t team_list, map_t map)
{
    server_t server;
    client_t *client = malloc(sizeof(client_t));

    if (init_server(&server, args, team_list, map) == 84)
        return 84;
    start_server(&server, client, team_list, map);
    free(client);
    return 0;
}
