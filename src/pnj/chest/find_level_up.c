/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** find_level_up
*/

#include "rpg.h"

void find_if_level_upt(rpg_t *rpg)
{
    if (rpg->quests->is_done == false)
        return;
    update_level(rpg->characters->main);
    rpg->characters->main->emo += 2;
    rpg->characters->main->money += 500;
}
