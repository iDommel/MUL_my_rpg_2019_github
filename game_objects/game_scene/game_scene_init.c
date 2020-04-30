/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_scene_init
*/

#include "my_rpg.h"
#include <time.h>
#include <math.h>

void heartbeat_update(prog_stat_t *prog_stat, music_t *music,
list_t *own_scene)
{
    float percent = 0;

    if (own_scene && prog_stat->scene_index == game_scene
    && music->running == 0) {
        sfMusic_play(music->music);
        music->running = 1;
    }
    if (music->running == 1) {
        percent = (clock_get_s(get_my_clock(own_scene)) * 100) / TOTAL_TIME;
        sfMusic_setVolume(music->music, exp(percent * log(1.055)));
    }
}

void init_heartbeat(list_t *game)
{
    add_to_front(game, add_music_data(GAME_HEARTBEAT, heartbeat));
    game->next->data->music->update = &heartbeat_update;
}

list_t *init_game_scene(void)
{
    list_t *game = create_list();

    srand(time(NULL));
    init_player_c(game);
    init_buttons_game(game);
    init_heartbeat(game);
    return (game);
}