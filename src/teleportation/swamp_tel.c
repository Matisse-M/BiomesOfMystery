/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** swamp_tel
*/

#include "rpg.h"

static void rest_swamp(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (position.x >= 256.0 && position.x <= 266.0 && position.y >= 114.0 &&
        position.y <= 117.0 && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->swamp, window_size.x, position);
        rpg->maps->swamp->is_active = false;
        rpg->maps->house->is_active = true;
        player->position.x = 135;
        player->position.y = 107;
        rpg->maps->center.x = 230;
        rpg->maps->center.y = 100;
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        rpg->maps->house->is_trans = true;
        rpg->maps->is_trans = true;
        choose_under_map(rpg, player);
    }
    else_swamp(rpg, player, position, x);
}

static void swamp_coord(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->swamp->is_active = false;
    rpg->maps->downstairs->is_active = true;
    player->position.x = 63;
    player->position.y = 405;
    rpg->maps->center.x = 240;
    rpg->maps->center.y = 100;
    rpg->maps->downstairs->is_trans = true;
    rpg->maps->is_trans = true;
}

int find_where_swamp(rpg_t *rpg, main_player_t *player,
    sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    int x = select_ani(rpg->game->clock_mv);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (position.x >= 507.0 && position.x <= 508.0 && position.y >= 296.0 &&
        position.y <= 315 && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->swamp, window_size.x, position);
        swamp_coord(rpg, player);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        choose_under_map(rpg, player);
    }
    rest_swamp(rpg, player, position, x);
    return 0;
}

static void find_pos_food_shop(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->beach->is_active = false;
    rpg->maps->food_shop->is_active = true;
    rpg->maps->food_shop->is_trans = true;
    rpg->maps->is_trans = true;
    modif_music(rpg, rpg->assets->music_shop);
    player->position.x = 90;
    player->position.y = 110;
    rpg->maps->center.x = 230;
    rpg->maps->center.y = 100;
}

void rest_beach(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (position.x >= 334.0 && position.x <= 340.0 &&
        position.y >= 225.0 && position.y <= 228.0
        && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->beach, window_size.x, position);
        find_pos_food_shop(rpg, player);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        choose_under_map(rpg, player);
    }
    else_beach(rpg, player, position, x);
}
