##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Trantorians/Trantorians.py
##

# 0=up | 1=right | 2=down | 3=left

class Trantorians:
    def __init__(self) -> None:
        self.direction = 0
        self.food = 126
        self.found = []
        self.inventory = {}
        self.fov = 1
        self.sound = 0

    def forward(self) -> None:
        print("forward")

    def left(self) -> None:
        self.direction -= 1
        if self.direction < 0:
            self.direction = 3

    def right(self) -> None:
        self.direction += 1
        if self.direction > 3:
            self.direction = 0

    def look(self) -> None:
        print(f"look for {self.fov} squares")

    def inventory(self) -> None:
        print(self.inventory)

    def broadcast_text(self, text) -> None:
        print(text)

    def connect_nbr(self) -> None:
        print("slot")

    def fork(self) -> None:
        print("fork")

    def eject(self) -> None:
        print(" eject")

    def dead(self) -> bool:
        if (self.food < 0):
            print("dead")
            return True
        return False

    def take_object(self) -> None:
        print("take_object")

    def set_object(self) -> None:
        print("set_object")

    def incantation(self) -> None:
        print("incantation")
