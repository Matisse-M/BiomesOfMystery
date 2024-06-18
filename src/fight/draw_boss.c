/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** draw_fight
*/

#include "rpg.h"
#include <string.h>

void draw_frog(rpg_t *rpg)
{
    if (rpg->boss->frog == true) {
        sfRenderWindow_drawSprite(rpg->game->window, rpg->boss->s_frog, NULL);
        if (rpg->characters->main->position.x < 110 && (
            rpg->characters->main->position.y >= 0 &&
            rpg->characters->main->position.y <= 350)) {
            rpg->fight->e_active = 11;
            rpg->fight->is_active = true;
        }
    }
    if (rpg->boss->frog == false)
        rpg->quests->discovery[4]->is_discovered = true;
    if (rpg->quests->discovery[0]->is_discovered == true &&
        rpg->quests->discovery[1]->is_discovered == true &&
        rpg->quests->discovery[2]->is_discovered == true &&
        rpg->quests->discovery[3]->is_discovered == true &&
        rpg->quests->discovery[4]->is_discovered == true)
        rpg->quests->is_done = true;
    find_if_level_upt(rpg);
}

static void anim_pyro(mapboss_t *boss)
{
    float f = time_elapsed(boss->clock);

    if (f < 0.2) {
        sfSprite_setTextureRect(boss->s_pyro, (sfIntRect) {0, 0, 16, 16});
        return;
    }
    if (f < 0.4) {
        sfSprite_setTextureRect(boss->s_pyro, (sfIntRect) {0, 16, 16, 16});
        return;
    }
    if (f < 0.6) {
        sfSprite_setTextureRect(boss->s_pyro, (sfIntRect) {0, 32, 16, 16});
        return;
    }
    sfSprite_setTextureRect(boss->s_pyro, (sfIntRect) {0, 48, 16, 16});
    if (f >= 0.8)
        sfClock_restart(boss->clock);
}

void draw_pyro(rpg_t *rpg)
{
    if (rpg->boss->pyro == true) {
        anim_pyro(rpg->boss);
        sfRenderWindow_drawSprite(rpg->game->window, rpg->boss->s_pyro, NULL);
        if ((rpg->characters->main->position.x >= 0 &&
            rpg->characters->main->position.x <= 80) && (
            rpg->characters->main->position.y >= 20 &&
            rpg->characters->main->position.y <= 60)) {
            rpg->fight->e_active = 12;
            rpg->fight->is_active = true;
        }
    }
}

static void anim_cryo(mapboss_t *boss)
{
    float f = time_elapsed(boss->clock);

    if (f < 0.2) {
        sfSprite_setTextureRect(boss->s_cryo, (sfIntRect) {0, 48, 16, 16});
        return;
    }
    if (f < 0.4) {
        sfSprite_setTextureRect(boss->s_cryo, (sfIntRect) {0, 32, 16, 16});
        return;
    }
    if (f < 0.6) {
        sfSprite_setTextureRect(boss->s_cryo, (sfIntRect) {0, 16, 16, 16});
        return;
    }
    sfSprite_setTextureRect(boss->s_cryo, (sfIntRect) {0, 0, 16, 16});
    if (f >= 0.8)
        sfClock_restart(boss->clock);
}

void draw_cryo(rpg_t *rpg)
{
    if (rpg->boss->cryo == true) {
        anim_cryo(rpg->boss);
        sfRenderWindow_drawSprite(rpg->game->window, rpg->boss->s_cryo, NULL);
        if ((rpg->characters->main->position.x >= 100 &&
            rpg->characters->main->position.x <= 150) && (
            rpg->characters->main->position.y >= 20 &&
            rpg->characters->main->position.y <= 60)) {
            rpg->fight->e_active = 13;
            rpg->fight->is_active = true;
        }
    }
}

static void anim_cyclop(mapboss_t *boss)
{
    float f = time_elapsed(boss->clock);

    if (f < 0.2) {
        sfSprite_setTextureRect(boss->s_cyclop, (sfIntRect) {16, 0, 16, 16});
        return;
    }
    if (f < 0.4) {
        sfSprite_setTextureRect(boss->s_cyclop, (sfIntRect) {16, 16, 16, 16});
        return;
    }
    if (f < 0.6) {
        sfSprite_setTextureRect(boss->s_cyclop, (sfIntRect) {16, 32, 16, 16});
        return;
    }
    sfSprite_setTextureRect(boss->s_cyclop, (sfIntRect) {16, 48, 16, 16});
    if (f >= 0.8)
        sfClock_restart(boss->clock);
}

void draw_cyclop(rpg_t *rpg)
{
    if (rpg->boss->cyclop == true) {
        anim_cyclop(rpg->boss);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->boss->s_cyclop, NULL);
        if ((rpg->characters->main->position.x >= 765 &&
            rpg->characters->main->position.x <= 825) && (
            rpg->characters->main->position.y >= 650 &&
            rpg->characters->main->position.y <= 700)) {
            rpg->fight->e_active = 14;
            rpg->fight->is_active = true;
        }
    }
}

void draw_rajah(rpg_t *rpg)
{
    if (rpg->boss->rajah == true) {
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->boss->s_rajah, NULL);
        if ((rpg->characters->main->position.x >= 0 &&
            rpg->characters->main->position.x <= 250) && (
            rpg->characters->main->position.y >= 495 &&
            rpg->characters->main->position.y <= 530)) {
            music_fight(rpg);
            rpg->fight->e_active = 15;
            rpg->fight->is_active = true;
            rpg->fight->music = true;
        }
    }
}
