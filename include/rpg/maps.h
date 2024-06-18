/*
** EPITECH PROJECT, 2023
** player
** File description:
** Header to prepare players
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct pnjs_s {
    sfTexture **texture;
    sfSprite **sprite;
    sfTexture *box_texture;
    sfSprite *box_sprite;
    sfVector2f **position;
    bool is_active;
    bool can_interact;
    bool is_print;
    sfText *name;
    int count_line;
    sfText *text;
    char **lines;
    int i;
    int line_count;
} pnjs_t;


typedef struct dialog_player_s {
    bool can_interact;
    bool is_print;
    bool is_active;
    bool talked;
    sfTexture *faces_texture;
    sfSprite *faces_sprite;
    char **array;
    float x_min;
    float y_min;
    float x_max;
    float y_max;
    int line_count;
    int count_line;
    int i;
    sfText *text;
    sfText *name;
} dialog_player_t;


typedef struct shop_s {
    bool can_interact_shop;
    bool shop_active;
    bool can_interact_skill;
    bool skill_active;
} shop_t;

typedef struct dialogue_s {
    dialog_player_t *aymeric;
    dialog_player_t *kid_bp;
    dialog_player_t *old_bp;
    dialog_player_t *dungeon_old;
    dialog_player_t *museum_blue;
    dialog_player_t *museum_red;
    dialog_player_t *museum_satue;
    dialog_player_t *plage_ninja;
    dialog_player_t *plage_kid;
    dialog_player_t *plage_old;
    dialog_player_t *plage_woman;
    dialog_player_t *swamp_frog;
    dialog_player_t *martin;
    dialog_player_t *chat;
    dialog_player_t *cow;
    shop_t *shop;
} dialogue_t;


typedef struct room_s {
    bool is_active;
    bool unlock;
    sfFloatRect area;
    sfTexture **texture;
    sfSprite **sprite;
    sfImage *under;
    pnjs_t *pnj_mat;
    bool is_trans;
    float duration;
    sfClock *clock;
    sfTime time;
    float deltaTime;
    sfVector2f originalSize;
} room_t;

typedef struct key_inter_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    bool e_relased;
    bool enter;
    sfClock *clock_e;
    sfClock *clock_enter;
} key_inter_t;

typedef struct maps_s {
    int num;
    bool is_trans;
    bool is_active;
    key_inter_t *inter;
    sfImage *under;
    sfVector2f center;
    room_t *museum;
    room_t *downstairs;
    room_t *upstairs;
    room_t *swamp;
    room_t *beach;
    room_t *village;
    room_t *dungeon;
    room_t *snow;
    room_t *kamar;
    room_t *food_shop;
    room_t *house;
    room_t *bathroom;
    room_t *weapon_shop;
    room_t *maze;
    room_t *grotte;
} maps_t;
