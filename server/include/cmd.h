/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** cmd
*/

#ifndef CMD_H_
    #define CMD_H_

    #include "server.h"

int forward(data_t *data, char *arg);
int right(data_t *data, char *arg);
int left(data_t *data, char *arg);
int look(data_t *data, char *arg);
int inventory(data_t *data, char *arg);
int broadcast(data_t *data, char *arg);
int connect_nbr(data_t *data, char *arg);
//int fork(data_t *data, char *arg);
int eject(data_t *data, char *arg);
int take(data_t *data, char *arg);
int set(data_t *data, char *arg);
int incantation(data_t *data, char *arg);

static const char *cmd[] = {
    {"forward\0", &forward},
    {"right\0", &right},
    {"left\0", &left},
    {"look\0", &look}, // return char ** of look
    {"inventory", &inventory},
    {"broadcast", &broadcast}, // string
    {"connect_nbr", &connect_nbr}, // return int nb place team
    //{"fork\0", &fork},
    {"eject\0", &eject},
    {"take", &take},
    {"set", &set},
    {"incantation", &incantation}, // send to all client on tile
    {NULL, NULL}
};

#endif /* !CMD_H_ */
