/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** perfect_maze
*/

#include "generator.h"
#include <stdlib.h>

list_data_t *init_data_pos(int x, int y)
{
    list_data_t *actual = malloc(sizeof(list_data_t));

    actual->active = malloc(sizeof(active_list_t));
    actual->active->x = x;
    actual->active->y = y;
    return (actual);
}

static void dig_part_two(char **maze, list_t *list, list_t *cursor, int axe)
{
    int x = cursor->data->active->x;
    int y = cursor->data->active->y;

    if (axe == 1) {
        maze[y - 1][x] = '*';
        maze[y - 2][x] = '*';
        add_to_front(list, init_data_pos(x, y - 2));
    }
    if (axe == 3) {
        maze[y + 1][x] = '*';
        maze[y + 2][x] = '*';
        add_to_front(list, init_data_pos(x, y + 2));
    }
}

void dig(char **maze, list_t *list, list_t *cursor, int axe)
{
    int x = cursor->data->active->x;
    int y = cursor->data->active->y;

    if (axe == 0) {
        maze[y][x - 1] = '*';
        maze[y][x - 2] = '*';
        add_to_front(list, init_data_pos(x - 2, y));
    } else if (axe == 2) {
        maze[y][x + 1] = '*';
        maze[y][x + 2] = '*';
        add_to_front(list, init_data_pos(x + 2, y));
    } else
        dig_part_two(maze, list, cursor, axe);
}

// chosen_one is 0, 1, 2, 3 for West, North, ect

char **create_perfect_maze(char **maze, int perfect)
{
    list_t *list = NULL;
    list_t *cursor = NULL;

    if (maze == NULL)
        return (NULL);
    list = grow_init(maze);
    while (list_len(list) > 0) {
        cursor = choose_active(list);
        dig(maze, list, cursor, choose_node(maze, cursor->data->active->x
        , cursor->data->active->y));
        check_neibhor(maze, cursor);
    }
    if (((my_str_arr_len(maze) % 2) == 0) || ((my_strlen(maze[0]) % 2 == 0)) ||
    !perfect)
        dig_final_path(maze, perfect);
    delete_list(list);
    return (maze);
}