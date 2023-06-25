##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## ai/parser_look.py
##

## @file parser_look.py

import random

## @author Pierre-Louis
def search_stone(trant, functions, client) -> bool:
    stone_need = "linemate"
    getattr(trant, functions[8])() #look
    client.check_client()
    look = client.data

    if stone_need in look:
        stone_case = look[:look.index(stone_need)].count(",")
        go_to_stone(trant, functions, client, stone_need, stone_case)
        return (True)
    else:
        random_move(trant, functions, client)
        return (False)

## @author Pierre-Louis
def go_to_stone(trant, functions, client, stone_need, stone_case) -> None:
    bot_case = 0
    counter = 0
    tab_max_case = [0, 3, 8, 15]
    tab_mid_case = [2, 6, 12, 20]

    if (bot_case != stone_case):
        for i in tab_max_case:
            if (stone_case > i):
                bot_case = tab_mid_case[counter]
                getattr(trant, functions[4])() #forward
                client.check_client()
            counter += 1

        if (bot_case != stone_case):
            if (bot_case > stone_case):
                getattr(trant, functions[7])() #left
                client.check_client()
            else:
                getattr(trant, functions[9])() #right
                client.check_client()

            while (bot_case != stone_case):
                if (bot_case > stone_case):
                    bot_case -= 1
                else:
                    bot_case += 1
                getattr(trant, functions[4])() #forward
                client.check_client()

## @author Pierre-Louis
def random_move(trant, functions, client) -> None:
    rdm = random.randint(0,1)

    getattr(trant, functions[4])() #forward
    client.check_client()

    if rdm == 0:
        getattr(trant, functions[9])() #left
        client.check_client()
    elif rdm == 1:
        getattr(trant, functions[7])() #right
        client.check_client()
