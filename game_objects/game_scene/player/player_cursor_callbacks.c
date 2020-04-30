/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_cursor_callbacks
*/

#include <stdlib.h>
#include "my_rpg.h"

static void animate_player_c(player_cursor_t *player_c)
{
    int seconds =
    sfClock_getElapsedTime(player_c->clock).microseconds * 1000000;

    if (seconds > 1) {
        if (player_c->rect->left < (TILE_WIDTH * 2))
            player_c->rect->left += TILE_WIDTH;
        else
            player_c->rect->left = 0;
        sfClock_restart(player_c->clock);
    }
    sfSprite_setTextureRect(player_c->sprite, *(player_c->rect));
}

void update_player_cursor(prog_stat_t *prog_stat
, struct player_cursor *player_c, list_t *own_scene)
{
    if (own_scene && prog_stat)
        player_c->sprite_pos.x = player_c->pos.x + (TILE_WIDTH / 2);
    player_c->sprite_pos.y = player_c->pos.y + (TILE_HEIGHT / 2);
    sfSprite_setPosition(player_c->sprite, player_c->sprite_pos);
    manage_tilemap_actions(prog_stat, player_c, own_scene);
}

void render_player_cursor(prog_stat_t *prog_stat
, struct player_cursor *player_c, list_t *own_scene)
{
    if (own_scene)
        sfRenderWindow_drawSprite(prog_stat->window, player_c->sprite, NULL);
}

void destroy_player_cursor(prog_stat_t *prog_stat
, struct player_cursor *player_c, list_t *own_scene)
{
    if (prog_stat && own_scene)
        sfTexture_destroy(player_c->texture);
    sfSprite_destroy(player_c->sprite);
    sfClock_destroy(player_c->clock);
    free(player_c->rect);
    free(player_c);
    player_c = NULL;
}