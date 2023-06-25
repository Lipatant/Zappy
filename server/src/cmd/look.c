/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** look
*/

#include "my.h"
#include "server.h"
#include "cmd.h"
#include "our_time.h"

/**
 * @brief look up
 * @param data
 * @param to_send
 * @return
 */
static char *look_up(data_t *data, char *to_send)
{
    look_t look = {1, data->player->posx, data->player->posx + 1,
        data->player->posy + data->player->lvl + 1};

    for (int i = data->player->posy; i != look.ly; i++,
        look.j += 2, look.k -= 1) {
        fix(&i, &look.ly, data->map->max_y);
        fix(&look.k, NULL, data->map->max_x);
        look.lx = look.k - look.j;
        for (int n = look.k; n != look.lx; n--) {
            fix(&n, &look.lx, data->map->max_x);
            to_send = add_tile(data, to_send, i, n);
            realloc(to_send, strlen(to_send) + 1);
            to_send[strlen(to_send) - 1] = ',';
            to_send[strlen(to_send)] = ' ';
        }
    }
    return to_send;
}

/**
 * @brief look down
 * @param data
 * @param to_send
 * @return
 */
static char *look_down(data_t *data, char *to_send)
{
    look_t look = {1, data->player->posx, data->player->posx + 1,
        data->player->posy - data->player->lvl - 1};

    for (int i = data->player->posy; i != look.ly; i--,
        look.j += 2, look.k += 1) {
        fix(&i, &look.ly, data->map->max_y);
        fix(&look.k, NULL, data->map->max_x);
        look.lx = look.k - look.j;
        for (int n = look.k; n != look.lx; n--) {
            fix(&n, &look.lx, data->map->max_x);
            to_send = add_tile(data, to_send, i, n);
            realloc(to_send, strlen(to_send) + 1);
            to_send[strlen(to_send) - 1] = ',';
            to_send[strlen(to_send)] = ' ';
        }
    }
    return to_send;
}

/**
 * @brief look left
 * @param data
 * @param to_send
 * @return
 */
static char *look_left(data_t *data, char *to_send)
{
    look_t look = {1, data->player->posy, data->player->posx -
        data->player->lvl - 1, data->player->posy + 1};
    for (int i = data->player->posx; i != look.lx; i--, look.j += 2,
        look.k -= 1) {
        fix(&i, &look.lx, data->map->max_x);
        fix(&look.k, NULL, data->map->max_y);
        look.ly = look.k - look.j;
        for (int n = look.k; n != look.ly; n--) {
            fix(&n, &look.ly, data->map->max_y);
            to_send = add_tile(data, to_send, i, n);
            realloc(to_send, strlen(to_send) + 1);
            to_send[strlen(to_send) - 1] = ',';
            to_send[strlen(to_send)] = ' ';
        }
    }
    return to_send;
}

/**
 * @brief look right
 * @param data
 * @param to_send
 * @return
 */
static char *look_right(data_t *data, char *to_send)
{
    look_t look = {1, data->player->posy, data->player->posx +
        data->player->lvl + 1, data->player->posy + 1};
    for (int i = data->player->posx; i != look.lx; i++, look.j += 2,
            look.k += 1) {
        fix(&i, &look.lx, data->map->max_x);
        fix(&look.k, NULL, data->map->max_y);
        look.ly = look.k - look.j;
        for (int n = look.k; n != look.ly; n--) {
            fix(&n, &look.ly, data->map->max_y);
            to_send = add_tile(data, to_send, i, n);
            realloc(to_send, strlen(to_send) + 1);
            to_send[strlen(to_send) - 1] = ',';
            to_send[strlen(to_send)] = ' ';
        }
    }
    return to_send;
}

/**
 * @brief look command
 * @param data
 * @return
 */
data_t *look(data_t *data)
{
    char *to_send = malloc(sizeof(char) + 1024);
    to_send[0] = '[';

    if (data->player->orientation == UP)
        to_send = look_up(data, to_send);
    if (data->player->orientation == DOWN)
        to_send = look_down(data, to_send);
    if (data->player->orientation == LEFT)
        to_send = look_left(data, to_send);
    if (data->player->orientation == RIGHT)
        to_send = look_right(data, to_send);
    to_send[strlen(to_send) - 1] = ']';
    to_send[strlen(to_send)] = '\n';
    usleep(7 / data->freq * CONVERT_SEC);
    send(data->fd, to_send, strlen(to_send), 0);
    return data;
}
