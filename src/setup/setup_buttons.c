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

button_t *create_button(sfVector2f pos, assets_t *assets,
    sfVector2f pos_text, char *name)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box2h;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {316, 60});
    sfRectangleShape_setPosition(btn->rect, pos);
    btn->text = sfText_create();
    sfText_setString(btn->text, name);
    sfText_setFont(btn->text, assets->font);
    sfText_setCharacterSize(btn->text, 45);
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setPosition(btn->text, pos_text);
    btn->state = 0;
    return btn;
}

button_t *create_button2(sfVector2f pos, assets_t *assets)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box2h;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setPosition(btn->rect, pos);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {316, 60});
    sfRectangleShape_setRotation(btn->rect, 90);
    sfRectangleShape_setScale(btn->rect, (sfVector2f) {1, 3});
    btn->text = NULL;
    btn->state = 0;
    return btn;
}

button_t *create_button3(assets_t *assets)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box3;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {316, 60});
    sfRectangleShape_setScale(btn->rect, (sfVector2f) {1.5, 1});
    sfRectangleShape_setPosition(btn->rect, (sfVector2f) {542, 495});
    btn->text = NULL;
    btn->state = 0;
    return btn;
}

button_t *create_button_arrow(sfVector2f pos, assets_t *assets,
    sfVector2f pos_text, char *name)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box2h;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {345, 160});
    sfRectangleShape_setPosition(btn->rect, pos);
    btn->text = sfText_create();
    sfText_setString(btn->text, name);
    sfText_setFont(btn->text, assets->font);
    sfText_setCharacterSize(btn->text, 45);
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setPosition(btn->text, pos_text);
    btn->state = 0;
    return btn;
}

button_t *create_button_arrow_game(sfVector2f pos, assets_t *assets,
    sfVector2f pos_text, char *name)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box2h;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {70, 30});
    sfRectangleShape_setPosition(btn->rect, pos);
    btn->text = sfText_create();
    sfText_setString(btn->text, name);
    sfText_setFont(btn->text, assets->font);
    sfText_setCharacterSize(btn->text, 10);
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setPosition(btn->text, pos_text);
    btn->state = 0;
    return btn;
}
