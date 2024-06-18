/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** find_if_pnjs
*/

#include "rpg.h"

void find_if_pnjs(rpg_t *rpg, main_player_t *player, room_t *room)
{
    if (player->position.x >= rpg->dialogue->aymeric->x_min &&
        player->position.x <= rpg->dialogue->aymeric->x_max &&
        player->position.y >= rpg->dialogue->aymeric->y_min &&
        player->position.y <= rpg->dialogue->aymeric->y_max
        && rpg->dialogue->aymeric->is_active == false) {
        rpg->dialogue->aymeric->can_interact = true;
    } else
        rpg->dialogue->aymeric->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->aymeric);
    find_if_print(rpg, rpg->dialogue->aymeric);
    draw_text_in_chatbox(rpg, rpg->dialogue->aymeric);
    if (rpg->quests->discovery[0]->is_discovered &&
        rpg->dialogue->aymeric->talked == true) {
        rpg->quests->discovery[1]->is_discovered = true;
        rpg->maps->beach->unlock = true;
    }
}

void find_museum_blue(rpg_t *rpg, main_player_t *player, room_t *room)
{
    if (player->position.x >= rpg->dialogue->museum_blue->x_min &&
        player->position.x <= rpg->dialogue->museum_blue->x_max &&
        player->position.y >= rpg->dialogue->museum_blue->y_min &&
        player->position.y <= rpg->dialogue->museum_blue->y_max
        && rpg->dialogue->museum_blue->is_active == false) {
        rpg->dialogue->museum_blue->can_interact = true;
    } else
        rpg->dialogue->museum_blue->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->museum_blue);
    find_if_print(rpg, rpg->dialogue->museum_blue);
    draw_text_in_chatbox(rpg, rpg->dialogue->museum_blue);
    if (rpg->dialogue->museum_blue->talked == true) {
        rpg->quests->quests[1]->is_discovered = false;
        rpg->quests->quests[2]->is_discovered = true;
    }
}

void find_museum_red(rpg_t *rpg, main_player_t *player, room_t *room)
{
    if (player->position.x >= rpg->dialogue->museum_red->x_min &&
        player->position.x <= rpg->dialogue->museum_red->x_max &&
        player->position.y >= rpg->dialogue->museum_red->y_min &&
        player->position.y <= rpg->dialogue->museum_red->y_max
        && rpg->dialogue->museum_red->is_active == false) {
        rpg->dialogue->museum_red->can_interact = true;
    } else
        rpg->dialogue->museum_red->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->museum_red);
    find_if_print(rpg, rpg->dialogue->museum_red);
    draw_text_in_chatbox(rpg, rpg->dialogue->museum_red);
}

void find_beach(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->plage_ninja->x_min &&
        player->position.x <= rpg->dialogue->plage_ninja->x_max &&
        player->position.y >= rpg->dialogue->plage_ninja->y_min &&
        player->position.y <= rpg->dialogue->plage_ninja->y_max
        && rpg->dialogue->plage_ninja->is_active == false) {
        rpg->dialogue->plage_ninja->can_interact = true;
    } else
        rpg->dialogue->plage_ninja->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->plage_ninja);
    find_if_print(rpg, rpg->dialogue->plage_ninja);
    draw_text_in_chatbox(rpg, rpg->dialogue->plage_ninja);
}

void find_qna(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->plage_woman->x_min &&
        player->position.x <= rpg->dialogue->plage_woman->x_max &&
        player->position.y >= rpg->dialogue->plage_woman->y_min &&
        player->position.y <= rpg->dialogue->plage_woman->y_max
        && rpg->dialogue->plage_woman->is_active == false) {
        rpg->dialogue->plage_woman->can_interact = true;
    } else
        rpg->dialogue->plage_woman->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->plage_woman);
    find_if_print(rpg, rpg->dialogue->plage_woman);
    draw_text_in_chatbox(rpg, rpg->dialogue->plage_woman);
    if (rpg->inv->armor->get_item[0] == false &&
        rpg->dialogue->plage_woman->i != 0)
        rpg->inv->armor->get_item[0] = true;
    if (rpg->quests->discovery[1]->is_discovered &&
        rpg->dialogue->plage_woman->talked == true) {
        rpg->quests->discovery[2]->is_discovered = true;
        rpg->maps->village->unlock = true;
    }
}
