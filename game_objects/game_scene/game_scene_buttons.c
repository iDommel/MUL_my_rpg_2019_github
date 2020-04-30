/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_scene_buttons
*/

#include "my_rpg.h"

void reload_map(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve)
{
    list_data_t *data = malloc(sizeof(list_data_t));
    list_t *cursor = NULL;

    cursor = find_object(scene, tile_map_type);
    if (cursor && cursor->data->tile_map->destroy) {
        cursor->data->tile_map->destroy(prog_stat, cursor->data->tile_map);
        rm_elem(cursor);
    }
    cursor = find_object(scene, clock_type);
    if (cursor && cursor->data->clock->destroy) {
        cursor->data->clock->destroy(prog_stat, cursor->data->clock);
        rm_elem(cursor);
    }
    if (button || eve) {
        initialize_map(scene);
    }
    data->clock = clock_create();
    add_to_queue(scene, data);
}

list_data_t *init_reload_map_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));
    sfIntRect rect = {0, 0, MENU_ICON_WIDTH, MENU_ICON_HEIGHT};

    button->rect = rect;
    button->pos.x = (WINDOW_WIDTH - MENU_ICON_WIDTH);
    button->pos.y = (WINDOW_HEIGHT - MENU_ICON_HEIGHT);
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &reload_map;
    button->textu = sfTexture_createFromFile(MENU_START_BUTTON, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}

void init_buttons_game(list_t *game)
{
    add_to_front(game, init_reload_map_button());
}