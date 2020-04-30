/*
** EPITECH PROJECT, 2019
** CLOCK_GET
** File description:
** Clock_get function
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

sfInt64 clock_get_s(my_clock_t *clock)
{
    return (clock_get_mcs(clock) / 1000000);
}

sfInt64 clock_get_ms(my_clock_t *clock)
{
    return (clock_get_mcs(clock) / 1000);
}

sfInt64 clock_get_mcs(my_clock_t *clock)
{
    sfInt64 elapse;
    sfInt64 delta_elapse;

    if (!clock)
        return (0);
    if (clock->is_paused)
        return (clock->paused_at);
    elapse = sfClock_getElapsedTime(clock->clock).microseconds + clock->to_add;
    if (clock->speed_at != -1) {
        delta_elapse = elapse - clock->speed_at;
        elapse -= delta_elapse;
        elapse += delta_elapse * clock->speed;
    }
    return (elapse);
}