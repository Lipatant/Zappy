##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## ai/main.py
##

## @file main.py

from ai.arguments import arguments
from ai.trantorians import trantorians
from ai.client import Client
from ai.error import print_error_exit

## @author Damien and Pierre-Louis
## @brief Print the message explaining how to use it
## @return always 0
def print_h() -> int:
    print("""USAGE: ./zappy_ai -p port -n name -h machine
\tport\tis the port number
\tname\tis the name of the team
\tmachine\tis the name of the machine; localhost by default""")
    exit(0)

## @author Damien and Pierre-Louis
## @brief Argument error handling
## @param argc is the length of argv
## @param argv contain argument given by the user
## @return 84 in case of error otherwise 0 or 1 in case of sucess
def error_handling(argc: int, argv: list[str]) -> int:
    if argc == 1 and (argv[0] == "-help" or argv[0] == "-h"):
        print_h()
    if argc != 4 and argc != 6:
        print_error_exit("error: invalid number of arguments")

## @author Damien and Pierre-Louis
## @brief Start function for ia launches error handling and connection to server
## @param argc is the length of argv
## @param argv contain argument given by the user
## @return 84 in case of error otherwise 0 or 1 in case of sucess
def main(argc: int, argv: list[str]) -> int:
    error_handling(argc, argv)
    args = arguments.arguments()
    args.parse_args(argc, argv)
    client = Client.Client(args)
    client.connect_to_server()
    msg = client.communicate()
    client.parsing_data(msg)
    trant = trantorians.trantorians(client)
    attributes = dir(trant)

    ######## functions in array  ################
    functions = [attr for attr in attributes if callable(getattr(trant, attr))
                and not attr.startswith('__')]

    ######## print functions and their index#########
    for i in range (len(functions)):
        print(i, functions[i])

    ######## call look ########
    getattr(trant, functions[12])()

    client.disconnect_from_server()
    return 0