/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** music_utilities
*/

#include "my_rpg.h"
#include <SFML/Audio.h>

list_data_t *add_music_data(char *file, audio_id_t id)
{
    list_data_t *music_data = malloc(sizeof(list_data_t));
    music_t *music = malloc(sizeof(music_t));

    music->type = music_list_type;
    music->running = 0;
    music->id = id;
    music->music = sfMusic_createFromFile(file);
    music->update = NULL;
    music->render = NULL;
    music->destroy = &music_destroy;
    sfMusic_setLoop(music->music, sfTrue);
    music_data->music = music;
    return (music_data);
}

void music_destroy(prog_stat_t *prog_stat, music_t *music)
{
    sfMusic_pause(music->music);
    sfMusic_destroy(music->music);
    if (prog_stat)
        free(music);
}

list_t *music_create(void)
{
    list_t *musics = create_list();

    add_to_front(musics, add_music_data(MENU_MUSIC, menu_background_music));
    return (musics);
}