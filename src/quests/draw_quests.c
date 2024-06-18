/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** draw_quests
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"

void update_pos_quests(quests_t *quests, sfVector2f pos)
{
    for (int i = 0; i < 8; i++) {
        sfRectangleShape_setSize(quests->btn[i]->btn->rect,
            (sfVector2f) {160, 30});
        sfText_setCharacterSize(quests->btn[i]->btn->text, 13);
    }
    for (int i = 0; i < 4; i++)
        update_pos(quests->btn[i], (sfVector2f) {pos.x - 190, pos.y - 62.5
            + (i * 45)}, (sfVector2f) {pos.x - 177, pos.y - 58 + (i * 45)});
    for (int j = 0; j < 4; j++)
        update_pos(quests->btn[j + 4], (sfVector2f) {pos.x + 12, pos.y - 62.5
            + (j * 45)}, (sfVector2f) {pos.x + 25, pos.y - 58 + (j * 45)});
}

void hover_clicked_quests(rpg_t *rpg, inv_btn_t *btn)
{
    for (int i = 0; i < 8; i++)
        rpg->quests->btn[i]->is_active = false;
    btn->is_active = true;
}

static void set_not_discovered(rpg_t *rpg)
{
    if (!rpg->quests->discovery[0]->is_discovered)
        rpg->quests->btn[0]->is_discovered = false;
    else
        rpg->quests->btn[0]->is_discovered = true;
    for (int i = 0; rpg->quests->quests[i]; i++)
        if (!rpg->quests->quests[i]->is_discovered)
            rpg->quests->btn[i + 1]->is_discovered = false;
        else
            rpg->quests->btn[i + 1]->is_discovered = true;
}

static void draw_a_quest_btn(rpg_t *rpg, int i)
{
    if (rpg->quests->btn[i]->is_active == true) {
        sfRectangleShape_setTexture(rpg->quests->btn[i]->btn->rect,
            rpg->quests->btn[i]->btn->texture[3], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->quests->btn[i]->btn->rect, NULL);
    } else {
        if (button_view_hover(rpg, rpg->quests->btn[i]->btn) == 1)
            hover_clicked_quests(rpg, rpg->quests->btn[i]);
        sfRectangleShape_setTexture(rpg->quests->btn[i]->btn->rect, rpg->quests
            ->btn[i]->btn->texture[rpg->quests->btn[i]->btn->state], sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->quests->btn[i]->btn->rect, NULL);
    }
}

static void if_quests_completed(rpg_t *rpg)
{
    for (int i = 0; rpg->quests->quests[i]; i++) {
        if (rpg->quests->quests[i]->is_completed == true) {
            sfRectangleShape_setTexture(rpg->quests->btn[i + 1]->btn->rect,
                rpg->assets->wrong, sfTrue);
            sfRenderWindow_drawRectangleShape(rpg->game->window,
                rpg->quests->btn[i + 1]->btn->rect, NULL);
            sfRenderWindow_drawText(rpg->game->window,
                    rpg->quests->btn[i + 1]->btn->text, NULL);
        }
    }
}

static void if_discovery_completed(rpg_t *rpg)
{
    if (rpg->quests->is_done) {
        sfRectangleShape_setTexture(rpg->quests->btn[0]->btn->rect,
            rpg->assets->wrong, sfTrue);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->quests->btn[0]->btn->rect, NULL);
        sfRenderWindow_drawText(rpg->game->window,
                rpg->quests->btn[0]->btn->text, NULL);
    }
}

void draw_quests(rpg_t *rpg, sfVector2f pos)
{
    set_not_discovered(rpg);
    for (int i = 0; i < 8; i++) {
        update_pos_quests(rpg->quests, pos);
        if (rpg->quests->btn[i]->is_discovered == true) {
            draw_a_quest_btn(rpg, i);
        } else {
            sfRectangleShape_setTexture(rpg->quests->btn[i]->btn->rect,
                rpg->assets->wrong, sfTrue);
            sfRenderWindow_drawRectangleShape(rpg->game->window,
                rpg->quests->btn[i]->btn->rect, NULL);
        }
        if (rpg->quests->btn[i]->is_discovered)
            sfRenderWindow_drawText(rpg->game->window,
                rpg->quests->btn[i]->btn->text, NULL);
        if_discovery_completed(rpg);
    }
    if_quests_completed(rpg);
}
