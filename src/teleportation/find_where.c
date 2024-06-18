/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** find_where
*/

#include "rpg.h"

int is_white(sfColor color_pixel)
{
    if (color_pixel.r == 255 && color_pixel.g == 255 && color_pixel.b == 255)
        return 1;
    return 0;
}

static void vill_coord(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->village->is_active = false;
    rpg->maps->upstairs->is_active = true;
    rpg->characters->main->position.x = 408.79;
    rpg->characters->main->position.y = 340.2;
    player->direction = 16;
    rpg->maps->center.x = 350;
    rpg->maps->center.y = 330;
    rpg->maps->upstairs->is_trans = true;
    rpg->maps->is_trans = true;
}

int find_where_village(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    int x = select_an(rpg->game->clock_mv);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (position.x >= 245.0 && position.x <= 270.0 &&
        position.y >= 4.5 && position.y <= 7.0 &&
        rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->village, window_size.x, position);
        vill_coord(rpg, player);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        choose_under_map(rpg, player);
    }
    return 0;
}

int wich_room(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    if (rpg->maps->downstairs->is_active == true) {
        if (find_where_downstairs(rpg, player, position) == 0)
            return 0;
    }
    if (rpg->maps->swamp->is_active == true) {
        if (find_where_swamp(rpg, player, position) == 0)
            return 0;
    }
    if (rpg->maps->beach->is_active == true) {
        if (find_where_beach(rpg, player, position) == 0)
            return 0;
    }
    if (rpg->maps->food_shop->is_active == true) {
        if (find_where_noodle(rpg, player, position) == 0)
            return 0;
    }
    if (wich_room2(rpg, player, position) == 0)
        return 0;
    return 1;
}
