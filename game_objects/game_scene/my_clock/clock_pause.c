/*
** EPITECH PROJECT, 2020
** CLOCK_PAUSE
** File description:
** Clock_pause function
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

void clock_pause(my_clock_t *clock)
{
    if (clock->is_paused)
        return;
    clock->paused_at = clock_get_mcs(clock);
    clock->is_paused = 1;
    clock->pause_speed = clock->speed;
    clock_set_speed(clock, 1);
}

void clock_unpause(my_clock_t *clock)
{
    if (!clock->is_paused)
        return;
    clock->is_paused = 0;
    clock->to_add -= clock_get_mcs(clock) - clock->paused_at;
    clock_set_speed(clock, clock->pause_speed);
}