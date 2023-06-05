##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Trantorians/Trantorians.py
##

## @file Trantorians.py

# 0=up | 1=right | 2=down | 3=left
tmp_map_down = [
    [3,3,3,0,3,3,3],
    [3,3,0,0,1,3,3],
    [3,0,2,0,0,0,3],
    [0,1,0,0,0,0,0]
]

tmp_map_up = [
    [0,1,0,0,0,0,0],
    [3,0,2,0,0,0,3],
    [3,3,0,0,1,3,3],
    [3,3,3,0,3,3,3]
]

tmp_map_right = [
    [3,3,3,0],
    [3,3,0,1],
    [3,0,2,0],
    [0,0,0,0],
    [3,1,0,0],
    [3,3,0,0],
    [3,3,3,0]
]

tmp_map_left = [
    [0,3,3,3],
    [0,1,3,3],
    [0,2,0,3],
    [0,0,0,0],
    [1,0,0,3],
    [0,0,3,3],
    [0,3,3,3]
]

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



    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def __init__(self) -> None:
        self.direction = 2
        self.food = 126
        self.found = []
        self.fov = 1
        self.inventory = {}
        self.sound = 0

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def forward(self) -> None:
        print("forward")

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
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def loop_up(self, level: int) -> None:
        x = 0                          # x of the player
        y = 4 - 1                      # y - 1 of the player

        for i in range(0, level):
            j = i
            while (j > 0):             # MODIFIER ALGO
                print(tmp_map_up[x + i][y - j], end="")
                j -= 1
            print(tmp_map_up[x + i][y], end="") # middle
            for k in range(1, i + 1):
                print(tmp_map_up[x + i][y + k], end="")
            print()
                                       # print("up")

    ## @author Pierre-Louis
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def loop_right(self, level: int) -> None:
        x = 0                          # x of the player
        y = 4 - 1                      # y - 1 of the player

        for i in range(0, level):
            j = i
            while (j > 0):             # MODIFIER ALGO
                print(tmp_map_right[x + i][y - j], end="")
                j -= 1
            print(tmp_map_right[x + i][y], end="") # middle
            for k in range(1, i + 1):
                print(tmp_map_right[x + i][y + k], end="")
            print()
                                       # print("right")

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def loop_down(self, level: int) -> None:
        x = 0#x of the player
        y = 4 - 1#y - 1 of the player

        for i in range(0, level):
            j = i
            while (j > 0):
                print(tmp_map_down[x + i][y - j], end="")
                j -= 1
            print(tmp_map_down[x + i][y], end="")#middle
            for k in range(1, i + 1):
                print(tmp_map_down[x + i][y + k], end="")
            print()

    ## @author Pierre-Louis
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def loop_left(self, level: int) -> None:
        x = 0                          # x of the player
        y = 4 - 1                      # y - 1 of the player

        for i in range(0, level):
            j = i
            while (j > 0):             # MODIFIER ALGO
                print(tmp_map_left[x + i][y - j], end="")
                j -= 1
            print(tmp_map_left[x + i][y], end="") # middle
            for k in range(1, i + 1):
                print(tmp_map_left[x + i][y + k], end="")
            print()
                                       # print("left")

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def look(self, level: int) -> None:
        if (self.direction == 0):
            self.loop_up(level)
        if (self.direction == 1):
            self.loop_left(level)
        if (self.direction == 2):
            self.loop_down(level)
        if (self.direction == 3):
            self.loop_right(level)
# 0=up | 1=right | 2=down | 3=left

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
        print("fork")



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
