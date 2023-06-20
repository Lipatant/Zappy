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

from ai.parser_look import *

import time
import random

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

## @author Damien
## @brief create a trantorian and then loop
## @return always 0
def trantorian_lives(client: Client):
    trant = trantorians.trantorians(client)
    attributes = dir(trant)
    functions = [attr for attr in attributes if callable(getattr(trant, attr))
                and not attr.startswith('_')]

    while 1:
        result = algo_search_stone(trant, functions, client)

        if (result == 42):
            break
        elif (result == 0):
            trant.bag[0] += 1
        time.sleep(1)

        getattr(trant, functions[11])("food") #take food
        client.check_client()

        #incantation
        if trant.bag == trantorians.UPGRADES[trant.level - 1]:
            for i in range(6):
                while(trant.bag[i] != 0):
                    getattr(trant, functions[10])(trantorians.RESOURCES[i])
                    client.check_client()
                    trant.bag[i] -= 1
            getattr(trant, functions[5])()
            client.check_client()
            if (client.data == "Elevation underway\n"):
                client.data = client.socket.recv(1024).decode()
                print("Received from server:", client.data)
                trant.bag = [0 for i in range(6)]
                trant.level += 1

    # disconnect
    client.disconnect_from_server()
    return 0

## @author Damien and Pierre-Louis
## @brief Start function for ia launches error handling and connection to server
## @param argc is the length of argv
## @param argv contain argument given by the user
## @return 84 in case of error otherwise 0 or 1 in case of sucess
def main(argc: int, argv: list[str]) -> int:

    # error handling exit if an error occured
    error_handling(argc, argv)

    # argument parser, see arguments/arguments.py
    args = arguments.arguments()
    args.parse_args(argc, argv)

    # create the client, see client/Client.py
    client = Client.Client(args)
    client.connect_to_server()

    # this part initializes with the server
    msg = client.communicate()
    client.parsing_data(msg)
    trantorian_lives(client)

# PARTIE AI ===================================================================

