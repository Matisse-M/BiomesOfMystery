/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** anim
*/


#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>


#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_

    #define NUM_RAIN 60
    #define NUM_PUDDLE 40
    #define NUM_LEAVES 50

typedef struct anim_s {
    bool is_init;
    sfClock* clock;
    float totalTime;
    sfTexture *texture_rain;
    sfSprite *rain[NUM_RAIN];
    float frameChangeInterval;
    float elapsedTimes[NUM_RAIN];
    float elapsedTimespudlle[NUM_PUDDLE];
    float dt;
    sfVector2f movement;
    sfSprite *pudlle[NUM_PUDDLE];
    sfTexture *texture_puddle;
    float frame_rain;
} anim_t;

typedef struct animations_s {
    anim_t *rain_anim;
    float totalTime;
    sfClock* clock;
    sfTexture *texture;
    sfSprite *sprite[NUM_LEAVES];
    float frameChangeInterval;
    float elapsedTimes[NUM_LEAVES];
    float dt;
    float swayAmplitude;
    float swaySpeed;
    float swayMovement;
    sfVector2f movement;
    bool created;
} animations_t;

#endif /* !ANIMATIONS_H_ */
