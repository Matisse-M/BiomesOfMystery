/*
** EPITECH PROJECT, 2023
** setup player
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"

static button_t *create_btn_res(sfVector2f pos, assets_t *assets,
    sfVector2f pos_text, char *name)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box2h;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {120, 16});
    sfRectangleShape_setPosition(btn->rect, pos);
    btn->text = sfText_create();
    sfText_setString(btn->text, name);
    sfText_setFont(btn->text, assets->font);
    sfText_setCharacterSize(btn->text, 8);
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setPosition(btn->text, pos_text);
    btn->state = 0;
    return btn;
}

static button_t *create_btn_vol(assets_t *assets, char *text)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->btn1;
    btn->texture[1] = assets->btn2;
    btn->texture[2] = assets->btn3;
    btn->texture[3] = assets->btn4;
    btn->state = 0;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {20, 20});
    btn->text = sfText_create();
    sfText_setFont(btn->text, assets->font);
    sfText_setString(btn->text, text);
    sfText_setCharacterSize(btn->text, 8);
    sfText_setFillColor(btn->text, sfBlack);
    return btn;
}

static void create_six_btns(sett_t *sett, assets_t *assets)
{
    sett->resolutions = malloc(sizeof(button_t) * 3);
    sett->resolutions[0] = create_btn_res((sfVector2f) {0, 0}, assets,
        (sfVector2f) {0, 0}, "1300x780");
    sett->resolutions[1] = create_btn_res((sfVector2f) {0, 0}, assets,
        (sfVector2f) {0, 0}, "1600x900");
    sett->resolutions[2] = create_btn_res((sfVector2f) {0, 0}, assets,
        (sfVector2f) {0, 0}, "1920x1080");
    sett->resume = create_btn_res((sfVector2f) {0, 0}, assets,
        (sfVector2f) {0, 0}, "RESUME");
    sett->save = create_btn_res((sfVector2f) {0, 0}, assets,
        (sfVector2f) {0, 0}, "SAVE");
    sett->exit = create_btn_res((sfVector2f) {0, 0}, assets,
        (sfVector2f) {0, 0}, "EXIT");
}

static void create_text_volume(assets_t *assets, sett_t *sett)
{
    sett->music = sfText_create();
    sfText_setString(sett->music, "MUSICS");
    sfText_setFont(sett->music, assets->font);
    sfText_setFillColor(sett->music, sfBlack);
    sfText_setCharacterSize(sett->music, 15);
    sett->sound = sfText_create();
    sfText_setString(sett->sound, "SOUNDS");
    sfText_setFont(sett->sound, assets->font);
    sfText_setFillColor(sett->sound, sfBlack);
    sfText_setCharacterSize(sett->sound, 15);
}

sett_t *fill_settings_menu(assets_t *assets)
{
    sett_t *sett = malloc(sizeof(sett_t));

    sett->musicbar = my_set_sprite(assets->bar100, (sfVector2f) {0, 0},
        (sfVector2f) {4, 2}, 0);
    sett->soundbar = my_set_sprite(assets->bar100, (sfVector2f) {0, 0},
        (sfVector2f) {4, 2}, 0);
    sett->under_music = my_set_sprite(assets->barback, (sfVector2f) {0, 0},
        (sfVector2f) {4, 2}, 0);
    sett->under_sound = my_set_sprite(assets->barback, (sfVector2f) {0, 0},
        (sfVector2f) {4, 2}, 0);
    sett->music_sub = create_btn_vol(assets, "-");
    sett->music_add = create_btn_vol(assets, "+");
    sett->sound_sub = create_btn_vol(assets, "-");
    sett->sound_add = create_btn_vol(assets, "+");
    create_six_btns(sett, assets);
    create_text_volume(assets, sett);
    return sett;
}
