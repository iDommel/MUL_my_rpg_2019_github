/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tile_map_prepare
*/

#include "my_rpg.h"
#include "./generator/generator.h"

void fill_tile_dimensions(sfIntRect *rect, sfVector2f *pos)
{
    rect->left = pos->x;
    rect->top = pos->y;
    rect->width = TILE_WIDTH;
    rect->height = TILE_HEIGHT;
}

tile_t *create_tile(sfVector2f *pos, char *path)
{
    tile_t *this_tile = malloc(sizeof(tile_t));
    sfVector2f scale = {(float)TILE_WIDTH / 100 , (float)TILE_HEIGHT / 100};

    if (!this_tile)
        return (NULL);
    this_tile->texture = sfTexture_createFromFile(path, NULL);
    this_tile->sprite = sfSprite_create();
    fill_tile_dimensions(&(this_tile->rect), pos);
    this_tile->pos.x = pos->x;
    this_tile->pos.y = pos->y;
    sfSprite_scale(this_tile->sprite, scale);
    sfSprite_setTexture(this_tile->sprite, this_tile->texture, sfTrue);
    sfSprite_setPosition(this_tile->sprite, this_tile->pos);
    return (this_tile);
}

tile_t **fill_tilemap(char **map_str, tile_map_t *dest)
{
    tile_t **tilemap;
    sfVector2f current_pos = {0, 0};

    tilemap = malloc(sizeof(tile_t *) * dest->map_height);
    for (int i = 0; map_str[i] && i < dest->map_height; i++) {
        current_pos.y = (i * TILE_HEIGHT);
        current_pos.x = 0;
        tilemap[i] = malloc(sizeof(tile_t) * (dest->map_width));
        for (int j = 0; map_str[i][j] && j < dest->map_width; j++) {
            current_pos.x = (j) * TILE_WIDTH;
            tilemap[i][j] = *convert_tile(&current_pos
            , map_str[i][j]);
        }
    }
    return (tilemap);
}

void fill_with_map(char **map, int elem_nbr, char area, char id)
{
    int x = rand() % MAP_WIDTH;
    int y = rand() % MAP_HEIGHT;

    if ((map[y][x] == area) && (area != 'X')) {
        map[y][x] = id;
        elem_nbr--;
    }
    if ((map[y][x] == area) && (area == 'X')
    && (((y > 0) && (map[y - 1][x] == '*'))
    || ((x > 0) && (map[y][x - 1] == '*'))
    || (map[y + 1] && (map[y + 1][x] == '*')) || (map[y][x + 1] == '*'))) {
        map[y][x] = id;
        elem_nbr--;
    }
    if (elem_nbr > 0)
        fill_with_map(map, elem_nbr, area, id);
}