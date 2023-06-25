##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## ai/arguments/arguments.py
##

## @file arguments.py

from ai.error import print_error_exit

## @author Damien and Pierre-Louis
## @brief Contains server variables and the function to parse arguments of argv
class Arguments:
    port: int
    team: str
    ip: str

    ## @author Damien
    ## @brief Initiates variables server
    ## @param self will contain the machine's port, name and machine address
    ## @return None
    def __init__(self) -> None:
        self.port = 0
        self.team = ""
        self.ip = "127.0.0.1"

    ## @author Damien and Pierre-Louis
    ## @brief Parsing argv's argument
    ## @param self contain the machine's port, name and machine address
    ## @param argc is the length of argv
    ## @param argv contain argument given by the user
    ## @return None
    def parse_args(self, argc: int, argv: list[str]) -> None:
        ## @details (start, fin, acrementation)
        for i in range(0, argc, 2):
            if argv[i] == "-p":
                try:
                    self.port = int(argv[i + 1])
                except:
                    print_error_exit("Invalid argument for port" + argv[i + 1])
            elif argv[i] == "-n":
                self.team = argv[i + 1]
            elif argv[i] == "-h":
                self.ip = argv[i + 1]
            else:
                print_error_exit(f"Error: invalid parser parameter: {argv[i]}")
        if self.port == 0 or self.team == "" or self.ip == "":
            print_error_exit("Error: invalid parser")
