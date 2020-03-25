/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_destroy
*/

#include "my_rpg.h"

void button_destroy(prog_stat_t *prog_stat, button_t *button)
{
    sfTexture_destroy(button->textu);
    sfSprite_destroy(button->sprite);
    if (prog_stat || !prog_stat)
        free(button);
}

void backgr_destroy(prog_stat_t *prog_stat, backgr_t *backgr)
{
    sfTexture_destroy(backgr->textu);
    sfSprite_destroy(backgr->sprite);
    if (prog_stat || !prog_stat)
        free(backgr);
}