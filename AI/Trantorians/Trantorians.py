##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Trantorians/Trantorians.py
##

## @file Trantorians.py

####    temporary map, it is used as a global variable for now but will soon be
####    replaced by the one from the server
tmp_map = [
    [0,0,0,0,0],
    [1,1,1,1,1],
    [2,2,2,2,2],
    [3,3,3,3,3],
    [4,4,4,4,4],
]

import os

## @author Damien and Pierre-Louis
## @brief contain function and variable for Trantorians
## @details The name Trantorians refers to bots that do not collaborate with each other to evolve.
class Trantorians:
    direction: int
    food: int
    found: list[int]####temporary
    fov: int
    inventory: dict
    sound: int###temporary, need to know what this is
    x: int
    y: int

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def __init__(self) -> None:
        self.direction = 0
        self.food = 126
        self.found = []
        self.level = 1
        self.inventory = {}
        self.sound = 0
        #temporary values ###
        self.x = 2
        self.y = 2
        #####################

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def forward(self) -> None:
        if self.direction == 0:
            self.x -= 1
        elif self.direction == 1:
            self.y += 1
        elif self.direction == 2:
            self.x += 1
        elif self.direction == 3:
            self.y -= 1

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
    def look_up(self) -> None:
        for i in range(0, self.level + 1):
            j = i
            while (j > 0):
                print(tmp_map[self.x - i][self.y - j], end = "")
                j -= 1
            print(tmp_map[self.x - i][self.y], end = "")
            for k in range(1, i + 1):
                print(tmp_map[self.x - i][self.y + k], end = "")
            print()



    ## @author Damien
    ## @brief function for the trantorian can looking down
    ## @param self Contains trantorian values
    ## @return None
    def look_down(self) -> None:
        for i in range(0, self.level + 1):
            j = i
            for k in range(1, i + 1):
                print(tmp_map[self.x + i][self.y + k], end="")
            print(tmp_map[self.x + i][self.y], end="")#middle
            while (j > 0):
                print(tmp_map[self.x + i][self.y - j], end = "")
                j -= 1
            print()

    ## @author Cyprien
    ## @brief function for the trantorian can looking to the left
    ## @param self Contains trantorian values
    ## @return None
    def look_left(self) -> None:
        for i in range(0, self.level + 1):
            j = i

            while (j > 0):
                print(tmp_map[self.x + j][self.y - i], end="")
                j -= 1

            print(tmp_map[self.x][self.y - i], end="")

            for k in range(1, i + 1):
                print(tmp_map[self.x - k][self.y - i], end="")
            print()



    ## @author Cyprien
    ## @brief function for the trantorian can looking to the right
    ## @param self Contains trantorian values
    ## @return None
    def look_right(self) -> None:
        for i in range(0, self.level + 1):
            j = i
            while j > 0:
                if self.y - j >= 0 and self.x + i < len(tmp_map[self.y - j]):
                    print(tmp_map[self.y - j][self.x + i], end="")
                j -= 1
            if self.y >= 0 and self.x + i < len(tmp_map[self.y]):
                print(tmp_map[self.y][self.x + i], end="")
            for k in range(1, i + 1):
                if self.y + k < len(tmp_map) and self.x + i < len(tmp_map[self.y + k]):
                    print(tmp_map[self.y + k][self.x + i], end="")
            print()

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def look(self) -> None:
        if (self.direction == 0):
            self.look_up()
        if (self.direction == 1):
            self.look_right()
        if (self.direction == 2):
            self.look_down()
        if (self.direction == 3):
            self.look_left()


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
    def fork(self) -> None:
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
