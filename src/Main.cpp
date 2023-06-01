/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
** File description:
** src/Main.cpp
*/

// @file Main.cpp

#include <iostream>

// @author Pierre-Louis
// @brief Print the message explaining how to use it
// @return always 1
int print_h(void)
{
    std::cout << "USAGE: ./zappy_ai -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
    return 1;
}

// @author Pierre-Louis
// @brief For launch Gui Zappy
// @param argc is the length of argv
// @param argv contain argument given by the user
// @return 0 in case of sucess
int main(int const ac, char * const * const av)
{
    return 0;
}
