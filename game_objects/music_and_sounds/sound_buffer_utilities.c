/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** sound_buffer_utlities
*/

#include "my_rpg.h"
#include <SFML/Audio.h>

void buffer_destroy(prog_stat_t *prog_stat, sound_buffer_t *buffer)
{
    sfSoundBuffer_destroy(buffer->buffer);
    if (prog_stat)
        free(buffer);
}

list_data_t *add_sound_data(char *file, audio_id_t id)
{
    list_data_t *buffer_data = malloc(sizeof(list_data_t));
    sound_buffer_t *buffer = malloc(sizeof(sound_buffer_t));

    buffer->type = sound_buffers_type;
    buffer->id = id;
    buffer->buffer = sfSoundBuffer_createFromFile(file);
    buffer->update = NULL;
    buffer->render = NULL;
    buffer->destroy = &buffer_destroy;
    buffer_data->buffer = buffer;
    return (buffer_data);
}

list_t *sound_buffers_create(void)
{
    list_t *sound_buffers_list = create_list();

    add_to_front(sound_buffers_list, add_sound_data(CLICK_SOUND, button_click));
    return (sound_buffers_list);
}