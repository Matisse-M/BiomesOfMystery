/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main loops of our rpg
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "csfml.h"

void anim_coin(conso_t *conso)
{
    sfTime time = sfClock_getElapsedTime(conso->clock);
    float f = sfTime_asSeconds(time);

    if (f <= 0.2) {
        sfSprite_setTextureRect(conso->piece, (sfIntRect) {0, 0, 10, 10});
        return;
    }
    if (f <= 0.4) {
        sfSprite_setTextureRect(conso->piece, (sfIntRect) {11, 0, 10, 10});
        return;
    }
    if (f <= 0.6) {
        sfSprite_setTextureRect(conso->piece, (sfIntRect) {22, 0, 10, 10});
        return;
    }
    if (f <= 0.8) {
        sfSprite_setTextureRect(conso->piece, (sfIntRect) {33, 0, 10, 10});
        return;
    }
    sfClock_restart(conso->clock);
}
