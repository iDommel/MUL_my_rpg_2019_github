/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** analyse_event
*/

#include "my_rpg.h"

int get_event_type(sfEventType srctype)
{
    int i = 0;
    unsigned int evttype[NB_EVT_FUNCTIONS] = {sfEvtClosed,
    sfEvtMouseButtonPressed};

    for (i = 0; srctype != evttype[i] && i < NB_EVT_FUNCTIONS; i++);
    return (i < NB_EVT_FUNCTIONS ? i : -1);
}

void manage_inputs(sfEvent *event, prog_stat_t *prog_stat, list_t *scene)
{
    int type = event->type;
    int index = get_event_type(type);

    void (*ptr[NB_EVT_FUNCTIONS])(sfEvent *, prog_stat_t *, list_t *)
    = {close_window, button_clicked};
    if (index != -1)
        ptr[index](event, prog_stat, scene);
}

void analyse_events(prog_stat_t *prog_stat, list_t *scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(prog_stat->window, &event))
        manage_inputs(&event, prog_stat, scene);
}