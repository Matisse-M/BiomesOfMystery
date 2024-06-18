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

static int button_released(rpg_t *rpg, button_t *btn)
{
    if (rpg->game->event.type == sfEvtMouseButtonReleased && btn->state == 2) {
        return 1;
    }
    return 0;
}

static int button_clicked(rpg_t *rpg, button_t *btn)
{
    if (rpg->game->event.type == sfEvtMouseButtonPressed) {
        return 1;
    }
    return 0;
}

static int try_to_catch_clicked(rpg_t *rpg, button_t *btn)
{
    if (button_clicked(rpg, btn) == 1) {
        btn->state = 2;
        sfRectangleShape_setTexture(btn->rect, btn->texture[2], sfTrue);
        return 0;
        }
    btn->state = 1;
    sfRectangleShape_setTexture(btn->rect, btn->texture[1], sfTrue);
    return 0;
}

static int try_to_catch_released(rpg_t *rpg, button_t *btn)
{
    if (button_released(rpg, btn) == 1) {
        btn->state = 3;
        sfRectangleShape_setTexture(btn->rect, btn->texture[3], sfTrue);
        return 1;
        }
    btn->state = 2;
    sfRectangleShape_setTexture(btn->rect, btn->texture[2], sfTrue);
    return 0;
}

int button_hover(rpg_t *rpg, button_t *btn)
{
    if (my_hover_effect(rpg->game->window, btn->rect) == 1) {
        if (btn->state < 2) {
            return try_to_catch_clicked(rpg, btn);
        } else {
            return try_to_catch_released(rpg, btn);
        }
    }
    btn->state = 0;
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    return 0;
}

int button_view_hover(rpg_t *rpg, button_t *btn)
{
    if (my_hover_view(rpg->game->window, btn->rect, rpg->game->view)) {
        if (btn->state < 2) {
            return try_to_catch_clicked(rpg, btn);
        } else {
            return try_to_catch_released(rpg, btn);
        }
    }
    btn->state = 0;
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    return 0;
}
