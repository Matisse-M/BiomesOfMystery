/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** move_up
*/

# include "rpg.h"

static int pixel_color(rpg_t *rpg, main_player_t *player,
    sfVector2f front_pixel)
{
    sfColor front_pixel_color = sfGreen;

    front_pixel.y -= 2;
    if (wich_room(rpg, player, front_pixel) == 0)
        return 0;
    front_pixel.y += 2;
    for (int i = 2; i < 16; i++) {
        front_pixel_color = sfImage_getPixel(rpg->maps->under,
        front_pixel.x + i, front_pixel.y);
        if (front_pixel_color.r != 0)
            return 0;
    }
    return 1;
}

void move_player_up(sfClock *movementClock, main_player_t *player)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(movementClock)) >= 15) {
        player->position.y -= 1;
        player->direction = 16;
        sfSprite_setPosition(player->sprite, player->position);
        sfClock_restart(movementClock);
    }
}

int move_key_up(sfClock *clock, main_player_t *player, rpg_t *rpg)
{
    static sfClock *movementClock = NULL;
    int x = select_an(clock);
    sfVector2f front_pixel;

    if (!movementClock)
        movementClock = sfClock_create();
    if (sfKeyboard_isKeyPressed(rpg->key_board->up) &&
        !sfKeyboard_isKeyPressed(rpg->key_board->down) &&
        !sfKeyboard_isKeyPressed(rpg->key_board->right) &&
        !sfKeyboard_isKeyPressed(rpg->key_board->left)) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect){16, x, 16, 16});
        front_pixel = player->position;
        front_pixel.y += 12;
        if (pixel_color(rpg, player, front_pixel) == 0)
            return 2;
        move_player_up(movementClock, player);
        return 1;
    }
    return 0;
}
