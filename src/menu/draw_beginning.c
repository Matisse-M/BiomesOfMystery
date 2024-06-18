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

static void retexture_sprite(sfSprite **sprite, sfIntRect area)
{
    sfSprite_setTextureRect(*sprite, area);
}

void select_anim(rpg_t *rpg, int i)
{
    sfTime time = sfClock_getElapsedTime(rpg->begin->clock);
    float f = sfTime_asSeconds(time);

    if (f > 0.8)
        sfClock_restart(rpg->begin->clock);
    if (f <= 0.2)
        return retexture_sprite(&rpg->begin->sprites[i],
            (sfIntRect) {0, 0, 16, 16});
    if (f <= 0.4)
        return retexture_sprite(&rpg->begin->sprites[i],
            (sfIntRect) {0, 17, 16, 16});
    if (f <= 0.6)
        return retexture_sprite(&rpg->begin->sprites[i],
            (sfIntRect) {0, 34, 16, 16});
    retexture_sprite(&rpg->begin->sprites[i], (sfIntRect) {0, 51, 16, 16});
}

void male_hover(rpg_t *rpg, begin_t *btn)
{
    if (button_hover(rpg, btn->genders[0]) == 1)
        btn->gender = 1;
}

void female_hover(rpg_t *rpg, begin_t *btn)
{
    if (button_hover(rpg, btn->genders[1]) == 1)
        btn->gender = 2;
}

void textbox_hover(rpg_t *rpg, begin_t *btn)
{
    if (my_hover_effect(rpg->game->window, btn->name_bar->rect) == 1) {
        if (button_hover(rpg, btn->name_bar) == 1) {
            btn->alpha->is_selsected = true;
            return;
        }
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            btn->name_bar->rect, NULL);
        if (!rpg->begin->alpha->answer)
            sfRenderWindow_drawText(rpg->game->window,
                btn->alpha->pre_text, NULL);
        return;
    }
    sfRectangleShape_setTexture(rpg->begin->name_bar->rect,
            rpg->begin->name_bar->texture[0], sfTrue);
    sfRenderWindow_drawRectangleShape(rpg->game->window, btn->name_bar->rect,
        NULL);
    if (!rpg->begin->alpha->answer)
        sfRenderWindow_drawText(rpg->game->window, btn->alpha->pre_text, NULL);
    return;
}

void validate_hover(rpg_t *rpg, begin_t *btn)
{
    if (button_hover(rpg, rpg->begin->validate) == 1) {
        chara_chosen(rpg);
        rpg->begin->is_active = false;
        rpg->menu->is_active = false;
        rpg->maps->is_active = true;
        rpg->maps->downstairs->is_active = true;
        choose_under_map(rpg, rpg->characters->main);
        rpg->game->is_active = true;
    }
    sfRenderWindow_drawRectangleShape(rpg->game->window, btn->validate->rect,
        NULL);
    sfRenderWindow_drawText(rpg->game->window, btn->validate->text, NULL);
}
