/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** command
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "server.h"

static int manage_quit(server_t *s, data_t *data)
{
    s->client--;
    close(data->fd);
    free(data);
    return 0;
}

static char *clean_str(char *str)
{
    int space = 0;
    int i = 0;
    char *clean = malloc(strlen(str) + 1);

    for (i = 0; str[i]; i++) {
        if (str[i] == '\t') {
            str[i] = ' ';
        }
    }
    for (space = 0; str[space] == ' '; space++);
    for (i = 0; str[space]; space++) {
        if (!(str[space] == ' ' && str[space + 1] == ' ')) {
            clean[i++] = str[space];
        }
    }
    if (clean[strlen(clean) - 1] == ' ') {
        clean[strlen(clean) - 1] = '\0';
    }
    free(str);
    return clean;
}

static char *get_command(data_t *data)
{
    int ret = 0;
    size_t size = 500;
    char *buff = malloc(sizeof(char) * size);

    if (buff == NULL) {
        perror("malloc");
        return NULL;
    }
    memset(buff, '\0', size);
    ret = read(data->fd, buff, size);
    if (ret <= 0) {
        perror("read");
        free(buff);
        return NULL;
    }
    return clean_str(buff);
}

int command(server_t *s, client_t *c, data_t *data)
{
    char *command = get_command(data);
    int ret = (command == NULL) ? 84 : cmd(data, command);

    free(command);
    if (ret == 1) {
        return manage_quit(s, data);
    }
    return 0;
}
