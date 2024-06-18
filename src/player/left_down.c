/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** left_down
*/

#include "rpg.h"

static int rest_pos(rpg_t *rpg, main_player_t *player, sfVector2f front_pixel,
    sfColor front_pixel_color)
{
    front_pixel = player->position;
    front_pixel.y += 18;
    if (wich_room(rpg, player, front_pixel) == 0)
        return 0;
    for (int i = 0; i < 15; i++) {
        front_pixel_color = sfImage_getPixel(rpg->maps->under,
            front_pixel.x + i, front_pixel.y);
        if (front_pixel_color.r != 0)
            return 0;
    }
    return 1;
}

static int pixel_color(rpg_t *rpg, main_player_t *player,
    sfVector2f front_pixel)
{
    sfColor front_pixel_color = sfGreen;

    front_pixel.x += 1;
    front_pixel.y += 14;
    if (wich_room(rpg, player, front_pixel) == 0)
        return 0;
    for (int i = 0; i < 3; i++) {
        front_pixel_color = sfImage_getPixel(rpg->maps->under,
            front_pixel.x, front_pixel.y + i);
        if (front_pixel_color.r != 0)
            return 0;
    }
    if (rest_pos(rpg, player, front_pixel, front_pixel_color) == 0)
        return 0;
    return 1;
}

static void move_player_left(main_player_t *player, sfClock *movementClock)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(movementClock)) >= 15) {
        player->position.x -= 0.8;
        player->position.y += 0.8;
        player->direction = 16;
        sfSprite_setPosition(player->sprite, player->position);
        sfClock_restart(movementClock);
    }
}

int move_left_down(sfClock *clock, main_player_t *player, rpg_t *rpg)
{
    static sfClock *movementClock = NULL;
    int x = select_an(clock);
    sfVector2f front_pixel;

    if (!movementClock)
        movementClock = sfClock_create();
    if (!sfKeyboard_isKeyPressed(rpg->key_board->up) &&
        sfKeyboard_isKeyPressed(rpg->key_board->down) &&
        !sfKeyboard_isKeyPressed(rpg->key_board->right) &&
        sfKeyboard_isKeyPressed(rpg->key_board->left)) {
            sfSprite_setTextureRect(player->sprite, (sfIntRect)
                {0, x, 16, 16});
            front_pixel = player->position;
            if (pixel_color(rpg, player, front_pixel) == 0)
                return 2;
            move_player_left(player, movementClock);
            return 1;
    }
    return 0;
}
