/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** look
*/

#include "my.h"
#include "server.h"
#include "cmd.h"


void look(data_t *data)
{
    if (direction == 0) {
        look_up(data);
    } else if (direction == 1) {
        look_right(data);
    } else if (direction == 2) {
        look_down(data);
    } else if (direction == 3) {
        look_left(data);
    }
    send(socket, to_send, strlen(to_send), 0);
}

void look_left(data_t *data)
{
    int j = 0;
    int rank = 0;

    for (int i = 0; i <= level; i++) {
        j = i;
        rank = y - i;
        while (rank < 0)
            rank += client_y - 1;
        while (j > 0) {
            printf("%c", tmp_map[x + j][rank]);
            j--;
        }
        printf("%c", tmp_map[x][rank]);
        for (int k = 1; k <= i; k++) {
            printf("%c", tmp_map[x - k][rank]);
        }
        printf("\n");
    }
}

void look_down(data_t *data)
{
    int j = 0;
    int rank = 0;

    for (int i = 0; i <= level; i++) {
        j = i;
        rank = x + i;
        while (rank >= client_x)
            rank -= client_x;
        while (rank < 0)
            rank += client_x;
        for (int k = 1; k <= i; k++)
            printf("%c", tmp_map[rank][y + k]);
        printf("%c", tmp_map[rank][y]);
        while (j > 0) {
            printf("%c", tmp_map[rank][y - j]);
            j--;
        }
        printf("\n");
    }
}

void look_up(data_t *data)
{
    int j = 0;
    int rank = 0;

    for (int i = 0; i <= level; i++) {
        j = i;
        rank = x - i;
        while (rank < 0)
            rank += client_x;
        while (j > 0) {
            printf("%c", tmp_map[rank][y - j]);
            j--;
        }
        printf("%c", tmp_map[rank][y]);
        for (int k = 1; k <= i; k++)
            printf("%c", tmp_map[rank][y + k]);
        printf("\n");
    }
}

void look_right(data_t *data)
{
    int j = 0;
    int rank = 0;

    for (int i = 0; i <= level; i++) {
        j = i;
        rank = y + i;
        while (rank >= client_y)
            rank -= client_y;
        while (j > 0) {
            printf("%c", tmp_map[x - j][rank]);
            j--;
        }
        printf("%c", tmp_map[x][rank]);
        for (int k = 1; k <= i; k++)
            printf("%c", tmp_map[x + k][rank]);
        printf("\n");
    }
}