/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** simple_render
*/

#include "my_rpg.h"

void render_button(prog_stat_t *prog_stat, button_t *button)
{
    sfRenderWindow_drawSprite(prog_stat->window, button->sprite, NULL);
}

void render_background(prog_stat_t *prog_stat, backgr_t *backgr)
{
    sfRenderWindow_drawSprite(prog_stat->window, backgr->sprite, NULL);
}