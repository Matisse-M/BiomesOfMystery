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
    if (my_hover_view(rpg->game->window, btn->rect, rpg->game->view)) {
        if (button_clicked(rpg, btn) == 1) {
            btn->state = 2;
            sfRectangleShape_setTexture(btn->rect, btn->texture[2], sfTrue);
            return 0;
            }
        btn->state = 1;
        sfRectangleShape_setTexture(btn->rect, btn->texture[1], sfTrue);
        return 0;
    }
    btn->state = 1;
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    return 0;
}

static int try_to_catch_released(rpg_t *rpg, button_t *btn, button_t *target,
    int i)
{
    if (button_released(rpg, btn) == 1) {
        if (my_hover_view(rpg->game->window, target->rect, rpg->game->view)) {
            btn->state = 3;
            sfRectangleShape_setTexture(btn->rect, btn->texture[3], sfTrue);
            return 1;
        }
        btn->state = 0;
        sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
        return 0;
    }
    btn->state = 2;
    sfRectangleShape_setTexture(btn->rect, btn->texture[2], sfTrue);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->inv->armor->temp, NULL);
    return 0;
}

static int grab_item(rpg_t *rpg, button_t *btn, button_t *target, int i)
{
    if (btn->state < 2) {
        return try_to_catch_clicked(rpg, btn);
    } else {
        return try_to_catch_released(rpg, btn, target, i);
    }
}

static void update_tempory_sprite(rpg_t *rpg, int rotate, int i,
    sfVector2f map_view)
{
    sfTexture *texture = (sfTexture *) sfSprite_getTexture(
        rpg->inv->armor->items[i]);
    int x[10] = {9, 5, 5, -15, -15, 6, 6, 6, -15, -15};
    int y[10] = {10, 11, 15, 15, 15, 10, 10, 12, 15, 15};

    sfSprite_setTexture(rpg->inv->armor->temp, texture, sfTrue);
    sfSprite_setScale(rpg->inv->armor->temp, (sfVector2f) {1.8, 1.8});
    sfSprite_setPosition(rpg->inv->armor->temp, (sfVector2f)
        {map_view.x + x[i], map_view.y - y[i]});
    sfSprite_setRotation(rpg->inv->armor->temp, rotate);
}

static void modify_item(rpg_t *rpg, sfVector2f pos, int i, int *rotate)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->game->window);
    sfVector2f map_view = sfRenderWindow_mapPixelToCoords(rpg->game->window,
            mouse, rpg->game->view);

    sfSprite_setScale(rpg->inv->armor->current, (sfVector2f) {1.8, 1.8});
    sfSprite_setRotation(rpg->inv->armor->current,
        rotate[rpg->characters->main->weapon]);
    if (rpg->inv->armor->slots[i]->state == 2)
        update_tempory_sprite(rpg, rotate[i], i, map_view);
    if (grab_item(rpg, rpg->inv->armor->slots[i],
        rpg->inv->armor->player[1], i) == 1) {
        rpg->characters->main->weapon = i;
        rpg->inv->armor->slots[i]->state = 0;
        sfSprite_setPosition(rpg->inv->armor->current, pos);
        sfSprite_setTexture(rpg->inv->armor->current, sfSprite_getTexture(
            rpg->inv->armor->items[rpg->characters->main->weapon]), sfTrue);
        return;
    }
}

void drag_n_drop(rpg_t *rpg, sfVector2f pos)
{
    sfVector2f position[10] = {(sfVector2f) {pos.x - 85, pos.y - 62},
        (sfVector2f) {pos.x - 90, pos.y - 61},
        (sfVector2f) {pos.x - 90, pos.y - 65},
        (sfVector2f) {pos.x - 107, pos.y - 65},
        (sfVector2f) {pos.x - 107, pos.y - 65},
        (sfVector2f) {pos.x - 86, pos.y - 64},
        (sfVector2f) {pos.x - 87, pos.y - 63},
        (sfVector2f) {pos.x - 86, pos.y - 65},
        (sfVector2f) {pos.x - 107, pos.y - 65},
        (sfVector2f) {pos.x - 107, pos.y - 65}};
    int rotate[10] = {45, 45, 45, 0, 0, 45, 45, 45, 0, 0};

    for (int i = 0; i < 10; i++) {
        if (rpg->inv->armor->get_item[i] == true)
            modify_item(rpg, position[i], i, rotate);
    }
    sfSprite_setPosition(rpg->inv->armor->current,
        position[rpg->characters->main->weapon]);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->inv->armor->current, NULL);
}
