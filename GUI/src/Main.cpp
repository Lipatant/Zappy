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
    Citadel::Instance citadel(engine);

    citadel << "pnw 1 0 0 3 0 0\n";
    citadel << "pnw 2 1 0 2 0 0\n";
    citadel << "ppo 2 2 2 1\n";
    while (engine.udpate());
    return 0;
}
