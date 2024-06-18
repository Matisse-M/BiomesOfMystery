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

void apply_atk_effect(rpg_t *rpg, skilltree_t *tree, int i)
{
    if (i == 1 && rpg->characters->main->emo >= 1) {
        tree->atk_progress += 1;
        rpg->characters->main->emo -= 1;
        rpg->characters->main->atk += 5;
    }
    if (i == 2 && rpg->characters->main->emo >= 4) {
        tree->atk_progress += 1;
        rpg->characters->main->emo -= 4;
        rpg->characters->main->critical = true;
    }
    if (i == 3 && rpg->characters->main->emo >= 7) {
        tree->atk_progress += 1;
        rpg->characters->main->emo -= 7;
        rpg->characters->main->boost = true;
    }
    if (i == 4 && rpg->characters->main->emo >= 8) {
        tree->atk_progress += 1;
        rpg->characters->main->emo -= 8;
        rpg->characters->main->atk += 20;
    }
}

static void last_hp_effect(rpg_t *rpg, skilltree_t *tree, int i)
{
    if (i == 4 && rpg->characters->main->emo >= 8) {
        tree->hp_progress += 1;
        rpg->characters->main->emo -= 8;
        rpg->characters->main->hp_max += 20;
        rpg->characters->main->hp += 20;
    }
}

void apply_hp_effect(rpg_t *rpg, skilltree_t *tree, int i)
{
    if (i == 1 && rpg->characters->main->emo >= 1) {
        tree->hp_progress += 1;
        rpg->characters->main->emo -= 1;
        rpg->characters->main->hp_max += 5;
        rpg->characters->main->hp += 5;
    }
    if (i == 2 && rpg->characters->main->emo >= 4) {
        tree->hp_progress += 1;
        rpg->characters->main->emo -= 4;
        rpg->characters->main->critical = true;
    }
    if (i == 3 && rpg->characters->main->emo >= 7) {
        tree->hp_progress += 1;
        rpg->characters->main->emo -= 7;
        rpg->characters->main->boost = true;
    }
    last_hp_effect(rpg, tree, i);
}
