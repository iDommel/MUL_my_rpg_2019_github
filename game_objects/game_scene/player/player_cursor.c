/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_cursor
*/

#include <stdlib.h>
#include "my_rpg.h"

static sfIntRect *fill_player_rect(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->height = TILE_HEIGHT;
    rect->width = TILE_WIDTH;
    rect->left = 0;
    rect->top = 0;
    return (rect);
}

player_cursor_t *create_player_cursor(sfVector2f spawnpos)
{
    player_cursor_t *player_c = malloc(sizeof(player_cursor_t));

    player_c->current_tile = NULL;
    player_c->type = player_cursor_type;
    player_c->pos.x = spawnpos.x;
    player_c->pos.y = spawnpos.y;
    player_c->sprite_pos = (sfVector2f){player_c->pos.x + (TILE_WIDTH / 2),
    player_c->pos.y + (TILE_HEIGHT / 2)};
    player_c->rect = fill_player_rect();
    player_c->texture = sfTexture_createFromFile(PLAYER_CURSOR_SPRITE, NULL);
    player_c->sprite = sfSprite_create();
    sfSprite_setScale(player_c->sprite, (sfVector2f){1, 1});
    sfSprite_setTexture(player_c->sprite, player_c->texture, sfTrue);
    sfSprite_setOrigin(player_c->sprite
    , (sfVector2f){TILE_WIDTH / 2, TILE_HEIGHT / 2});
    sfSprite_setPosition(player_c->sprite, player_c->pos);
    player_c->clock = sfClock_create();
    player_c->update = &update_player_cursor;
    player_c->render = &render_player_cursor;
    player_c->destroy = &destroy_player_cursor;
    return (player_c);
}

void init_player_c(list_t *game_scene)
{
    list_data_t *player_c_elem = malloc(sizeof(list_data_t));
    sfVector2f spawnpos = {-TILE_WIDTH, -TILE_HEIGHT};

    player_c_elem->player_c = create_player_cursor(spawnpos);
    add_to_queue(game_scene, player_c_elem);
}