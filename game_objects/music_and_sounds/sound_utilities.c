/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** sound_utilities
*/

#include "my_rpg.h"
#include <SFML/Audio.h>

list_t *get_next_sound_cell(list_t *sounds_list)
{
    static list_t *cursor = NULL;

    if (cursor == NULL)
        cursor = sounds_list->next;
    if (sounds_list == sounds_list->next) {
        my_printf("Error : pls, allow more sounds cells in my_rpg.h");
        return (NULL);
    }
    cursor = cursor->next;
    if (cursor->data == NULL)
        return (cursor->next);
    else
        return (cursor);
}

void sound_destroy(prog_stat_t *prog_stat, sound_t *sound)
{
    sfSound_pause(sound->sound);
    sfSound_destroy(sound->sound);
    if (prog_stat)
        free(sound);
}

list_data_t *add_empt_sound_data(void)
{
    list_data_t *empty_sound_data = malloc(sizeof(list_data_t));
    sound_t *sound = malloc(sizeof(sound_t));

    sound->type = sound_type;
    sound->update = NULL;
    sound->render = NULL;
    sound->destroy = &sound_destroy;
    sound->sound = sfSound_create();
    empty_sound_data->sound = sound;
    return (empty_sound_data);
}

list_t *empty_sounds_create(void)
{
    list_t *empty_sounds_list = create_list();

    for (int i = 0; i < MAX_SOUNDS_AT_ONCE; i++) {
        add_to_front(empty_sounds_list, add_empt_sound_data());
    }
    return (empty_sounds_list);
}

