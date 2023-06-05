##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Trantorians/Trantorians.py
##

## @file Trantorians.py

tmp_map_up = [
    [0,1,0,0,0,0,0],
    [3,0,2,0,0,0,3],
    [3,3,0,0,1,3,3],
    [3,3,3,0,3,3,3]
]

tmp_map_down = [
    [3,3,3,0,3,3,3],
    [3,3,0,0,1,3,3],
    [3,0,2,0,0,0,3],
    [0,1,0,0,0,0,0]
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

tmp_map_right = [
    [3,3,3,0],
    [3,3,0,1],
    [3,0,2,0],
    [0,0,0,0],
    [3,1,0,0],
    [3,3,0,0],
    [3,3,3,0]
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
    x: int
    y: int

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def __init__(self) -> None:
        self.direction = 1
        self.food = 126
        self.found = []
        self.level = 1
        self.inventory = {}
        self.sound = 0

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
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def loop_up(self, level: int) -> None:
        self.x = 3
        self.y = 4 - 1

        for i in range(0, level + 1):
            j = i
            while (j > 0):
                print(tmp_map_up[self.x - i][self.y - j], end = "")
                j -= 1
            print(tmp_map_up[self.x - i][self.y], end = "")
            for k in range(1, i + 1):
                print(tmp_map_up[self.x - i][self.y + k], end = "")
            print()

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def loop_down(self, level: int) -> None:
        self.x = 0
        self.y = 4 - 1

        for i in range(0, level):
            j = i
            while (j > 0):
                print(tmp_map_down[self.x + i][self.y - j], end = "")
                j -= 1
            print(tmp_map_down[self.x + i][self.y], end = "")
            for k in range(1, i + 1):
                print(tmp_map_down[self.x + i][self.y + k], end = "")
            print()

    ## @author Pierre-Louis
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def loop_left(self, level: int) -> None:
        self.x = 4 - 1
        self.y = 3

        for i in range(0, level):
            j = i
            while j > 0:
                if self.x - j >= 0 and self.y + i < len(tmp_map_left):
                    print(tmp_map_left[self.x - j][self.y - i], end="")
                j -= 1
            if self.x >= 0 and self.y - i < len(tmp_map_left):
                print(tmp_map_left[self.x][self.y - i], end="")
            for k in range(1, i + 1):
                if self.x + k < len(tmp_map_left) and self.y - i < len(tmp_map_left):
                    print(tmp_map_left[self.x + k][self.y - i], end="")
            print()
    ## @author Pierre-Louis
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def loop_right(self, level: int) -> None:
        self.x = 0
        self.y = 4 - 1

        for i in range(0, level):
            j = i
            while (j > 0):
                print(tmp_map_right[self.x + i][self.y - j], end = "")
                j -= 1
            print(tmp_map_right[self.x + i][self.y], end = "")
            for k in range(1, i + 1):
                print(tmp_map_right[self.x + i][self.y + k], end = "")
            print()

    ## @author Damien
    ## @brief
    ## @param self Contains trantorian values
    ## @return None
    def look(self, level: int) -> None:
        if (self.direction == 0):
            self.loop_up(level)
        elif (self.direction == 1):
            self.loop_left(level)
        elif (self.direction == 2):
            self.loop_down(level)
        elif (self.direction == 3):
            self.loop_right(level)
        else:
            exit(84)

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
