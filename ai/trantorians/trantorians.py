##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## ai/trantorians/trantorians.py
##

## @file trantorians.py

from ai.client import Client

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
    inventory: dict
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
        self.inventory = {}
        self.sound = 0
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
        if self.direction == 0:
            self.x -= 1
            if self.x < 0:
                self.x = self.client.x - 1
        elif self.direction == 1:
            self.y += 1
            if self.y > self.client.y - 1:
                self.y = 0
        elif self.direction == 2:
            self.x += 1
            if self.x > self.client.x - 1:
                self.x = 0
        elif self.direction == 3:
            self.y -= 1
            if self.y < 0:
                self.y = self.client.y - 1

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def left(self) -> None:
        self.direction -= 1
        if self.direction < 0:
            self.direction = 3

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def right(self) -> None:
        self.direction += 1
        if self.direction > 3:
            self.direction = 0

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
        if (self.direction == 0):
            self._look_up()
        if (self.direction == 1):
            self._look_right()
        if (self.direction == 2):
            self._look_down()
        if (self.direction == 3):
            self._look_left()


    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def inventory(self) -> None:
        print(self.inventory)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def broadcast_text(self, text) -> None:
        print(text)

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def connect_nbr(self) -> None:
        print("slot")

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def fork(self) -> None:###creer un oeuf
        pid: int = os.fork()

        if pid > 0:
            print("I am parent process:")
            print("Process ID:", os.getpid())
            print("Child's process ID:", pid)
        else:
            print("\nI am child process:")
            print("Process ID:", os.getpid())
            print("Parent's process ID:", os.getppid())

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def eject(self) -> None:
        print(" eject")

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return True if he runs out of food else return False
    def dead(self) -> bool:
        if (self.food < 0):
            print("dead")
            return True
        return False

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def take_object(self) -> None:
        print("take_object")

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def set_object(self) -> None:
        print("set_object")

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def incantation(self) -> None:
        print("incantation")

# things to do are updated on the trello, do not hesitate
