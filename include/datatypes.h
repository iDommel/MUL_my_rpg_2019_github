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

typedef struct program_status
{
    sfRenderWindow *window;
    int running;
    int scene_index;
} prog_stat_t;
////////////////////////////////////////////////////////////////////////////////
//                              Gameobject structures                         //
////////////////////////////////////////////////////////////////////////////////

typedef enum g_o_type
{
    button_type,
    background_type,
    music_type,
} g_o_type_t;

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

typedef struct music
{
    g_o_type_t type;
    void (*update)(prog_stat_t *prog_stat, struct music *music,
    list_t *own_scene);
    void (*render)(prog_stat_t *prog_stat, struct music *music);
    void (*destroy)(prog_stat_t *prog_stat, struct music *music);
    sfMusic *music;
    int running;
} music_t;


////////////////////////////////////////////////////////////////////////////////
//                         Linked list Datastructure                          //
////////////////////////////////////////////////////////////////////////////////

typedef union list_data
{
    button_t *button;
    backgr_t *background;
    music_t *music;
} list_data_t;

#endif /* !DATATYPES_H_ */