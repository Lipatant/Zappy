/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** error
*/

#include <stdio.h>

/**
 * @brief the function for perror the error and return 84
 * @param msg the error msg
 * @return
 */
int error(char *msg)
{
    perror(msg);
    return 84;
}
