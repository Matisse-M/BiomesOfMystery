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

static void draw_texts_btn(rpg_t *rpg, start_menu_t *screen)
{
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        screen->new_btn->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        screen->resume_btn->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        screen->quit_btn->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window, screen->new_btn->text, NULL);
    sfRenderWindow_drawText(rpg->game->window, screen->resume_btn->text,
        NULL);
    sfRenderWindow_drawText(rpg->game->window, screen->quit_btn->text, NULL);
}

void draw_start_menu(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->game->window, rpg->menu->game_title, NULL);
    if (button_hover(rpg, rpg->menu->start->new_btn) == 1) {
        rpg->menu->start->is_active = false;
        rpg->begin->is_active = true;
    }
    if (!access(my_scat(rpg->name, SAVE), F_OK) &&
        button_hover(rpg, rpg->menu->start->resume_btn) == 1) {
        rpg = parse_save(rpg, read_file(my_scat(rpg->name, SAVE)));
        rpg->menu->start->is_active = false;
        rpg->game->is_active = true;
    }
    if (access(my_scat(rpg->name, SAVE), F_OK))
        sfRectangleShape_setTexture(rpg->menu->start->resume_btn->rect,
            rpg->assets->wrong, sfTrue);
    if (button_hover(rpg, rpg->menu->start->quit_btn) == 1) {
        rpg->menu->start->is_active = false;
        rpg->menu->title->is_active = true;
    }
    draw_texts_btn(rpg, rpg->menu->start);
}
