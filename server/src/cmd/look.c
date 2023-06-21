/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** look
*/

#include "my.h"
#include "server.h"
#include "cmd.h"

char *look_left(data_t *data, char *msg)
{
    int j = 0;
    int rank = 0;

    for (size_t i = 0; i <= data->player->level; i++) {
        j = i;
        rank = data->player->posy - i;
        while (rank < 0)
            rank += data->player->posy - 1;
        while (j > 0) {
            sprintf(msg ,"%s", data->map->map[data->player->posy + j][rank]);
            j--;
        }
        sprintf(msg, "%s", data->map->map[data->player->posx][rank]);
        for (size_t k = 1; k <= i; k++) {
            sprintf(msg, "%s", data->map->map[data->player->posx - k][rank]);
        }
        sprintf(msg, "\n");
    }
    return msg;
}

char *look_down(data_t *data, char *msg)
{
    int j = 0;
    int rank = 0;

    for (size_t i = 0; i <= data->player->level; i++) {
        j = i;
        rank = data->player->posx + i;
        while (rank >= data->player->posx)
            rank -= data->player->posx;
        while (rank < 0)
            rank += data->player->posx;
        for (size_t k = 1; k <= i; k++)
            sprintf(msg, "%s", data->map->map[rank][data->player->posy + k]);
        sprintf(msg, "%s", data->map->map[rank][data->player->posy]);
        while (j > 0) {
            sprintf(msg, "%s", data->map->map[rank][data->player->posy - j]);
            j--;
        }
        sprintf(msg, "\n");
    }
    return msg;
}

char *look_up(data_t *data, char *msg)
{
    int j = 0;
    int rank = 0;

    for (size_t i = 0; i <= data->player->level; i++) {
        j = i;
        rank = data->player->posx - i;
        while (rank < 0)
            rank += data->player->posx;
        while (j > 0) {
            sprintf(msg, "%s", data->map->map[rank][data->player->posy - j]);
            j--;
        }
        sprintf(msg, "%s", data->map->map[rank][data->player->posy]);
        for (size_t k = 1; k <= i; k++)
            sprintf(msg, "%s", data->map->map[rank][data->player->posy + k]);
        sprintf(msg, "\n");
    }
    return msg;
}

char *look_right(data_t *data, char *msg)
{
    int j = 0;
    int rank = 0;

    for (size_t i = 0; i <= data->player->level; i++) {
        j = i;
        rank = data->player->posy + i;
        while (rank >= data->player->posy)
            rank -= data->player->posy;
        while (j > 0) {
            sprintf(msg, "%s", data->map->map[data->player->posx - j][rank]);
            j--;
        }
        sprintf(msg, "%s", data->map->map[data->player->posx][rank]);
        for (size_t k = 1; k <= i; k++)
            sprintf(msg, "%s", data->map->map[data->player->posx + k][rank]);
        sprintf(msg, "\n");
    }
    return msg;
}

int look(data_t *data)
{
    char *to_send = NULL;

    switch (data->player->orientation) {
        case NORTH:
            look_up(data, to_send);
            break;
        case WEST:
            look_right(data, to_send);
            break;
        case SOUTH:
            look_down(data, to_send);
            break;
        case EAST:
            to_send = look_left(data, to_send);
            break;
        default:
            break;
    }
    send(data->fd, to_send, strlen(to_send), 0);
    return 0;
}
