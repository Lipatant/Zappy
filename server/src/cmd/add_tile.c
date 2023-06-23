/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** add_tile
*/

#include "my.h"
#include "server.h"

/**
 * @brief add the tile to send part 4
 * @param data
 * @param to_send
 * @param x
 * @param y
 * @return
 */
static char *add_tile_4(data_t *data, char *to_send, int x, int y)
{
    int size = 0;

    if (data->map->tile[x][y].phiras > 0)
        for (int i = 1; i <= data->map->tile[x][y].phiras; i++) {
            size = snprintf(NULL, 0, "phiras ");
            realloc(to_send, sizeof(char) * (strlen(to_send) + size + 1));
            strcat(to_send, "phiras ");
        }
    if (data->map->tile[x][y].thystame > 0)
        for (int i = 1; i <= data->map->tile[x][y].thystame; i++) {
            size = snprintf(NULL, 0, "thystame ");
            realloc(to_send, sizeof(char) * (strlen(to_send) + size + 1));
            strcat(to_send, "thystame ");
        }
    return to_send;
}

/**
 * @brief add tile to send part 3
 * @param data
 * @param to_send
 * @param x
 * @param y
 * @return
 */
static char *add_tile_3(data_t *data, char *to_send, int x, int y)
{
    int size = 0;

    if (data->map->tile[x][y].sibur > 0)
        for (int i = 1; i <= data->map->tile[x][y].sibur; i++) {
            size = snprintf(NULL, 0, "sibur ");
            realloc(to_send, sizeof(char) * (strlen(to_send) + size + 1));
            strcat(to_send, "sibur ");
        }
    if (data->map->tile[x][y].mendiane > 0)
        for (int i = 1; i <= data->map->tile[x][y].mendiane; i++) {
            size = snprintf(NULL, 0, "mendiane ");
            realloc(to_send, sizeof(char) * (strlen(to_send) + size + 1));
            strcat(to_send, "mendiane ");
        }
    return add_tile_4(data, to_send, x, y);
}

/**
 * @brief add tile to send part 2
 * @param data
 * @param to_send
 * @param x
 * @param y
 * @return
 */
static char *add_tile_2(data_t *data, char *to_send, int x, int y)
{
    int size = 0;

    if (data->map->tile[x][y].linemate > 0)
        for (int i = 1; i <= data->map->tile[x][y].linemate; i++) {
            size = snprintf(NULL, 0, "linemate ");
            realloc(to_send, sizeof(char) * (strlen(to_send) + size + 1));
            strcat(to_send, "linemate ");
        }
    if (data->map->tile[x][y].deraumere > 0)
        for (int i = 1; i <= data->map->tile[x][y].deraumere; i++) {
            size = snprintf(NULL, 0, "deraumere ");
            realloc(to_send, sizeof(char) * (strlen(to_send) + size + 1));
            strcat(to_send, "deraumere ");
        }
    return add_tile_3(data, to_send, x, y);
}

/**
 * @brief add tile to send part 1
 * @param data
 * @param send
 * @param x
 * @param y
 * @return
 */
char *add_tile(data_t *data, char *send, int x, int y)
{
    int size = 0;

    if (data->map->tile[x][y].player > 0)
        for (int i = 1; i <= data->map->tile[x][y].player; i++) {
            size = snprintf(NULL, 0, "player ");
            realloc(send, sizeof(char) * (strlen(send) + size + 1));
            strcat(send, "player ");
        }
    if (data->map->tile[x][y].food > 0)
        for (int i = 1; i <= data->map->tile[x][y].food; i++) {
            size = snprintf(NULL, 0, "food ");
            realloc(send, sizeof(char) * (strlen(send) + size + 1));
            strcat(send, "food ");
        }
    return add_tile_2(data, send, x, y);
}

/**
 * @brief fix the position of the player
 * @param n
 * @param goal
 * @param lim
 */
void fix(int *n, int *goal, int lim)
{
    if (goal == NULL && *n == lim)
        *n = 0;
    else if (goal == NULL && *n < 0)
        *n = lim - 1;
    if (*n == lim) {
        *n = 0;
        *goal -= lim;
    } else if (*n < 0) {
        *n = lim - 1;
        *goal += lim;
    }
}
