/*
** EPITECH PROJECT, 2023
** setup game params
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"

button_t *create_buy_btn(assets_t *assets)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box2;
    btn->texture[1] = assets->box2h;
    btn->texture[2] = assets->box3;
    btn->texture[3] = assets->box1;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {75, 22});
    btn->text = sfText_create();
    sfText_setCharacterSize(btn->text, 8);
    sfText_setString(btn->text, "BUY");
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setFont(btn->text, assets->font);
    btn->state = 0;
    return btn;
}

static button_t *create_buy_item_btn(assets_t *assets, char *cost)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box2;
    btn->texture[1] = assets->box2h;
    btn->texture[2] = assets->box1;
    btn->texture[3] = assets->box3;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {175, 22});
    btn->text = sfText_create();
    sfText_setCharacterSize(btn->text, 8);
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setFont(btn->text, assets->font);
    sfText_setString(btn->text, cost);
    btn->state = 0;
    return btn;
}

static void create_coin(rpg_t *rpg, store_t *store)
{
    store->t_coin = sfTexture_createFromFile(my_scat(rpg->name,
        "/secr/coin.png"), NULL);
    if (store->t_coin == NULL)
        exit(84);
    store->coin = my_set_sprite(store->t_coin, (sfVector2f) {0, 0},
        (sfVector2f) {2, 2}, 0);
    store->val_coin = sfText_create();
    sfText_setFont(store->val_coin, rpg->assets->font);
    sfText_setCharacterSize(store->val_coin, 16);
    sfText_setFillColor(store->val_coin, sfBlack);
}

static void create_all_btn(rpg_t *rpg, store_t *store)
{
    char *cost[6] = {"100", "220", "350", "300", "500", "500"};
    int c[6] = {6, 7, 8, 9, 0, 1};

    for (int i = 0; i < 6; i++) {
        store->items[i] = create_buy_item_btn(rpg->assets, cost[i]);
        store->effect[i] = rpg->inv->conso->conso[c[i]]->desc;
        store->product[i] = rpg->inv->conso->conso[c[i]]->name;
        store->asset[i] = rpg->inv->conso->conso[c[i]]->sprite;
    }
    store->buy = create_buy_btn(rpg->assets);
}

store_t *fill_store(rpg_t *rpg)
{
    store_t *store = malloc(sizeof(store_t));

    store->is_active = false;
    store->nb = 0;
    store->clock = sfClock_create();
    store->bck = rpg->skilltree->bck;
    store->logo = my_set_sprite(rpg->assets->grocery, (sfVector2f) {0, 0},
        (sfVector2f) {0.2, 0.2}, 0);
    store->description = sfRectangleShape_create();
    create_coin(rpg, store);
    sfRectangleShape_setTexture(store->description, rpg->assets->box2, sfTrue);
    sfRectangleShape_setSize(store->description, (sfVector2f) {205, 52});
    create_all_btn(rpg, store);
    store->items[0]->state = 3;
    return store;
}
