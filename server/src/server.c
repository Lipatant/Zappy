/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

static int init_server(server_t *s, char **argv)
{
    int opt = 1;
    s->port = atoi(argv[1]);
    s->client = 0;
    s->fd = socket(PF_INET, SOCK_STREAM, 0);
    setsockopt(s->fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
    &opt, sizeof(opt));
    if (s->fd == -1)
        return error("socket");
    s->addr.sin_addr.s_addr = INADDR_ANY;
    s->addr.sin_family = PF_INET;
    s->addr.sin_port = htons(s->port);
    s->size_addr = sizeof(s->addr);
    s->size_sock = sizeof(s->fd);
    if (bind(s->fd, (struct sockaddr *)&s->addr, s->size_addr) == -1)
        return error("bind");
    s->queue = listen(s->fd, 1024);
    if (s->queue == -1)
        return error("listen");
    return 0;
}

static int start_server(server_t *s, client_t *c)
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
        if (in_loop(c, s) == 84)
            break;
    }
    return 0;
}

int server(int argc, char **argv)
{
    server_t server;
    client_t *client = malloc(sizeof(client_t));

    if (argc != 2)
        return error("See usage with ./server -h");
    if (init_server(&server, argv) == 84)
        return 84;
    start_server(&server, client);
    free(client);
    return 0;
}
