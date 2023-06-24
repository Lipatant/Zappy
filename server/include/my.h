/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include "struct.h"

enum orientation { UP, RIGHT, DOWN, LEFT };

void init_struct(args_t args, team_list_t *team_list, map_t *maps);
data_t *make_elevation(data_t *data);
data_t *elevation_lvl2(data_t *data);
data_t *elevation_lvl3(data_t *data);
data_t *elevation_lvl4(data_t *data);
data_t *elevation_lvl5(data_t *data);
data_t *elevation_lvl6(data_t *data);
data_t *elevation_lvl7(data_t *data);
data_t *elevation_lvl8(data_t *data);
bool check_lvl2(data_t *d);
bool check_lvl3(data_t *d);
bool check_lvl4(data_t *d);
bool check_lvl5(data_t *d);
bool check_lvl6(data_t *d);
bool check_lvl7(data_t *d);
bool check_lvl8(data_t *d);
bool check_ressource_lvl4(data_t *d);
bool check_ressource_lvl5(data_t *d);
bool check_ressource_lvl6(data_t *d);
bool check_ressource_lvl7(data_t *d);
bool check_ressource_lvl8(data_t *d);
void free_struct(player_t *player, map_t maps, team_list_t team);

#endif /* !MY_H_ */
