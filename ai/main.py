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
    trant = trantorians.trantorians(client)
    attributes = dir(trant)

    # list of the callable functions
    # So that functions beginning with '_' are ignored, create a function table
    functions = [attr for attr in attributes if callable(getattr(trant, attr))
                and not attr.startswith('_')]

# PARTIE AI ===================================================================

#    counter = 0
    while client.data != "dead\n":
#        print("===START===> ", counter, ">", client.data, "<")

        getattr(trant, functions[6])() #inventory
        if (client.data == "dead\n"):
            break

        getattr(trant, functions[4])() #forward
        if (client.data == "dead\n"):
            break

        time.sleep(1)
        rdm = random.randint(0,3)

        if rdm == 0:
            getattr(trant, functions[9])() #left
            if (client.data == "dead\n"):
                break
        elif rdm == 1:
            getattr(trant, functions[7])() #right
            if (client.data == "dead\n"):
                break

#        counter += 1
        time.sleep(1)
        getattr(trant, functions[8])() #look
        if (client.data == "dead\n"):
            break

        time.sleep(1)
        getattr(trant, functions[11])("food") #take food
        if (client.data == "dead\n"):
            break

        #loot resources
        for i in range(6):
            if trant.bag[i] != trantorians.UPGRADES[trant.level - 1][i]:
                getattr(trant, functions[11])(trantorians.RESOURCES[i])
                if (client.data == "dead\n"):
                    break
                if (client.data == "ok\n"):
                    trant.bag[i] += 1

        #incantation
        if trant.bag == trantorians.UPGRADES[trant.level - 1]:
            for i in range(6):
                while(trant.bag[i] != 0):
                    getattr(trant, functions[10])(trantorians.RESOURCES[i])
                    if (client.data == "dead\n"):
                        break
                    trant.bag[i] -= 1
            getattr(trant, functions[5])()
            if (client.data == "dead\n"):
                break
            trant.bag = [0 for i in range(6)]
            trant.level += 1
#    for i in range (9, 12):
#        print(i)
#        if i == 0 or i == 10 or i == 11:
#            getattr(trant, functions[i])("test")
#        else:
#            getattr(trant, functions[i])()

#    getattr(trant, functions[11])("food")
#    getattr(trant, functions[11])("food")
#    getattr(trant, functions[6])()
#    time.sleep(1)
#    # this part should be replaced by the command gestion. It must be able to
#    # listen to the server, change the data and execute the commands
#    # TEMPORARY VALUE

# PARTIE AI ===================================================================

    # disconnect
    client.disconnect_from_server()
    return 0

'''
0 Broacast "Text"
1 Connect_nbr
2 Eject
3 Fork
4 Forward
5 Incantation
6 Inventory
7 Left
8 Look
9 Right
10 Set "Text"
11 Take "Text"
'''
