/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** cmd
*/

#ifndef CMD_H_
    #define CMD_H_

    #include "server.h"
    #define inv_1 "[linemate %ld, deraumere %ld, sibur %ld, mendiane %ld, "
    #define inv_2 "phiras %ld, thystame %ld, food %d]"

typedef struct cmd_s {
    char *cmd;
    data_t *(*func_ptr)(data_t *data);
} cmd_t;

data_t *forward(data_t *data);
data_t *right(data_t *data);
data_t *left(data_t *data);
data_t *look(data_t *data);
void fix(int *n, int *goal, int lim);
char *add_tile(data_t *data, char *send, int x, int y);
data_t *inventory(data_t *data);
//int broadcast(data_t *data);
data_t *connect_nbr(data_t *data);
//int fork(data_t *data);
//data_t *eject(data_t *data);
data_t *take(data_t *data);
data_t *take_phiras(data_t *d);
data_t *set(data_t *data);
data_t *set_phiras(data_t *d);
//int incantation(data_t *data); // bastien

static const cmd_t cmds[] = {
    {"Forward\0", &forward},
    {"Right\0", &right},
    {"Left\0", &left},
    {"Look\0", &look},
    {"Inventory\0", &inventory},
    //{"broadcast", &broadcast}, // string
    {"Connect_nbr\0", &connect_nbr}, // return int nb place team
    ////{"fork\0", &fork},
    //{"Eject\0", &eject},
    {"Take\0", &take},
    {"Set\0", &set},
    //{"incantation", &incantation}, // send to all client on tile
    {NULL, NULL}
};

#endif /* !CMD_H_ */
