/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_scene_init
*/

#include "my_rpg.h"

static list_data_t *init_quit_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2)) / 2;
    button->pos.y = ((WINDOW_HEIGHT / 6) * 4) - (MENU_ICON_HEIGHT / 2);
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &quit_game;
    button->textu = sfTexture_createFromFile(MENU_QUIT_BUTTON, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}

static list_data_t *init_start_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    button->pos.x = ((WINDOW_WIDTH / 2) - (MENU_ICON_WIDTH / 2)) / 2;
    button->pos.y = ((WINDOW_HEIGHT / 6) * 2) - (MENU_ICON_HEIGHT / 2);
    button->update = NULL;
    button->destroy = &button_destroy;
    button->render = &render_button;
    button->onclick = &start_game;
    button->textu = sfTexture_createFromFile(MENU_START_BUTTON, NULL);
    button->type = button_type;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->textu, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    data->button = button;
    return (data);
}

static void init_menu_buttons(list_t *menu_scene)
{
    add_to_front(menu_scene, init_start_button());
    add_to_front(menu_scene, init_quit_button());
}

static void init_menu_background(list_t *menu_scene)
{
    backgr_t *backgr = malloc(sizeof(backgr_t));
    list_data_t *data = malloc(sizeof(list_data_t));

    backgr->pos.x = 0;
    backgr->pos.y = 0;
    backgr->textu =
    sfTexture_createFromFile(MENU_BACKGROUND, NULL);
    backgr->type = background_type;
    backgr->sprite = sfSprite_create();
    sfSprite_setTexture(backgr->sprite, backgr->textu, sfTrue);
    sfSprite_setPosition(backgr->sprite, backgr->pos);
    backgr->destroy = &backgr_destroy;
    backgr->render = &render_background;
    backgr->update = NULL;
    data->background = backgr;
    add_to_front(menu_scene, data);
}

list_t *init_menu_scene(void)
{
    list_t *menu_scene = create_list();

    init_menu_buttons(menu_scene);
    init_menu_background(menu_scene);
    return (menu_scene);
}