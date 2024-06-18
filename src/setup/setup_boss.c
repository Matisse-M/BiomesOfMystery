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

static void create_frog(mapboss_t *boss, sfTexture *texture)
{
    boss->monkey = true;
    boss->dog = true;
    boss->clock = sfClock_create();
    boss->frog = true;
    boss->s_frog = sfSprite_create();
    sfSprite_setTexture(boss->s_frog, texture, sfTrue);
    sfSprite_setScale(boss->s_frog, (sfVector2f) {3, 3});
    sfSprite_setPosition(boss->s_frog, (sfVector2f) {70, 275});
}

static void create_pyro(mapboss_t *boss, sfTexture *texture)
{
    boss->pyro = true;
    boss->s_pyro = sfSprite_create();
    sfSprite_setTexture(boss->s_pyro, texture, sfTrue);
    sfSprite_setScale(boss->s_pyro, (sfVector2f) {3, 3});
    sfSprite_setPosition(boss->s_pyro, (sfVector2f) {35, 10});
}

static void create_cryo(mapboss_t *boss, sfTexture *texture)
{
    boss->cryo = true;
    boss->s_cryo = sfSprite_create();
    sfSprite_setTexture(boss->s_cryo, texture, sfTrue);
    sfSprite_setScale(boss->s_cryo, (sfVector2f) {3, 3});
    sfSprite_setPosition(boss->s_cryo, (sfVector2f) {110, 10});
}

static void create_cyclop(mapboss_t *boss, sfTexture *texture)
{
    boss->cyclop = true;
    boss->s_cyclop = sfSprite_create();
    sfSprite_setTexture(boss->s_cyclop, texture, sfTrue);
    sfSprite_setScale(boss->s_cyclop, (sfVector2f) {3, 3});
    sfSprite_setPosition(boss->s_cyclop, (sfVector2f) {775, 650});
}

static void create_rajah(rpg_t *rpg, mapboss_t *boss)
{
    sfTexture *texture = sfTexture_createFromFile(my_scat(rpg->name,
        "/img/rajah.png"), NULL);

    boss->rajah = true;
    boss->s_rajah = sfSprite_create();
    sfSprite_setTexture(boss->s_rajah, texture, sfTrue);
    sfSprite_setScale(boss->s_rajah, (sfVector2f) {1, 1});
    sfSprite_setPosition(boss->s_rajah, (sfVector2f) {170, 500});
}

mapboss_t *fill_mapboss(rpg_t *rpg)
{
    mapboss_t *boss = malloc(sizeof(mapboss_t));
    sfTexture *froggy = sfTexture_createFromFile(my_scat(rpg->name,
        "/img/frog.png"), NULL);
    sfTexture *pierre = sfTexture_createFromFile(my_scat(rpg->name,
        "/img/pyro.png"), NULL);
    sfTexture *cris = sfTexture_createFromFile(my_scat(rpg->name,
        "/img/cryo.png"), NULL);
    sfTexture *clope = sfTexture_createFromFile(my_scat(rpg->name,
        "/img/cyclop.png"), NULL);

    if (!froggy || !pierre || !cris || !clope)
        exit(84);
    boss->clock = sfClock_create();
    create_frog(boss, froggy);
    create_pyro(boss, pierre);
    create_cryo(boss, cris);
    create_cyclop(boss, clope);
    create_rajah(rpg, boss);
    return boss;
}
