/*
** EPITECH PROJECT, 2023
** moves
** File description:
** Some function to handle player moves
*/

#include <SFML/Graphics.h>
#include "rpg/player.h"
#include "rpg.h"

int select_an(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float f = sfTime_asSeconds(time);

    if (f <= 0.20)
        return 0;
    if (f <= 0.40)
        return 17;
    if (f <= 0.60)
        return 34;
    return 51;
}

static int pixel_left(rpg_t *rpg, main_player_t *player,
    sfVector2f front_pixel)
{
    sfColor front_pixel_color = sfGreen;

    if (wich_room(rpg, player, front_pixel) == 0)
        return 0;
    for (int i = 0; i < 3; i++) {
        front_pixel_color = sfImage_getPixel(rpg->maps->under, front_pixel.x,
            front_pixel.y + i);
        if (front_pixel_color.r != 0) {
            return 0;
        }
    }
    return 1;
}

static int get_time_left(sfClock *movementClock, main_player_t *player,
    rpg_t *rpg, sfVector2f front_pixel)
{
    front_pixel = player->position;
    front_pixel.x += 1;
    front_pixel.y += 14;
    if (pixel_left(rpg, player, front_pixel) == 0)
        return 2;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(movementClock)) >= 15) {
        player->position.x -= 1;
        player->direction = 32;
        sfSprite_setPosition(player->sprite, player->position);
        sfClock_restart(movementClock);
    }
    return 1;
}

int move_key_left(sfClock *clock, main_player_t *player, rpg_t *rpg)
{
    static sfClock *movementClock = NULL;
    int x = select_an(clock);
    sfVector2f front_pixel;

    if (!movementClock)
        movementClock = sfClock_create();
    if (!sfKeyboard_isKeyPressed(rpg->key_board->up) &&
        !sfKeyboard_isKeyPressed(rpg->key_board->down) &&
        !sfKeyboard_isKeyPressed(rpg->key_board->right) &&
        sfKeyboard_isKeyPressed(rpg->key_board->left)) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {32, x, 16, 16});
        if (get_time_left(movementClock, player, rpg, front_pixel) == 2)
            return 2;
        else
            return 1;
    }
    return 0;
}

static int rigth_pixel(rpg_t *rpg, main_player_t *player,
    sfVector2f front_pixel)
{
    sfColor front_pixel_color = sfGreen;

    front_pixel.x += 19;
    front_pixel.y += 13;
    if (wich_room(rpg, player, front_pixel) == 0)
        return 2;
    front_pixel.x -= 2;
    for (int i = 0; i < 3; i++) {
        front_pixel_color = sfImage_getPixel(rpg->maps->under, front_pixel.x,
            front_pixel.y + i);
        if (front_pixel_color.r != 0) {
            return 0;
        }
    }
    return 1;
}

static void get_time_rigth(sfClock *movementClock, main_player_t *player,
    rpg_t *rpg)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(movementClock)) >= 15) {
        player->position.x += 1;
        player->direction = 48;
        sfSprite_setPosition(player->sprite, player->position);
        sfClock_restart(movementClock);
    }
}

int move_key_right(sfClock *clock, main_player_t *player, rpg_t *rpg)
{
    static sfClock *movementClock = NULL;
    int x = select_an(clock);
    sfVector2f front_pixel;

    if (!movementClock)
        movementClock = sfClock_create();
    if (!sfKeyboard_isKeyPressed(rpg->key_board->up) &&
        !sfKeyboard_isKeyPressed(rpg->key_board->down) &&
        sfKeyboard_isKeyPressed(rpg->key_board->right) &&
        !sfKeyboard_isKeyPressed(rpg->key_board->left)) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {48, x, 16, 16});
        sfSprite_setPosition(player->sprite, player->position);
        front_pixel = player->position;
        if (rigth_pixel(rpg, player, front_pixel) == 0)
            return 2;
        get_time_rigth(movementClock, player, rpg);
        return 1;
    }
    return 0;
}
