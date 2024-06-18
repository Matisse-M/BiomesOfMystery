/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** choose_wich_pnj
*/

#include "rpg.h"

void find_swamp(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->swamp_frog->x_min &&
        player->position.x <= rpg->dialogue->swamp_frog->x_max &&
        player->position.y >= rpg->dialogue->swamp_frog->y_min &&
        player->position.y <= rpg->dialogue->swamp_frog->y_max
        && rpg->dialogue->swamp_frog->is_active == false) {
        rpg->dialogue->swamp_frog->can_interact = true;
    } else
        rpg->dialogue->swamp_frog->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->swamp_frog);
    find_if_print(rpg, rpg->dialogue->swamp_frog);
    draw_text_in_chatbox(rpg, rpg->dialogue->swamp_frog);
    if (rpg->quests->discovery[3]->is_discovered &&
        rpg->dialogue->swamp_frog->talked == true) {
        rpg->quests->discovery[4]->is_discovered = false;
        rpg->quests->quests[0]->is_discovered = true;
        rpg->quests->quests[1]->is_discovered = false;
    }
    if (rpg->dialogue->swamp_frog->talked == true)
        rpg->maps->museum->unlock = true;
}

void find_old_bp(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->old_bp->x_min &&
        player->position.x <= rpg->dialogue->old_bp->x_max &&
        player->position.y >= rpg->dialogue->old_bp->y_min &&
        player->position.y <= rpg->dialogue->old_bp->y_max
        && rpg->dialogue->old_bp->is_active == false) {
        rpg->dialogue->old_bp->can_interact = true;
    } else
        rpg->dialogue->old_bp->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->old_bp);
    find_if_print(rpg, rpg->dialogue->old_bp);
    draw_text_in_chatbox(rpg, rpg->dialogue->old_bp);
    if (rpg->quests->discovery[2]->is_discovered &&
        rpg->dialogue->old_bp->talked == true) {
        rpg->quests->discovery[3]->is_discovered = true;
        rpg->maps->swamp->unlock = true;
    }
}

static int find_grado(rpg_t *rpg)
{
    if (rpg->dialogue->kid_bp->can_interact == true &&
        rpg->quests->quests[5]->is_discovered == true &&
        rpg->inv->armor->get_item[3] == true &&
        rpg->inv->armor->get_item[4] == true &&
        rpg->inv->armor->get_item[8] == true &&
        rpg->inv->armor->get_item[9] == true) {
        render_reward_kid(rpg);
            return 1;
    }
    return 0;
}

void find_bp_kid(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->kid_bp->x_min &&
        player->position.x <= rpg->dialogue->kid_bp->x_max &&
        player->position.y >= rpg->dialogue->kid_bp->y_min &&
        player->position.y <= rpg->dialogue->kid_bp->y_max
        && rpg->dialogue->kid_bp->is_active == false) {
        rpg->dialogue->kid_bp->can_interact = true;
    } else
        rpg->dialogue->kid_bp->can_interact = false;
    if (find_grado(rpg) == 1)
        return;
    find_key_interactions_beach(rpg, player, rpg->dialogue->kid_bp);
    find_if_print(rpg, rpg->dialogue->kid_bp);
    draw_text_in_chatbox(rpg, rpg->dialogue->kid_bp);
    if (rpg->dialogue->kid_bp->talked == true)
        rpg->quests->quests[5]->is_discovered = true;
}

void find_old_beach(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->plage_old->x_min &&
        player->position.x <= rpg->dialogue->plage_old->x_max &&
        player->position.y >= rpg->dialogue->plage_old->y_min &&
        player->position.y <= rpg->dialogue->plage_old->y_max
        && rpg->dialogue->plage_old->is_active == false) {
        rpg->dialogue->plage_old->can_interact = true;
    } else
        rpg->dialogue->plage_old->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->plage_old);
    find_if_print(rpg, rpg->dialogue->plage_old);
    draw_text_in_chatbox(rpg, rpg->dialogue->plage_old);
}
