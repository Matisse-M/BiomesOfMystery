/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** wait_relapce
*/

#include "rpg.h"

void wait_relapse(void)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float f = 0;

    while (sfMouse_isButtonPressed(sfMouseLeft)) {
        time = sfClock_getElapsedTime(clock);
        f = sfTime_asSeconds(time);
        if (f > 5)
            break;
    }
}

float time_elapsed(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float f = sfTime_asSeconds(time);

    return f;
}
