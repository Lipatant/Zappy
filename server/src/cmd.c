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

/**
 * @brief the function to check the ctrlf
 * @param command the command
 * @return the command
 */
static char *check_for_crlf(char *command)
{
    int len = strlen(command);

    if (command[len - 2] != '\r' || command[len - 1] != '\n')
        return NULL;
    command[len - 2] = '\0';
    return command;
}

/**
 * @brief the function to free the split
 * @param splitted the char ** to be split
 */
static void free_split(char **splitted)
{
    for (int i = 0; splitted[i] != NULL; i++)
        free(splitted[i]);
    free(splitted);
}

/**
 * @brief the function for spliting the command by the ' '
 * @param command
 * @return char ** the list with the command
 */
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

/**
 * @brief the cmd function that check the list for the command and execute it
 * if the command does not exist send ko
 * @param data the struct data
 * @param command the command get with read
 * @param c the client struct
 * @return
 * 0 if no error
 * 84 if error
 */
int cmd(data_t *data, char *command, client_t *c)
{
    int ret = -1;
    data->player = c->player;
    data->map = c->map;
    data->team = c->team;
    data->team_list = c->team_list;
    data->player->fd = c->fd;
    data->args = get_splitted(command);
    if (data->args == NULL)
        return 84;
    for (int i = 0; cmds[i].cmd != NULL; i++) {
        if (strcmp(cmds[i].cmd, data->args[0]) == 0) {
            data = cmds[i].func_ptr(data);
            ret = 0;
            break;
        }
    }
    if (ret == -1)
        dprintf(data->fd, "ko\n");
    free_split(data->args);
    return 0;
}
