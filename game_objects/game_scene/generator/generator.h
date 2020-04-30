/*
** EPITECH PROJECT, 2020
** Model
** File description:
** maze generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "../../../lib/my/my.h"
#include "../../../lib/lists/lists.h"

#define SUCCESS_CODE 0
#define FAILURE_CODE 84

//
// project functions
//
char **init_tab_with(int x, int y, char fill);
void print_tab(char **tab);
void free_tab(char **tab);

void is_secure_node(char **maze, int x, int y, char *pos);
int choose_node(char **maze, int x, int y);
list_t *choose_active(list_t *list);
void check_neibhor(char **maze, list_t *tmp);
int there_is_active_left(char **maze);

list_data_t *init_data_pos(int x, int y);
void growing_init_maze(char **maze);
list_t *grow_init(char **maze);
void dig_final_path(char **maze, int perfect);

char **create_perfect_maze(char **maze, int perfect);

#endif /* !GENERATOR_H_ */