/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** utils_client
*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include "server.h"

/**
 * @brief the function for finding the client
 *
 * @param data the data structure
 * @param nbr the number of client
 * @param fd the fd
 * @return int the return value
 */

int find_client(data_t **data, int nbr, int fd)
{
    int i = 0;

    for (; i != nbr; i++)
        if (data[i]->fd == fd)
            break;
    return i;
}

/**
 * @brief the function for checking if the client exist
 *
 * @param data the data structure
 * @param fd the fd
 * @param nbr the number of client
 * @return int the return value
 */
static int check_exist(data_t **data, int fd, int nbr)
{
    if (data == NULL)
        return 0;
    for (int i = 0; i != nbr; i++)
        if (data[i]->fd == fd)
            return 84;
    return 0;
}

/**
 * @brief the function for filling the client structure
 *
 * @param c the client structure
 * @param s the server structure
 * @param fd the fd
 */
static void fill_client(client_t *c, server_t *s, int fd)
{
    c->data[s->client - 1]->args = NULL;
    c->data[s->client - 1]->fd = fd;
    c->data[s->client - 1]->port = -1;
    c->data[s->client - 1]->ip = inet_ntoa(c->addr.sin_addr);
}

/**
 * @brief the function for adding a client
 *
 * @param s the server structure
 * @param c the client structure
 * @param fd the fd
 * @return int the return value
 */
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
