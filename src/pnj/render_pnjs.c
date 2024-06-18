/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** render_pnjs
*/

#include "rpg.h"

void render_pnjs(rpg_t *rpg)
{
    if (rpg->maps->upstairs->is_active == true)
        find_if_pnjs(rpg, rpg->characters->main, rpg->maps->upstairs);
    find_pnj_upt(rpg);
}

void find_pnj_rest(rpg_t *rpg)
{
    if (rpg->maps->village->is_active == true) {
        find_old_bp(rpg, rpg->characters->main);
        find_bp_kid(rpg, rpg->characters->main);
        find_cow(rpg, rpg->characters->main);
    }
    find_pnj_upt(rpg);
}

static int find_grad(rpg_t *rpg)
{
    if (rpg->dialogue->museum_satue->can_interact == true &&
        rpg->quests->quests[1]->is_discovered == true
        && rpg->quests->quests[1]->is_completed == false
        && rpg->inv->armor->get_item[5] == true) {
        draw_reward(rpg, rpg->dialogue->museum_satue);
        return 1;
    }
    return 0;
}

static void find_statue(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->museum_satue->x_min &&
        player->position.x <= rpg->dialogue->museum_satue->x_max &&
        player->position.y >= rpg->dialogue->museum_satue->y_min &&
        player->position.y <= rpg->dialogue->museum_satue->y_max)
        rpg->dialogue->museum_satue->can_interact = true;
    else
        rpg->dialogue->museum_satue->can_interact = false;
    if (find_grad(rpg) == 1)
        return;
    find_key_interactions(rpg, player, rpg->dialogue->museum_satue);
    find_if_print(rpg, rpg->dialogue->museum_satue);
    draw_text_in_chatbox(rpg, rpg->dialogue->museum_satue);
    if (rpg->dialogue->museum_satue->talked == true) {
        rpg->quests->quests[1]->is_discovered = true;
        rpg->maps->maze->unlock = true;
    }
}

void find_pnjs(rpg_t *rpg)
{
    if (rpg->maps->museum->is_active == true) {
        find_museum_blue(rpg, rpg->characters->main, rpg->maps->downstairs);
        find_statue(rpg, rpg->characters->main);
        find_museum_red(rpg, rpg->characters->main, rpg->maps->downstairs);
    }
    if (rpg->maps->beach->is_active == true) {
        find_beach(rpg, rpg->characters->main);
        find_qna(rpg, rpg->characters->main);
        find_old_beach(rpg, rpg->characters->main);
        find_kid_beach(rpg, rpg->characters->main);
    }
    if (rpg->maps->swamp->is_active == true)
        find_swamp(rpg, rpg->characters->main);
    find_pnj_rest(rpg);
}
