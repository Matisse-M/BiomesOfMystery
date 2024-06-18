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

static void draw_stat_values(rpg_t *rpg, sfVector2f pos)
{
    char *val[4] = {my_itoa(rpg->characters->main->lvl),
        my_itoa(rpg->characters->main->hp),
        my_itoa(rpg->characters->main->atk),
        my_itoa(rpg->characters->main->emo)};

    for (int i = 0; i < 2; i++) {
        rpg->inv->armor->value[i] = my_set_text(rpg, val[i], 20,
            (sfVector2f) {pos.x + 70 + (i * 100), pos.y - 75});
        sfRenderWindow_drawText(rpg->game->window, rpg->inv->armor->value[i],
            NULL);
    }
    for (int i = 2; i < 4; i++) {
        rpg->inv->armor->value[i] = my_set_text(rpg, val[i], 20,
            (sfVector2f) {pos.x + 65 + ((i - 2) * 122), pos.y - 50});
        sfRenderWindow_drawText(rpg->game->window, rpg->inv->armor->value[i],
            NULL);
    }
}

static void set_position_items(rpg_t *rpg, sfVector2f pos)
{
    sfSprite_setPosition(rpg->inv->armor->items[0], (sfVector2f)
        {pos.x - 108, pos.y + 12});
    sfSprite_setPosition(rpg->inv->armor->items[1], (sfVector2f)
        {pos.x - 52, pos.y + 13});
    sfSprite_setPosition(rpg->inv->armor->items[2], (sfVector2f)
        {pos.x + 6, pos.y + 10});
    sfSprite_setPosition(rpg->inv->armor->items[3], (sfVector2f)
        {pos.x + 50, pos.y + 10});
    sfSprite_setPosition(rpg->inv->armor->items[4], (sfVector2f)
        {pos.x + 111, pos.y + 11});
    sfSprite_setPosition(rpg->inv->armor->items[5], (sfVector2f)
        {pos.x - 110, pos.y + 72});
    sfSprite_setPosition(rpg->inv->armor->items[6], (sfVector2f)
        {pos.x - 50, pos.y + 72});
    sfSprite_setPosition(rpg->inv->armor->items[7], (sfVector2f)
        {pos.x + 10, pos.y + 70});
    sfSprite_setPosition(rpg->inv->armor->items[8], (sfVector2f)
        {pos.x + 50, pos.y + 72});
    sfSprite_setPosition(rpg->inv->armor->items[9], (sfVector2f)
        {pos.x + 111, pos.y + 70});
}

static void draw_items(rpg_t *rpg, sfVector2f pos)
{
    set_position_items(rpg, pos);
    for (int i = 0; i < 10; i++) {
        if (rpg->inv->armor->get_item[i] == false)
            sfSprite_setColor(rpg->inv->armor->items[i], sfBlack);
        else
            sfSprite_setColor(rpg->inv->armor->items[i], sfWhite);
        sfRenderWindow_drawSprite(rpg->game->window, rpg->inv->armor->items[i],
            NULL);
    }
}

static void draw_slots(rpg_t *rpg, sfVector2f pos)
{
    for (int i = 0; i < 5; i++) {
        sfRectangleShape_setPosition(rpg->inv->armor->slots[i]->rect,
            (sfVector2f) {pos.x - 140 + (i * 60), pos.y + 0});
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->armor->slots[i]->rect, NULL);
    }
    for (int i = 5; i < 10; i++) {
        sfRectangleShape_setPosition(rpg->inv->armor->slots[i]->rect,
            (sfVector2f) {pos.x - 140 + ((i - 5) * 60), pos.y + 60});
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->armor->slots[i]->rect, NULL);
    }
    for (int i = 0; i < 2; i++) {
        sfRectangleShape_setPosition(rpg->inv->armor->player[i]->rect,
            (sfVector2f) {pos.x - 177 + (i * 60), pos.y - 75});
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->inv->armor->player[i]->rect, NULL);
    }
}

static void draw_stats(rpg_t *rpg, sfVector2f pos)
{
    for (int i = 0; i < 2; i++) {
        sfText_setPosition(rpg->inv->armor->stats[i], (sfVector2f)
            {pos.x + 10 + (i * 120), pos.y - 70});
        sfRenderWindow_drawText(rpg->game->window,
            rpg->inv->armor->stats[i], NULL);
    }
    for (int i = 2; i < 4; i++) {
        sfText_setPosition(rpg->inv->armor->stats[i], (sfVector2f)
            {pos.x + 10 + ((i - 2) * 120), pos.y - 45});
        sfRenderWindow_drawText(rpg->game->window,
            rpg->inv->armor->stats[i], NULL);
    }
}

void draw_armor(rpg_t *rpg)
{
    sfVector2f pos = sfView_getCenter(rpg->game->view);

    draw_slots(rpg, pos);
    draw_stats(rpg, pos);
    sfSprite_setScale(rpg->characters->main->face, (sfVector2f) {1, 1});
    sfSprite_setPosition(rpg->characters->main->face, (sfVector2f)
        {pos.x - 172, pos.y - 70});
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->characters->main->face, NULL);
    draw_stat_values(rpg, pos);
    draw_items(rpg, pos);
    drag_n_drop(rpg, pos);
}
