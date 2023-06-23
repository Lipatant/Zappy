/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <netinet/in.h>
    #include <stddef.h>
    #include "struct.h"

int server(args_t args, team_list_t team_list, map_t map);
int error(char *msg);
int find_client(data_t **data, int nbr, int fd);
int add_client(server_t *s, client_t *c, int fd);
int handle_client_io(server_t *s, client_t *c, int i);
int in_loop(client_t *c, server_t *s);
char **simple_split(const char *command);
char **create_split(int nbr, const char *command);
char *convert_to_lowercase(char *to_convert);
int count_parts(const char *command, char sep);
int cmd(data_t *data, char *command, client_t *c);
char **split(const char *command, char sep);
int command(server_t *s, client_t *c, data_t *data);
int get_team_by_name(server_t *server, char *name, int nb_team);
player_t *init_player(player_t *player, server_t *server);
map_t *init_map(map_t *map, int nb_player);

#endif /* !SERVER_H_ */
