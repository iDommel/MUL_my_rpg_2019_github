/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_scenes
*/

#include "my_rpg.h"

sfText *init_text(void)
{
    sfText *text = sfText_create();
    static sfFont *font = NULL;
    static sfVector2f pos = {100, WINDOW_HEIGHT - 100};

    if (font == NULL)
        font = sfFont_createFromFile(FONT_STYLE_ONE);
    sfText_setColor(text, sfWhite);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
    return (text);
}

list_t **init_scenes(void)
{
    list_t **scenes_list = malloc(sizeof(list_t *) * NB_SCENES);

    scenes_list[menu_scene] = init_menu_scene();
    scenes_list[game_scene] = init_game_scene();
    scenes_list[fight_scene] = init_fight_scene(scenes_list[game_scene]);
    return (scenes_list);
}