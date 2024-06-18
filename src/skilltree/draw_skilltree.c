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

const char *cost[6] = {"FREE", "-1  GPA", "-4  GPA", "-7  GPA",
    "-8  GPA", "DONE!"};

static void btns_effect(rpg_t *rpg, skilltree_t *tree)
{
    if (button_view_hover(rpg, tree->btn[0]) == 1) {
        apply_atk_effect(rpg, tree, tree->atk_progress);
        tree->btn[0]->state = 0;
    }
    if (button_view_hover(rpg, tree->btn[1]) == 1) {
        apply_hp_effect(rpg, tree, tree->hp_progress);
        tree->btn[1]->state = 0;
    }
}

static void draw_learn_btns(rpg_t *rpg, skilltree_t *tree, sfVector2f pos)
{
    sfText_setString(tree->btn[0]->text, cost[tree->atk_progress]);
    sfText_setString(tree->btn[1]->text, cost[tree->hp_progress]);
    sfRectangleShape_setPosition(tree->btn[0]->rect,
        (sfVector2f) {pos.x - 100, pos.y + 70});
    sfRectangleShape_setPosition(tree->btn[1]->rect,
        (sfVector2f) {pos.x + 55, pos.y + 70});
    btns_effect(rpg, tree);
    sfText_setPosition(tree->btn[0]->text,
        (sfVector2f) {pos.x - 90, pos.y + 77});
    sfText_setPosition(tree->btn[1]->text,
        (sfVector2f) {pos.x + 65, pos.y + 77});
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        tree->btn[0]->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        tree->btn[1]->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window, tree->btn[0]->text, NULL);
    sfRenderWindow_drawText(rpg->game->window, tree->btn[1]->text, NULL);
}

static void texture_elem(assets_t *assets, skilltree_t *tree)
{
    for (int i = 0; i < 5; i++) {
        if (i < tree->atk_progress)
            sfRectangleShape_setTexture(tree->atk_btn[i],
                assets->box2, sfTrue);
        if (i == tree->atk_progress)
            sfRectangleShape_setTexture(tree->atk_btn[i],
                assets->box3, sfTrue);
        if (i > tree->atk_progress)
            sfRectangleShape_setTexture(tree->atk_btn[i],
                assets->box1, sfTrue);
        if (i < tree->hp_progress)
            sfRectangleShape_setTexture(tree->hp_btn[i], assets->box2, sfTrue);
        if (i == tree->hp_progress)
            sfRectangleShape_setTexture(tree->hp_btn[i], assets->box3, sfTrue);
        if (i > tree->hp_progress)
            sfRectangleShape_setTexture(tree->hp_btn[i], assets->box1, sfTrue);
    }
}

static void draw_stat_values(rpg_t *rpg, skilltree_t *tree, sfVector2f pos)
{
    sfText_setString(tree->val_gpa, my_itoa(rpg->characters->main->emo));
    sfText_setString(tree->val_atk, my_itoa(rpg->characters->main->atk));
    sfText_setString(tree->val_hp, my_itoa(rpg->characters->main->hp));
    sfText_setPosition(tree->gpa, (sfVector2f) {pos.x - 30, pos.y - 35});
    sfText_setPosition(tree->atk, (sfVector2f) {pos.x - 30, pos.y - 15});
    sfText_setPosition(tree->hp, (sfVector2f) {pos.x - 30, pos.y + 5});
    sfText_setPosition(tree->val_gpa, (sfVector2f) {pos.x + 15, pos.y - 35});
    sfText_setPosition(tree->val_atk, (sfVector2f) {pos.x + 15, pos.y - 15});
    sfText_setPosition(tree->val_hp, (sfVector2f) {pos.x + 15, pos.y + 5});
    sfRenderWindow_drawText(rpg->game->window, tree->gpa, NULL);
    sfRenderWindow_drawText(rpg->game->window, tree->atk, NULL);
    sfRenderWindow_drawText(rpg->game->window, tree->hp, NULL);
    sfRenderWindow_drawText(rpg->game->window, tree->val_gpa, NULL);
    sfRenderWindow_drawText(rpg->game->window, tree->val_atk, NULL);
    sfRenderWindow_drawText(rpg->game->window, tree->val_hp, NULL);
}

static void draw_new_abilities(rpg_t *rpg, skilltree_t *tree, sfVector2f pos)
{
    for (int i = 0; i < 5; i++) {
        sfRectangleShape_setPosition(tree->atk_btn[i],
            (sfVector2f) {pos.x - 150, pos.y - 90 + (32 * i)});
        sfRectangleShape_setPosition(tree->hp_btn[i],
            (sfVector2f) {pos.x + 55, pos.y - 90 + (32 * i)});
        sfText_setPosition(tree->atk_effect[i],
            (sfVector2f) {pos.x - 140, pos.y - 83 + (32 * i)});
        sfText_setPosition(tree->hp_effect[i],
            (sfVector2f) {pos.x + 65, pos.y - 83 + (32 * i)});
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            tree->atk_btn[i], NULL);
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            tree->hp_btn[i], NULL);
        sfRenderWindow_drawText(rpg->game->window, tree->atk_effect[i], NULL);
        sfRenderWindow_drawText(rpg->game->window, tree->hp_effect[i], NULL);
    }
}

void draw_skilltree(rpg_t *rpg, skilltree_t *tree)
{
    sfVector2f pos = sfView_getCenter(rpg->game->view);

    sfRectangleShape_setPosition(tree->bck,
        (sfVector2f) {pos.x - 250, pos.y - 140});
    sfRenderWindow_drawRectangleShape(rpg->game->window, tree->bck, NULL);
    texture_elem(rpg->assets, tree);
    draw_new_abilities(rpg, tree, pos);
    draw_stat_values(rpg, tree, pos);
    draw_learn_btns(rpg, tree, pos);
}
