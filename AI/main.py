##
## EPITECH PROJECT, 2022
## AI
## File description:
## main.py
##

from AI.Arguments import Arguments
from AI.Client import Client

def parse_args(argc, argv):
    args = Arguments.Arguments()
    for i in range(1, argc, 2):
        if argv[i] == "-p":
            args.port = int(argv[i + 1])
        elif argv[i] == "-n":
            args.name = argv[i + 1]
        elif argv[i] == "-h":
            args.machine = argv[i + 1]
        else:
            print(f"error: invalid parser parameter: {argv[i]}")
            exit(84)
    if args.port == 0 or args.name == "" or args.machine == "":
        print("Error: invalid parser")
        exit(84)
    return args


def print_h():
    print("""USAGE: ./zappy_ai -p port -n name -h machine
\tport\tis the port number
\tname\tis the name of the team
\tmachine\tis the name of the machine; localhost by default""")
    return 1

def error_handling(argc, argv):
    if argc == 2 and argv[1] == "-help":
        return print_h()
    if argc != 5 and argc != 7:
        print("error: invalid number of arguments")
        return 84
    return 0

def main(argc, argv):
    value_return = error_handling(argc, argv)
    if (value_return == 84):
        return 84
    if (value_return == 1):
        return 0
    args = parse_args(argc, argv)
    Client.connect_to_server(args.port, args.name, args.machine)
    return 0
