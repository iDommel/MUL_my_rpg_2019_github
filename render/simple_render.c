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

void render_enemy(prog_stat_t *prog_stat, enemy_t *enemy)
{
    sfSprite_setTextureRect(enemy->life_bar->sprite, enemy->life_bar->rect);
    sfRenderWindow_drawSprite(prog_stat->window, enemy->life_bar->sprite, NULL);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfRenderWindow_drawSprite(prog_stat->window, enemy->sprite, NULL);
}

void render_player(prog_stat_t *prog_stat, player_t *player)
{
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setTextureRect(player->life_bar->sprite, player->life_bar->rect);
    sfRenderWindow_drawSprite(prog_stat->window, player->life_bar->sprite
    , NULL);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfRenderWindow_drawSprite(prog_stat->window, player->sprite, NULL);
}