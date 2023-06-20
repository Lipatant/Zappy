##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## ai/trantorians/trantorians.py
##

## @file trantorians.py

from ai.client import Client

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
class trantorians:
    level: int
    bag: list[int]
    client: Client

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def __init__(self, client: Client) -> None:
        self.level = 1
        self.bag = [0 for i in range(6)]
        self.client = client

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def forward(self) -> None:
        to_send = "Forward\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def left(self) -> None:
        to_send = "Left\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def right(self) -> None:
        to_send = "Right\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def look(self) -> None:
        to_send = "Look\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def inventory(self) -> None:
        to_send = "Inventory\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def broadcast_text(self, text) -> None:
        to_send = "Broadcast " + text + "\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def connect_nbr(self) -> None:
        to_send = "Connect_nbr\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def fork(self) -> None:###creer un oeuf
        to_send = "Fork\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def eject(self) -> None:
        to_send = "Eject\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def take_object(self, object: str) -> None:
        to_send = "Take " + object + "\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def set_object(self, object: str) -> None:
        to_send = "Set " + object + "\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def incantation(self) -> None:
        to_send = "Incantation\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)
