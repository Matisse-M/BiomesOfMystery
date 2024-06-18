/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** maze_tel
*/

#include "rpg.h"

static void find_pos_mase(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->upstairs->is_active = false;
    rpg->maps->maze->is_active = true;
    rpg->maps->maze->is_trans = true;
    rpg->maps->is_trans = true;
    player->direction = 48;
    player->position.x = 17;
    player->position.y = 284;
    rpg->maps->center.x = 240;
    rpg->maps->center.y = 292;
}

void rest_upstairs(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (position.x >= 563.0 && position.x <= 564.0 &&
        position.y >= 179.0 && position.y <= 210.0
        && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->upstairs, window_size.x, position);
        find_pos_mase(rpg, player);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        choose_under_map(rpg, player);
        return;
    }
    else_upt(rpg, player, position, x);
}
