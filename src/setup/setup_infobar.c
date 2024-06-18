/*
** EPITECH PROJECT, 2024
** crpg
** File description:
** setup_infobar
*/

#include "rpg.h"

static void create_text_infobar(rpg_t *rpg, info_bar_t *infobar)
{
    infobar->name = sfText_create();
    sfText_setFont(infobar->name, rpg->assets->font);
    sfText_setFillColor(infobar->name, sfBlack);
    sfText_setCharacterSize(infobar->name, 6);
    infobar->lvl = sfText_create();
    sfText_setFont(infobar->lvl, rpg->assets->font);
    sfText_setFillColor(infobar->lvl, sfBlack);
    sfText_setCharacterSize(infobar->lvl, 6);
    infobar->quest = sfText_create();
    sfText_setFont(infobar->quest, rpg->assets->font);
    sfText_setFillColor(infobar->quest, sfBlack);
    sfText_setCharacterSize(infobar->quest, 6);
}

info_bar_t *fill_infobar(rpg_t *rpg)
{
    info_bar_t *infobar = malloc(sizeof(info_bar_t));

    infobar->is_active = false;
    infobar->sprite = sfSprite_create();
    infobar->exp[0] = sfSprite_create();
    create_text_infobar(rpg, infobar);
    sfSprite_setTexture(infobar->exp[0], rpg->assets->barback, sfTrue);
    sfSprite_setScale(infobar->exp[0], (sfVector2f) {5.5, 2});
    infobar->exp[1] = sfSprite_create();
    sfSprite_setTexture(infobar->exp[1], rpg->assets->expbar, sfTrue);
    sfSprite_setScale(infobar->exp[1], (sfVector2f) {5.5, 2});
    sfSprite_setTexture(infobar->sprite, rpg->assets->info_bar, sfTrue);
    sfSprite_setScale(infobar->sprite, (sfVector2f) {0.20, 0.20});
    infobar->box = sfSprite_create();
    sfSprite_setTexture(infobar->box, sfTexture_createFromFile(my_scat
        (rpg->name, "/img/box.png"), NULL), sfTrue);
    sfSprite_setScale(infobar->box, (sfVector2f) {0.45, 0.45});
    return infobar;
}
