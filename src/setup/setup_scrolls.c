/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** setup_fight
*/

#include "rpg.h"

static button_t *create_fbutton(sfVector2f size, assets_t *assets, char *name)
{
    button_t *btn = calloc(1, sizeof(button_t));

    btn->texture[0] = assets->box3;
    btn->texture[1] = assets->box1;
    btn->texture[2] = assets->box1h;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, size);
    btn->text = sfText_create();
    sfText_setFont(btn->text, assets->font);
    sfText_setCharacterSize(btn->text, 15);
    sfText_setColor(btn->text, sfBlack);
    sfText_setString(btn->text, name);
    return btn;
}

scroll_t *fill_scroll_menu(rpg_t *rpg)
{
    scroll_t *scroll = malloc(sizeof(scroll_t));

    scroll->is_active = false;
    scroll->scroll[0] = rpg->inv->conso->secret[3]->sprite;
    scroll->scroll[1] = rpg->inv->conso->secret[4]->sprite;
    scroll->scroll[2] = rpg->inv->conso->secret[5]->sprite;
    scroll->btn[0] = create_fbutton((sfVector2f) {100, 50},
        rpg->assets, "STONE");
    scroll->btn[1] = create_fbutton((sfVector2f) {100, 50},
        rpg->assets, "ICE");
    scroll->btn[2] = create_fbutton((sfVector2f) {100, 50},
        rpg->assets, "FIRE");
    scroll->quit = create_fbutton((sfVector2f) {100, 50},
        rpg->assets, "RETURN");
    return scroll;
}
