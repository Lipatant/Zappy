/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** error
*/

#include <stdio.h>

int error(char *msg)
{
    perror(msg);
    return 84;
}
