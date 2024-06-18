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
#include "csfml.h"

//resolutions
#define LOW_MODE ((sfVideoMode) {1333, 782, 32})
#define MEDIUM_MODE ((sfVideoMode) {1600, 900, 32})
#define HIGH_MODE ((sfVideoMode) {1920, 1080, 32})

#define LOW_FM 60

typedef struct title_screen_s {
    bool is_active;
    sfText **text;
    button_t *start_btn;
    button_t *settings_btn;
    button_t *quit_btn;
} title_screen_t;

typedef struct start_menu_s {
    bool is_active;
    button_t *new_btn;
    button_t *resume_btn;
    button_t *quit_btn;
} start_menu_t;

typedef struct settings_s {
    bool is_active;
    sfText *music;
    sfText *sound;
    sfSprite *bground;
    sfSprite *soundbar;
    sfSprite *musicbar;
    sfSprite *under_music;
    sfSprite *under_sound;
    button_t *music_add;
    button_t *music_sub;
    button_t *sound_add;
    button_t *sound_sub;
    button_t **resolutions;
    button_t *quit_btn;
} settings_t;

typedef struct menu_s {
    bool is_active;
    sfMusic *music;
    sfText *game_title;
    sfSprite *background;
    title_screen_t *title;
    start_menu_t *start;
    settings_t *settings;
} menu_t;

typedef struct alphabet_s {
    bool is_selsected;
    char *answer;
    sfText *pre_text;
    int max;
    int size;
    sfClock *write_clock;
} alphabet_t;

typedef struct begin_s {
    bool is_active;
    int gender;
    sfClock *clock;
    sfTexture **textures;
    sfSprite **sprites;
    button_t **genders;
    button_t *name_bar;
    button_t *validate;
    sfText *name;
    alphabet_t *alpha;
} begin_t;
