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

typedef struct main_player_s {
    bool critical;
    bool boost;
    bool ricochets;
    bool sustain;
    int hp;
    int hp_max;
    int weapon;
    char *name;
    unsigned int lvl;
    unsigned int exp;
    int atk;
    int bag;
    unsigned int emo;
    unsigned int money;
    unsigned int direction;
    sfVector2f position;
    sfTexture **texture;
    sfSprite *sprite;
    sfSprite *face;
    sfSound **sound;
} main_player_t;

typedef struct pnj_s {
    char *name;
    char **speech;
    sfVector2f position;
    sfTexture *texture;
    sfSprite *sprite;
    struct pnj_s *next;
} pnj_t;

typedef struct characters_s {
    main_player_t *main;
    pnj_t *pnj;
} characters_t;

// functions from ./src/player
main_player_t *fill_main_player(void);
