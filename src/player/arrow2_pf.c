/*
** EPITECH PROJECT, 2023
** moves
** File description:
** Some function to handle player moves
*/

#include <SFML/Graphics.h>
#include "rpg/player.h"
#include "rpg.h"

int select_ani(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float f = sfTime_asSeconds(time);

    if (f <= 0.2)
        return 0;
    if (f <= 0.4)
        return 17;
    if (f <= 0.6)
        return 34;
    return 51;
}

static int front_pixel_ul(rpg_t *rpg, main_player_t *player,
    sfVector2f front_pixel)
{
    sfColor front_pixel_color = sfGreen;

    front_pixel.x += 1;
    front_pixel.y += 14;
    for (int i = 0; i < 3; i++) {
        front_pixel_color = sfImage_getPixel(rpg->maps->under,
            front_pixel.x, front_pixel.y + i);
        if (front_pixel_color.r != 0)
            return 0;
    }
    front_pixel = player->position;
    front_pixel.y += 12;
    for (int i = 0; i < 16; i++) {
        front_pixel_color = sfImage_getPixel(rpg->maps->under,
            front_pixel.x + i, front_pixel.y);
        if (front_pixel_color.r != 0)
            return 0;
    }
    return 1;
}

static void move_player_left_up(sfClock *movementClock, main_player_t *player)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
        (movementClock)) >= 15) {
        player->position.x -= 0.8;
        player->position.y -= 0.8;
        player->direction = 16;
        sfSprite_setPosition(player->sprite, player->position);
        sfClock_restart(movementClock);
    }
}

int move_left_up(sfClock *clock, main_player_t *player, rpg_t *rpg)
{
    static sfClock *movementClock = NULL;
    int x = select_an(clock);
    sfVector2f front_pixel;

    if (!movementClock)
        movementClock = sfClock_create();
    if (sfKeyboard_isKeyPressed(rpg->key_board->up) &&
        !sfKeyboard_isKeyPressed(rpg->key_board->down)
        && !sfKeyboard_isKeyPressed(rpg->key_board->right)
        && sfKeyboard_isKeyPressed(rpg->key_board->left)) {
            sfSprite_setTextureRect(player->sprite, (sfIntRect)
                {16, x, 16, 16});
            front_pixel = player->position;
            if (front_pixel_ul(rpg, player, front_pixel) == 0)
                return 2;
            move_player_left_up(movementClock, player);
            return 1;
    }
    return 0;
}

static int right_down_color(rpg_t *rpg, main_player_t *player,
    sfVector2f front_pixel)
{
    sfColor front_pixel_color = sfGreen;

    front_pixel.y += 17;
    for (int i = 0; i < 15; i++) {
        front_pixel_color = sfImage_getPixel(rpg->maps->under,
            front_pixel.x + i, front_pixel.y);
        if (front_pixel_color.r != 0)
            return 0;
    }
    front_pixel = player->position;
    front_pixel.x += 17;
    front_pixel.y += 13;
    for (int i = 0; i < 3; i++) {
        front_pixel_color = sfImage_getPixel(rpg->maps->under,
            front_pixel.x, front_pixel.y + i);
        if (front_pixel_color.r != 0)
            return 0;
    }
    return 1;
}

static void move_player_rigth(sfClock *movementClock, main_player_t *player)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
        (movementClock)) >= 15) {
        player->position.x += 0.8;
        player->position.y += 0.8;
        player->direction = 0;
        sfSprite_setPosition(player->sprite, player->position);
        sfClock_restart(movementClock);
    }
}

int move_right_down(sfClock *clock, main_player_t *player, rpg_t *rpg)
{
    static sfClock *movementClock = NULL;
    int x = select_an(clock);
    sfVector2f front_pixel;

    if (!movementClock)
        movementClock = sfClock_create();
    if (!sfKeyboard_isKeyPressed(rpg->key_board->up) &&
        sfKeyboard_isKeyPressed(rpg->key_board->down) &&
        sfKeyboard_isKeyPressed(rpg->key_board->right) &&
        !sfKeyboard_isKeyPressed(rpg->key_board->left)) {
            sfSprite_setTextureRect(player->sprite, (sfIntRect)
                {0, x, 16, 16});
            front_pixel = player->position;
            if (right_down_color(rpg, player, front_pixel) == 0)
                return 2;
            move_player_rigth(movementClock, player);
            return 1;
    }
    return 0;
}
