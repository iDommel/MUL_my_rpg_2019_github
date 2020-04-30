/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** special_prim_tools
*/

#include "../generator.h"

void dig_final_path(char **maze, int perfect)
{
    int y = my_str_arr_len(maze) - 1;
    int x = my_strlen(maze[0]) - 1;

    maze[y][x] = '*';
    if (!perfect) {
        for (int x_i = x; x_i > 0; x_i--)
            maze[y / 2][x_i] = '*';
        for (int y_i = y; y_i > 0; y_i--)
            maze[y_i][x / 2] = '*';
    }
    if ((y + 1) % 2 == 0)
        maze[y - 1][x] = '*';
    else if (x > 0)
        maze[y][x - 1] = '*';
}

void growing_init_maze(char **maze)
{
    for (int y = 0; maze[y]; y++)
        for (int x = 0; maze[y][x] != '\0'; x++)
            if ((y % 2 == 0) && (x % 2 == 0))
                maze[y][x] = 'U';
}

list_t *grow_init(char **maze)
{
    list_t *list = NULL;

    list = create_list();
    add_to_front(list, init_data_pos(0, 0));
    growing_init_maze(maze);
    maze[0][0] = '*';
    return (list);
}