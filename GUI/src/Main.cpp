/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** src/Main.cpp
*/

#include "Flags.hpp"
#include "Citadel/Instance.hpp"
#include "Mortymere/Instance.hpp"

int main(FLAG_UNUSED int const ac, FLAG_UNUSED char const * const * const av)
{
    Mortymere::Instance engine;
    Citadel::Instance citadel;

    while (engine.udpate());
    return 0;
}
