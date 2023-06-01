##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/main.py
##

from AI.Arguments import Arguments
from AI.Client import Client

def print_h():
    print("""USAGE: ./zappy_ai -p port -n name -h machine
\tport\tis the port number
\tname\tis the name of the team
\tmachine\tis the name of the machine; localhost by default""")
    return 1

def error_handling(argc: int, argv: list[str]):
    if argc == 2 and argv[1] == "-help":
        return print_h()
    if argc != 5 and argc != 7:
        print("error: invalid number of arguments")
        return 84
    return 0

def main(argc: int, argv: list[str]):
    value_return = error_handling(argc, argv)
    if (value_return == 84):
        return 84
    if (value_return == 1):
        return 0
    args = Arguments.Arguments()
    args.parse_args(argc, argv)
    Client.connect_to_server(args)
    return 0
