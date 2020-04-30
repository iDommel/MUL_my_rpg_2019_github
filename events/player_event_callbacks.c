/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_envet_callbacks
*/

#include "my_rpg.h"


static int move_player_c(int x, int y, list_t *g_o_list)
{
    char **map = find_object(g_o_list, tile_map_type)->data->tile_map->map;
    player_cursor_t *player = find_object(g_o_list,
    player_cursor_type)->data->player_c;
    sfVector2i current_pos;

    current_pos.x = (int)player->pos.x / TILE_WIDTH;
    current_pos.y = (int)player->pos.y / TILE_HEIGHT;
    if ((current_pos.x + x) >= MAP_WIDTH || (current_pos.y + y) >= MAP_HEIGHT
    || (current_pos.x + x) < 0 || (current_pos.y + y) < 0)
        return (FAILURE_CODE);
    if (map[current_pos.y + y][current_pos.x + x] != 'X') {
        player->pos.x += x * TILE_WIDTH;
        player->pos.y += y * TILE_HEIGHT;
        player->current_tile = &(map[current_pos.y + y][current_pos.x + x]);
        if (x == 0)
            sfSprite_setRotation(player->sprite, (y == 1 ? 0 : 180));
        else if (y == 0)
            sfSprite_setRotation(player->sprite, (x == 1 ? -90 : 90));
    }
    return (SUCCESS_CODE);
}

void direction_pressed(sfEvent *event, prog_stat_t *prog_stat,
list_t *g_o_list)
{
    if (prog_stat->scene_index == game_scene) {
        switch (event->key.code)
        {
        case sfKeyLeft:
            move_player_c(-1, 0, g_o_list);
            break;
        case sfKeyRight:
            move_player_c(1, 0, g_o_list);
            break;
        case sfKeyUp:
            move_player_c(0, -1, g_o_list);
            break;
        case sfKeyDown:
            move_player_c(0, 1, g_o_list);
            break;
        default:
            if (prog_stat)
                break;
        }
    }
}