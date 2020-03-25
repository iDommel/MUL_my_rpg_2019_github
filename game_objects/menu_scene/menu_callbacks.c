/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_callbacks
*/

#include "my_rpg.h"

void quit_game(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    if (button || scene || eve)
        prog_stat->running = 0;
}

void start_game(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    if (button || scene || eve)
        prog_stat->scene_index = 1;
}