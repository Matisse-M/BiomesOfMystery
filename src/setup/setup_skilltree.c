/*
** EPITECH PROJECT, 2023
** setup game params
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"

const char *atk_tree[5] = {"ATK  +  5", "ATK  +  5", "CRITICAL  HITS",
    "WEAPONS  X2", "ATK  +  20"};

const char *hp_tree[5] = {"HP  +  5", "HP  +  5", "RICOCHETS",
    "SUSTAIN", "HP  +  20"};

static button_t *create_learn_btn(assets_t *assets)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box3;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {50, 22});
    btn->text = sfText_create();
    sfText_setFont(btn->text, assets->font);
    sfText_setCharacterSize(btn->text, 8);
    sfText_setFillColor(btn->text, sfBlack);
    btn->state = 0;
    return btn;
}

static void create_tree_atk_hp(assets_t *assets, skilltree_t *tree)
{
    for (int i = 0; i < 5; i++) {
        tree->atk_btn[i] = sfRectangleShape_create();
        sfRectangleShape_setTexture(tree->atk_btn[i], assets->box1, sfTrue);
        sfRectangleShape_setSize(tree->atk_btn[i], (sfVector2f) {100, 22});
        tree->hp_btn[i] = sfRectangleShape_create();
        sfRectangleShape_setTexture(tree->hp_btn[i], assets->box1, sfTrue);
        sfRectangleShape_setSize(tree->hp_btn[i], (sfVector2f) {100, 22});
        tree->atk_effect[i] = sfText_create();
        sfText_setFont(tree->atk_effect[i], assets->font);
        sfText_setString(tree->atk_effect[i], atk_tree[i]);
        sfText_setCharacterSize(tree->atk_effect[i], 8);
        sfText_setFillColor(tree->atk_effect[i], sfBlack);
        tree->hp_effect[i] = sfText_create();
        sfText_setFont(tree->hp_effect[i], assets->font);
        sfText_setString(tree->hp_effect[i], hp_tree[i]);
        sfText_setCharacterSize(tree->hp_effect[i], 8);
        sfText_setFillColor(tree->hp_effect[i], sfBlack);
    }
}

static void create_statistic(assets_t *assets, skilltree_t *tree)
{
    tree->atk = sfText_create();
    sfText_setFont(tree->atk, assets->font);
    sfText_setString(tree->atk, "ATK:");
    sfText_setCharacterSize(tree->atk, 15);
    sfText_setFillColor(tree->atk, sfBlack);
    tree->hp = sfText_create();
    sfText_setFont(tree->hp, assets->font);
    sfText_setString(tree->hp, "      HP:");
    sfText_setCharacterSize(tree->hp, 15);
    sfText_setFillColor(tree->hp, sfBlack);
    tree->val_atk = sfText_create();
    sfText_setFont(tree->val_atk, assets->font);
    sfText_setCharacterSize(tree->val_atk, 15);
    sfText_setFillColor(tree->val_atk, sfBlack);
    tree->val_hp = sfText_create();
    sfText_setFont(tree->val_hp, assets->font);
    sfText_setCharacterSize(tree->val_hp, 15);
    sfText_setFillColor(tree->val_hp, sfBlack);
}

static void create_gpa(assets_t *assets, skilltree_t *tree)
{
    tree->gpa = sfText_create();
    sfText_setFont(tree->gpa, assets->font);
    sfText_setString(tree->gpa, "GPA:");
    sfText_setCharacterSize(tree->gpa, 15);
    sfText_setFillColor(tree->gpa, sfBlack);
    tree->val_gpa = sfText_create();
    sfText_setCharacterSize(tree->val_gpa, 15);
    sfText_setFillColor(tree->val_gpa, sfBlack);
    sfText_setFont(tree->val_gpa, assets->font);
}

skilltree_t *fill_skilltree(assets_t *assets)
{
    skilltree_t *tree = malloc(sizeof(skilltree_t));

    tree->is_active = false;
    tree->unlock = false;
    tree->atk_progress = 1;
    tree->hp_progress = 1;
    create_tree_atk_hp(assets, tree);
    create_statistic(assets, tree);
    create_gpa(assets, tree);
    tree->bck = sfRectangleShape_create();
    sfRectangleShape_setTexture(tree->bck, assets->box2, sfTrue);
    sfRectangleShape_setSize(tree->bck, (sfVector2f) {500, 280});
    tree->btn[0] = create_learn_btn(assets);
    tree->btn[1] = create_learn_btn(assets);
    return tree;
}
