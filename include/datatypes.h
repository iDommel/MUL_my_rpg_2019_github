/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** datatypes
*/

#ifndef DATATYPES_H_
#define DATATYPES_H_

////////////////////////////////////////////////////////////////////////////////
//                              Previous Declarations                         //
////////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
typedef struct list list_t;
typedef struct musics_and_sounds musics_and_sounds_t;
typedef struct life_bar life_bar_t;

typedef struct program_status
{
    sfRenderWindow *window;
    int running;
    int scene_index;
    musics_and_sounds_t *musics_sounds;
} prog_stat_t;

////////////////////////////////////////////////////////////////////////////////
//                              Gameobject structures                         //
////////////////////////////////////////////////////////////////////////////////

typedef enum g_o_type
{
    button_type,
    background_type,
    music_list_type,
    sound_buffers_type,
    sound_type,
    tile_map_type,
    clock_type,
    enemy_type,
    player_cursor_type,
    player_type
} g_o_type_t;

typedef enum audio_id
{
    button_click,
    menu_background_music,
    heartbeat
} audio_id_t;

typedef struct musics_and_sounds
{
    list_t *musics_list;
    list_t *sounds_buffer_list;
    list_t *sounds_list;
} musics_and_sounds_t;

typedef struct button
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct button *button,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct button *button);
    void (*destroy)(prog_stat_t *prog_stat, struct button *button);
    void (*onclick)(prog_stat_t *prog_stat, struct button *button,
    list_t *game_scene, sfEvent *eve);
    sfVector2f pos;
    sfIntRect rect;
    int offset;
    sfTexture *textu;
    sfSprite *sprite;
    int id;
} button_t;

typedef struct background
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct background *backgr,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct background *backgr);
    void (*destroy)(prog_stat_t *prog_stat, struct background *backgr);
    sfVector2f pos;
    sfTexture *textu;
    sfSprite *sprite;
} backgr_t;

typedef struct enemy
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct enemy *enemy,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct enemy *enemy);
    void (*destroy)(prog_stat_t *prog_stat, struct enemy *enemy);
    sfVector2f pos;
    sfIntRect rect;
    sfTexture *textu;
    sfSprite *sprite;
    int life;
    sfClock *clock;
    life_bar_t *life_bar;
} enemy_t;

typedef struct inventory_s
{
    int do_what_you_want;
} inventory_t;

typedef struct player
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct player *player,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct player *player);
    void (*destroy)(prog_stat_t *prog_stat, struct player *player);
    sfVector2f pos;
    sfIntRect rect;
    sfTexture *textu;
    sfSprite *sprite;
    int life;
    int animeted;
    inventory_t *inventory;
    sfClock *clock;
    life_bar_t *life_bar;
} player_t;

typedef struct life_bar
{
    sfVector2f pos;
    sfIntRect rect;
    sfTexture *textu;
    sfSprite *sprite;
} life_bar_t;

typedef struct music
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct music *music,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct music *music);
    void (*destroy)(prog_stat_t *prog_stat, struct music *music);
    audio_id_t id;
    sfMusic *music;
    int running;
} music_t;

typedef struct sound
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct sound *sound,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct sound *sound);
    void (*destroy)(prog_stat_t *prog_stat, struct sound *sound);
    sfSound *sound;
} sound_t;

typedef struct sound_buffer
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct sound_buffer *buffer,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct sound_buffer *buffer);
    void (*destroy)(prog_stat_t *prog_stat, struct sound_buffer *buffer);
    audio_id_t id;
    sfSoundBuffer *buffer;
} sound_buffer_t;

typedef struct player_cursor
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct player_cursor *player_c,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct player_cursor *player_c,
    list_t *own_scene);
    void (*destroy)(prog_stat_t *prog_stat, struct player_cursor *player_c,
    list_t *own_scene);
    char *current_tile;
    inventory_t *inventory;
    sfVector2f pos;
    sfVector2f sprite_pos;
    sfIntRect *rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
} player_cursor_t;

////////////////////////////////////////////////////////////////////////////////
//                              Tilemap structures                         //
////////////////////////////////////////////////////////////////////////////////
typedef struct active_list_s
{
    int type;
    int x;
    int y;
} active_list_t;

typedef struct tile_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} tile_t;

typedef struct tile_map
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct tile_map *tilemap,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct tile_map *tilemap);
    void (*destroy)(prog_stat_t *prog_stat, struct tile_map *tilemap);
    int map_height;
    int map_width;
    char **map;
    tile_t **tiles;
} tile_map_t;

typedef struct tilemap_scene
{
    char tile_id;
    void (*tile_action)(prog_stat_t *prog_stat, struct player_cursor *player_c,
    list_t *own_scene);
    int scene_id;
} tmap_scene_t;

typedef struct clock_s
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct clock_s *clock,
    list_t *game_scene);
    void (*render)(prog_stat_t *prog_stat, struct clock_s *clock);
    void (*destroy)(prog_stat_t *prog_stat, struct clock_s *clock);
    sfClock *clock;
    int is_paused;
    sfInt64 paused_at;
    sfInt64 to_add;
    sfInt64 speed_at;
    float speed;
    float pause_speed;
} my_clock_t;
////////////////////////////////////////////////////////////////////////////////
//                         Linked list Datastructure                          //
////////////////////////////////////////////////////////////////////////////////

typedef union list_data
{
    button_t *button;
    backgr_t *background;
    music_t *music;
    sound_buffer_t *buffer;
    sound_t *sound;
    tile_map_t *tile_map;
    active_list_t *active;
    my_clock_t *clock;
    enemy_t *enemy;
    player_t *player;
    player_cursor_t *player_c;
} list_data_t;

#endif /* !DATATYPES_H_ */