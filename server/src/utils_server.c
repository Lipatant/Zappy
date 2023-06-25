/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** utils_server
*/

#include "server.h"
#include "my.h"
#include <stdio.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * @brief the function to read the input
 * @param c the client structure
 * @return
 */
static char *read_input(client_t *c)
{
    int ret = 0;
    size_t size = 500;
    char *buff = malloc(sizeof(char) * size);

    if (buff == NULL) {
        perror("malloc");
        return NULL;
    }
    memset(buff, '\0', size);
    ret = read(c->fd, buff, size);
    if (ret <= 0) {
        perror("read");
        free(buff);
        return NULL;
    }
    return buff;
}

/**
 * @brief the function to handle a new client if it's an IA
 * @param s the server structure
 * @param c the client structure
 * @param input the input (represented has a char *)
 * @return
 */
static int handle_new_ia(server_t *s, client_t *c, char *input)
{
    int nb = 0;

    nb = get_team_by_name(s, input, s->nb_team);
    if (s->team_list->team[nb].nb_clients != 0) {
        s->team_list->team[nb].nb_clients--;
        dprintf(c->fd, "%d\n%d %d\n", s->team_list->team[nb].nb_clients,
            s->map->max_x, s->map->max_y);
        c->team_nb = nb;
        c->team = &s->team_list->team[nb];
        c->player = &s->team_list->team[nb].
            player[s->team_list->team[nb].player_use];
        s->team_list->team[nb].player_use++;
        c->team_list = s->team_list;
        c->nb_client = s->client;
        c->player = init_player(c->player, s);
    } else {
        dprintf(c->fd, "ko\n");
    }
    return 0;
}

/**
 * @brief the function for adding the client
 *
 * @param s the server structure
 * @param c the client structure
 * @return int the return value
 */
static int handle_new_connection(server_t *s, client_t *c)
{
    char *input = NULL;

    c->GUI = false;
    c->fd = accept(s->fd, (struct sockaddr *)&c->addr, &s->size_sock);
    if (c->fd == -1) {
        perror("accept");
        return 84;
    }
    dprintf(c->fd, "WELCOME\r\n");
    input = read_input(c);
    if (strncmp(input, "GRAPHIC", 7) == 0)
        c->GUI = true;
    else {
        handle_new_ia(s, c, input);
    }
    c->map = s->map;
    FD_SET(c->fd, &c->active_fd);
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
    c->data[current]->freq = s->freq;
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
