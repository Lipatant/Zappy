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
    #include <stdbool.h>

typedef struct data_s {
    int fd;
    int socket;
    int port;
    char **args;
    char *ip;
} data_t;

typedef struct server_s {
    int port;
    int fd;
    int queue;
    int client;
    struct sockaddr_in addr;
    socklen_t size_addr;
    socklen_t size_sock;
} server_t;

typedef struct client_s {
    int fd;
    struct sockaddr_in addr;
    fd_set read_fd;
    data_t **data;
} client_t;

typedef struct args_s {
    int port;
    int width;
    int height;
    char **names;
    int clients;
    int freq;
} args_t;

int server(int argc, char **argv);
int error(char *msg);
int find_client(data_t **data, int nbr, int fd);
int add_client(server_t *s, client_t *c, int fd);
int handle_client_io(server_t *s, client_t *c, int i);
int in_loop(client_t *c, server_t *s);

#endif /* !SERVER_H_ */
