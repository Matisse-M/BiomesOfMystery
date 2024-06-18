/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "csfml.h"

static void setup_pig1(rpg_t *rpg, sfTexture *t1, sfTexture *t2)
{
    rpg->pig->pig_s[0] = sfRectangleShape_create();
    sfRectangleShape_setTexture(rpg->pig->pig_s[0], t1, sfTrue);
    sfRectangleShape_setSize(rpg->pig->pig_s[0], (sfVector2f) {32, 16});
    sfRectangleShape_setPosition(rpg->pig->pig_s[0], (sfVector2f) {700, 420});
    rpg->pig->rpig_s[0] = sfRectangleShape_create();
    sfRectangleShape_setTexture(rpg->pig->rpig_s[0], t2, sfTrue);
    sfRectangleShape_setSize(rpg->pig->rpig_s[0], (sfVector2f) {32, 16});
    sfRectangleShape_setPosition(rpg->pig->rpig_s[0], (sfVector2f) {300, 420});
}

static void setup_pig2(rpg_t *rpg, sfTexture *t1, sfTexture *t2)
{
    rpg->pig->pig_s[1] = sfRectangleShape_create();
    sfRectangleShape_setTexture(rpg->pig->pig_s[1], t1, sfTrue);
    sfRectangleShape_setSize(rpg->pig->pig_s[1], (sfVector2f) {32, 16});
    sfRectangleShape_setPosition(rpg->pig->pig_s[1], (sfVector2f) {208, 200});
    rpg->pig->rpig_s[1] = sfRectangleShape_create();
    sfRectangleShape_setTexture(rpg->pig->rpig_s[1], t2, sfTrue);
    sfRectangleShape_setSize(rpg->pig->rpig_s[1], (sfVector2f) {32, 16});
    sfRectangleShape_setPosition(rpg->pig->rpig_s[1], (sfVector2f) {208, 320});
}

static void setup_pig3(rpg_t *rpg, sfTexture *t1)
{
    rpg->pig->pig_s[2] = sfRectangleShape_create();
    sfRectangleShape_setTexture(rpg->pig->pig_s[2], t1, sfTrue);
    sfRectangleShape_setTextureRect(rpg->pig->pig_s[2],
        (sfIntRect) {0, 0, 16, 16});
    sfRectangleShape_setSize(rpg->pig->pig_s[2], (sfVector2f) {16, 16});
    sfRectangleShape_setPosition(rpg->pig->pig_s[2], (sfVector2f) {223, 52});
}

void setup_piggies(rpg_t *rpg)
{
    sfTexture *texture = sfTexture_createFromFile(my_scat(
        rpg->name, "/img/pig.png"), NULL);
    sfTexture *texture2 = sfTexture_createFromFile(my_scat(
        rpg->name, "/img/pig_r.png"), NULL);

    if (!texture && !texture2)
        exit(84);
    rpg->pig = malloc(sizeof(pig_t));
    rpg->pig->complete = false;
    rpg->pig->is_active = false;
    rpg->pig->left = true;
    rpg->pig->found[0] = 0;
    rpg->pig->found[1] = 0;
    rpg->pig->found[2] = 0;
    rpg->pig->clock = sfClock_create();
    setup_pig1(rpg, texture, texture2);
    setup_pig2(rpg, texture, texture2);
    setup_pig3(rpg, texture);
}
