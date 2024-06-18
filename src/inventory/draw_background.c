/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main loops of our rpg
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "csfml.h"

void update_pos(inv_btn_t *btn, sfVector2f pos, sfVector2f pos2)
{
    sfRectangleShape_setPosition(btn->btn->rect, pos);
    sfText_setPosition(btn->btn->text, pos2);
}

void hover_clicked(rpg_t *rpg, inv_btn_t *btn)
{
    rpg->inv->btn[0]->is_active = false;
    rpg->inv->btn[1]->is_active = false;
    rpg->inv->btn[2]->is_active = false;
    rpg->inv->btn[3]->is_active = false;
    btn->is_active = true;
}

static void draw_buttons_you(rpg_t *rpg, sfVector2f pos)
{
    sfText_setString(rpg->inv->btn[0]->btn->text, rpg->characters->main->name);
    update_pos(rpg->inv->btn[0], (sfVector2f) {pos.x - 215, pos.y - 110},
        (sfVector2f) {pos.x - (my_strlen(rpg->characters->main->name) * 4 +
        158), pos.y - 107});
    if (rpg->inv->btn[0]->is_active == true) {
        sfRectangleShape_setTexture(rpg->inv->btn[0]->btn->rect,
            rpg->inv->btn[0]->btn->texture[3], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->btn[0]->btn->rect, NULL);
        draw_armor(rpg);
    } else {
        if (button_view_hover(rpg, rpg->inv->btn[0]->btn) == 1)
            hover_clicked(rpg, rpg->inv->btn[0]);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->btn[0]->btn->rect, NULL);
    }
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->btn[0]->btn->text, NULL);
}

static void draw_buttons_items(rpg_t *rpg, sfVector2f pos)
{
    update_pos(rpg->inv->btn[1], (sfVector2f) {pos.x - 105, pos.y - 110},
        (sfVector2f) {pos.x - 70, pos.y - 107});
    if (rpg->inv->btn[1]->is_active == true) {
        sfRectangleShape_setTexture(rpg->inv->btn[1]->btn->rect,
            rpg->inv->btn[1]->btn->texture[3], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->btn[1]->btn->rect, NULL);
        draw_items_inv(rpg);
    } else {
        if (button_view_hover(rpg, rpg->inv->btn[1]->btn) == 1)
            hover_clicked(rpg, rpg->inv->btn[1]);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->btn[1]->btn->rect, NULL);
    }
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->btn[1]->btn->text, NULL);
}

static void draw_buttons_quests(rpg_t *rpg, sfVector2f pos)
{
    update_pos(rpg->inv->btn[2], (sfVector2f) {pos.x + 5, pos.y - 110},
        (sfVector2f) {pos.x + 38, pos.y - 107});
    if (rpg->inv->btn[2]->is_active == true) {
        sfRectangleShape_setTexture(rpg->inv->btn[2]->btn->rect,
            rpg->inv->btn[2]->btn->texture[3], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->btn[2]->btn->rect, NULL);
        draw_quests(rpg, pos);
    } else {
        if (button_view_hover(rpg, rpg->inv->btn[2]->btn) == 1)
            hover_clicked(rpg, rpg->inv->btn[2]);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->btn[2]->btn->rect, NULL);
    }
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->btn[2]->btn->text, NULL);
}

static void draw_buttons_settings(rpg_t *rpg, sfVector2f pos)
{
    update_pos(rpg->inv->btn[3], (sfVector2f) {pos.x + 115, pos.y - 110},
        (sfVector2f) {pos.x + 142, pos.y - 107});
    if (rpg->inv->btn[3]->is_active == true) {
        sfRectangleShape_setTexture(rpg->inv->btn[3]->btn->rect,
            rpg->inv->btn[3]->btn->texture[3], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->btn[3]->btn->rect, NULL);
        draw_settings_inv(rpg);
    } else {
        if (button_view_hover(rpg, rpg->inv->btn[3]->btn) == 1)
            hover_clicked(rpg, rpg->inv->btn[3]);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->btn[3]->btn->rect, NULL);
    }
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->btn[3]->btn->text, NULL);
}

void draw_inv_menu(rpg_t *rpg)
{
    sfVector2f pos = sfView_getCenter(rpg->game->view);

    if (rpg->inv->is_active == true) {
        sfRectangleShape_setPosition(rpg->inv->bkgrnd,
            (sfVector2f) {pos.x - 250, pos.y - 140});
        sfRenderWindow_drawRectangleShape(rpg->game->window, rpg->inv->bkgrnd,
            NULL);
        draw_buttons_you(rpg, pos);
        draw_buttons_items(rpg, pos);
        draw_buttons_quests(rpg, pos);
        draw_buttons_settings(rpg, pos);
    }
}
