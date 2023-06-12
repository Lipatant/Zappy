/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** utils_split
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "server.h"

int count_parts(const char *command, char sep)
{
    int nbr = 0;

    for (const char *c = command; *c != '\0'; c++)
        if (*c == sep)
            nbr++;
    return nbr;
}

char *convert_to_lowercase(char *to_convert)
{
    for (char *c = to_convert; *c != '\0'; c++)
        *c = tolower(*c);
    return to_convert;
}

char **create_split(int nbr, const char *command)
{
    char **split = malloc(sizeof(char *) * (nbr + 2));

    if (split == NULL)
        return NULL;
    for (int i = 0; i <= nbr; i++) {
        split[i] = calloc(strlen(command) + 1, sizeof(char));
        if (split[i] == NULL)
            return NULL;
    }
    return split;
}

char **simple_split(const char *command)
{
    char **split = malloc(sizeof(char *) * 2);

    if (split == NULL)
        return NULL;
    split[0] = strdup(command);
    if (split[0] == NULL) {
        free(split);
        return NULL;
    }
    split[0] = convert_to_lowercase(split[0]);
    split[1] = NULL;
    return split;
}
