/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** in_loop
*/

#include <unistd.h>
#include "server.h"

/**
 * @brief the function for handling the client io
 *
 * @param i the index
 * @param c the client structure
 * @param s the server structure
 * @return int the return value
 */
static int in_in_loop(int i, client_t *c, server_t *s)
{
    if (FD_ISSET(i, &c->read_fd)) {
        if (handle_client_io(s, c, i) == 84) {
            close(s->fd);
            return 84;
        }
    }
    return 0;
}

/**
 * @brief the function for handling the client io
 *
 * @param c the client structure
 * @param s the server structure
 * @return int the return value
 */
int in_loop(client_t *c, server_t *s)
{
    for (int i = 0; i != FD_SETSIZE; i++) {
        if (in_in_loop(i, c, s) == 84)
            return 84;
    }
    return 0;
}
