/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_enemy
*/

#include <stdlib.h>
#include "my_rpg.h"

void update_enemy(prog_stat_t *prog_stat, enemy_t *enemy, list_t *scene)
{
    sfInt64 time = sfClock_getElapsedTime(enemy->clock).microseconds;
    float seconds = time / 1000000.0;
    list_t *to_kill = find_object(scene, enemy_type);

    if (seconds > 1) {
        if (enemy->rect.left < (948 - 237))
            enemy->rect.left += 237;
        else
            enemy->rect.left = 0;
        sfClock_restart(enemy->clock);
    }
    if (enemy && scene && prog_stat && enemy->life > 0)
        enemy->life_bar->rect.top = enemy->life *
        (enemy->life_bar->rect.height + 7);
    else {
        enemy_destroy(prog_stat, enemy);
        rm_elem(to_kill);
    }
}

static void init(enemy_t *enemy)
{
    enemy->update = &update_enemy;
    enemy->destroy = &enemy_destroy;
    enemy->render = &render_enemy;
}

void init_enemy(list_t *fight_scene)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    sfVector2f pos = {700, 300};

    init(enemy);
    enemy->rect = (sfIntRect){0, 0, 237, 180};
    enemy->life = 4;
    enemy->clock = sfClock_create();
    enemy->pos = pos;
    enemy->textu =
    sfTexture_createFromFile("ressources/fight/dragonfire.png", NULL);
    enemy->type = enemy_type;
    enemy->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->sprite, enemy->textu, sfTrue);
    sfSprite_setPosition(enemy->sprite, enemy->pos);
    sfSprite_setScale(enemy->sprite, (sfVector2f){4, 4});
    data->enemy = enemy;
    init_barlife_enemy(enemy);
    add_to_front(fight_scene, data);
}