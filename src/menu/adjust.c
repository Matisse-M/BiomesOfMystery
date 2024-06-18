/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** adjust_all
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"

sfVector2f get_pos(sfVideoMode res, sfVector2f pos, sfVector2u old_size)
{
    sfVector2f new_pos = {0, 0};

    if (old_size.x == MEDIUM_MODE.width && res.width == HIGH_MODE.width)
        new_pos = (sfVector2f) {pos.x * 1.2, pos.y * 1.2};
    if (old_size.x == HIGH_MODE.width && res.width == MEDIUM_MODE.width)
        new_pos = (sfVector2f) {pos.x / 1.2, pos.y / 1.2};
    if (old_size.x == MEDIUM_MODE.width && res.width == LOW_MODE.width)
        new_pos = (sfVector2f) {pos.x / 1.2, pos.y / 1.2};
    if (old_size.x == LOW_MODE.width && res.width == MEDIUM_MODE.width)
        new_pos = (sfVector2f) {pos.x * 1.2, pos.y * 1.2};
    if (old_size.x == HIGH_MODE.width && res.width == LOW_MODE.width)
        new_pos = (sfVector2f) {pos.x / 1.44, pos.y / 1.44};
    if (old_size.x == LOW_MODE.width && res.width == HIGH_MODE.width)
        new_pos = (sfVector2f) {pos.x * 1.44, pos.y * 1.44};
    return new_pos;
}

static void adjust_settings_screen(rpg_t *rpg, sfVideoMode res,
    sfVector2u old_size)
{
    set_new_pos_btn(rpg->menu->settings->quit_btn, res, old_size);
    set_new_pos_btn(rpg->menu->settings->music_sub, res, old_size);
    set_new_pos_btn(rpg->menu->settings->music_add, res, old_size);
    set_new_pos_btn(rpg->menu->settings->sound_sub, res, old_size);
    set_new_pos_btn(rpg->menu->settings->sound_add, res, old_size);
    set_new_pos_sprite(rpg->menu->settings->musicbar, res, old_size);
    set_new_pos_sprite(rpg->menu->settings->soundbar, res, old_size);
    set_new_pos_sprite(rpg->menu->settings->under_music, res, old_size);
    set_new_pos_sprite(rpg->menu->settings->under_sound, res, old_size);
    set_new_pos_text(rpg->menu->settings->music, res, old_size);
    set_new_pos_text(rpg->menu->settings->sound, res, old_size);
    for (int i = 0; i < 3; i++)
        set_new_pos_btn(rpg->menu->settings->resolutions[i], res, old_size);
}

static void adjust_start_screen(rpg_t *rpg, sfVideoMode res,
    sfVector2u old_size)
{
    set_new_pos_btn(rpg->menu->start->new_btn, res, old_size);
    set_new_pos_btn(rpg->menu->start->resume_btn, res, old_size);
    set_new_pos_btn(rpg->menu->start->quit_btn, res, old_size);
}

static void adjust_title_screen(rpg_t *rpg, sfVideoMode res,
    sfVector2u old_size)
{
    set_new_pos_btn(rpg->menu->title->start_btn, res, old_size);
    set_new_pos_btn(rpg->menu->title->settings_btn, res, old_size);
    set_new_pos_btn(rpg->menu->title->quit_btn, res, old_size);
}

void begin_lm(rpg_t *rpg, sfVideoMode res, sfVector2u old_size)
{
    sfText_setPosition(rpg->menu->game_title, (sfVector2f) {260, 150});
    sfRectangleShape_setPosition(rpg->begin->name_bar->rect,
        (sfVector2f) {402, 490});
    sfText_setPosition(rpg->begin->alpha->pre_text,
        (sfVector2f) {537, 500});
    sfRectangleShape_setPosition(rpg->begin->validate->rect,
        (sfVector2f) {485, 565});
    sfText_setPosition(rpg->begin->validate->text,
        (sfVector2f) {555, 567});
    sfRectangleShape_setPosition(rpg->begin->genders[0]->rect,
        (sfVector2f) {570, 135});
    sfRectangleShape_setPosition(rpg->begin->genders[1]->rect,
        (sfVector2f) {870, 135});
    sfSprite_setPosition(rpg->begin->sprites[0],
        (sfVector2f) {450, 265});
    sfSprite_setPosition(rpg->begin->sprites[1],
        (sfVector2f) {755, 265});
}

void begin_hm(rpg_t *rpg, sfVideoMode res, sfVector2u old_size)
{
    sfText_setPosition(rpg->menu->game_title, (sfVector2f) {530, 150});
    sfRectangleShape_setPosition(rpg->begin->name_bar->rect,
        (sfVector2f) {712, 490});
    sfText_setPosition(rpg->begin->alpha->pre_text,
        (sfVector2f) {847, 505});
    sfRectangleShape_setPosition(rpg->begin->validate->rect,
        (sfVector2f) {785, 585});
    sfText_setPosition(rpg->begin->validate->text,
        (sfVector2f) {855, 587});
    sfRectangleShape_setPosition(rpg->begin->genders[0]->rect,
        (sfVector2f) {755, 150});
    sfRectangleShape_setPosition(rpg->begin->genders[1]->rect,
        (sfVector2f) {1265, 150});
    sfSprite_setPosition(rpg->begin->sprites[0],
        (sfVector2f) {630, 285});
    sfSprite_setPosition(rpg->begin->sprites[1],
        (sfVector2f) {1140, 285});
}

void begin_mm(rpg_t *rpg, sfVideoMode res, sfVector2u old_size)
{
    sfText_setPosition(rpg->menu->game_title, (sfVector2f) {375, 150});
    sfRectangleShape_setPosition(rpg->begin->name_bar->rect,
        (sfVector2f) {712, 510});
    sfText_setPosition(rpg->begin->alpha->pre_text,
        (sfVector2f) {847, 520});
    sfRectangleShape_setPosition(rpg->begin->validate->rect,
        (sfVector2f) {785, 585});
    sfText_setPosition(rpg->begin->validate->text,
        (sfVector2f) {855, 587});
    sfRectangleShape_setPosition(rpg->begin->genders[0]->rect,
        (sfVector2f) {735, 150});
    sfRectangleShape_setPosition(rpg->begin->genders[1]->rect,
        (sfVector2f) {1265, 150});
    sfSprite_setPosition(rpg->begin->sprites[0],
        (sfVector2f) {610, 285});
    sfSprite_setPosition(rpg->begin->sprites[1],
        (sfVector2f) {1140, 285});
}

static void adjust_begin_screen(rpg_t *rpg, sfVideoMode res,
    sfVector2u old_size)
{
    if (res.width == LOW_MODE.width)
        begin_lm(rpg, res, old_size);
    if (res.width == MEDIUM_MODE.width)
        begin_mm(rpg, res, old_size);
    if (res.width == HIGH_MODE.width)
        begin_hm(rpg, res, old_size);
}

static void adjust_settings_bg(rpg_t *rpg, sfVideoMode res)
{
    if (res.width == LOW_MODE.width) {
        sfSprite_setScale(rpg->menu->settings->bground,
            (sfVector2f) {1.60, 1.60});
        sfSprite_setPosition(rpg->menu->settings->bground,
            (sfVector2f) {130, 70});
    }
    if (res.width == MEDIUM_MODE.width) {
        sfSprite_setScale(rpg->menu->settings->bground,
            (sfVector2f) {2, 2});
        sfSprite_setPosition(rpg->menu->settings->bground,
            (sfVector2f) {110, 70});
    }
    if (res.width == HIGH_MODE.width) {
        sfSprite_setScale(rpg->menu->settings->bground,
            (sfVector2f) {2.25, 2.25});
        sfSprite_setPosition(rpg->menu->settings->bground,
            (sfVector2f) {170, 85});
    }
}

void adjust_all(rpg_t *rpg, sfVideoMode res, sfVector2u old_size)
{
    adjust_title_screen(rpg, res, old_size);
    adjust_start_screen(rpg, res, old_size);
    adjust_begin_screen(rpg, res, old_size);
    adjust_settings_screen(rpg, res, old_size);
    adjust_settings_bg(rpg, res);
}
