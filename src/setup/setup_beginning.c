/*
** EPITECH PROJECT, 2023
** setup player
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "my.h"
#include "rpg.h"

static alphabet_t *fill_alphabet(assets_t *assets)
{
    alphabet_t *alpha = malloc(sizeof(alphabet_t));

    alpha->is_selsected = false;
    alpha->answer = NULL;
    alpha->size = 0;
    alpha->pre_text = sfText_create();
    sfText_setString(alpha->pre_text, "ENTER  YOUR  NAME");
    sfText_setFont(alpha->pre_text, assets->font);
    sfText_setFillColor(alpha->pre_text, sfBlack);
    sfText_setCharacterSize(alpha->pre_text, 20);
    sfText_setPosition(alpha->pre_text, (sfVector2f) {675, 512});
    alpha->max = 8;
    alpha->write_clock = sfClock_create();
    return alpha;
}

static void set_all_texts(begin_t *begin, assets_t *assets)
{
    begin->name = sfText_create();
    sfText_setFont(begin->name, assets->font);
    sfText_setPosition(begin->name, (sfVector2f) {775, 500});
    sfText_setCharacterSize(begin->name, 32);
    sfText_setString(begin->name, begin->alpha->answer);
    sfText_setFillColor(begin->name, sfBlack);
}

begin_t *fill_beginning_menu(assets_t *assets)
{
    begin_t *begin = malloc(sizeof(begin_t));

    begin->is_active = false;
    begin->gender = 1;
    begin->clock = sfClock_create();
    begin->alpha = fill_alphabet(assets);
    begin->textures = malloc(sizeof(sfTexture *) * 2);
    begin->sprites = malloc(sizeof(sfSprite *) * 2);
    begin->genders = malloc(sizeof(button_t *) * 2);
    return begin;
}

void fill_anim_layer(rpg_t *rpg)
{
    rpg->begin->textures[0] = sfTexture_createFromFile(
        my_scat(rpg->name, "/PNJ/main-male/SpriteSheet.png"), NULL);
    rpg->begin->textures[1] = sfTexture_createFromFile(
        my_scat(rpg->name, "/PNJ/main-female/SpriteSheet.png"), NULL);
    if (rpg->begin->textures[0] == NULL || rpg->begin->textures[1] == NULL)
        exit(84);
    rpg->begin->sprites[0] = my_set_sprite(rpg->begin->textures[0],
        (sfVector2f) {615, 350}, (sfVector2f) {4, 4}, 0);
    rpg->begin->sprites[1] = my_set_sprite(rpg->begin->textures[1],
        (sfVector2f) {885, 350}, (sfVector2f) {4, 4}, 0);
    rpg->begin->genders[0] = create_button2((sfVector2f) {725, 150},
        rpg->assets);
    rpg->begin->genders[1] = create_button2((sfVector2f) {1010, 150},
        rpg->assets);
    rpg->begin->name_bar = create_button3(rpg->assets);
    rpg->begin->validate = create_button((sfVector2f) {612.5, 600}, rpg->assets
        , (sfVector2f) {612.5 + 75, 600}, "START");
    set_all_texts(rpg->begin, rpg->assets);
    rpg->maps->center = (sfVector2f) {640, 160};
    int_anim(rpg);
}
