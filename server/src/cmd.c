/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** cmd
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "server.h"
#include "cmd.h"

static char *check_for_crlf(char *command)
{
    int len = strlen(command);

    if (command[len - 2] != '\r' || command[len - 1] != '\n')
        return NULL;
    command[len - 2] = '\0';
    return command;
}

static void free_split(char **splitted)
{
    for (int i = 0; splitted[i] != NULL; i++)
        free(splitted[i]);
    free(splitted);
}

static char **get_splitted(char *command)
{
    char **splitted;

    command = check_for_crlf(command);
    if (command == NULL)
        return NULL;
    splitted = split(command, ' ');
    if (splitted == NULL)
        return NULL;
    for (int i = 0; splitted[0][i] != '\0'; i++) {
        if (splitted[0][i] == '\n' || splitted[0][i] == '\r') {
            splitted[0][i] = '\0';
            break;
        }
    }
    return splitted;
}

int cmd(data_t *data, char *command)
{
    int ret = -1;

    data->args = get_splitted(command);
    if (data->args == NULL)
        return 84;
    for (int i = 0; cmds[i].cmd != NULL; i++) {
        if (strcmp(cmds[i].cmd, data->args[0]) == 0) {
            ret = cmds[i].func_ptr(data);
            break;
        }
    }
    if (ret == -1)
        dprintf(data->fd, "Commande inconnue");
    free_split(data->args);
    return 0;
}
