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
#define MENU_ICON_WIDTH 200
#define MENU_ICON_HEIGHT 50
#define MENU_START_BUTTON "ressources/menu/start.png"
#define MENU_QUIT_BUTTON "ressources/menu/quit.png"

#define NB_SCENES 2

#define NB_EVT_FUNCTIONS 2

#define READ_SIZE 1

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

////////////////////////
//  EVENTS_HANDLING   //
////////////////////////
void analyse_events(prog_stat_t *, list_t *scene);
void button_clicked(sfEvent *event, prog_stat_t *prog_stat, list_t *g_o_list);
void close_window(sfEvent *, prog_stat_t *, list_t *scene);
void start_game(prog_stat_t *, button_t *, list_t *scene, sfEvent *);
void quit_game(prog_stat_t *, button_t *, list_t *scene, sfEvent *);

////////////////////////
//     UPDATING       //
////////////////////////

////////////////////////
//     RENDERING      //
////////////////////////
void render_button(prog_stat_t *prog_stat, button_t *button);
void render_background(prog_stat_t *prog_stat, backgr_t *backgr);

////////////////////////
//    DESTROYING      //
////////////////////////
void button_destroy(prog_stat_t *prog_stat, button_t *button);
void backgr_destroy(prog_stat_t *prog_stat, backgr_t *backgr);

#endif /* !MY_RPG_H_ */