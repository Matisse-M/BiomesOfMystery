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

static void check_pig_area(rpg_t *rpg, int x)
{
    sfFloatRect rec = sfRectangleShape_getGlobalBounds(rpg->pig->pig_s[x]);

    if (sfFloatRect_contains(&rec, rpg->characters->main->position.x + 13,
        rpg->characters->main->position.y + 13))
        rpg->pig->found[x] = 1;
    if (rpg->pig->found[0] == 1 && rpg->pig->found[1] == 1 &&
        rpg->pig->found[2] == 1)
        rpg->inv->conso->secret[1]->unlock = true;
}

static void check_rpig_area(rpg_t *rpg, int x)
{
    sfFloatRect rec = sfRectangleShape_getGlobalBounds(rpg->pig->rpig_s[x]);

    if (sfFloatRect_contains(&rec, rpg->characters->main->position.x + 13,
        rpg->characters->main->position.y + 13))
        rpg->pig->found[x] = 1;
    if (rpg->pig->found[0] == 1 && rpg->pig->found[1] == 1 &&
        rpg->pig->found[2] == 1)
        rpg->inv->conso->secret[1]->unlock = true;
}

static void anim_pig1(pig_t *pig, sfRectangleShape *rect)
{
    sfVector2f pos = sfRectangleShape_getPosition(rect);
    float f = time_elapsed(pig->clock);

    if (f < 0.2) {
        sfRectangleShape_setPosition(rect, (sfVector2f) {pos.x - 1, pos.y});
        sfRectangleShape_setTextureRect(rect, (sfIntRect) {0, 0, 16, 16});
        sfRectangleShape_setSize(rect, (sfVector2f) {16, 16});
        return;
    }
    sfRectangleShape_setPosition(rect, (sfVector2f) {pos.x - 1, pos.y});
    sfRectangleShape_setTextureRect(rect, (sfIntRect) {16, 0, 16, 16});
    sfRectangleShape_setSize(rect, (sfVector2f) {16, 16});
    if (pos.x <= 300)
        pig->left = false;
    if (f >= 0.4)
        sfClock_restart(pig->clock);
}

static void anim_pig2(pig_t *pig, sfRectangleShape *rect)
{
    sfVector2f pos = sfRectangleShape_getPosition(rect);
    float f = time_elapsed(pig->clock);

    if (f < 0.2) {
        sfRectangleShape_setPosition(rect, (sfVector2f) {pos.x + 1, pos.y});
        sfRectangleShape_setTextureRect(rect, (sfIntRect) {0, 0, 16, 16});
        sfRectangleShape_setSize(rect, (sfVector2f) {16, 16});
        return;
    }
    sfRectangleShape_setPosition(rect, (sfVector2f) {pos.x + 1, pos.y});
    sfRectangleShape_setTextureRect(rect, (sfIntRect) {16, 0, 16, 16});
    sfRectangleShape_setSize(rect, (sfVector2f) {16, 16});
    if (pos.x >= 700)
        pig->left = true;
    if (f >= 0.4)
        sfClock_restart(pig->clock);
}

static void anim_pig3(pig_t *pig, sfRectangleShape *rect)
{
    sfVector2f pos = sfRectangleShape_getPosition(rect);
    float f = time_elapsed(pig->clock);

    if (f < 0.2) {
        sfRectangleShape_setPosition(rect, (sfVector2f) {pos.x, pos.y - 1});
        sfRectangleShape_setTextureRect(rect, (sfIntRect) {0, 0, 16, 16});
        sfRectangleShape_setSize(rect, (sfVector2f) {16, 16});
        return;
    }
    sfRectangleShape_setPosition(rect, (sfVector2f) {pos.x, pos.y - 1});
    sfRectangleShape_setTextureRect(rect, (sfIntRect) {16, 0, 16, 16});
    sfRectangleShape_setSize(rect, (sfVector2f) {16, 16});
    if (pos.y <= 200)
        pig->left = false;
    if (f >= 0.4)
        sfClock_restart(pig->clock);
}

static void anim_pig4(pig_t *pig, sfRectangleShape *rect)
{
    sfVector2f pos = sfRectangleShape_getPosition(rect);
    float f = time_elapsed(pig->clock);

    if (f < 0.2) {
        sfRectangleShape_setPosition(rect, (sfVector2f) {pos.x, pos.y + 1});
        sfRectangleShape_setTextureRect(rect, (sfIntRect) {0, 0, 16, 16});
        sfRectangleShape_setSize(rect, (sfVector2f) {16, 16});
        return;
    }
    sfRectangleShape_setPosition(rect, (sfVector2f) {pos.x, pos.y + 1});
    sfRectangleShape_setTextureRect(rect, (sfIntRect) {16, 0, 16, 16});
    sfRectangleShape_setSize(rect, (sfVector2f) {16, 16});
    if (pos.y >= 320)
        pig->left = true;
    if (f >= 0.4)
        sfClock_restart(pig->clock);
}

void draw_pig1(rpg_t *rpg)
{
    if (rpg->pig->is_active && rpg->pig->found[0] == 0 &&
        rpg->maps->downstairs->is_active) {
        if (rpg->pig->left == true) {
            sfRectangleShape_setPosition(rpg->pig->rpig_s[0],
                (sfVector2f) {300, 420});
            anim_pig1(rpg->pig, rpg->pig->pig_s[0]);
            check_pig_area(rpg, 0);
            sfRenderWindow_drawRectangleShape(rpg->game->window,
                rpg->pig->pig_s[0], NULL);
        } else {
            sfRectangleShape_setPosition(rpg->pig->pig_s[0],
                (sfVector2f) {700, 420});
            anim_pig2(rpg->pig, rpg->pig->rpig_s[0]);
            check_rpig_area(rpg, 0);
            sfRenderWindow_drawRectangleShape(rpg->game->window,
                rpg->pig->rpig_s[0], NULL);
        }
    }
}

void draw_pig2(rpg_t *rpg)
{
    if (rpg->pig->is_active && rpg->pig->found[1] == 0 &&
        rpg->maps->upstairs->is_active) {
        if (rpg->pig->left == true) {
            sfRectangleShape_setPosition(rpg->pig->pig_s[1],
                (sfVector2f) {208, 200});
            anim_pig3(rpg->pig, rpg->pig->rpig_s[1]);
            check_rpig_area(rpg, 1);
            sfRenderWindow_drawRectangleShape(rpg->game->window,
                rpg->pig->rpig_s[1], NULL);
        } else {
            sfRectangleShape_setPosition(rpg->pig->rpig_s[1],
                (sfVector2f) {208, 320});
            anim_pig4(rpg->pig, rpg->pig->pig_s[1]);
            check_pig_area(rpg, 1);
            sfRenderWindow_drawRectangleShape(rpg->game->window,
                rpg->pig->pig_s[1], NULL);
        }
    }
}

void draw_pig3(rpg_t *rpg)
{
    if (rpg->pig->is_active && rpg->pig->found[2] == 0 &&
        rpg->maps->beach->is_active) {
        check_pig_area(rpg, 2);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->pig->pig_s[2], NULL);
    }
}
