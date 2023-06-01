##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Main.py
##

## @file Main.py

from AI.Arguments import Arguments
from AI.Client import Client

## @author Damien
## @brief Print the message explaining how to use it
## @return always 1
def print_h() -> int:
    print("""USAGE: ./zappy_ai -p port -n name -h machine
\tport\tis the port number
\tname\tis the name of the team
\tmachine\tis the name of the machine; localhost by default""")
    return 1

## @author Damien and Pierre-Louis
## @brief Argument error handling
## @param argc is the length of argv
## @param argv contain argument given by the user
## @return 84 in case of error otherwise 0 or 1 in case of sucess
def error_handling(argc: int, argv: list[str]) -> int:
    if argc == 1 and (argv[0] == "-help" or argv[0] == "-h"):
        return print_h()
    if argc != 4 and argc != 6:
        print("error: invalid number of arguments")
        return 84
    return 0

## @author Damien and Pierre-Louis
## @brief Start function for ia launches error handling and connection to server
## @param argc is the length of argv
## @param argv contain argument given by the user
## @return 84 in case of error otherwise 0 or 1 in case of sucess
def main(argc: int, argv: list[str]) -> int:
    value_return = error_handling(argc, argv)
    if (value_return == 84):
        return 84
    if (value_return == 1):
        return 0
    args = Arguments.Arguments()
    args.parse_args(argc, argv)
    Client.connect_to_server(args)
    return 0
