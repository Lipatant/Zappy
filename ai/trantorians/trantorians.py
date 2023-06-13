##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## ai/trantorians/trantorians.py
##

## @file trantorians.py

from ai.client import Client

# inventory indexes
FOOD = 0
LINEMATE = 1
DERAUMERE = 2
SIBUR = 3
MENDIANE = 4
PHIRAS = 5
THYSMATE = 6

####    temporary map, it is used as a global variable for now but will soon be
####    replaced by the one from the server
tmp_map = [
    [i for k in range(10)] for i in range(10)
]

import os

## @author Damien and Pierre-Louis
## @brief contain function and variable for trantorians
## @details The name trantorians refers to bots that do not collaborate with each other to evolve.
class trantorians:
    direction: int
    food: int
    found: list[int]####temporary
    fov: int
    bag: list[int]
    sound: int###temporary, need to know what this is
    x: int
    y: int
    client: Client

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def __init__(self, client: Client) -> None:
        self.direction = 0
        self.food = 126
        self.found = []
        self.level = 1
        self.sound = 0
        self.bag = [0 for i in range(7)]
        #temporary values ###
        self.x = 2
        self.y = 2
        self.client = client
        #####################

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

#        self.food -= 1
#        if self.direction == 0:
#            self.x -= 1
#            if self.x < 0:
#                self.x = self.client.x - 1
#        elif self.direction == 1:
#            self.y += 1
#            if self.y > self.client.y - 1:
#                self.y = 0
#        elif self.direction == 2:
#            self.x += 1
#            if self.x > self.client.x - 1:
#                self.x = 0
#        elif self.direction == 3:
#            self.y -= 1
#            if self.y < 0:
#                self.y = self.client.y - 1
#        to_send = "Forward\n"
#        self.client.socket.send(to_send.encode())

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
#        self.direction -= 1
#        if self.direction < 0:
#            self.direction = 3
#        to_send = "Left\n"
#        self.client.socket.send(to_send.encode())

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
#        self.direction += 1
#        if self.direction > 3:
#            self.direction = 0
#        to_send = "Right\n"
#        self.client.socket.send(to_send.encode())

    ## @author Pierre-Louis
    ## @brief function for the trantorian can looking up
    ## @param self Contains trantorian values
    ## @return None
    def _look_up(self) -> None:
        for i in range(0, self.level + 1):
            j = i
            rank = self.x - i
            while (rank < 0):
                rank += self.client.x
            while (j > 0):
                print(tmp_map[rank][self.y - j], end = "")
                j -= 1
            print(tmp_map[rank][self.y], end = "")
            for k in range(1, i + 1):
                print(tmp_map[rank][self.y + k], end = "")
            print()



    ## @author Damien
    ## @brief function for the trantorian can looking down
    ## @param self Contains trantorian values
    ## @return None
    def _look_down(self) -> None:
        for i in range(0, self.level + 1):
            j = i
            rank = self.x + i
            while (rank >= self.client.x):
                rank -= self.client.x
            while (rank < 0):
                rank += self.client.x
            for k in range(1, i + 1):
                print(tmp_map[rank][self.y + k], end="")
            print(tmp_map[rank][self.y], end="")#middle
            while (j > 0):
                print(tmp_map[rank][self.y - j], end = "")
                j -= 1
            print()

    ## @author Cyprien
    ## @brief function for the trantorian can looking to the left
    ## @param self Contains trantorian values
    ## @return None
    def _look_left(self) -> None:
        for i in range(0, self.level + 1):
            j = i
            rank = self.y - i
            while (rank < 0):
                rank += self.client.y - 1

            while (j > 0):
                print(tmp_map[self.x + j][rank], end="")
                j -= 1

            print(tmp_map[self.x][rank], end="")

            for k in range(1, i + 1):
                print(tmp_map[self.x - k][rank], end="")
            print()



    ## @author Cyprien
    ## @brief function for the trantorian can looking to the right
    ## @param self Contains trantorian values
    ## @return None
    def _look_right(self) -> None:
        for i in range(0, self.level + 1):
            j = i
            rank = self.y + i
            while (rank >= self.client.y):
                rank -= self.client.y
            while j > 0:
                print(tmp_map[self.x - j][rank], end="")
                j -= 1
            print(tmp_map[self.x][rank], end="")
            for k in range(1, i + 1):
                print(tmp_map[self.x + k][rank], end="")
            print()

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
#        if (self.direction == 0):
#            self._look_up()
#        if (self.direction == 1):
#            self._look_right()
#        if (self.direction == 2):
#            self._look_down()
#        if (self.direction == 3):
#            self._look_left()
#        to_send = "Look\n"
#        self.client.socket.send(to_send.encode())


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
#        print(f"""    Inventory:
#Food: {self.bag[FOOD]}
#Linemate: {self.bag[LINEMATE]}
#Deraumere: {self.bag[DERAUMERE]}
#Sibur: {self.bag[SIBUR]}
#Mendiane: {self.bag[MENDIANE]}
#Phiras: {self.bag[PHIRAS]}
#Thysmate: {self.bag[THYSMATE]}
#""")

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def broadcast_text(self, text) -> None:
        to_send = "Broacast " + text + "\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)
#        print(text)
#        to_send = "Broadcast " + text + "\n"
#        self.client.socket.send(to_send.encode())

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
#        print("slot")
#        to_send = "Connect_nbr\n"
#        self.client.socket.send(to_send.encode())

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
#        pid: int = os.fork()
#        to_send = "Fork\n"
#        self.client.socket.send(to_send.encode())
#
#        if pid > 0:
#            print("I am parent process:")
#            print("Process ID:", os.getpid())
#            print("Child's process ID:", pid)
#        else:
#            print("\nI am child process:")
#            print("Process ID:", os.getpid())
#            print("Parent's process ID:", os.getppid())

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
#        print(" eject")
#        to_send = "eject\n"
#        self.client.socket.send(to_send.encode())

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return True if he runs out of food else return False
    def dead(self) -> bool:
        if (self.food < 0):
            return True
        return False

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def take_object(self) -> None:
        to_send = "Take object\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)
#        print("Take object")
#        to_send = "Take object\n"
#        self.client.socket.send(to_send.encode())

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def set_object(self) -> None:
        to_send = "Set object\n"
        self.client.socket.send(to_send.encode())
        print("Sent to server:", to_send)
        self.client.data = self.client.socket.recv(1024).decode()
        print("Received from server:", self.client.data)
#        print("Set object")
#        to_send = "Set object\n"
#        self.client.socket.send(to_send.encode())

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
#        print("Incantation")
#        to_send = "Incantation\n"
#        self.client.socket.send(to_send.encode())
# things to do are updated on the trello, do not hesitate
