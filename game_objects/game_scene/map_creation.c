/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_creation
*/

#include "my_rpg.h"
#include "./generator/generator.h"

void render_tilemap(prog_stat_t *prog_stat, tile_map_t *tilemap)
{
    tile_t *cursor = NULL;

    for (int i = 0; i < tilemap->map_height; i++) {
        for (int j = 0; j < tilemap->map_width; j++) {
            cursor = &(tilemap->tiles[i][j]);
            if (cursor)
                sfRenderWindow_drawSprite(prog_stat->window, cursor->sprite
                , NULL);
        }
    }
}

                /* my_printf("x = %d\ty = %d\n", j, i); */
                /* free(cursor); */

void destroy_tilemap(prog_stat_t *prog_stat, tile_map_t *tilemap)
{
    tile_t *cursor = NULL;

    for (int i = 0; i < tilemap->map_height; i++) {
        for (int j = 0; j < tilemap->map_width; j++) {
            cursor = &(tilemap->tiles[i][j]);
            if (cursor && prog_stat) {
                sfTexture_destroy(cursor->texture);
                sfSprite_destroy(cursor->sprite);
            }
        }
    }
    free(tilemap->tiles);
    free_my_str_arr(tilemap->map);
    free(tilemap);
}

tile_map_t *create_map(char **map_str)
{
    tile_map_t *tile_map = malloc(sizeof(tile_map_t));

    tile_map->type = tile_map_type;
    tile_map->map_height = MAP_HEIGHT;
    tile_map->map_width = MAP_WIDTH;
    tile_map->map = map_str;
    tile_map->tiles = fill_tilemap(tile_map->map, tile_map);
    tile_map->update = NULL;
    tile_map->render = &render_tilemap;
    tile_map->destroy = &destroy_tilemap;
    return (tile_map);
}