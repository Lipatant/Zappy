/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** utils_client
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "server.h"

int find_client(data_t **data, int nbr, int fd)
{
    int i = 0;

    for (; i != nbr; i++)
        if (data[i]->fd == fd)
            break;
    return i;
}

static int check_exist(data_t **data, int fd, int nbr)
{
    if (data == NULL)
        return 0;
    for (int i = 0; i != nbr; i++)
        if (data[i]->fd == fd)
            return 84;
    return 0;
}

static void fill_client(client_t *c, server_t *s, int fd)
{
    c->data[s->client - 1]->args = NULL;
    c->data[s->client - 1]->fd = fd;
    c->data[s->client - 1]->port = -1;
    c->data[s->client - 1]->ip = inet_ntoa(c->addr.sin_addr);
}

int add_client(server_t *s, client_t *c, int fd)
{
    if (check_exist(c->data, fd, s->client) == 84)
        return 0;
    s->client += 1;
    c->data = reallocarray(c->data,
    sizeof(data_t *), (size_t) s->client);
    if (c->data == NULL) {
        perror("reallocarray");
        return 84;
    }
    c->data[s->client - 1] = malloc(sizeof(data_t));
    if (c->data[s->client - 1] == NULL) {
        perror("malloc");
        return 84;
    }
    fill_client(c, s, fd);
    return 0;
}
