##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Arguments/Arguments.py
##

## @file Arguments.py

## @author Damien and Pierre-Louis
## @brief Contains server variables and the function to parse arguments of argv
class Arguments:
    port: int
    name: str
    machine: str

    ## @author Damien
    ## @brief Initiates variables server
    ## @param self will contain the machine's port, name and machine address
    ## @return None
    def __init__(self) -> None:
        self.port = 0
        self.name = ""
        self.machine = "127.0.0.1"

    ## @author Damien and Pierre-Louis
    ## @brief Parsing argv's argument
    ## @param self contain the machine's port, name and machine address
    ## @param argc is the length of argv
    ## @param argv contain argument given by the user
    ## @return None
    def parse_args(self, argc: int, argv: list[str]) -> None:
        ## @detail (start, fin, acrementation)
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
