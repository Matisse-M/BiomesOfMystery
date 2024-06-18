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

const int p1[12] = {160, 155, 173, 178, 185, 180, 65, 60, 72, 72, 60, 55};
const int p2[6] = {45, 38, 38, 158, 170, 165};

void update_bag(rpg_t *rpg, conso_t *item)
{
    rpg->characters->main->bag = (atoi(sfText_getString(item->conso[0]->qty)))
        + (atoi(sfText_getString(item->conso[1]->qty))) + (atoi(
        sfText_getString(item->conso[2]->qty))) + (atoi(sfText_getString(
        item->conso[3]->qty))) + (atoi(sfText_getString(item->conso[4]->qty)))
        + (atoi(sfText_getString(item->conso[6]->qty))) + (atoi(
        sfText_getString(item->conso[5]->qty))) + (atoi(sfText_getString(
        item->conso[7]->qty))) + (atoi(sfText_getString(item->conso[8]->qty)))
        + (atoi(sfText_getString(item->conso[9]->qty))) + (atoi(
        sfText_getString(item->conso[10]->qty))) + (atoi(sfText_getString(
        item->conso[11]->qty)));
}

static void restart_boolean(rpg_t *rpg, conso_list_t *conso)
{
    for (int j = 0; j < 12; j++) {
        if (rpg->inv->conso->conso[j] == conso)
            rpg->inv->conso->conso[j]->is_active = true;
        else
            rpg->inv->conso->conso[j]->is_active = false;
    }
}

static void update_position2(sfVector2f pos, secret_t **secret)
{
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_setPosition(secret[i]->btn, (sfVector2f)
            {pos.x + 5, pos.y - 65 + (i * 30)});
        sfSprite_setPosition(secret[i]->sprite, (sfVector2f)
            {pos.x + 85, pos.y - 62 + (i * 30)});
        sfText_setPosition(secret[i]->name, (sfVector2f)
            {pos.x + p2[i], pos.y - 59 + (i * 30)});
    }
    for (int i = 3; i < 6; i++) {
        sfRectangleShape_setPosition(secret[i]->btn, (sfVector2f)
            {pos.x + 115, pos.y - 65 + ((i - 3) * 30)});
        sfSprite_setPosition(secret[i]->sprite, (sfVector2f)
            {pos.x + 195, pos.y - 62 + ((i - 3) * 30)});
        sfText_setPosition(secret[i]->name, (sfVector2f)
            {pos.x + p2[i], pos.y - 59 + ((i - 3) * 30)});
    }
}

static void update_position(sfVector2f pos, conso_t *consos)
{
    for (int i = 0; i < 6; i++) {
        sfRectangleShape_setPosition(consos->conso[i]->btn->rect,
            (sfVector2f) {pos.x - 215, pos.y - 65 + (i * 30)});
        sfSprite_setPosition(consos->conso[i]->sprite, (sfVector2f)
            {pos.x - 135, pos.y - 62 + (i * 30)});
        sfText_setPosition(consos->conso[i]->name, (sfVector2f)
            {pos.x - p1[i], pos.y - 59 + (i * 30)});
        sfText_setPosition(consos->conso[i]->qty, (sfVector2f)
            {pos.x - 208, pos.y - 59 + (i * 30)});
    }
    for (int i = 0; i < 6; i++) {
        sfRectangleShape_setPosition(consos->conso[i + 6]->btn->rect,
            (sfVector2f) {pos.x - 105, pos.y - 65 + (i * 30)});
        sfSprite_setPosition(consos->conso[i + 6]->sprite, (sfVector2f)
            {pos.x - 25, pos.y - 62 + (i * 30)});
        sfText_setPosition(consos->conso[i + 6]->name, (sfVector2f)
            {pos.x - p1[i + 6], pos.y - 59 + (i * 30)});
        sfText_setPosition(consos->conso[i + 6]->qty, (sfVector2f)
            {pos.x - 98, pos.y - 59 + (i * 30)});
    }
}

static void display_secret_list(rpg_t *rpg, secret_t **secret)
{
    for (int i = 0; i < 6; i++) {
        sfRenderWindow_drawRectangleShape(rpg->game->window, secret[i]->btn,
            NULL);
        if (secret[i]->unlock == false)
            sfSprite_setColor(secret[i]->sprite, sfBlack);
        else
            sfSprite_setColor(secret[i]->sprite, sfWhite);
        sfRenderWindow_drawSprite(rpg->game->window, secret[i]->sprite, NULL);
        if (secret[i]->unlock == true)
            sfRenderWindow_drawText(rpg->game->window, secret[i]->name, NULL);
    }
}

static void draw_btn_effect(rpg_t *rpg, conso_list_t *conso)
{
    if (button_view_hover(rpg, conso->btn) == 1) {
        restart_boolean(rpg, conso);
        conso->is_active = true;
        conso->btn->state = 3;
    }
}

static void btn_use(rpg_t *rpg, conso_t *conso, conso_list_t *i)
{
    int nb = atoi(sfText_getString(i->qty));

    if (nb > 0) {
        if (button_view_hover(rpg, conso->rect_use) == 1) {
            conso->rect_use->state = 0;
            nb--;
            i->func(rpg->characters->main);
            sfText_setString(i->qty, my_itoa(nb));
        }
        sfText_setFillColor(conso->rect_use->text, sfBlack);
    } else {
        sfText_setFillColor(conso->rect_use->text,
            (sfColor) {125, 125, 125, 255});
        conso->rect_use->state = 0;
    }
    sfRectangleShape_setTexture(conso->rect_use->rect,
        conso->rect_use->texture[conso->rect_use->state], sfTrue);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        conso->rect_use->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window, conso->rect_use->text, NULL);
}

static void display_conso_list(rpg_t *rpg, conso_t *consos)
{
    for (int i = 0; i < 12; i++) {
        if (consos->conso[i]->is_active == false) {
            draw_btn_effect(rpg, consos->conso[i]);
        } else {
            sfRenderWindow_drawText(rpg->game->window,
                consos->conso[i]->desc, NULL);
            btn_use(rpg, rpg->inv->conso, consos->conso[i]);
        }
        sfRectangleShape_setTexture(consos->conso[i]->btn->rect,
            consos->conso[i]->btn->texture[consos->conso[i]->btn->state],
            sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            consos->conso[i]->btn->rect, NULL);
        sfRenderWindow_drawSprite(rpg->game->window, consos->conso[i]->sprite,
            NULL);
        sfRenderWindow_drawText(rpg->game->window, consos->conso[i]->name,
            NULL);
        sfRenderWindow_drawText(rpg->game->window, consos->conso[i]->qty,
            NULL);
    }
}

static void update_position_from_view(sfVector2f pos, rpg_t *rpg)
{
    update_position(pos, rpg->inv->conso);
    update_position2(pos, rpg->inv->conso->secret);
    sfSprite_setPosition(rpg->inv->conso->piece,
        (sfVector2f) {pos.x + 10, pos.y + 32});
    sfSprite_setPosition(rpg->inv->conso->bag,
        (sfVector2f) {pos.x + 84, pos.y + 33});
    sfRectangleShape_setPosition(rpg->inv->conso->chatbox,
        (sfVector2f) {pos.x + 10, pos.y + 55});
    sfRectangleShape_setPosition(rpg->inv->conso->rect_use->rect,
        (sfVector2f) {pos.x + 182, pos.y + 30});
    sfText_setPosition(rpg->inv->conso->money,
        (sfVector2f) {pos.x + 25, pos.y + 33});
    sfText_setPosition(rpg->inv->conso->stock,
        (sfVector2f) {pos.x + 105, pos.y + 33});
    sfText_setPosition(rpg->inv->conso->rect_use->text,
        (sfVector2f) {pos.x + 190, pos.y + 33});
    for (int i = 0; i < 12; i++)
        sfText_setPosition(rpg->inv->conso->conso[i]->desc,
            (sfVector2f) {pos.x + 17, pos.y + 63});
}

void draw_items_inv(rpg_t *rpg)
{
    sfVector2f pos = sfView_getCenter(rpg->game->view);

    anim_coin(rpg->inv->conso);
    update_position_from_view(pos, rpg);
    sfText_setString(rpg->inv->conso->money, my_itoa(
        rpg->characters->main->money));
    sfText_setString(rpg->inv->conso->stock, my_scat(my_itoa(
        rpg->characters->main->bag), "/25"));
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->conso->chatbox, NULL);
    display_conso_list(rpg, rpg->inv->conso);
    display_secret_list(rpg, rpg->inv->conso->secret);
    sfRenderWindow_drawSprite(rpg->game->window, rpg->inv->conso->piece, NULL);
    sfRenderWindow_drawSprite(rpg->game->window, rpg->inv->conso->bag, NULL);
    sfRenderWindow_drawText(rpg->game->window, rpg->inv->conso->money, NULL);
    sfRenderWindow_drawText(rpg->game->window, rpg->inv->conso->stock, NULL);
}
