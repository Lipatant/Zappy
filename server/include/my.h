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

enum orientation { UP, DOWN, LEFT, RIGHT };

void init_struct(args_t args, team_list_t *team_list, map_t *maps);
void make_elevation(team_t *team);
void elevation_lvl2(team_t *team);
void elevation_lvl3(team_t *team);
void elevation_lvl4(team_t *team);
void elevation_lvl5(team_t *team);
void elevation_lvl6(team_t *team);
void elevation_lvl7(team_t *team);
void elevation_lvl8(team_t *team);
void free_struct(player_t *player, map_t maps, team_list_t team);

#endif /* !MY_H_ */
