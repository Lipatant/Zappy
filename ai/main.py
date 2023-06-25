##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## ai/main.py
##

## @file main.py

from ai.arguments import arguments
from ai.client import client
from ai.error import print_error_exit
from ai.parser_look import search_stone, random_move
from ai.trantorians import trantorians

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

## @author Pierre-Louis
def check_nb_food(trant, functions, client) -> bool:
    getattr(trant, functions[6])() #inventory
    client.check_client()
    chaine = client.data

    if (chaine != "ok\n" and chaine != "ko\n"):
        elements = chaine.strip('[ ]').split(',')
        nombre_food = None
        for element in elements:
            nom, quantite = element.strip().split()
            if nom == "food":
                nombre_food = int(quantite)
                break
        if nombre_food.isdigit() and nombre_food < 30:
            return True
        else:
            return False
    return False

## @author Damien
## @brief create a trantorian and then loop
## @return always 0
def trantorian_lives(client: client, args: arguments):
    linemate_found = False
    trant = trantorians.Trantorians(client)
    attributes = dir(trant)
    functions = [attr for attr in attributes if callable(getattr(trant, attr))
                and not attr.startswith('_')]

    getattr(trant, functions[1])() #connect nbr
    if int(client.data[0]) > 0:
        getattr(trant, functions[3])(args) #fork

    while 1:
        getattr(trant, functions[11])("food") #take food
        client.check_client()

        if (trant.level == 1):
            linemate_found = search_stone(trant, functions, client)

        if (trant.level == 1 and linemate_found):
            getattr(trant, functions[5])() #incantation
            client.check_client()
            if (client.data == "Elevation underway\n"):
                client.data = client.socket.recv(1024).decode()
                print("Received from server:", client.data)
                trant.level = 2
                linemate_found = False

        if (trant.level == 2):
            random_move(trant, functions, client)

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
    args = arguments.Arguments()
    args.parse_args(argc, argv)

    # create the client, see client/Client.py
    client_m = client.Client(args)
    client_m.connect_to_server()

    # this part initializes with the server
    msg = client_m.communicate()
    client_m.parsing_data(msg)
    trantorian_lives(client_m, args)
