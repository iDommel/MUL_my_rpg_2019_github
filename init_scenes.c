/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_scenes
*/

#include "my_rpg.h"

list_t **init_scenes(void)
{
    list_t **scenes_list = malloc(sizeof(list_t *) * NB_SCENES);

    scenes_list[0] = init_menu_scene();
    scenes_list[1] = init_game_scene();
    return (scenes_list);
}