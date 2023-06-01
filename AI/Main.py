##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Main.py
##

## @file Main.py

from AI.Arguments import Arguments
from AI.Client import Client

## @author Damien Benais-Captal
## @brief Cette fonction permet ...
## @param a ...
## @return None
def print_h() -> int:
    print("""USAGE: ./zappy_ai -p port -n name -h machine
\tport\tis the port number
\tname\tis the name of the team
\tmachine\tis the name of the machine; localhost by default""")
    return 1

## @author Damien Benais-Captal
## @brief Cette fonction permet ...
## @param a ...
## @return None
def error_handling(argc: int, argv: list[str]) -> int:
    if argc == 2 and argv[1] == "-help":
        return print_h()
    if argc != 5 and argc != 7:
        print("error: invalid number of arguments")
        return 84
    return 0

## @author Damien Benais-Captal
## @brief Cette fonction permet ...
## @param a ...
## @return None
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