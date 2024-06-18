/*
** EPITECH PROJECT, 2023
** setup player
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "my.h"
#include "rpg.h"

static void anim_coin_buy(store_t *store)
{
    sfTime time = sfClock_getElapsedTime(store->clock);
    float f = sfTime_asSeconds(time);

    if (f <= 0.2) {
        sfSprite_setTextureRect(store->coin, (sfIntRect) {0, 0, 10, 10});
        return;
    }
    if (f <= 0.4) {
        sfSprite_setTextureRect(store->coin, (sfIntRect) {11, 0, 10, 10});
        return;
    }
    if (f <= 0.6) {
        sfSprite_setTextureRect(store->coin, (sfIntRect) {22, 0, 10, 10});
        return;
    }
    if (f <= 0.8) {
        sfSprite_setTextureRect(store->coin, (sfIntRect) {33, 0, 10, 10});
        return;
    }
    sfClock_restart(store->clock);
}

static void update_store_positions(store_t *store, sfVector2f pos)
{
    sfText_setPosition(store->val_coin, (sfVector2f) {pos.x + 30, pos.y + 10});
    sfText_setPosition(store->buy->text,
        (sfVector2f) {pos.x + 160, pos.y + 18});
    sfRectangleShape_setPosition(store->bck,
        (sfVector2f) {pos.x - 250, pos.y - 140});
    sfSprite_setPosition(store->logo, (sfVector2f) {pos.x + 60, pos.y - 100});
    sfSprite_setPosition(store->coin, (sfVector2f) {pos.x, pos.y + 10});
    sfRectangleShape_setPosition(store->description,
        (sfVector2f) {pos.x, pos.y + 45});
    sfRectangleShape_setPosition(store->buy->rect,
        (sfVector2f) {pos.x + 130, pos.y + 12});
}

static void increase_obj(conso_list_t *conso)
{
    int nb = atoi(sfText_getString(conso->qty));

    nb += 1;
    sfText_setString(conso->qty, my_itoa(nb));
}

static void change_items_state(rpg_t *rpg, store_t *store, int i)
{
    if (i == store->nb) {
        sfRectangleShape_setTexture(store->items[i]->rect,
            store->items[i]->texture[3], sfTrue);
        sfRenderWindow_drawText(rpg->game->window, store->effect[i], NULL);
    } else {
        if (button_view_hover(rpg, store->items[i]) == 1) {
            store->nb = i;
        }
        sfRectangleShape_setTexture(store->items[i]->rect,
            store->items[i]->texture[store->items[i]->state], sfTrue);
    }
}

static void draw_all_btn(rpg_t *rpg, store_t *store, sfVector2f pos)
{
    for (int i = 0; i < 6; i++) {
        sfRectangleShape_setPosition(store->items[i]->rect,
            (sfVector2f) {pos.x - 210, pos.y - 100 + (35 * i)});
        sfText_setPosition(store->items[i]->text,
            (sfVector2f) {pos.x - 60, pos.y - 93 + (35 * i)});
        sfText_setPosition(store->effect[i], (sfVector2f)
            {pos.x + 10, pos.y + 55});
        sfSprite_setPosition(store->asset[i],
            (sfVector2f) {pos.x - 205, pos.y - 97 + (35 * i)});
        sfText_setPosition(store->product[i],
            (sfVector2f) {pos.x - 180, pos.y - 93 + (35 * i)});
        change_items_state(rpg, store, i);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            store->items[i]->rect, NULL);
        sfRenderWindow_drawText(rpg->game->window,
            store->items[i]->text, NULL);
        sfRenderWindow_drawSprite(rpg->game->window, store->asset[i], NULL);
        sfRenderWindow_drawText(rpg->game->window, store->product[i], NULL);
    }
}

static void check_which_obj(rpg_t *rpg, store_t *store)
{
    if (store->nb == 0)
        increase_obj(rpg->inv->conso->conso[6]);
    if (store->nb == 1)
        increase_obj(rpg->inv->conso->conso[7]);
    if (store->nb == 2)
        increase_obj(rpg->inv->conso->conso[8]);
    if (store->nb == 3)
        increase_obj(rpg->inv->conso->conso[9]);
    if (store->nb == 4)
        increase_obj(rpg->inv->conso->conso[0]);
    if (store->nb == 5)
        increase_obj(rpg->inv->conso->conso[1]);
}

static void draw_buy_btn(rpg_t *rpg, store_t *store)
{
    if (atoi(sfText_getString(store->items[store->nb]->text)) >
        rpg->characters->main->money || rpg->characters->main->bag >= 25) {
        sfText_setFillColor(store->buy->text, (sfColor) {125, 125, 125, 255});
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            store->buy->rect, NULL);
    } else {
        if (button_view_hover(rpg, store->buy) == 1) {
            rpg->characters->main->money -= atoi(sfText_getString(
                store->items[store->nb]->text));
            check_which_obj(rpg, store);
            store->buy->state = 0;
        }
        sfRectangleShape_setTexture(store->buy->rect,
            store->buy->texture[store->buy->state], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            store->buy->rect, NULL);
        sfText_setFillColor(store->buy->text, sfBlack);
    }
    sfRenderWindow_drawText(rpg->game->window, store->buy->text, NULL);
}

void draw_store(rpg_t *rpg, store_t *store)
{
    sfVector2f pos = sfView_getCenter(rpg->game->view);

    anim_coin_buy(store);
    sfText_setString(store->val_coin, my_itoa(rpg->characters->main->money));
    update_store_positions(store, pos);
    sfRenderWindow_drawRectangleShape(rpg->game->window, store->bck, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        store->description, NULL);
    sfRenderWindow_drawSprite(rpg->game->window, store->coin, NULL);
    sfRenderWindow_drawText(rpg->game->window, store->val_coin, NULL);
    sfRenderWindow_drawSprite(rpg->game->window, store->logo, NULL);
    draw_buy_btn(rpg, store);
    draw_all_btn(rpg, store, pos);
}
