##
## EPITECH PROJECT, 2022
## AI
## File description:
## Arguments.py
##

class Arguments:
    port: int
    name: str
    machine: str = "127.0.0.1"

def parse_args(argc: int, argv: list[str]):
    args = Arguments.Arguments()
    for i in range(1, argc, 2):
        if argv[i] == "-p":
            args.port = int(argv[i + 1])
        elif argv[i] == "-n":
            args.name = argv[i + 1]
        elif argv[i] == "-h":
            args.machine = argv[i + 1]
        else:
            print(f"error: invalid parser parameter: {argv[i]}")
            exit(84)
    if args.port == 0 or args.name == "" or args.machine == "":
        print("Error: invalid parser")
        exit(84)
    return args
