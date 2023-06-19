##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## ai/parser_look.py
##

## @file parser_look.py

import random

# return (42) == For break while

## @author Pierre-Louis
def algo_search_stone(trant, functions, client):
    # defines the stone we're looking for
    stone_need = "linemate"

    getattr(trant, functions[8])() #look
    if (client.data == "dead\n"):
        return (42)

    # Send look and stone for parsing
    result = parser_look(client.data, stone_need)


    # if Stone isn't in look, move random
    if (result == "ABSENT"):
        getattr(trant, functions[4])() #forward
        if (client.data == "dead\n"):
            return (42)

        rdm = random.randint(0,3)

        if rdm == 0:
            getattr(trant, functions[9])() #left
            if (client.data == "dead\n"):
                return (42)
        elif rdm == 1:
            getattr(trant, functions[7])() #right
            if (client.data == "dead\n"):
                return (42)

    else: # STONE IN LOOK
        return (go_to_stone(trant, functions, client, stone_need, result))

## @author Pierre-Louis
def parser_look(look, stone_need):
    if look.startswith("[ player,"):
        print("""ONLY PLAYER ONLY PLAYER ONLY PLAYER
ONLY PLAYER ONLY PLAYER ONLY PLAYER""")
    if stone_need in look:
        stone_case = look[:look.index(stone_need)].count(",")
        print(f"PRESENT")
        return (stone_case)
    else:
        print("ABSENT")
        return ("ABSENT")

## @author Pierre-Louis
def go_to_stone(trant, functions, client, stone_need, stone_case):
    bot_case = 0
    counter = 0
    tab_max_case = [0, 3, 8, 15]
    tab_mid_case = [2, 6, 12, 20]

    for i in tab_max_case:
        if (stone_case > i):
            bot_case = tab_mid_case[counter]
            getattr(trant, functions[4])() #forward
            if (client.data == "dead\n"):
                return (42)
        counter += 1

    if (bot_case == stone_case):
        getattr(trant, functions[11])(stone_need) #take
        if (client.data == "dead\n"):
            return (42)
    else:
        if (bot_case > stone_case):
            getattr(trant, functions[7])() #left
            if (client.data == "dead\n"):
                return (42)
        else:
            getattr(trant, functions[9])() #right
            if (client.data == "dead\n"):
                return (42)

        while (bot_case != stone_case):
            if (bot_case > stone_case):
                bot_case -= 1
            else:
                bot_case += 1
            getattr(trant, functions[4])() #forward
            if (client.data == "dead\n"):
                return (42)

        getattr(trant, functions[11])(stone_need) #take
        if (client.data == "dead\n"):
            return (42)
        return (0)

'''
0 Broadcast "Text"
1 Connect_nbr
2 Eject
3 Fork
4 Forward
5 Incantation
6 Inventory
7 Left
8 Look
9 Right
10 Set "Text"
11 Take "Text"
'''
