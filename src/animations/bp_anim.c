/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** swamp_anim
*/

#include "rpg.h"

void init_sprite(rpg_t *rpg, animations_t *anim)
{
    sfVector2f scale = {1.0f, 1.0f};

    rpg->anim->totalTime = 0;
    for (int i = 0; i < NUM_LEAVES; i++) {
        anim->sprite[i] = sfSprite_create();
        sfSprite_setTexture(anim->sprite[i], anim->texture, sfTrue);
        sfSprite_setTextureRect(anim->sprite[i], (sfIntRect){0, 0, 12, 7});
        sfSprite_setPosition(anim->sprite[i],
            (sfVector2f){(float)(rand() % 800), (float)(-rand() % 800)});
    }
    anim->frameChangeInterval = 0.2f;
    for (int i = 0; i < NUM_LEAVES; i++)
        sfSprite_setScale(anim->sprite[i], scale);
}

void move_frame(animations_t *anim, int i, sfColor color)
{
    sfIntRect rect = sfSprite_getTextureRect(anim->sprite[i]);

    rect.left += rect.width;
    if (rect.left == 60) {
        color.a -= 100;
        sfSprite_setColor(anim->sprite[i], color);
    }
    if (rect.left == 72) {
        color.a -= 20;
        rect.left = 0;
        sfSprite_setColor(anim->sprite[i], color);
    }
    sfSprite_setTextureRect(anim->sprite[i], rect);
    anim->elapsedTimes[i] -= anim->frameChangeInterval;
}

void anim_leaves(animations_t *anim)
{
    sfColor color = sfWhite;

    for (int i = 0; i < NUM_LEAVES; i++)
        sfSprite_move(anim->sprite[i],
            (sfVector2f){anim->swayMovement, 5.f * anim->dt});
    for (int i = 0; i < NUM_LEAVES; i++) {
        anim->elapsedTimes[i] += anim->dt;
        color = sfSprite_getColor(anim->sprite[i]);
        if (anim->elapsedTimes[i] >= anim->frameChangeInterval) {
            move_frame(anim, i, color);
        }
    }
}

void init_anim(rpg_t *rpg, animations_t *anim)
{
    anim->dt = sfClock_restart(anim->clock).microseconds / 1000000.0f;
    anim->totalTime += anim->dt;
    anim->swayAmplitude = 1.5;
    anim->swaySpeed = 2;
    anim->swayMovement =
        sin(anim->totalTime * anim->swaySpeed) * anim->swayAmplitude;
    anim_leaves(anim);
    for (int i = 0; i < NUM_LEAVES; ++i)
        sfRenderWindow_drawSprite(rpg->game->window, anim->sprite[i], NULL);
}
