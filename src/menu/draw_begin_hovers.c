/*
** EPITECH PROJECT, 2023
** draw scene
** File description:
** Some functions to draw menu's scene
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"

void hover_choose_chara(rpg_t *rpg)
{
    if (rpg->begin->gender == 2) {
        male_hover(rpg, rpg->begin);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->begin->genders[0]->rect, NULL);
    } else {
        sfRectangleShape_setTexture(rpg->begin->genders[0]->rect,
            rpg->begin->genders[0]->texture[3], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->begin->genders[0]->rect, NULL);
    }
    if (rpg->begin->gender == 1) {
        female_hover(rpg, rpg->begin);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->begin->genders[1]->rect, NULL);
    } else {
        sfRectangleShape_setTexture(rpg->begin->genders[1]->rect,
            rpg->begin->genders[1]->texture[3], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->begin->genders[1]->rect, NULL);
    }
}

void hover_textbox(rpg_t *rpg, float f)
{
    if (my_hover_effect(rpg->game->window, rpg->begin->name_bar->rect) == 0 &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
        rpg->begin->alpha->is_selsected = false;
        rpg->begin->name_bar->state = 0;
    }
    if (rpg->begin->alpha->is_selsected == true) {
        my_put_alphabet(rpg, &rpg->begin->alpha->write_clock, f);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->begin->name_bar->rect, NULL);
        sfRenderWindow_drawText(rpg->game->window, rpg->begin->name, NULL);
    } else {
        textbox_hover(rpg, rpg->begin);
    }
}
