/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_new_pos
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"

void set_new_pos_sprite(sfSprite *sprite, sfVideoMode res, sfVector2u old_size)
{
    sfSprite_setPosition(sprite, get_pos(res,
        sfSprite_getPosition(sprite), old_size));
}

void set_new_pos_text(sfText *text, sfVideoMode res, sfVector2u old_size)
{
    sfText_setPosition(text, get_pos(res, sfText_getPosition(text), old_size));
}

void set_new_pos_rect(sfRectangleShape *rect, sfVideoMode res,
    sfVector2u old_size)
{
    sfRectangleShape_setPosition(rect, get_pos(res,
        sfRectangleShape_getPosition(rect), old_size));
}

void set_new_pos_btn(button_t *btn, sfVideoMode res, sfVector2u old_size)
{
    sfVector2f pos_rect = sfRectangleShape_getPosition(btn->rect);
    sfVector2f pos_text = sfText_getPosition(btn->text);
    sfVector2f newpos_rect = get_pos(res, pos_rect, old_size);
    sfVector2f newpos_text = get_pos(res, pos_text, old_size);

    sfRectangleShape_setPosition(btn->rect, newpos_rect);
    sfText_setPosition(btn->text, newpos_text);
}
