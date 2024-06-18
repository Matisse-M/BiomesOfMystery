/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** swamp_anims
*/

#include "rpg.h"

static void init_puddle(anim_t *anim, rpg_t *rpg, sfVector2f scale,
    sfVector2u windowSize)
{
    anim->frameChangeInterval = 0.1f;
    anim->frame_rain = 0.2f;
    for (int i = 0; i < NUM_RAIN; ++i)
        sfSprite_setScale(anim->rain[i], scale);
    for (int i = 0; i < NUM_PUDDLE; ++i) {
        anim->pudlle[i] = sfSprite_create();
        sfSprite_setTexture(anim->pudlle[i], anim->texture_puddle, sfTrue);
        sfSprite_setTextureRect(anim->pudlle[i], (sfIntRect){0, 0, 8, 8});
        sfSprite_setPosition(anim->pudlle[i], (sfVector2f){(float)(rand()
            % windowSize.x), (float)(rand() % windowSize.y)});
    }
    for (int i = 0; i < NUM_PUDDLE; ++i)
        sfSprite_setScale(anim->pudlle[i], scale);
}

void init_rain(anim_t *anim, rpg_t *rpg)
{
    sfVector2f scale = {1.5f, 1.5f};
    sfVector2u windowSize = sfRenderWindow_getSize(rpg->game->window);

    for (int i = 0; i < NUM_RAIN; ++i) {
        anim->rain[i] = sfSprite_create();
        sfSprite_setTexture(anim->rain[i], anim->texture_rain, sfTrue);
        sfSprite_setTextureRect(anim->rain[i], (sfIntRect){0, 0, 8, 8});
        sfSprite_setPosition(anim->rain[i], (sfVector2f){(float)(rand()
            % 800), (float)(rand() % 900)});
    }
    init_puddle(anim, rpg, scale, windowSize);
}

static void move_rain(anim_t *anim, int i, sfVector2u windowSize)
{
    sfVector2f position = sfSprite_getPosition(anim->rain[i]);
    sfIntRect rect = sfSprite_getTextureRect(anim->rain[i]);

    if (position.y >= windowSize.y) {
        sfSprite_setPosition(anim->rain[i], (sfVector2f){(float)(rand() %
            800), (float)(rand() % 900)});
    }
    anim->elapsedTimes[i] += anim->dt;
    if (anim->elapsedTimes[i] >= anim->frameChangeInterval) {
        rect.left += rect.width;
        if (rect.left == 24)
            rect.left = 0;
        sfSprite_setTextureRect(anim->rain[i], rect);
        anim->elapsedTimes[i] -= anim->frameChangeInterval;
    }
}

static void move_puddle(anim_t *anim, int i, sfVector2u windowSize)
{
    sfVector2f position = sfSprite_getPosition(anim->rain[i]);
    sfIntRect rect_rain = sfSprite_getTextureRect(anim->pudlle[i]);

    if (position.y >= windowSize.y)
        sfSprite_setPosition(anim->pudlle[i], (sfVector2f){(float)(rand() %
        windowSize.x), (float)(rand() % windowSize.y)});
    anim->elapsedTimespudlle[i] += anim->dt;
    if (anim->elapsedTimespudlle[i] >= anim->frame_rain) {
        rect_rain.left += rect_rain.width;
        if (rect_rain.left >= 24) {
            sfSprite_setPosition(anim->pudlle[i], (sfVector2f){(float)(rand() %
            windowSize.x + 200), (float)(rand() % windowSize.y + 200)});
            rect_rain.left = 0;
        }
        sfSprite_setTextureRect(anim->pudlle[i], rect_rain);
        anim->elapsedTimespudlle[i] -= anim->frame_rain;
    }
}

void anim_rain(anim_t *anim, rpg_t *rpg)
{
    sfVector2u windowSize = sfRenderWindow_getSize(rpg->game->window);

    for (int i = 0; i < NUM_RAIN; i++)
        sfSprite_move(anim->rain[i], (sfVector2f) {0, 600.f * anim->dt});
    for (int i = 0; i < NUM_RAIN; i++)
        move_rain(anim, i, windowSize);
}

void update_rain(anim_t *anim, rpg_t *rpg)
{
    anim_rain(anim, rpg);
    for (int i = 0; i < NUM_RAIN; ++i)
        sfRenderWindow_drawSprite(rpg->game->window, anim->rain[i], NULL);
}

void updtate_pudlle(anim_t *anim, rpg_t *rpg)
{
    sfVector2u windowSize = sfRenderWindow_getSize(rpg->game->window);

    anim->dt = sfClock_restart(anim->clock).microseconds / 1000000.0f;
    anim->totalTime += anim->dt;
    for (int i = 0; i < NUM_PUDDLE; i++)
        move_puddle(anim, i, windowSize);
    for (int i = 0; i < NUM_PUDDLE; ++i)
        sfRenderWindow_drawSprite(rpg->game->window, anim->pudlle[i], NULL);
}
    //sfRenderWindow_clear(rpg->game->window, sfBlack);
