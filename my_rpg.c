/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg
*/

#include "my_rpg.h"

static prog_stat_t *init_program_status(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BYTES};
    prog_stat_t *prog = malloc(sizeof(prog_stat_t));

    prog->window = sfRenderWindow_create(mode, WINDOW_TITLE, WINDOW_STYLE
    , NULL);
    prog->running = 1;
    prog->scene_index = 0;
    sfRenderWindow_setFramerateLimit(prog->window, FRAMERATE);
    return (prog);
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
    free(stat);
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