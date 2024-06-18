/*
** EPITECH PROJECT, 2023
** setup menu
** File description:
** Some function to setup <menu_t *menu;> in rpg_t
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"


static button_t *create_btn_vol(assets_t *assets, char *text, sfVector2f pos)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->btn1;
    btn->texture[1] = assets->btn2;
    btn->texture[2] = assets->btn3;
    btn->texture[3] = assets->btn4;
    btn->state = 0;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {60, 60});
    sfRectangleShape_setPosition(btn->rect, pos);
    btn->text = sfText_create();
    sfText_setFont(btn->text, assets->font);
    sfText_setString(btn->text, text);
    sfText_setCharacterSize(btn->text, 36);
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setPosition(btn->text, (sfVector2f) {pos.x + 18, pos.y + 5});
    return btn;
}

static title_screen_t *fill_title_screen(assets_t *assets)
{
    title_screen_t *title = malloc(sizeof(title_screen_t));

    title->is_active = true;
    title->start_btn = create_button((sfVector2f) {640, 350}, assets,
        (sfVector2f) {640 + 68, 350}, "START");
    title->settings_btn = create_button((sfVector2f) {640, 450}, assets,
        (sfVector2f) {640 + 25, 450}, "SETTINGS");
    title->quit_btn = create_button((sfVector2f) {640, 550}, assets,
        (sfVector2f) {640 + 85, 550}, "QUIT");
    return title;
}

static start_menu_t *fill_start_menu(assets_t *assets)
{
    start_menu_t *start = malloc(sizeof(start_menu_t));

    start->is_active = false;
    start->new_btn = create_button((sfVector2f) {640, 350}, assets,
        (sfVector2f) {640 + 30, 350}, "NEW GAME");
    start->resume_btn = create_button((sfVector2f) {640, 450}, assets,
        (sfVector2f) {640 + 55, 450}, "RESUME");
    start->quit_btn = create_button((sfVector2f) {640, 550}, assets,
        (sfVector2f) {640 + 55, 550}, "RETURN");
    return start;
}

static void create_text_volume(assets_t *assets, settings_t *sett)
{
    sett->music = sfText_create();
    sfText_setString(sett->music, "MUSICS");
    sfText_setFont(sett->music, assets->font);
    sfText_setFillColor(sett->music, sfBlack);
    sfText_setCharacterSize(sett->music, 36);
    sfText_setPosition(sett->music, (sfVector2f) {368.75, 245});
    sett->sound = sfText_create();
    sfText_setString(sett->sound, "SOUNDS");
    sfText_setFont(sett->sound, assets->font);
    sfText_setFillColor(sett->sound, sfBlack);
    sfText_setCharacterSize(sett->sound, 36);
    sfText_setPosition(sett->sound, (sfVector2f) {1056.25, 245});
}

static void setup_resolutions(assets_t *assets, settings_t *settings)
{
    settings->resolutions = malloc(sizeof(button_t **) * 3);
    settings->resolutions[0] = create_button((sfVector2f) {185, 400}, assets,
        (sfVector2f) {185 + 42, 400}, "1300x780");
    settings->resolutions[1] = create_button((sfVector2f) {615, 400}, assets,
        (sfVector2f) {615 + 33, 400}, "1600x900");
    settings->resolutions[2] = create_button((sfVector2f) {1015, 400}, assets,
        (sfVector2f) {1015 + 33, 400}, "1920x1080");
    settings->quit_btn = create_button((sfVector2f) {602.5, 550}, assets,
        (sfVector2f) {602.5 + 55, 550}, "RETURN");
}

static void set_mus_buttons(assets_t *assets, settings_t *settings)
{
    settings->music_sub = create_btn_vol(assets, "-", (sfVector2f) {260, 285});
    settings->music_add = create_btn_vol(assets, "+", (sfVector2f) {595, 285});
    settings->sound_sub = create_btn_vol(assets, "-", (sfVector2f) {935, 285});
    settings->sound_add = create_btn_vol(assets, "+",
        (sfVector2f) {1260, 285});
}

static settings_t *fill_settings(assets_t *assets)
{
    settings_t *settings = malloc(sizeof(settings_t));

    settings->is_active = false;
    settings->bground = my_set_sprite(assets->settings_bg,
        (sfVector2f) {110, 70}, (sfVector2f) {1, 1}, 0);
    sfSprite_setScale(settings->bground, (sfVector2f) {2, 2});
    settings->musicbar = my_set_sprite(assets->bar100,
        (sfVector2f) {362, 300}, (sfVector2f) {10, 5}, 0);
    settings->soundbar = my_set_sprite(assets->bar100,
        (sfVector2f) {1052, 300}, (sfVector2f) {10, 5}, 0);
    settings->under_music = my_set_sprite(assets->barback,
        (sfVector2f) {362, 300}, (sfVector2f) {10, 5}, 0);
    settings->under_sound = my_set_sprite(assets->barback,
        (sfVector2f) {1052, 300}, (sfVector2f) {10, 5}, 0);
    set_mus_buttons(assets, settings);
    create_text_volume(assets, settings);
    setup_resolutions(assets, settings);
    return settings;
}

menu_t *fill_menu(rpg_t *rpg, assets_t *assets)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->is_active = true;
    menu->title = fill_title_screen(assets);
    menu->start = fill_start_menu(assets);
    menu->settings = fill_settings(assets);
    menu->background = my_set_sprite(sfTexture_createFromFile
        (my_scat(rpg->name, "/img/menu/menu1.png"), NULL), (sfVector2f)
        {0, 0}, (sfVector2f) {1, 1}, 0);
    menu->game_title = sfText_create();
    sfText_setString(menu->game_title, "BIOMES    OF    MYSTERY...");
    sfText_setFont(menu->game_title, rpg->assets->font);
    sfText_setCharacterSize(menu->game_title, 65);
    sfText_setPosition(menu->game_title, (sfVector2f) {375, 150});
    sfText_setColor(menu->game_title, sfColor_fromRGB(22, 23, 32));
    return menu;
}
