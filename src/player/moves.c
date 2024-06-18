/*
** EPITECH PROJECT, 2023
** moves
** File description:
** Some function to handle player moves
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static int (*key[8])(sfClock *, main_player_t *, rpg_t *) = {&move_key_up,
    &move_key_left, &move_key_down, &move_key_right, &move_right_down,
    &move_right_up, &move_left_up, &move_left_down};

void move_player(sfClock *clock, main_player_t *player, rpg_t *rpg)
{
    for (int i = 0; i < 8; i++) {
        if (key[i](clock, player, rpg) != 0)
            return;
    }
    sfSprite_setTextureRect(player->sprite, (sfIntRect)
        {player->direction, 0, 16, 17});
}
