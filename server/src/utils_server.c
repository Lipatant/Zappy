/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** utils_server
*/

#include "server.h"
#include <stdio.h>

/**
 * @brief the function for adding the client
 *
 * @param s the server structure
 * @param c the client structure
 * @return int the return value
 */

static int handle_new_connection(server_t *s, client_t *c)
{
    c->fd = accept(s->fd, (struct sockaddr *)&c->addr, &s->size_sock);
    if (c->fd == -1) {
        perror("accept");
        return 84;
    }
    dprintf(c->fd, "WELCOME\r\n");
    return 0;
}

/**
 * @brief the function for handling the existing connection
 *
 * @param s the server structure
 * @param c the client structure
 * @param i the index
 * @return int the return value
 */

static int handle_existing_connection(server_t *s, client_t *c, int i)
{
    if (add_client(s, c, i) == 84) {
        return 84;
    }
    int current = find_client(c->data, s->client, i);
    return command(s, c, c->data[current]);
}

/**
 * @brief the function for handling the client io
 *
 * @param s the server structure
 * @param c the client structure
 * @param i the index
 * @return int the return value
 */

int handle_client_io(server_t *s, client_t *c, int i)
{
    if (i == s->fd) {
        return handle_new_connection(s, c);
    } else if (c->fd != -1) {
        return handle_existing_connection(s, c, i);
    }
    return 0;
}
