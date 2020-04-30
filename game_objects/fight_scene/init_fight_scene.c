/*
** EPITECH PROJECT, 2020
** init_fight_scene.c
** File description:
** init_fight_scene
*/

#include <stdlib.h>
#include "my_rpg.h"

void attack_attack(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    list_t *player = find_object(scene, player_type);
    list_t *enemy = find_object(scene, enemy_type);

    if (player && enemy && prog_stat && button && scene && eve) {
        if (player->data->player->animeted == 0) {
            player->data->player->animeted = 1;
            enemy->data->enemy->life--;
        }
    }
}

static void init_attack_button(list_t *fight_scene)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    sfIntRect rect = {0, 0, 181 * (0.75), 181 * (0.75)};

    button->rect = rect;
    button->pos.x = 350;
    button->pos.y = 700;
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &attack_attack;
    button->textu = sfTexture_createFromFile(FIGHT_ATTACK_BUTTON, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setScale(button->sprite, (sfVector2f){0.75, 0.75});
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    add_to_front(fight_scene, data);
}

static void init_fight_background(list_t *fight_scene)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 0;
    backgr->pos.y = 0;
    backgr->textu = sfTexture_createFromFile(FIGHT_BACKGROUND, NULL);
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setTexture(backgr->sprite, backgr->textu, sfTrue);
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    backgr->destroy = &backgr_destroy;
    backgr->render = &render_background;
    backgr->update = NULL;
    data->background = backgr;
    add_to_front(fight_scene, data);
}

list_t *init_fight_scene(list_t *game_scene)
{
    list_t *fight_scene = create_list();

    init_player(fight_scene, game_scene);
    init_enemy(fight_scene);
    init_attack_button(fight_scene);
    init_fight_background(fight_scene);
    return (fight_scene);
}