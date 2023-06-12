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

int server(args_t args);
int error(char *msg);
int find_client(data_t **data, int nbr, int fd);
int add_client(server_t *s, client_t *c, int fd);
int handle_client_io(server_t *s, client_t *c, int i);
int in_loop(client_t *c, server_t *s);
char **simple_split(const char *command);
char **create_split(int nbr, const char *command);
char *convert_to_lowercase(char *to_convert);
int count_parts(const char *command, char sep);
int cmd(data_t *data, char *command);
char **split(const char *command, char sep);
int command(server_t *s, client_t *c, data_t *data);
buffer_t *create_node(char *str);
void delete_at_begining(buffer_t **head);
void insert_at_end(buffer_t **head, char *str);
int size_list(buffer_t *head);

#endif /* !SERVER_H_ */
