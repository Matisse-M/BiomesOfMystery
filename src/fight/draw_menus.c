/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** draw_fight_menus
*/

#include "rpg.h"
#include <string.h>

const int pos_x[10] = {50, 55, 60, 60, 50, 50, 60, 50, 50};

static void update_positions(items_fight_t *menu, sfVector2f pos)
{
    for (int i = 0; i < 10; i++) {
        sfRectangleShape_setPosition(menu->items[menu->current]->rect,
            (sfVector2f) {pos.x - 160, pos.y + 85});
        sfText_setPosition(menu->items[menu->current]->text,
            (sfVector2f) {pos.x - 150, pos.y + 91});
        sfText_setPosition(menu->name[menu->current],
            (sfVector2f) {pos.x - pos_x[menu->current], pos.y + 91});
        sfSprite_setPosition(menu->asset[menu->current],
            (sfVector2f) {pos.x - 10, pos.y + 87});
        sfRectangleShape_setPosition(menu->prev->rect,
            (sfVector2f) {pos.x - 175, pos.y + 87});
        sfRectangleShape_setPosition(menu->next->rect,
            (sfVector2f) {pos.x + 30, pos.y + 105});
        sfRectangleShape_setPosition(menu->quit->rect,
            (sfVector2f) {pos.x + 116, pos.y + 70});
        sfText_setPosition(menu->quit->text,
            (sfVector2f) {pos.x + 131, pos.y + 85});
    }
}

static void active_medikit(rpg_t *rpg, items_fight_t *menu)
{
    if (menu->current == 3 && is_animal(rpg->characters->main))
        medikit2(rpg);
}

static void check_item_usage(rpg_t *rpg, items_fight_t *menu)
{
    if (button_view_hover(rpg, menu->items[menu->current])) {
        if (atoi(sfText_getString(menu->items[menu->current]->text)) > 0) {
            sfText_setString(menu->items[menu->current]->text, my_itoa(atoi(
                sfText_getString(menu->items[menu->current]->text)) - 1));
            sfText_setString(rpg->inv->conso->conso[menu->current + 2]->qty,
                my_itoa(atoi(sfText_getString(rpg->inv->conso->conso[
                    menu->current + 2]->qty)) - 1));
            rpg->inv->conso->conso[menu->current + 2]->func(
                rpg->characters->main);
            menu->is_active = false;
            active_medikit(rpg, menu);
            e_attack(rpg);
        }
        menu->items[menu->current]->state = 0;
    }
}

static void check_arrow(rpg_t *rpg, items_fight_t *menu)
{
    if (button_view_hover(rpg, menu->prev)) {
        menu->current -= 1;
        if (menu->current < 0)
            menu->current = 9;
        menu->prev->state = 0;
    }
    if (button_view_hover(rpg, menu->next)) {
        menu->current += 1;
        if (menu->current > 9)
            menu->current = 0;
        menu->next->state = 0;
    }
    if (button_view_hover(rpg, menu->quit)) {
        rpg->fight->items->is_active = false;
        menu->quit->state = 0;
    }
}

static void update_texture(rpg_t *rpg, items_fight_t *menu)
{
    check_item_usage(rpg, menu);
    check_arrow(rpg, menu);
    sfRectangleShape_setTexture(menu->items[menu->current]->rect,
        menu->items[menu->current]->texture[menu->items[menu->current]->state],
        sfTrue);
    sfRectangleShape_setTexture(menu->prev->rect,
        menu->prev->texture[menu->prev->state], sfTrue);
    sfRectangleShape_setTexture(menu->next->rect,
        menu->next->texture[menu->next->state], sfTrue);
    sfRectangleShape_setTexture(menu->quit->rect,
        menu->quit->texture[menu->quit->state], sfTrue);
}

static void draw_other_buttons(rpg_t *rpg, items_fight_t *menu)
{
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        menu->prev->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        menu->next->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        menu->quit->rect, NULL);
}

void draw_item_menu(rpg_t *rpg, items_fight_t *menu)
{
    sfVector2f pos = sfView_getCenter(rpg->game->view);

    if (menu->is_active == true) {
        update_positions(menu, pos);
        update_texture(rpg, menu);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            menu->items[menu->current]->rect, NULL);
        sfRenderWindow_drawText(rpg->game->window,
            menu->items[menu->current]->text, NULL);
        sfRenderWindow_drawText(rpg->game->window,
            menu->name[menu->current], NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            menu->asset[menu->current], NULL);
        draw_other_buttons(rpg, menu);
        sfRenderWindow_drawText(rpg->game->window, menu->quit->text, NULL);
    }
}

void get_reward(rpg_t *rpg)
{
    if (rpg->fight->e_active == 11) {
        rpg->boss->frog = false;
    }
    if (rpg->fight->e_active == 12) {
        rpg->inv->conso->secret[5]->unlock = true;
        rpg->boss->pyro = false;
    }
    if (rpg->fight->e_active == 13) {
        rpg->inv->conso->secret[4]->unlock = true;
        rpg->boss->cryo = false;
    }
    if (rpg->fight->e_active == 14) {
        rpg->inv->conso->secret[3]->unlock = true;
        rpg->boss->cyclop = false;
    }
    if (rpg->fight->e_active == 15) {
        rpg->boss->rajah = false;
    }
}
