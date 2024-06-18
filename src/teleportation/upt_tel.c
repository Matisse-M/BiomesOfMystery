/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** upt_tel
*/

#include "rpg.h"

static void find_where_village_two(rpg_t *rpg, main_player_t *player,
    sfVector2f position)
{
    rpg->maps->upstairs->is_active = false;
    rpg->maps->village->is_active = true;
    rpg->maps->village->is_trans = true;
    rpg->maps->is_trans = true;
    modif_music(rpg, rpg->assets->music_village);
    player->position.x = 260;
    player->position.y = 5;
    rpg->maps->center.x = 270;
    rpg->maps->center.y = 135;
}

void else_upt(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (position.x >= 400.0 && position.x <= 413.0 &&
        position.y >= 365.0 && position.y <= 367.0 &&
        rpg->maps->is_trans == false && rpg->maps->village->unlock) {
        render_trans(rpg, rpg->maps->upstairs, window_size.x, position);
        find_where_village_two(rpg, player, position);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        init_sprite(rpg, rpg->anim);
        choose_under_map(rpg, player);
    }
}

static void coord_upt(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->downstairs->is_active = true;
    rpg->maps->upstairs->is_active = false;
    rpg->maps->downstairs->is_trans = true;
    rpg->maps->is_trans = true;
    player->direction = 16;
    player->position.x = 339;
    player->position.y = 200;
    rpg->maps->center.x = 240;
    rpg->maps->center.y = 100;
    sfSprite_setPosition(player->sprite, player->position);
}

static void meseum_coordinates(rpg_t *rpg, main_player_t *player,
    sfVector2f position, sfVector2u window_size)
{
    render_trans(rpg, rpg->maps->upstairs, window_size.x, position);
    rpg->maps->upstairs->is_active = false;
    rpg->maps->museum->is_active = true;
    rpg->maps->museum->is_trans = true;
    rpg->maps->is_trans = true;
    modif_music(rpg, rpg->assets->music_museum);
    player->position.x = 139;
    player->position.y = 471;
    rpg->maps->center.x = 238.8;
    rpg->maps->center.y = 377.4;
    choose_under_map(rpg, player);
}

static void find_grotte_coordinates(rpg_t *rpg, main_player_t *player,
    sfVector2f position, sfVector2u window_size)
{
    if (position.x >= 338.0 && position.x <= 353.0 &&
        position.y >= 228.0 && position.y <= 230.0
        && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->upstairs, window_size.x, position);
        coord_upt(rpg, player);
        choose_under_map(rpg, player);
    }
}

int find_where_upstairs(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    int x = select_ani(rpg->game->clock_mv);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (position.x >= 727.0 && position.x <= 738.0 &&
        position.y >= 298 && position.y <= 320.0
        && rpg->maps->is_trans == false && rpg->maps->museum->unlock) {
        meseum_coordinates(rpg, player, position, window_size);
        return 0;
    }
    find_grotte_coordinates(rpg, player, position, window_size);
    rest_upstairs(rpg, player, position, x);
    return 0;
}

void else_beach(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (position.x >= 478.0 && position.x <= 490.0 && position.y >= 210.0 &&
        position.y <= 211 && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->beach, window_size.x, position);
        rpg->maps->beach->is_active = false;
        rpg->maps->weapon_shop->is_active = true;
        rpg->maps->weapon_shop->is_trans = true;
        rpg->maps->is_trans = true;
        modif_music(rpg, rpg->assets->music_lighthouse);
        player->position.x = 120;
        player->position.y = 145;
        rpg->maps->center.x = 240;
        rpg->maps->center.y = 150;
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        choose_under_map(rpg, player);
    }
}

static void find_down_beach_pos(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->beach->is_active = false;
    rpg->maps->downstairs->is_active = true;
    rpg->maps->is_trans = true;
    rpg->maps->downstairs->is_trans = true;
    player->position.x = 78;
    player->position.y = 184;
    rpg->maps->center.x = 240;
    rpg->maps->center.y = 100;
    sfSprite_setPosition(player->sprite, player->position);
}

int find_where_beach(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    int x = select_ani(rpg->game->clock_mv);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (position.x >= 376.0 && position.x <= 390.0 &&
        position.y >= 508.0 && position.y <= 509
        && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->beach, window_size.x, position);
        find_down_beach_pos(rpg, player);
        choose_under_map(rpg, player);
    }
    rest_beach(rpg, player, position, x);
    return 0;
}
