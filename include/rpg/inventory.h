/*
** EPITECH PROJECT, 2023
** inventory
** File description:
** Header to prepare inventory
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "rpg.h"

typedef struct armor_s {
    button_t **slots;
    button_t **player;
    sfSprite **items;
    sfSprite *current;
    sfSprite *temp;
    sfText **stats;
    sfText **value;
    bool *get_item;
} armor_t;

typedef struct secret_s {
    sfText *name;
    sfText *qty;
    sfSprite *sprite;
    sfRectangleShape *btn;
    bool unlock;
} secret_t;

typedef struct conso_list_s {
    bool is_active;
    sfSprite *sprite;
    sfText *name;
    sfText *qty;
    sfText *desc;
    button_t *btn;
    void (*func)(main_player_t *main);
} conso_list_t;

typedef struct conso_s {
    sfClock *clock;
    sfText *money;
    sfText *stock;
    button_t *rect_use;
    sfTexture *t_bag;
    sfSprite *bag;
    sfSprite *piece;
    sfTexture *t_piece;
    sfRectangleShape *chatbox;
    conso_list_t **conso;
    secret_t **secret;
} conso_t;

typedef struct sett_s {
    sfSprite *soundbar;
    sfSprite *musicbar;
    sfSprite *under_music;
    sfSprite *under_sound;
    button_t *music_add;
    button_t *music_sub;
    button_t *sound_add;
    button_t *sound_sub;
    button_t **resolutions;
    button_t *save;
    button_t *exit;
    button_t *resume;
    sfText *music;
    sfText *sound;
} sett_t;

typedef struct inv_btn_s {
    bool is_active;
    bool is_discovered;
    int id;
    button_t *btn;
} inv_btn_t;

typedef struct inventory_s {
    bool is_active;
    inv_btn_t **btn;
    sfClock *clock;
    sfRectangleShape *bkgrnd;
    armor_t *armor;
    conso_t *conso;
    sett_t *settings;
} inventory_t;
