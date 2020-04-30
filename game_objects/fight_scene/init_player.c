/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_player
*/

#include "my_rpg.h"

void init_barlife_player(player_t *player)
{
    life_bar_t *life_bar = malloc(sizeof(life_bar_t));

    player->life_bar = life_bar;
    player->life_bar->pos.x = 100;
    player->life_bar->pos.y = 100;
    player->life_bar->rect.top = 0;
    player->life_bar->rect.left = 0;
    player->life_bar->rect.width = 300;
    player->life_bar->rect.height = 45;
    player->life_bar->textu = sfTexture_createFromFile(LIFE_BAR, NULL);
    player->life_bar->sprite = sfSprite_create();
    sfSprite_setTexture(player->life_bar->sprite, player->life_bar->textu
    , sfTrue);
    sfSprite_setPosition(player->life_bar->sprite, player->life_bar->pos);
}

void attack_animation(player_t *player)
{
    sfInt64 time = sfClock_getElapsedTime(player->clock).microseconds;
    float seconds = time / 1000000.0;

    if (seconds > 0.05)
        player->pos.x += 100;
    if (seconds > 0.1) {
        if (player->rect.left < (425 - 85)) {
            player->rect.left += 85;
        } else {
            player->rect.left = 0;
            player->animeted = 0;
            player->pos.x = 100;
        }
        sfClock_restart(player->clock);
    }
}

void update_player(prog_stat_t *prog_stat, player_t *player, list_t *scene)
{
    if (player && scene && prog_stat && player->life > 0)
        player->life_bar->rect.top = player->life *
        (player->life_bar->rect.height + 7);
    else
        player_destroy(prog_stat, player);
    if (player->animeted == 1)
        attack_animation(player);
}

static void init(player_t *player, list_t *game_scene)
{
    player_cursor_t *game_player = find_object(game_scene
    , player_cursor_type)->data->player_c;

    player->inventory = game_player->inventory;
    player->update = &update_player;
    player->destroy = &player_destroy;
    player->render = &render_player;
    player->textu = sfTexture_createFromFile(PLAYER_SPRITE, NULL);
}

void init_player(list_t *fight_scene, list_t *game_scene)
{
    player_t *player = malloc(sizeof(player_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    sfVector2f pos = {100, 675};

    init(player, game_scene);
    player->animeted = 0;
    player->rect = (sfIntRect){0, 0, 85, 85};
    player->life = 4;
    player->clock = sfClock_create();
    player->pos = pos;
    player->type = player_type;
    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, player->textu, sfTrue);
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setScale(player->sprite, (sfVector2f){3, 3});
    data->player = player;
    init_barlife_player(player);
    add_to_front(fight_scene, data);
}