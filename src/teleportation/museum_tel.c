/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** museum_tel
*/

#include "rpg.h"

static void museum_under(rpg_t *rpg, main_player_t *player)
{
    int x = select_an(rpg->game->clock_mv);

    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setTextureRect(player->sprite, (sfIntRect)
        {16, x, 16, 16});
    choose_under_map(rpg, player);
}

static void museum_coord(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->grotte->is_active = true;
    rpg->maps->museum->is_active = false;
    modif_music(rpg, rpg->assets->music_cave);
    rpg->characters->main->position.x = 88.7;
    rpg->characters->main->position.y = 165.19;
    player->direction = 16;
    rpg->maps->center.x = 120;
    rpg->maps->center.y = 130;
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setTextureRect(player->sprite, (sfIntRect)
        {16, 0, 16, 16});
    rpg->maps->grotte->is_trans = true;
    rpg->maps->is_trans = true;
    choose_under_map(rpg, player);
}

static void museum_coord2(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->upstairs->is_active = true;
    rpg->maps->museum->is_active = false;
    rpg->characters->main->position.x = 710;
    rpg->characters->main->position.y = 307.5;
    player->direction = 32;
    rpg->maps->center.x = 495.59;
    rpg->maps->center.y = 311.30;
    rpg->maps->upstairs->is_trans = true;
    rpg->maps->is_trans = true;
}

static void find_grotte(rpg_t *rpg, main_player_t *player, sfVector2f position,
    sfVector2u window_size)
{
    if (position.x >= 320.5 && position.x <= 334.0 &&
        position.y >= 37 && position.y <= 39.0
        && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->museum, window_size.x, position);
        museum_coord(rpg, player);
        museum_under(rpg, player);
    }
}

int find_where_museum(rpg_t *rpg, main_player_t *player,
    sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    find_grotte(rpg, player, position, window_size);
    if (position.x >= 129 && position.x <= 150 &&
        position.y >= 494 && position.y <= 496
        && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->museum, window_size.x, position);
        museum_coord2(rpg, player);
        museum_under(rpg, player);
    }
    return 0;
}

static void choos_grotte(rpg_t *rpg, main_player_t *player)
{
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setTextureRect(player->sprite, (sfIntRect)
        {0, 0, 16, 16});
    rpg->maps->museum->is_trans = true;
    choose_under_map(rpg, player);
    museum_under(rpg, player);
}

static void find_pos_museum(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->museum->is_active = true;
    rpg->maps->grotte->is_active = false;
    rpg->maps->is_trans = true;
    modif_music(rpg, rpg->assets->music_museum);
    player->position.x = 330;
    player->position.y = 57;
    player->direction = 0;
    rpg->maps->center.x = 272.20;
    rpg->maps->center.y = 135.00;
    sfSprite_setPosition(player->sprite, player->position);
}

int find_where_grotte(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (position.x >= 80 && position.x <= 100.0 &&
        position.y >= 190 && position.y <= 192.0
        && rpg->maps->is_trans == false) {
            render_trans(rpg, rpg->maps->grotte, window_size.x, position);
            find_pos_museum(rpg, player);
            choos_grotte(rpg, player);
    }
    return 0;
}

static void choose_dungeon(rpg_t *rpg, main_player_t *player)
{
    int x = select_an(rpg->game->clock_mv);

    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setTextureRect(player->sprite, (sfIntRect)
    {48, x, 16, 16});
    rpg->maps->downstairs->is_trans = true;
    choose_under_map(rpg, player);
}

int find_where_dungeon(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (position.x >= 1034 && position.x <= 1040 && position.y >= 393.6
        && position.y <= 459 && rpg->maps->is_trans == false) {
            render_trans(rpg, rpg->maps->dungeon, window_size.x, position);
            rpg->maps->downstairs->is_active = true;
            rpg->maps->dungeon->is_active = false;
            rpg->maps->is_trans = true;
            player->position.x = 23.2;
            player->position.y = 240.80;
            rpg->maps->center.x = 240.80;
            rpg->maps->center.y = 240.60;
            player->direction = 48;
            choose_dungeon(rpg, player);
    }
    return 0;
}
