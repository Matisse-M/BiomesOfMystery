/*
** EPITECH PROJECT, 2023
** setup game params
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdbool.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"

const char *statistic[4] = {"LVL:", "HP:", "ATK:", "GPA:"};

button_t *create_escape_btn(sfVector2f pos, assets_t *assets,
    sfVector2f pos_text, const char *name)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box3;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {100, 15});
    sfRectangleShape_setPosition(btn->rect, pos);
    btn->text = sfText_create();
    sfText_setString(btn->text, name);
    sfText_setFont(btn->text, assets->font);
    sfText_setCharacterSize(btn->text, 8);
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setPosition(btn->text, pos_text);
    btn->state = 0;
    return btn;
}

static button_t *create_slot(sfTexture *texture, sfVector2f size)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = texture;
    btn->texture[1] = texture;
    btn->texture[2] = texture;
    btn->texture[3] = texture;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, size);
    btn->text = NULL;
    btn->state = 0;
    return btn;
}

static void set_slots(armor_t *armor, sfTexture *texture)
{
    armor->get_item = malloc(sizeof(bool) * 10);
    for (int i = 0; i < 10; i++)
        armor->get_item[i] = false;
    for (int i = 0; i < 10; i++)
        armor->slots[i] = create_slot(texture, (sfVector2f) {48, 48});
    for (int i = 0; i < 2; i++)
        armor->player[i] = create_slot(texture, (sfVector2f) {48, 48});
}

static void set_sprite_armor(armor_t *armor, sfTexture *stick, sfTexture *bone,
    sfTexture *axe)
{
    armor->items[0] = my_set_sprite(stick, (sfVector2f) {0, 0},
        (sfVector2f) {1.8, 1.8}, 45);
    armor->items[1] = my_set_sprite(bone, (sfVector2f) {0, 0},
        (sfVector2f) {1.8, 1.8}, 45);
    armor->items[2] = my_set_sprite(axe, (sfVector2f) {0, 0},
        (sfVector2f) {1.8, 1.8}, 45);
}

static void set_items1(rpg_t *rpg, armor_t *armor)
{
    sfTexture *stick = sfTexture_createFromFile(my_scat(rpg->name,
        "/weapons/1.png"), NULL);
    sfTexture *bone = sfTexture_createFromFile(my_scat(rpg->name,
        "/weapons/2.png"), NULL);
    sfTexture *axe = sfTexture_createFromFile(my_scat(rpg->name,
        "/weapons/3.png"), NULL);
    sfTexture *bamboo = sfTexture_createFromFile(my_scat(rpg->name,
        "/weapons/4.png"), NULL);
    sfTexture *monkey = sfTexture_createFromFile(my_scat(rpg->name,
        "/weapons/5.png"), NULL);

    if (bamboo == NULL || monkey == NULL || stick == NULL || bone == NULL
        || axe == NULL)
        exit(84);
    set_sprite_armor(armor, stick, bone, axe);
    armor->items[3] = my_set_sprite(bamboo, (sfVector2f) {0, 0},
        (sfVector2f) {1.8, 1.8}, 0);
    armor->items[4] = my_set_sprite(monkey, (sfVector2f) {0, 0},
        (sfVector2f) {1.8, 1.8}, 0);
}

static void set_sprite_items(armor_t *armor, sfTexture *dog, sfTexture *lizard,
    sfTexture *bigsword)
{
    armor->items[7] = my_set_sprite(bigsword, (sfVector2f) {0, 0},
        (sfVector2f) {1.8, 1.8}, 45);
    armor->items[8] = my_set_sprite(dog, (sfVector2f) {0, 0},
        (sfVector2f) {1.8, 1.8}, 0);
    armor->items[9] = my_set_sprite(lizard, (sfVector2f) {0, 0},
        (sfVector2f) {1.8, 1.8}, 0);
}

static void set_items2(rpg_t *rpg, armor_t *armor)
{
    sfTexture *sword = sfTexture_createFromFile(my_scat(rpg->name,
        "/weapons/6.png"), NULL);
    sfTexture *katana = sfTexture_createFromFile(my_scat(rpg->name,
        "/weapons/7.png"), NULL);
    sfTexture *bigsword = sfTexture_createFromFile(my_scat(rpg->name,
        "/weapons/8.png"), NULL);
    sfTexture *dog = sfTexture_createFromFile(my_scat(rpg->name,
        "/weapons/9.png"), NULL);
    sfTexture *lizard = sfTexture_createFromFile(my_scat(rpg->name,
        "/weapons/10.png"), NULL);

    if (dog == NULL || lizard == NULL || sword == NULL || katana == NULL
        || bigsword == NULL)
        exit(84);
    armor->items[5] = my_set_sprite(sword, (sfVector2f) {0, 0},
        (sfVector2f) {1.8, 1.8}, 45);
    armor->items[6] = my_set_sprite(katana, (sfVector2f) {0, 0},
        (sfVector2f) {1.8, 1.8}, 45);
    set_sprite_items(armor, dog, lizard, bigsword);
}

static armor_t *create_armor_section(rpg_t *rpg, assets_t *assets)
{
    armor_t *armor = malloc(sizeof(armor_t));

    armor->slots = malloc(sizeof(button_t) * 10);
    armor->player = malloc(sizeof(button_t) * 2);
    armor->stats = malloc(sizeof(sfText *) * 4);
    armor->value = malloc(sizeof(sfText *) * 4);
    armor->items = malloc(sizeof(sfSprite *) * 10);
    set_slots(armor, assets->btn1);
    for (int i = 0; i < 4; i++) {
        armor->stats[i] = sfText_create();
        sfText_setCharacterSize(armor->stats[i], 15);
        sfText_setString(armor->stats[i], statistic[i]);
        sfText_setFillColor(armor->stats[i], sfBlack);
        sfText_setFont(armor->stats[i], assets->font);
    }
    set_items1(rpg, armor);
    set_items2(rpg, armor);
    armor->current = sfSprite_create();
    armor->temp = sfSprite_create();
    return armor;
}

inv_btn_t *create_btn(char *str, bool bin, assets_t *assets)
{
    inv_btn_t *btn = malloc(sizeof(inv_btn_t));

    btn->is_active = bin;
    btn->btn = create_escape_btn((sfVector2f) {0, 0}, assets, (sfVector2f)
        {0, 0}, str);
    return btn;
}

inventory_t *create_inventory(rpg_t *rpg)
{
    inventory_t *inv = malloc(sizeof(inventory_t));
    char *name[4] = {"YOU", "ITEMS", "QUESTS", "SETTINGS"};

    inv->is_active = false;
    inv->clock = sfClock_create();
    inv->bkgrnd = sfRectangleShape_create();
    inv->armor = create_armor_section(rpg, rpg->assets);
    inv->conso = fill_conso_item(rpg->assets, rpg);
    inv->settings = fill_settings_menu(rpg->assets);
    sfRectangleShape_setTexture(inv->bkgrnd, rpg->assets->box1, sfTrue);
    sfRectangleShape_setSize(inv->bkgrnd, (sfVector2f) {500, 280});
    inv->btn = malloc(sizeof(inv_btn_t *) * 4);
    for (int i = 0; i < 4; i++) {
        if (i == 0)
            inv->btn[i] = create_btn(name[i], true, rpg->assets);
        else
            inv->btn[i] = create_btn(name[i], false, rpg->assets);
    }
    return inv;
}
