##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## ai/trantorians/trantorians.py
##

## @file trantorians.py

from ai.client import client
from ai.arguments import arguments
import os

## @author Damien
## @brief lists of the resources
## @details each resource is at its index
RESOURCES = [
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thysmate",
]

## @author Damien
## @brief lists of the resources needed for the trantorian to upgrade
## @details each list correspond to index - 1
UPGRADES = [
    [1, 0, 0, 0, 0, 0],
    [1, 1, 1, 0, 0, 0],
    [2, 0, 1, 0, 2, 0],
    [1, 1, 2, 0, 1, 0],
    [1, 2, 1, 3, 0, 0],
    [1, 2, 3, 0, 1, 0],
    [2, 2, 2, 2, 2, 1],
]

## @author Damien and Pierre-Louis
## @brief contain function and variable for trantorians
## @details The name trantorians refers to bots that do not collaborate with each other to evolve.
class Trantorians:
    level: int
    bag: list[int]
    client_t: client

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def __init__(self, client: client) -> None:
        self.level = 1
        self.bag = [0 for i in range(6)]
        self.client_t = client

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def forward(self) -> None:
        try:
            self.client_t.write_to_server("Forward\n")
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)
    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def left(self) -> None:
        try:
            self.client_t.write_to_server("Left\n")
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def right(self) -> None:
        try:
            self.client_t.write_to_server("Right\n")
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def look(self) -> None:
        try:
            self.client_t.write_to_server("Look\n")
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def inventory(self) -> None:
        try:
            self.client_t.write_to_server("Inventory\n")
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def broadcast_text(self, text) -> None:
        try:
            to_send = "Broadcast " + text + "\n"
            self.client_t.write_to_server(to_send)
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def connect_nbr(self) -> None:
        try:
            self.client_t.write_to_server("Connect_nbr\n")
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def fork(self, args) -> None:###creer un oeuf
        try:
            self.client_t.write_to_server("Fork\n")
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)
        if self.client_t.data == "ok\n":
            pid = os.fork()
            if pid == 0:
                cmd = f"./zappy_ai -p {args.port} -n {args.team} -h {args.ip}"
                os.system(cmd)
                self.client_t.disconnect_from_server()
                exit(0)
            else:
                return pid
    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def eject(self) -> None:
        try:
            self.client_t.write_to_server("Eject\n")
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def take_object(self, object: str) -> None:
        try:
            to_send = "Take " + object + "\n"
            self.client_t.write_to_server(to_send)
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def set_object(self, object: str) -> None:
        try:
            to_send = "Set " + object + "\n"
            self.client_t.write_to_server(to_send)
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def incantation(self) -> None:
        try:
            self.client_t.write_to_server("Incantation\n")
            self.client_t.read_server()
        except:
            print("error reading")
            exit(84)
