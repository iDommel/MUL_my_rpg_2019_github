/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** node_choose
*/

#include <stdlib.h>
#include "../generator.h"

void check_neibhor(char **maze, list_t *tmp)
{
    if (choose_node(maze, tmp->data->active->x, tmp->data->active->y) == -1) {
        free(tmp->data->active);
        rm_elem(tmp);
    }
}

list_t *choose_active(list_t *list)
{
    int mode = 0;
    static int started = 0;
    static int behavior_percent = 0;

    if (started == 0) {
        behavior_percent = rand() % 99 + 1;
        started = 1;
    }
    mode = rand() % 99 + 1;
    if (mode < behavior_percent)
        return (list->next);
    else {
        mode = rand() % list_len(list) + 1;
        for (int i = 0; (i < mode) && (list->next->data != NULL); i++) {
            list = list->next;
        }
        return (list);
    }
}

// [left] [top] [right] [bot]

void is_secure_node(char **maze, int x, int y, char *pos)
{
    if ((x >= 2) && (maze[y][x - 2] == 'U'))
        pos[0] = '1';
    else
        pos[0] = '0';
    if ((y >= 2) && (maze[y - 2][x] == 'U'))
        pos[1] = '1';
    else
        pos[1] = '0';
    if ((maze[y][x + 1] != '\0') && (maze[y][x + 2] != '\0')
    && (maze[y][x + 2] == 'U'))
        pos[2] = '1';
    else
        pos[2] = '0';
    if (maze[y + 1] && maze[y + 2] && (maze[y + 2][x] == 'U'))
        pos[3] = '1';
    else
        pos[3] = '0';
}

static char *init_who_s_ok(void)
{
    char *who_s_ok = malloc(5);

    who_s_ok[0] = '0';
    who_s_ok[1] = '0';
    who_s_ok[2] = '0';
    who_s_ok[3] = '0';
    who_s_ok[4] = '\0';
    return (who_s_ok);
}

int choose_node(char **maze, int x, int y)
{
    static char *who_s_ok = NULL;
    int chosen_one = 0;

    if (maze != NULL) {
        if (who_s_ok == NULL)
            who_s_ok = init_who_s_ok();
        is_secure_node(maze, x, y, who_s_ok);
        if (my_streq(who_s_ok, "0000"))
            return (-1);
        while ((who_s_ok[(chosen_one = (rand() % 4))] != '1'));
    } else {
        free(who_s_ok);
        return (SUCCESS_CODE);
    }
    return (chosen_one);
}