/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "csfml.h"

void draw_monkey(rpg_t *rpg)
{
    if (rpg->boss->monkey == true && rpg->maps->village->is_active) {
        sfSprite_setPosition(rpg->inv->armor->items[4],
            (sfVector2f) {15, 130});
        sfSprite_setColor(rpg->inv->armor->items[4], sfWhite);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->inv->armor->items[4], NULL);
        if ((rpg->characters->main->position.x >= 10 &&
            rpg->characters->main->position.x <= 50) && (
            rpg->characters->main->position.y >= 125 &&
            rpg->characters->main->position.y <= 135)) {
            rpg->inv->armor->get_item[4] = true;
            rpg->boss->monkey = false;
        }
    }
}

void draw_dog(rpg_t *rpg)
{
    if (rpg->boss->dog == true && rpg->maps->house->is_active) {
        sfSprite_setPosition(rpg->inv->armor->items[8], (sfVector2f) {45, 80});
        sfSprite_setColor(rpg->inv->armor->items[8], sfWhite);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->inv->armor->items[8], NULL);
        if ((rpg->characters->main->position.x >= 40 &&
            rpg->characters->main->position.x <= 65) && (
            rpg->characters->main->position.y >= 75 &&
            rpg->characters->main->position.y <= 110)) {
            rpg->inv->armor->get_item[8] = true;
            rpg->boss->dog = false;
        }
    }
}
