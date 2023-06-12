/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** split
*/

#include <stdio.h>

#include "server.h"

char **split_count(const char *command, char sep, int *nbr_parts)
{
    int count = 0;
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == sep) {
            count++;
        }
    }
    *nbr_parts = count + 1;
    return simple_split(command);
}

char **split_create(const char *command, char sep, int nbr)
{
    char **split = create_split(nbr, command);
    int j = 0;
    int z = 0;

    if (split == NULL)
        return NULL;
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == sep) {
            split[j][z] = '\0';
            j++;
            z = 0;
        } else {
            split[j][z] = command[i];
            z++;
        }
    }
    split[j][z] = '\0';
    split[0] = convert_to_lowercase(split[0]);
    split[nbr + 1] = NULL;
    return split;
}

char **split(const char *command, char sep)
{
    int nbr_parts = count_parts(command, sep);
    char **split;
    if (nbr_parts == 0) {
        return simple_split(command);
    }
    split = split_create(command, sep, nbr_parts);
    return split;
}
