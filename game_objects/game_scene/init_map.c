/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_map
*/

#include "my_rpg.h"
#include "./generator/generator.h"

// #if_forest ...

tile_t *convert_tile(sfVector2f *current_pos, char tile_type)
{
    if (tile_type == ('U'))
        return (create_tile(current_pos, "ressources/tilemap/upstairs.png"));
    if (tile_type == ('D'))
        return (create_tile(current_pos, "ressources/tilemap/downstairs.png"));
    if (tile_type == ('X'))
        return (create_tile(current_pos, "ressources/tilemap/wall.png"));
    if (tile_type == ('*'))
        return (create_tile(current_pos, "ressources/tilemap/path.png"));
    if (tile_type == ('S'))
        return (create_tile(current_pos, "ressources/tilemap/shop.png"));
    if (tile_type == ('B'))
        return (create_tile(current_pos, "ressources/tilemap/boss.png"));
    if (tile_type == ('T'))
        return (create_tile(current_pos, "ressources/tilemap/trap.png"));
    if (tile_type == ('C'))
        return (create_tile(current_pos, "ressources/tilemap/chest.png"));
    return (NULL);
}

// always fill wall events before path !"events"!

void fill_map(char **map)
{
    fill_with_map(map, 1, '*', 'U');
    fill_with_map(map, 1, '*', 'D');
    fill_with_map(map, SHOPS_NBR, 'X', 'S');
    fill_with_map(map, BOSS_NBR, 'X', 'B');
    fill_with_map(map, TRAPS_NBR, '*', 'T');
    fill_with_map(map, CHESTS_NBR, '*', 'C');
}

/* load_screen(); */
static void find_spawnpos(list_t *scene, char **map)
{
    list_t *cursor = find_object(scene, player_cursor_type);

    for (int i = 0; cursor && map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == 'U') {
                cursor->data->player_c->pos.x = j * TILE_WIDTH;
                cursor->data->player_c->pos.y = i * TILE_HEIGHT;
            }
        }
    }
}

int initialize_map(list_t *go_list)
{
    tile_map_t *tile_map;
    list_data_t *map_object = malloc(sizeof(list_data_t));
    char **map_str = create_perfect_maze(init_tab_with(MAP_WIDTH
    , MAP_HEIGHT, 'X'), 1);

    if (!map_str)
        return (84);
    fill_map(map_str);
    tile_map = create_map(map_str);
    if (!tile_map)
        return (84);
    map_object->tile_map = tile_map;
    find_spawnpos(go_list, map_str);
    add_to_front(go_list, map_object);
    return (0);
}