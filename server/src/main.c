/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** main
*/

#include <stdio.h>
#include <string.h>

#include "server.h"

static int help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height ");
    printf("-n name1 name2 ... -c clientsNb -f freq\n");
    printf("\tport\t\tis the port number\n");
    printf("\twidth\t\tis the width of the world\n");
    printf("\theight\t\tis the height of the world\n");
    printf("\tnameX\t\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\t\tis the reciprocal of time unit for execution of ");
    printf("actions\n");
    return 0;
}

int main(int argc, char **argv)
{
    server_t *server = malloc(sizeof(server_t));
    map_t *map = malloc(sizeof(map_t));

    if (map == NULL || server == NULL)
        return 84;
    init_struct(argv, server, map);
    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        return help();
    return server(argc, argv);
}
