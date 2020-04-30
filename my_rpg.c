/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg
*/

#include "my_rpg.h"

list_t * get_music_sound_cursor(list_t *root, audio_id_t id)
{
    list_t *cursor = root->next;

    for (; cursor != root; cursor = cursor->next)
        if ((cursor->data != NULL) && (cursor->data->music->id == id))
            return (cursor);
    return (root);
}

static prog_stat_t *init_program_status(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BYTES};
    prog_stat_t *prog = malloc(sizeof(prog_stat_t));

    prog->window = sfRenderWindow_create(mode, WINDOW_TITLE, WINDOW_STYLE
    , NULL);
    prog->running = 1;
    prog->scene_index = menu_scene;
    prog->musics_sounds = malloc(sizeof(musics_and_sounds_t));
    prog->musics_sounds->musics_list = music_create();
    prog->musics_sounds->sounds_buffer_list = sound_buffers_create();
    prog->musics_sounds->sounds_list = empty_sounds_create();
    sfRenderWindow_setFramerateLimit(prog->window, FRAMERATE);
    sfMusic_play(get_music_sound_cursor(prog->musics_sounds->musics_list
    , menu_background_music)->data->music->music);
    return (prog);
}

void kill_stat(prog_stat_t *stat)
{
    for (list_t *cursor = stat->musics_sounds->musics_list->next;
        cursor != stat->musics_sounds->musics_list; cursor = cursor->next) {
            if (cursor->data->music->destroy != NULL)
                cursor->data->music->destroy(stat, cursor->data->music);
        }
    delete_list(stat->musics_sounds->musics_list);
    for (list_t *cursor = stat->musics_sounds->sounds_buffer_list->next;
        cursor != stat->musics_sounds->sounds_buffer_list
        ; cursor = cursor->next) {
            if (cursor->data->music->destroy != NULL)
                cursor->data->music->destroy(stat, cursor->data->music);
        }
    delete_list(stat->musics_sounds->sounds_buffer_list);
    for (list_t *cursor = stat->musics_sounds->sounds_list->next;
        cursor != stat->musics_sounds->sounds_list; cursor = cursor->next) {
            if (cursor->data->music->destroy != NULL)
                cursor->data->music->destroy(stat, cursor->data->music);
        }
    delete_list(stat->musics_sounds->sounds_list);
    free(stat->musics_sounds);
    free(stat);
}

static void update_scene(prog_stat_t *prog_stat, list_t *scene)
{
    list_t *cursor = scene->next;
    list_t *cursor_cop = scene;

    for (; cursor != scene; cursor = cursor->next,
    cursor_cop = cursor_cop->next) {
        if ((cursor->data != NULL)
        && (cursor->data->button->update != NULL)) {
            cursor->data->button->update(prog_stat, cursor->data->button
            , scene);
            if (cursor != cursor_cop->next)
                cursor = cursor_cop->next;
        }
    }
}

static void render_scene(prog_stat_t *prog_stat, list_t *scene)
{
    list_t *cursor = scene->next;

    sfRenderWindow_clear(prog_stat->window, sfBlack);
    for (; cursor != scene; cursor = cursor->next) {
        if (cursor->data->button->render != NULL)
            cursor->data->button->render(prog_stat, cursor->data->button);
    }
    sfRenderWindow_display(prog_stat->window);
}

static void cleaner(prog_stat_t *stat,
list_t **scene)
{
    for (int i = 0; i < NB_SCENES; i++)
        for (list_t *cursor = scene[i]->next;
        cursor != scene[i]; cursor = cursor->next) {
            if (cursor->data->button->destroy != NULL)
                cursor->data->button->destroy(stat, cursor->data->button);
        }
    for (int i = 0; i < NB_SCENES; i++)
        delete_list(scene[i]);
    sfRenderWindow_destroy(stat->window);
    kill_stat(stat);
    free(scene);
}

int role_play_game(void)
{
    list_t **scene = init_scenes();
    prog_stat_t *prog_stat = init_program_status();

    while (prog_stat->running && sfRenderWindow_isOpen(prog_stat->window)) {
        analyse_events(prog_stat, scene[prog_stat->scene_index]);
        update_scene(prog_stat, scene[prog_stat->scene_index]);
        render_scene(prog_stat, scene[prog_stat->scene_index]);
    }
    cleaner(prog_stat, scene);
    return (SUCCESS_CODE);
}