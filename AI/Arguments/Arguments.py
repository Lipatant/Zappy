##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Arguments/Arguments.py
##

## @file Arguments.py

## @author Damien BENAIS-CAPTAL and Pierre-Louis LEROY
## @brief La classe "Arguments" permet de stocker les arguments donné par le serveur + fonctions
class Arguments:
    port: int
    name: str
    machine: str

    ## @author Damien BENAIS-CAPTAL
    ## @brief Cette fonction permet d'initier la variable self
    ## @param self stock le port, le name et la machine donné par le serveur
    ## @return None
    def __init__(self) -> None:
        self.port = 0
        self.name = ""
        self.machine = "127.0.0.1"

    ## @author Damien BENAIS-CAPTAL and Pierre-Louis LEROY
    ## @brief Cette fonction permet de parser les arguments
    ## @param self permet de stocker les infos du serveur
    ## @param argc est la taille de argv
    ## @param argv contient une list de str
    ## @return None
    def parse_args(self, argc: int, argv: list[str]) -> None:
        ## @detail (start, fin, acrémentation)
        for i in range(0, argc, 2):
            if argv[i] == "-p":
                self.port = int(argv[i])
            elif argv[i] == "-n":
                self.name = argv[i]
            elif argv[i] == "-h":
                self.machine = argv[i]
            else:
                print(f"error: invalid parser parameter: {argv[i]}")
                exit(84)
        if self.port == 0 or self.name == "" or self.machine == "":
            print("Error: invalid parser")
            exit(84)
