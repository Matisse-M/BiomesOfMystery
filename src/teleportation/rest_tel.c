/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** rest_tel
*/

#include "rpg.h"

static void hoose_coord(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->house->is_active = false;
    rpg->maps->swamp->is_active = true;
    rpg->maps->swamp->is_trans = true;
    rpg->maps->is_trans = true;
    player->position.x = 260;
    player->position.y = 117;
    rpg->maps->center.x = 230;
    rpg->maps->center.y = 130;
}

int find_where_house(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    int x = select_an(rpg->game->clock_mv);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (position.x >= 130.0 && position.x <= 150.1 && position.y >= 126.9
        && position.y <= 128.0 && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->house, window_size.x, position);
        hoose_coord(rpg, player);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        init_rain(rpg->anim->rain_anim, rpg);
        choose_under_map(rpg, player);
    }
    return 0;
}

static void bath_coord(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->bathroom->is_active = false;
    rpg->maps->swamp->is_active = true;
    rpg->maps->swamp->is_trans = true;
    rpg->maps->is_trans = true;
    player->position.x = 370;
    player->position.y = 480;
    rpg->maps->center.x = 271;
    rpg->maps->center.y = 370;
}

int find_where_bathroom(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    int x = select_an(rpg->game->clock_mv);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (position.x >= 128.0 && position.x <= 150 &&
        position.y >= 126.0 && position.y <= 128
        && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->bathroom, window_size.x, position);
        bath_coord(rpg, player);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        init_rain(rpg->anim->rain_anim, rpg);
        choose_under_map(rpg, player);
    }
    return 0;
}

static void noodle_coord(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->food_shop->is_active = false;
    rpg->maps->beach->is_active = true;
    rpg->maps->beach->is_trans = true;
    rpg->maps->is_trans = true;
    modif_music(rpg, rpg->assets->music_beach);
    player->position.x = 336;
    player->position.y = 229;
    rpg->maps->center.x = 270;
    rpg->maps->center.y = 100;
}

int find_where_noodle(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    int x = select_an(rpg->game->clock_mv);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (player->position.x >= 80.0 && player->position.x <= 100.0 &&
        player->position.y >= 108.0 && player->position.y <= 110.0
        && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->food_shop, window_size.x, position);
        noodle_coord(rpg, player);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        choose_under_map(rpg, player);
    }
    return 0;
}

static void weapon_coord(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->weapon_shop->is_active = false;
    rpg->maps->beach->is_active = true;
    rpg->maps->beach->is_trans = true;
    rpg->maps->is_trans = true;
    modif_music(rpg, rpg->assets->music_beach);
    player->position.x = 478;
    player->position.y = 212;
    rpg->maps->center.x = 270;
    rpg->maps->center.y = 100;
}

int find_where_weapon(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    int x = select_an(rpg->game->clock_mv);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (player->position.x >= 134.0 && player->position.x <= 144.0 &&
        player->position.y >= 156.0 && player->position.y <= 159.0
        && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->weapon_shop, window_size.x, position);
        weapon_coord(rpg, player);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        choose_under_map(rpg, player);
    }
    return 0;
}

static void maze_coord(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->maze->is_active = false;
    rpg->maps->upstairs->is_active = true;
    rpg->maps->upstairs->is_trans = true;
    rpg->maps->is_trans = true;
    player->direction = 14;
    player->position.x = 541;
    player->position.y = 182;
    rpg->maps->center.x = 490;
    rpg->maps->center.y = 220;
}

int find_where_maze(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    int x = select_an(rpg->game->clock_mv);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (position.x >= 575 && position.x <= 602.0 &&
        position.y >= 100 && position.y <= 102
        && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->maze, window_size.x, position);
        maze_coord(rpg, player);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        choose_under_map(rpg, player);
    }
    return 0;
}
