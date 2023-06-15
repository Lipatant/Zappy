/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** generate_ressources
*/

#include "struct.h"

void init_density(density_t *den, args_t *args)
{
    den->nb_case = args->height * args->width;
    den->food_d = den->nb_case * 0.5;
    den->linemate_d = den->nb_case * 0.3;
    den->deraumere_d = den->nb_case * 0.15;
    den->sibur_d = den->nb_case * 0.1;
    den->mendiane_d = den->nb_case * 0.1;
    den->phiras_d = den->nb_case * 0.08;
    den->thystame_d = den->nb_case * 0.05;
}
