##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Trantorians/Trantorians.py
##

## @file Trantorians.py

# 0=up | 1=right | 2=down | 3=left

## @author Damien Benais-Captal et Pierre-Louis Leroy
## @brief Cette fonction permet ...
## @param a ...
## @return None

class Trantorians:
    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def __init__(self) -> None:
        self.direction = 0
        self.food = 126
        self.found = []
        self.inventory = {}
        self.fov = 1
        self.sound = 0

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def forward(self) -> None:
        print("forward")

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def left(self) -> None:
        self.direction -= 1
        if self.direction < 0:
            self.direction = 3

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def right(self) -> None:
        self.direction += 1
        if self.direction > 3:
            self.direction = 0

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def look(self) -> None:
        print(f"look for {self.fov} squares")

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def inventory(self) -> None:
        print(self.inventory)

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def broadcast_text(self, text) -> None:
        print(text)

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def connect_nbr(self) -> None:
        print("slot")

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def fork(self) -> None:
        print("fork")

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def eject(self) -> None:
        print(" eject")

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def dead(self) -> bool:
        if (self.food < 0):
            print("dead")
            return True
        return False

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def take_object(self) -> None:
        print("take_object")

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def set_object(self) -> None:
        print("set_object")

    ## @author Damien Benais-Captal
    ## @brief Cette fonction permet ...
    ## @param a ...
    ## @return None
    def incantation(self) -> None:
        print("incantation")
