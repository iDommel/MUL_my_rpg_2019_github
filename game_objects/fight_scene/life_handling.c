/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** life_handling
*/

#include <stdlib.h>
#include "my_rpg.h"

void render_lifebar(prog_stat_t *prog_stat, button_t *button)
{
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfRenderWindow_drawSprite(prog_stat->window, button->sprite, NULL);
}

void init_barlife_enemy(enemy_t *enemy)
{
    life_bar_t *life_bar = malloc(sizeof(life_bar_t));

    enemy->life_bar = life_bar;
    enemy->life_bar->pos.x = 1200;
    enemy->life_bar->pos.y = 100;
    enemy->life_bar->rect.top = 0;
    enemy->life_bar->rect.left = 0;
    enemy->life_bar->rect.width = 300;
    enemy->life_bar->rect.height = 45;
    enemy->life_bar->textu = sfTexture_createFromFile(LIFE_BAR, NULL);
    enemy->life_bar->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->life_bar->sprite, enemy->life_bar->textu
    , sfTrue);
    sfSprite_setPosition(enemy->life_bar->sprite, enemy->life_bar->pos);
}

/* list_data_t *init_barlife(list_t *fight_scene)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.y = 100;
    button->rect.top = 0;
    button->rect.left = 0;
    button->rect.width = 300;
    button->rect.height = 45;
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_lifebar;
    button->textu = sfTexture_createFromFile(LIFE_BAR, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    add_to_front(fight_scene, data);
    return (data);
} */
