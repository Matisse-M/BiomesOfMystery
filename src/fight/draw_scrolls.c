/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** draw_fight_menus
*/

#include "rpg.h"
#include <string.h>

static void update_positions(scroll_t *scroll, sfVector2f pos)
{
    sfRectangleShape_setPosition(scroll->btn[0]->rect,
        (sfVector2f) {pos.x - 220, pos.y + 70});
    sfRectangleShape_setPosition(scroll->btn[1]->rect,
        (sfVector2f) {pos.x - 108, pos.y + 70});
    sfRectangleShape_setPosition(scroll->btn[2]->rect,
        (sfVector2f) {pos.x + 4, pos.y + 70});
    sfRectangleShape_setPosition(scroll->quit->rect,
        (sfVector2f) {pos.x + 118, pos.y + 70});
    sfSprite_setPosition(scroll->scroll[0],
        (sfVector2f) {pos.x - 185, pos.y + 78});
    sfSprite_setPosition(scroll->scroll[1],
        (sfVector2f) {pos.x - 73, pos.y + 78});
    sfSprite_setPosition(scroll->scroll[2],
        (sfVector2f) {pos.x + 39, pos.y + 78});
    sfText_setPosition(scroll->quit->text,
        (sfVector2f) {pos.x + 133, pos.y + 85});
}

static void btn_activate_stone(rpg_t *rpg, scroll_t *scroll)
{
    if (rpg->inv->conso->secret[3]->unlock) {
        if (button_view_hover(rpg, scroll->btn[0]) == 1) {
            scroll->btn[0]->state = 0;
            scroll->is_active = false;
            rpg->fight->state = 4;
            sfClock_restart(rpg->fight->anim);
            rpg->fight->stone = true;
            e_attack(rpg);
        }
        sfRectangleShape_setTexture(scroll->btn[0]->rect,
            scroll->btn[0]->texture[scroll->btn[0]->state], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            scroll->btn[0]->rect, NULL);
        sfRenderWindow_drawSprite(rpg->game->window, scroll->scroll[0], NULL);
    } else {
        sfRectangleShape_setTexture(scroll->btn[0]->rect,
            rpg->assets->wrong, sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            scroll->btn[0]->rect, NULL);
    }
}

static void btn_activate_ice(rpg_t *rpg, scroll_t *scroll)
{
    if (rpg->inv->conso->secret[4]->unlock) {
        if (button_view_hover(rpg, scroll->btn[1]) == 1) {
            scroll->btn[1]->state = 0;
            scroll->is_active = false;
            rpg->fight->state = 3;
            sfClock_restart(rpg->fight->anim);
            rpg->fight->ice = true;
            e_attack(rpg);
        }
        sfRectangleShape_setTexture(scroll->btn[1]->rect,
            scroll->btn[1]->texture[scroll->btn[1]->state], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            scroll->btn[1]->rect, NULL);
        sfRenderWindow_drawSprite(rpg->game->window, scroll->scroll[1], NULL);
    } else {
        sfRectangleShape_setTexture(scroll->btn[1]->rect,
            rpg->assets->wrong, sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            scroll->btn[1]->rect, NULL);
    }
}

static void btn_activate_fire(rpg_t *rpg, scroll_t *scroll)
{
    if (rpg->inv->conso->secret[5]->unlock) {
        if (button_view_hover(rpg, scroll->btn[2]) == 1) {
            scroll->btn[2]->state = 0;
            scroll->is_active = false;
            rpg->fight->state = 2;
            sfClock_restart(rpg->fight->anim);
            rpg->fight->fire = true;
            e_attack(rpg);
        }
        sfRectangleShape_setTexture(scroll->btn[2]->rect,
            scroll->btn[2]->texture[scroll->btn[2]->state], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            scroll->btn[2]->rect, NULL);
        sfRenderWindow_drawSprite(rpg->game->window, scroll->scroll[2], NULL);
    } else {
        sfRectangleShape_setTexture(scroll->btn[2]->rect,
            rpg->assets->wrong, sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            scroll->btn[2]->rect, NULL);
    }
}

static void draw_quit_btn(rpg_t *rpg, scroll_t *scroll)
{
    if (button_view_hover(rpg, scroll->quit) == 1) {
        scroll->quit->state = 0;
        scroll->is_active = false;
    }
    sfRectangleShape_setTexture(scroll->quit->rect,
        scroll->quit->texture[scroll->quit->state], sfTrue);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        scroll->quit->rect, NULL);
}

void draw_scrolls(rpg_t *rpg, scroll_t *scroll)
{
    sfVector2f pos = sfView_getCenter(rpg->game->view);

    if (scroll->is_active == true) {
        update_positions(scroll, pos);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            scroll->quit->rect, NULL);
        sfSprite_setScale(scroll->scroll[0], (sfVector2f) {2, 2});
        sfSprite_setScale(scroll->scroll[1], (sfVector2f) {2, 2});
        sfSprite_setScale(scroll->scroll[2], (sfVector2f) {2, 2});
        btn_activate_stone(rpg, scroll);
        btn_activate_ice(rpg, scroll);
        btn_activate_fire(rpg, scroll);
        draw_quit_btn(rpg, scroll);
        sfSprite_setScale(scroll->scroll[0], (sfVector2f) {1, 1});
        sfSprite_setScale(scroll->scroll[1], (sfVector2f) {1, 1});
        sfSprite_setScale(scroll->scroll[2], (sfVector2f) {1, 1});
        sfRenderWindow_drawText(rpg->game->window, scroll->quit->text, NULL);
    }
}
