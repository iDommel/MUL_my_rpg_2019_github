/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

////////////////////////////////////////////////////////////////////////////////
//                              INCLUDES                                      //
////////////////////////////////////////////////////////////////////////////////

#include "../lib/my/my.h"
#include "../lib/lists/lists.h"

#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
//                               DEFINES                                      //
////////////////////////////////////////////////////////////////////////////////
#define SUCCESS_CODE 0
#define FAILURE_CODE 84

#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 1600
#define WINDOW_STYLE sfClose
#define WINDOW_TITLE "My RPG"
#define WINDOW_BYTES 64
#define FRAMERATE 60
#define MENU_BACKGROUND "ressources/menu/background.png"
#define MENU_MUSIC "ressources/music/menu_music.ogg"
#define MENU_ICON_WIDTH 200
#define MENU_ICON_HEIGHT 50
#define MENU_START_BUTTON "ressources/menu/start.png"
#define MENU_QUIT_BUTTON "ressources/menu/quit.png"

#define CLICK_SOUND "ressources/sound/button_click.ogg"
#define GAME_HEARTBEAT "ressources/music/heartbeat.ogg"
#define FIGHT_BACKGROUND "ressources/fight/fonp.png"
#define FIGHT_ATTACK_BUTTON "ressources/fight/fight.png"
#define PLAYER_SPRITE "ressources/player.png"
#define LIFE_BAR "ressources/fight/vie.png"

// per map time in seconds
#define TOTAL_TIME 360
#define FONT_STYLE_ONE "ressources/solvic_font.ttf"

#define MAP_WIDTH 40
#define MAP_HEIGHT 20
#define TILE_HEIGHT 40
#define TILE_WIDTH 40

#define SHOPS_NBR 3
#define BOSS_NBR 2
#define TRAPS_NBR 20
#define CHESTS_NBR 4

#define NB_SCENES 3
typedef enum scenes_index
{
    menu_scene,
    game_scene,
    fight_scene
} scenes_index_t;

#define MAX_SOUNDS_AT_ONCE 3
#define NB_EVT_FUNCTIONS 3

#define READ_SIZE 1

// PLAYER INFO

#define PLAYER_CURSOR_SPRITE "ressources/player/player_cursor1.png"

// test to remove function
list_data_t *init_fight_button(void);
////////////////////////////////////////////////////////////////////////////////
//                               FUNCTIONS                                    //
////////////////////////////////////////////////////////////////////////////////
int role_play_game(void);

////////////////////////
//   INITIALISATION   //
////////////////////////
list_t **init_scenes(void);
list_t *init_menu_scene(void);
list_t *init_game_scene(void);
list_t *init_fight_scene(list_t *game_scene);
void init_barlife_enemy(enemy_t *enemy);
void init_enemy(list_t *fight_scene);
void init_player(list_t *fight_scene, list_t *game_scene);
sfText *init_text(void);
my_clock_t *clock_create(void);
list_t *sound_buffers_create(void);
list_t *music_create(void);
list_t *empty_sounds_create(void);

void init_player_c(list_t *game_scene);
void init_buttons_game(list_t *game);
int initialize_map(list_t *go_list);
tile_map_t *create_map(char **map_str);
tile_t *convert_tile(sfVector2f *current_pos, char tile_type);
void fill_map(char **map);
void fill_tile_dimensions(sfIntRect *rect, sfVector2f *pos);
tile_t *create_tile(sfVector2f *pos, char *path);
tile_t **fill_tilemap(char **map_str, tile_map_t *dest);
void fill_with_map(char **map, int elem_nbr, char area, char id);
void reload_map(prog_stat_t *prog_stat, button_t *button, list_t *scene,
sfEvent *eve);
void load_next_level(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *go_list);
////////////////////////
//  EVENTS_HANDLING   //
////////////////////////
void analyse_events(prog_stat_t *, list_t *scene);
void button_clicked(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list);
void close_window(sfEvent *, prog_stat_t *, list_t *scene);
void start_game(prog_stat_t *, button_t *, list_t *scene, sfEvent *);
void quit_game(prog_stat_t *, button_t *, list_t *scene, sfEvent *);
void direction_pressed(sfEvent *event, prog_stat_t *prog_stat,
list_t *g_o_list);

////////////////////////
//     UPDATING       //
////////////////////////
void clock_set_speed(my_clock_t *clock, float speed);
float clock_get_speed(my_clock_t *clock);
void clock_pause(my_clock_t *clock);
void clock_unpause(my_clock_t *clock);
void update_player_cursor(prog_stat_t *prog_stat, struct player_cursor *player_c,
list_t *own_scene);
void manage_tilemap_actions(prog_stat_t *prog_stat, player_cursor_t *player_c,
list_t *go_list);
////////////////////////
//     RENDERING      //
////////////////////////
void render_button(prog_stat_t *prog_stat, button_t *button);
void render_background(prog_stat_t *prog_stat, backgr_t *backgr);
void render_tilemap(prog_stat_t *prog_stat, tile_map_t *tilemap);
void win_draw_time(prog_stat_t *prog_stat, my_clock_t *clock);
void render_enemy(prog_stat_t *prog_stat, enemy_t *enemy);
void render_player(prog_stat_t *prog_stat, player_t *player);

void render_player_cursor(prog_stat_t *prog_stat, struct player_cursor *player_c,
list_t *own_scene);
////////////////////////
//    DESTROYING      //
////////////////////////
void button_destroy(prog_stat_t *prog_stat, button_t *button);
void backgr_destroy(prog_stat_t *prog_stat, backgr_t *backgr);
void destroy_tilemap(prog_stat_t *prog_stat, tile_map_t *tilemap);
void clock_destroy(prog_stat_t *prog_stat, my_clock_t *clock);
void music_destroy(prog_stat_t *prog_stat, music_t *music);
void enemy_destroy(prog_stat_t *prog_stat, enemy_t *enemy);
void player_destroy(prog_stat_t *prog_stat, player_t *player);
void destroy_player_cursor(prog_stat_t *prog_stat,
struct player_cursor *player_c, list_t *own_scene);
////////////////////////
//      OTHERS        //
////////////////////////
sfInt64 clock_get_s(my_clock_t *clock);
sfInt64 clock_get_ms(my_clock_t *clock);
sfInt64 clock_get_mcs(my_clock_t *clock);
list_t * get_music_sound_cursor(list_t *root, audio_id_t id);
list_data_t *add_music_data(char *file, audio_id_t id);
list_t *get_next_sound_cell(list_t *sounds_list);
my_clock_t *get_my_clock(list_t *scene);
list_t *find_object(list_t *go_list, g_o_type_t type);

#endif /* !MY_RPG_H_ */