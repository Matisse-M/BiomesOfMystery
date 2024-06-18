/*
** EPITECH PROJECT, 2023
** draw scene
** File description:
** Some functions to draw menu's scene
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"

sfRenderWindow *change_res(rpg_t *rpg, sfVideoMode res, int fm_limit)
{
    sfVector2u old_size = sfRenderWindow_getSize(rpg->game->window);
    sfRenderWindow *window = NULL;
    sfUint32 style = sfResize | sfClose;

    sfRenderWindow_close(rpg->game->window);
    sfRenderWindow_destroy(rpg->game->window);
    window = my_set_window("RPG", res, style);
    sfRenderWindow_setFramerateLimit(window, fm_limit);
    if (old_size.x != res.width)
        adjust_all(rpg, res, old_size);
    return window;
}

static void draw_texts_btn(rpg_t *rpg, settings_t *screen)
{
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        screen->resolutions[0]->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        screen->resolutions[1]->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        screen->resolutions[2]->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        screen->quit_btn->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        screen->resolutions[0]->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        screen->resolutions[1]->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        screen->resolutions[2]->text, NULL);
    sfRenderWindow_drawText(rpg->game->window, screen->quit_btn->text, NULL);
}

static void draw_btn_sound(rpg_t *rpg, settings_t *sett, sfTexture **texture)
{
    if (button_hover(rpg, sett->music_add) == 1) {
        rpg->game->vol_music += 1;
        if (rpg->game->vol_music > 5)
            rpg->game->vol_music = 5;
        sfSprite_setTexture(sett->musicbar,
            texture[rpg->game->vol_music], sfTrue);
        sett->music_add->state = 0;
        sfMusic_setVolume(rpg->game->music, rpg->game->vol_music * 20);
    }
    if (button_hover(rpg, sett->sound_add) == 1) {
        rpg->game->vol_sound += 1;
        if (rpg->game->vol_sound > 5)
            rpg->game->vol_sound = 5;
        sfSprite_setTexture(sett->soundbar,
            texture[rpg->game->vol_sound], sfTrue);
        sett->sound_add->state = 0;
    }
}

static void draw_volume(rpg_t *rpg, settings_t *sett, sfTexture **texture)
{
    if (button_hover(rpg, sett->music_sub) == 1) {
        rpg->game->vol_music -= 1;
        if (rpg->game->vol_music < 0)
            rpg->game->vol_music = 0;
        sfSprite_setTexture(sett->musicbar,
            texture[rpg->game->vol_music], sfTrue);
        sett->music_sub->state = 0;
        sfMusic_setVolume(rpg->game->music, rpg->game->vol_music * 20);
    }
    if (button_hover(rpg, sett->sound_sub) == 1) {
        rpg->game->vol_sound -= 1;
        if (rpg->game->vol_sound < 0)
            rpg->game->vol_sound = 0;
        sfSprite_setTexture(sett->soundbar,
            texture[rpg->game->vol_sound], sfTrue);
        sett->sound_sub->state = 0;
    }
    draw_btn_sound(rpg, sett, texture);
}

static void draw_volume_bars(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->menu->settings->under_music, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->menu->settings->under_sound, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->menu->settings->musicbar, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->menu->settings->soundbar, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->menu->settings->music, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->menu->settings->sound, NULL);
}

static void draw_volume_button(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->menu->settings->music_sub->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->menu->settings->music_add->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->menu->settings->sound_sub->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->menu->settings->sound_add->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->menu->settings->music_sub->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->menu->settings->music_add->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->menu->settings->sound_sub->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->menu->settings->sound_add->text, NULL);
    draw_volume_bars(rpg);
}

void draw_zqsd(rpg_t *rpg)
{
    if (button_hover(rpg, rpg->key_board->right_btn) == 1) {
        key_zqsd(rpg);
        rpg->key_board->right_bool = true;
        rpg->key_board->left_bool = false;
        rpg->key_board->left_btn->state = 0;
    }
    if (rpg->key_board->right_bool == true)
        rpg->key_board->right_btn->state = 3;
    sfRectangleShape_setTexture(rpg->key_board->right_btn->rect,
        rpg->key_board->right_btn->texture
        [rpg->key_board->right_btn->state], sfTrue);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->key_board->right_btn->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->key_board->right_btn->text, NULL);
}

void draw_key(rpg_t *rpg)
{
    if (button_hover(rpg, rpg->key_board->left_btn) == 1) {
        key_arrows(rpg);
        rpg->key_board->right_bool = false;
        rpg->key_board->left_bool = true;
        rpg->key_board->right_btn->state = 0;
    }
    if (rpg->key_board->left_bool == true)
        rpg->key_board->left_btn->state = 3;
    sfRectangleShape_setTexture(rpg->key_board->left_btn->rect,
        rpg->key_board->left_btn->texture
        [rpg->key_board->left_btn->state], sfTrue);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->key_board->left_btn->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->key_board->left_btn->text, NULL);
    draw_zqsd(rpg);
}

void find_resize(rpg_t *rpg)
{
    if (button_hover(rpg, rpg->menu->settings->resolutions[1]) == 1) {
        modify_key_pos(rpg, (sfVector2f){170, 530}, (sfVector2f){980, 530});
        rpg->game->window = change_res(rpg, MEDIUM_MODE, LOW_FM);
    }
    if (button_hover(rpg, rpg->menu->settings->resolutions[2]) == 1) {
        modify_key_pos(rpg, (sfVector2f) {220, 600}, (sfVector2f) {1200, 600});
        rpg->game->window = change_res(rpg, HIGH_MODE, LOW_FM);
    }
    if (button_hover(rpg, rpg->menu->settings->quit_btn) == 1) {
        rpg->menu->settings->is_active = false;
        rpg->menu->title->is_active = true;
    }
}

void draw_settings(rpg_t *rpg)
{
    sfTexture *texture[6] = {rpg->assets->bar0, rpg->assets->bar20,
        rpg->assets->bar40, rpg->assets->bar60, rpg->assets->bar80,
        rpg->assets->bar100};

    sfRenderWindow_drawSprite(rpg->game->window, rpg->menu->settings->
        bground, NULL);
    if (button_hover(rpg, rpg->menu->settings->resolutions[0]) == 1) {
        modify_key_pos(rpg, (sfVector2f) {150, 470}, (sfVector2f) {820, 470});
        rpg->game->window = change_res(rpg, LOW_MODE, LOW_FM);
    }
    find_resize(rpg);
    draw_volume(rpg, rpg->menu->settings, texture);
    draw_volume_button(rpg);
    draw_texts_btn(rpg, rpg->menu->settings);
    draw_key(rpg);
}
