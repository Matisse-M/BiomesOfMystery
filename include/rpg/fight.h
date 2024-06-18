/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** fight
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>

// enemies sprites
#define SLIME_SP "/enemies/Slime_SpriteSheet.png"
#define MOLE_SP "/enemies/Mole_SpriteSheet.png"
#define LARVA_SP "/enemies/Larva_SpriteSheet.png"
#define SHROOM_SP "/enemies/Shrooms_SpriteSheet.png"
#define BAMBOO_SP "/enemies/Bamboo_SpriteSheet.png"
#define FIRE_SP "/enemies/Flame_SpriteSheet.png"
#define ICE_SP "/enemies/Ice_SpriteSheet.png"
#define SKULL_SP "/enemies/Skull_SpriteSheet.png"
#define EYE_SP "/enemies/Eye_SpriteSheet.png"
#define BLOB_SP "/enemies/Blob_SpriteSheet.png"
#define FROG_SP "/enemies/Frog_SpriteSheet.png"
#define BFIRE_SP "/enemies/BFlame_SpriteSheet.png"
#define BICE_SP "/enemies/BIce_SpriteSheet.png"
#define CYCLOP_SP "/enemies/Cyclop_SpriteSheet.png"
#define RAJAH_SP "/enemies/Rajah_SpriteSheet.png"

// attacked animations for the bosses
#define FROG_HIT "/enemies/Frog_Hit.png"
#define BFIRE_HIT "/enemies/BFlame_Hit.png"
#define BICE_HIT "/enemies/BIce_Hit.png"
#define CYCLOP_HIT "/enemies/Cyclop_Hit.png"
#define RAJAH_HIT "/enemies/Rajah_Hit.png"

// frog attack
#define FROG_ATTACK "/enemies/Frog_Attack.png"

// fight spells
#define FIRE_SPELL "/enemies/Fire_Spell.png"
#define ICE_SPELL "/enemies/Ice_Spell.png"
#define STONE_SPELL "/enemies/Stone_Spell.png"

typedef struct items_fight_s {
    bool is_active;
    int current;
    button_t *quit;
    button_t *items[10];
    sfSprite *asset[10];
    sfText *name[10];
    button_t *next;
    button_t *prev;
} items_fight_t;

typedef struct scroll_s {
    bool is_active;
    button_t *quit;
    button_t *btn[3];
    sfSprite *scroll[3];
} scroll_t;

typedef struct enemy_s {
    int lvl;
    int hp;
    int hp_max;
    int exp;
    int atk;
    char *name;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfMusic *music;
    sfSound **sound;
} enemy_t;

typedef struct fight_s {
    bool is_active;                 // fight is active
    bool stone;                     // stone spell is enabled
    bool ice;                       // ice spell is enabled
    bool fire;                      // fire spell is enabled
    bool music;                     // active music
    int life2;                      // pet's life
    sfClock *clock;                 // clock for the fight
    sfClock *trig_clock;            // clock for the fight trigerring
    button_t **btn;                 // buttons for the fight
    sfRectangleShape *bg;           // swamp background for the fight
    sfRectangleShape *bbg;          // dungeon background for the fight
    sfRectangleShape *menu;         // menu for the fight
    sfRectangleShape *player_box;   // player's box for the fight
    sfRectangleShape *enemy_box;    // enemy's box for the fight
    sfSprite *player_life[2];       // player's lifebar for the fight
    sfSprite *enemy_life[2];        // enemy's lifebar for the fight
    sfSprite *animal_life;          // pet's lifebar for the fight
    sfSprite *e_hit[5];             // enemy's attacked animation
    sfSprite *frog_attack;          // frog's attack animation
    int state;                      // fight state
    sfClock *anim;                  // animation clock
    enemy_t **enemy;                // enemies for the fight
    sfText *player_hp;              // player's hp for the fight
    sfText *enemy_hp;               // enemy's hp for the fight
    int e_active;                   // active enemy
    items_fight_t *items;           // items for the fight
    scroll_t *scrolls;              // scrolls for the fight
    sfSprite *scroll;               // scrolls' animations
    sfText *end_msg;                // end message for the fight
    sfText *lvl_up;                 // level up message for the fight
    int exp_won;                    // exp won for the fight
} fight_t;
