/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** cmd
*/

#ifndef CMD_H_
    #define CMD_H_

    #include "server.h"
    #define inv_1 "[linemate %d, deraumere %d, sibur %d, mendiane %d, "
    #define inv_2 "phiras %d, thystame %d, food %d]\n"

typedef struct cmd_s {
    char *cmd;
    int (*func_ptr)(data_t *data);
} cmd_t;

int forward(data_t *data);
int right(data_t *data);
int left(data_t *data);
int quit(data_t *data);
int look(data_t *data);
int inventory(data_t *data);
//int broadcast(data_t *data);
//int connect_nbr(data_t *data);
//int fork(data_t *data);
//int eject(data_t *data);
//int take(data_t *data);
//int set(data_t *data);
// inventory and add to the tile
//int incantation(data_t *data); // bastien

static const cmd_t cmds[] = {
    {"Forward\0", &forward},
    {"Right\0", &right},
    {"Left\0", &left},
    {"Look\0", &look},
    {"Inventory", &inventory},
    //{"broadcast", &broadcast}, // string
    //{"connect_nbr", &connect_nbr}, // return int nb place team
    ////{"fork\0", &fork},
    //{"eject\0", &eject},
    //{"take", &take},
    //{"set", &set},
    //{"incantation", &incantation}, // send to all client on tile
    {"quit\0", &quit},
    {NULL, NULL}
};

#endif /* !CMD_H_ */
