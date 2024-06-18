/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** draw_boss_anim
*/

#include "rpg.h"

static void draw_rajah_hit(rpg_t *rpg, sfVector2f center)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(rpg->fight->clock))
        > 100) {
        sfClock_restart(rpg->fight->clock);
        sfSprite_setTextureRect(rpg->fight->e_hit[4],
            (sfIntRect) {48 * ((rand() % 4) + 1), 0, 48, 48});
    }
    sfSprite_setPosition(rpg->fight->e_hit[4],
        (sfVector2f) {center.x - 35, center.y - 110});
    sfRenderWindow_drawSprite(rpg->game->window, rpg->fight->e_hit[4], NULL);
}

static void draw_hit(sfRenderWindow *win, sfClock *clock, sfVector2f center,
    fight_t *fight)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 100) {
        sfClock_restart(clock);
        if (fight->e_active == 11)
            sfSprite_setTextureRect(fight->e_hit[fight->e_active - 11],
                (sfIntRect) {40 * (rand() % 3), 0, 40, 40});
        else
            sfSprite_setTextureRect(fight->e_hit[fight->e_active - 11],
                (sfIntRect) {50 * (rand() % 3), 0, 50, 50});
    }
    if (fight->e_active == 11)
        sfSprite_setPosition(fight->e_hit[fight->e_active - 11],
            (sfVector2f) {center.x - 40, center.y - 110});
    else
        sfSprite_setPosition(fight->e_hit[fight->e_active - 11],
            (sfVector2f) {center.x - 45, center.y - 115});
    sfRenderWindow_drawSprite(win, fight->e_hit[fight->e_active - 11], NULL);
}

static void draw_idle(sfRenderWindow *win, fight_t *fight, enemy_t *enemy,
    sfVector2f center)
{
    if (fight->state == 1)
        fight->state = 0;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(enemy->clock)) > 100) {
        sfClock_restart(enemy->clock);
        if (fight->e_active == 11)
            sfSprite_setTextureRect(enemy->sprite,
                (sfIntRect) {40 * (rand() % 5), 0, 40, 40});
        else
            sfSprite_setTextureRect(enemy->sprite,
                (sfIntRect) {50 * (rand() % 5), 0, 50, 50});
    }
    if (fight->e_active == 11)
        sfSprite_setPosition(enemy->sprite, (sfVector2f) {center.x - 40,
            center.y - 110});
    else
        sfSprite_setPosition(enemy->sprite, (sfVector2f) {center.x - 45,
            center.y - 115});
    sfSprite_setPosition(enemy->sprite,
        (sfVector2f) {center.x - 40, center.y - 110});
    sfRenderWindow_drawSprite(win, enemy->sprite, NULL);
}

static void draw_rajah_idle(rpg_t *rpg, fight_t *fight, sfVector2f center)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(fight->enemy[14]->clock))
        > 100) {
        sfClock_restart(fight->enemy[14]->clock);
        sfSprite_setTextureRect(fight->enemy[14]->sprite,
            (sfIntRect) {48 * (rand() % 6), 0, 48, 48});
    }
    sfSprite_setPosition(fight->enemy[14]->sprite, (sfVector2f) {center.x - 35,
        center.y - 110});
    sfRenderWindow_drawSprite(rpg->game->window,
        fight->enemy[14]->sprite, NULL);
}

void draw_boss(rpg_t *rpg, enemy_t *enemy, sfVector2f center)
{
    if (rpg->fight->state == 1 && time_elapsed(rpg->fight->anim) < 1) {
        if (rpg->fight->e_active != 15)
            draw_hit(rpg->game->window, enemy->clock, center, rpg->fight);
        else
            draw_rajah_hit(rpg, center);
    } else {
        if (rpg->fight->e_active != 15) {
            draw_idle(rpg->game->window, rpg->fight, enemy, center);
        } else {
            draw_rajah_idle(rpg, rpg->fight, center);
        }
    }
}
