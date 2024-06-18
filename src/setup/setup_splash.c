/*
** EPITECH PROJECT, 2024
** crpg
** File description:
** setup_splash
*/

#include "rpg.h"

splash_t *init_splash_screen(rpg_t *rpg)
{
    splash_t *s = malloc(sizeof(splash_t));
    sfVector2u size = sfTexture_getSize(rpg->assets->splash);

    s->scale = 0.1f;
    s->sprite = sfSprite_create();
    sfSprite_setTexture(s->sprite, rpg->assets->splash, sfTrue);
    sfSprite_setPosition(s->sprite, (sfVector2f) {770, 420});
    sfSprite_setOrigin(s->sprite, (sfVector2f) {size.x / 2.f, size.y / 2.f});
    s->splash_active = true;
    s->splash_clock = sfClock_create();
    s->delay_clock = sfClock_create();
    s->clock = sfClock_create();
    return s;
}

void render(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->game->window, sfBlack);
    sfSprite_setScale(rpg->splash->sprite, (sfVector2f) {rpg->splash->scale,
        rpg->splash->scale});
    sfRenderWindow_drawSprite(rpg->game->window, rpg->splash->sprite, NULL);
    sfRenderWindow_display(rpg->game->window);
}

void zoom_in(rpg_t *rpg, sfClock* clock)
{
    sfTime elapsedTime;

    rpg->splash->scale += 0.02f;
    render(rpg);
    elapsedTime = sfClock_getElapsedTime(clock);
    while (sfTime_asMilliseconds(elapsedTime) < 30)
        elapsedTime = sfClock_getElapsedTime(clock);
    sfClock_restart(clock);
}

void preload_splash_screen(rpg_t *rpg, sfClock *clock)
{
    if (rpg->splash->scale < 2.38f)
        zoom_in(rpg, clock);
    else {
        rpg->splash->splash_active = false;
        sfClock_restart(clock);
    }
}
