/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** downstair_tel
*/

#include "rpg.h"

static void dungeon_dowstatairs(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (position.x >= 6 && position.x <= 7
        && position.y >= 230 && position.y <= 253 &&
        rpg->maps->is_trans == false && rpg->maps->dungeon->unlock) {
        render_trans(rpg, rpg->maps->downstairs, window_size.x, position);
        rpg->maps->downstairs->is_active = false;
        rpg->maps->dungeon->is_active = true;
        modif_music(rpg, rpg->assets->music_donjon);
        player->position.x = 1012.60;
        player->position.y = 425.60;
        rpg->maps->center.x = 797.80;
        rpg->maps->center.y = 419.60;
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        rpg->maps->dungeon->is_trans = true;
        rpg->maps->is_trans = true;
        choose_under_map(rpg, player);
    }
}

static void find_pos_upstairs(rpg_t *rpg, main_player_t *player,
    sfVector2f positon, int x)
{
    rpg->maps->center.x = 305;
    rpg->maps->center.y = 275;
    player->position.x = 345;
    player->position.y = 196;
    player->direction = 16;
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setTextureRect(player->sprite, (sfIntRect)
        {16, x, 16, 16});
    rpg->maps->upstairs->is_trans = true;
    rpg->maps->is_trans = true;
}

static void else_downstairs(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (position.x >= 337.0 && position.x <= 352 &&
        position.y >= 234 && position.y <= 236
        && rpg->maps->is_trans == false && rpg->maps->upstairs->unlock) {
        rpg->maps->downstairs->is_active = false;
        rpg->maps->upstairs->is_active = true;
        render_trans(rpg, rpg->maps->downstairs, window_size.x, position);
        find_pos_upstairs(rpg, player, position, x);
        choose_under_map(rpg, player);
        return;
    }
    dungeon_dowstatairs(rpg, player, position, x);
}

static void find_pos_beach(rpg_t *rpg, main_player_t *player,
    sfVector2f position)
{
    rpg->maps->downstairs->is_active = false;
    rpg->maps->beach->is_active = true;
    modif_music(rpg, rpg->assets->music_beach);
    player->position.x = 378;
    player->position.y = 420;
    rpg->maps->center.x = 265;
    rpg->maps->center.y = 375;
}

static void rest_downstairs(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (position.x >= 73.8 && position.x <= 101.6 &&
        position.y >= 167.0 && position.y <= 179.8
        && rpg->maps->is_trans == false && rpg->maps->beach->unlock) {
        render_trans(rpg, rpg->maps->downstairs, window_size.x, position);
        find_pos_beach(rpg, player, position);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        rpg->maps->beach->is_trans = true;
        rpg->maps->is_trans = true;
        choose_under_map(rpg, player);
    }
    else_downstairs(rpg, player, position, x);
}

static void change_coord(rpg_t *rpg, main_player_t *player)
{
    rpg->maps->downstairs->is_active = false;
    rpg->maps->swamp->is_active = true;
    modif_music(rpg, rpg->assets->music_swamp);
    player->position.x = 458;
    player->position.y = 290;
    rpg->maps->center.x = 271;
    rpg->maps->center.y = 290;
    rpg->maps->swamp->is_trans = true;
    rpg->maps->is_trans = true;
}

int find_where_downstairs(rpg_t *rpg, main_player_t *player,
    sfVector2f position)
{
    sfColor color_pixel = sfImage_getPixel(rpg->maps->under,
        position.x, position.y);
    int x = select_ani(rpg->game->clock_mv);
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (is_white(color_pixel) == 0)
        return 1;
    if (position.x >= 58.0 && position.x <= 61.7 &&
        position.y >= 402.0 && position.y <= 430.3
        && rpg->maps->is_trans == false && rpg->maps->swamp->unlock) {
        render_trans(rpg, rpg->maps->downstairs, window_size.x, position);
        change_coord(rpg, player);
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        choose_under_map(rpg, player);
        init_rain(rpg->anim->rain_anim, rpg);
    }
    rest_downstairs(rpg, player, position, x);
    return 0;
}

void else_swamp(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x)
{
    sfVector2u window_size = sfRenderWindow_getSize(rpg->game->window);

    if (position.x >= 362.0 && position.x <= 380.0 && position.y >= 481
        && position.y <= 484 && rpg->maps->is_trans == false) {
        render_trans(rpg, rpg->maps->swamp, window_size.x, position);
        rpg->maps->swamp->is_active = false;
        rpg->maps->bathroom->is_active = true;
        player->position.x = 135;
        player->position.y = 105;
        rpg->maps->center.x = 230;
        rpg->maps->center.y = 100;
        sfSprite_setPosition(player->sprite, player->position);
        sfSprite_setTextureRect(player->sprite, (sfIntRect)
            {16, x, 16, 16});
        rpg->maps->bathroom->is_trans = true;
        rpg->maps->is_trans = true;
        choose_under_map(rpg, player);
    }
}
