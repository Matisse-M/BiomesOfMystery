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

static void draw_texts_btn(rpg_t *rpg, title_screen_t *screen)
{
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        screen->start_btn->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        screen->settings_btn->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        screen->quit_btn->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window, screen->start_btn->text, NULL);
    sfRenderWindow_drawText(rpg->game->window, screen->settings_btn->text,
        NULL);
    sfRenderWindow_drawText(rpg->game->window, screen->quit_btn->text, NULL);
}

void draw_title_screen(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->game->window, rpg->menu->game_title, NULL);
    if (button_hover(rpg, rpg->menu->title->start_btn) == 1) {
        rpg->menu->title->is_active = false;
        rpg->menu->start->is_active = true;
    }
    if (button_hover(rpg, rpg->menu->title->settings_btn) == 1) {
        rpg->menu->title->is_active = false;
        rpg->menu->settings->is_active = true;
    }
    if (button_hover(rpg, rpg->menu->title->quit_btn) == 1) {
        sfRenderWindow_close(rpg->game->window);
    }
    draw_texts_btn(rpg, rpg->menu->title);
}
