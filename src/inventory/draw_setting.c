/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main loops of our rpg
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "csfml.h"

static void update_params_btn(sett_t *sett, sfVector2f pos)
{
    sfRectangleShape_setPosition(sett->resume->rect,
        (sfVector2f) {pos.x - 200, pos.y + 50});
    sfRectangleShape_setPosition(sett->save->rect,
        (sfVector2f) {pos.x - 60, pos.y + 50});
    sfRectangleShape_setPosition(sett->exit->rect,
        (sfVector2f) {pos.x + 80, pos.y + 50});
    sfText_setPosition(sett->resume->text,
        (sfVector2f) {pos.x - 157, pos.y + 53});
    sfText_setPosition(sett->save->text,
        (sfVector2f) {pos.x - 12, pos.y + 53});
    sfText_setPosition(sett->exit->text,
        (sfVector2f) {pos.x + 128, pos.y + 53});
}

static void update_res_btn(sett_t *sett, sfVector2f pos)
{
    sfRectangleShape_setPosition(sett->resolutions[0]->rect,
        (sfVector2f) {pos.x - 200, pos.y + 10});
    sfRectangleShape_setPosition(sett->resolutions[1]->rect,
        (sfVector2f) {pos.x - 60, pos.y + 10});
    sfRectangleShape_setPosition(sett->resolutions[2]->rect,
        (sfVector2f) {pos.x + 80, pos.y + 10});
    sfText_setPosition(sett->resolutions[0]->text,
        (sfVector2f) {pos.x - 162, pos.y + 13});
    sfText_setPosition(sett->resolutions[1]->text,
        (sfVector2f) {pos.x - 22, pos.y + 13});
    sfText_setPosition(sett->resolutions[2]->text,
        (sfVector2f) {pos.x + 115, pos.y + 13});
}

static void update_sprites(sett_t *sett, sfVector2f pos)
{
    sfSprite_setPosition(sett->musicbar,
        (sfVector2f) {pos.x - 165, pos.y - 44});
    sfSprite_setPosition(sett->soundbar,
        (sfVector2f) {pos.x + 95, pos.y - 44});
    sfSprite_setPosition(sett->under_music,
        (sfVector2f) {pos.x - 165, pos.y - 44});
    sfSprite_setPosition(sett->under_sound,
        (sfVector2f) {pos.x + 95, pos.y - 44});
}

void update_btn_pos(sett_t *sett, sfVector2f pos)
{
    sfRectangleShape_setPosition(sett->music_sub->rect,
        (sfVector2f) {pos.x - 200, pos.y - 50});
    sfRectangleShape_setPosition(sett->music_add->rect,
        (sfVector2f) {pos.x - 80, pos.y - 50});
    sfRectangleShape_setPosition(sett->sound_sub->rect,
        (sfVector2f) {pos.x + 60, pos.y - 50});
    sfRectangleShape_setPosition(sett->sound_add->rect,
        (sfVector2f) {pos.x + 180, pos.y - 50});
    sfText_setPosition(sett->music_sub->text,
        (sfVector2f) {pos.x - 192, pos.y - 45});
    sfText_setPosition(sett->music_add->text,
        (sfVector2f) {pos.x - 72, pos.y - 45});
    sfText_setPosition(sett->sound_sub->text,
        (sfVector2f) {pos.x + 68, pos.y - 45});
    sfText_setPosition(sett->sound_add->text,
        (sfVector2f) {pos.x + 188, pos.y - 45});
    update_sprites(sett, pos);
}

static void draw_btn_sound(rpg_t *rpg, sett_t *sett, sfTexture **texture)
{
    if (button_view_hover(rpg, sett->music_add) == 1) {
        rpg->game->vol_music += 1;
        if (rpg->game->vol_music > 5)
            rpg->game->vol_music = 5;
        sfSprite_setTexture(sett->musicbar, texture[rpg->game->vol_music],
            sfTrue);
        sett->music_add->state = 0;
        sfMusic_setVolume(rpg->game->music, rpg->game->vol_music * 20);
    }
    if (button_view_hover(rpg, sett->sound_add) == 1) {
        rpg->game->vol_sound += 1;
        if (rpg->game->vol_sound > 5)
            rpg->game->vol_sound = 5;
        sfSprite_setTexture(sett->soundbar, texture[rpg->game->vol_sound],
            sfTrue);
        sett->sound_add->state = 0;
    }
}

static void draw_volume(rpg_t *rpg, sett_t *sett, sfTexture **texture)
{
    if (button_view_hover(rpg, sett->music_sub) == 1) {
        rpg->game->vol_music -= 1;
        if (rpg->game->vol_music < 0)
            rpg->game->vol_music = 0;
        sfSprite_setTexture(sett->musicbar, texture[rpg->game->vol_music],
            sfTrue);
        sett->music_sub->state = 0;
        sfMusic_setVolume(rpg->game->music, rpg->game->vol_music * 20);
    }
    if (button_view_hover(rpg, sett->sound_sub) == 1) {
        rpg->game->vol_sound -= 1;
        if (rpg->game->vol_sound < 0)
            rpg->game->vol_sound = 0;
        sfSprite_setTexture(sett->soundbar, texture[rpg->game->vol_sound],
            sfTrue);
        sett->sound_sub->state = 0;
    }
    draw_btn_sound(rpg, sett, texture);
}

static void draw_vol_btn(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->settings->music_add->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->settings->music_sub->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->settings->sound_add->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->settings->sound_sub->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->music_sub->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->music_add->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->sound_sub->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->sound_add->text, NULL);
}

void draw_settings_inv(rpg_t *rpg)
{
    sfVector2f pos = sfView_getCenter(rpg->game->view);
    sfTexture *texture[6] = {rpg->assets->bar0, rpg->assets->bar20,
        rpg->assets->bar40, rpg->assets->bar60, rpg->assets->bar80,
        rpg->assets->bar100};

    sfText_setPosition(rpg->inv->settings->music,
        (sfVector2f) {pos.x - 163, pos.y - 70});
    sfText_setPosition(rpg->inv->settings->sound,
        (sfVector2f) {pos.x + 96, pos.y - 70});
    update_btn_pos(rpg->inv->settings, pos);
    update_res_btn(rpg->inv->settings, pos);
    update_params_btn(rpg->inv->settings, pos);
    draw_volume(rpg, rpg->inv->settings, texture);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->music, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->sound, NULL);
    draw_vol_btn(rpg);
    draw_resolutions_params(rpg);
}
