##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Trantorians/Trantorians.py
##

## @file Trantorians.py

# 0=up | 1=right | 2=down | 3=left

## @author Damien BENAIS-CAPTAL et Pierre-Louis LEROY
## @brief La class "Trantorians" permet de regrouper toutes les fonctions qui les concernent
## @details Le nom Trantorians désigne les bots qui ne collaborent pas entre eux pour évoluer
class Trantorians:
    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet d'initier self
    ## @param self Contient les valeurs du trantorian
    ## @return None
    def __init__(self) -> None:
        self.direction = 0
        self.food = 126
        self.found = []
        self.inventory = {}
        self.fov = 1
        self.sound = 0

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction de print "forward" quand ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def forward(self) -> None:
        print("forward")

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet au bot de tourner à gauche
    ## @param self contient les valeurs du trantorian
    ## @return None
    def left(self) -> None:
        self.direction -= 1
        if self.direction < 0:
            self.direction = 3

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def right(self) -> None:
        self.direction += 1
        if self.direction > 3:
            self.direction = 0

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def look(self) -> None:
        print(f"look for {self.fov} squares")

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def inventory(self) -> None:
        print(self.inventory)

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @param text
    ## @return None
    def broadcast_text(self, text) -> None:
        print(text)

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def connect_nbr(self) -> None:
        print("slot")

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def fork(self) -> None:
        print("fork")

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def eject(self) -> None:
        print(" eject")

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def dead(self) -> bool:
        if (self.food < 0):
            print("dead")
            return True
        return False

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def take_object(self) -> None:
        print("take_object")

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def set_object(self) -> None:
        print("set_object")

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet ...
    ## @param self contient les valeurs du trantorian
    ## @return None
    def incantation(self) -> None:
        print("incantation")
