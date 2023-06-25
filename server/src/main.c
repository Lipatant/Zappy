/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server.h"
#include "my.h"

/**
 * @brief the function for displaying the help
 *
 * @return int the return value
 *      return 0 if no error
 */

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
    exit (0);
}

/**
 * @brief the function for parsing the names
 *
 * @param argc nb of arguments
 * @param argv the arguments
 * @param args the structure of the arguments
 * @return args_t the structure of the arguments with the names inside
 */
static args_t parse_names(int argc, char **argv, args_t args)
{
    int i = 0;
    if (optarg[0] != '-') {
        args.names = realloc(args.names, (i + 2) * sizeof(char *));
        args.names[i] = optarg;
        args.names[i + 1] = NULL;
        i++;
    }
    while (optind < argc && argv[optind][0] != '-') {
        args.names = realloc(args.names, (i + 2) * sizeof(char *));
        args.names[i] = argv[optind];
        args.names[i + 1] = NULL;
        i++;
        optind++;
    }
    return args;
}

/**
 * @brief the second function for checking the arguments
 *
 * @param argc the number of arguments
 * @param argv the arguments
 * @param args the structure of the arguments
 * @param opt the option that is given by getopt
 * @return args_t the structure of the arguments with the arguments inside
 */
static args_t check_args_2(int argc, char **argv, args_t args, int opt)
{
    switch (opt) {
        case 'x':
            args.width = atoi(optarg);
            break;
        case 'y':
            args.height = atoi(optarg);
            break;
        case 'n':
            args = parse_names(argc, argv, args);
            break;
        case 'c':
            args.clients = atoi(optarg);
            break;
        case 'f':
            args.freq = atoi(optarg);
            break;
        default:
            return args;
    }
    return args;
}

/**
 * @brief the function for checking the arguments
 *
 * @param argc the number of arguments
 * @param argv the arguments
 * @param args the structure of the arguments
 * @return args_t the structure of the arguments with the arguments inside
 */
static args_t check_args(int argc, char **argv, args_t args)
{
    int opt = 0;

    while (1) {
        opt = getopt(argc, argv, "hp:x:y:n:c:f:");
        if (opt == -1)
            break;
        switch (opt) {
            case 'h':
                help();
                break;
            case 'p':
                args.port = atoi(optarg);
                break;
            default:
                args = check_args_2(argc, argv, args, opt);
                break;
        }
    }
    return args;
}

/**
 * @brief the main function
 *
 * @param argc the number of arguments
 * @param argv the arguments
 * @return int the return value
 *      if 0 no error
 *      if 84 an error occured
 */
int main(int argc, char **argv)
{
    map_t map;
    args_t args;
    team_list_t team_list = {0, 0};

    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        return help();
    args.names = malloc(sizeof(char *));
    args.names[0] = NULL;
    args = check_args(argc, argv, args);
    init_struct(args, &team_list, &map);
    if (server(args, team_list, map) == 84)
        return 84;
    free_struct(team_list.team->player, map, team_list);
    return 0;
}
