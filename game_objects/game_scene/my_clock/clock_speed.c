/*
** EPITECH PROJECT, 2020
** CLOCK_SPEED
** File description:
** Clock_speed function
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

void clock_set_speed(my_clock_t *clock, float speed)
{
    sfInt64 elapse;

    if (!clock)
        return;
    if (clock->speed_at != -1) {
        elapse = clock_get_mcs(clock) - clock->speed_at;
        elapse /= clock->speed;
        clock->to_add += elapse * (clock->speed - 1);
        clock->speed = 1;
    }
    clock->speed_at = clock_get_mcs(clock);
    clock->speed = speed;
}

float clock_get_speed(my_clock_t *clock)
{
    if (!clock)
        return (0);
    return (clock->speed);
}