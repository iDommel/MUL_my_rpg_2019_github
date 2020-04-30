/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** char_dbl_stars_handle
*/

#include <unistd.h>
#include <stdlib.h>

void free_tab(char **tab)
{
    if (tab) {
        for (int i = 0; tab[i]; i++)
            free(tab[i]);
        free(tab);
    }
}

char **init_tab_with(int x, int y, char fill)
{
    char **tab = malloc(sizeof(char *) * (y + 1));

    if (tab == NULL)
        return (NULL);
    for (int i = 0; i < y; i++) {
        tab[i] = malloc(x + 1);
        if (tab[i] == NULL) {
            free_tab(tab);
            return (NULL);
        }
        for (int j = 0; j < x; j++)
            tab[i][j] = fill;
        tab[i][x] = '\0';
    }
    tab[y] = 0;
    return (tab);
}

void print_tab(char **tab)
{
    char carriage = '\n';
    int i = 0;

    for (; tab[i + 1]; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++)
            write(1, &tab[i][j], 1);
        write(1, &carriage, 1);
    }
    for (int j = 0; tab[i][j] != '\0'; j++)
        write(1, &tab[i][j], 1);
}