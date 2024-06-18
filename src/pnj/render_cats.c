/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** render_chats
*/

#include "rpg.h"

void find_chat(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->chat->x_min &&
        player->position.x <= rpg->dialogue->chat->x_max &&
        player->position.y >= rpg->dialogue->chat->y_min &&
        player->position.y <= rpg->dialogue->chat->y_max)
        rpg->dialogue->chat->can_interact = true;
    else
        rpg->dialogue->chat->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->chat);
    find_if_print(rpg, rpg->dialogue->chat);
    draw_text_in_chatbox(rpg, rpg->dialogue->chat);
}

static void find_martin(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->martin->x_min &&
        player->position.x <= rpg->dialogue->martin->x_max &&
        player->position.y >= rpg->dialogue->martin->y_min &&
        player->position.y <= rpg->dialogue->martin->y_max)
        rpg->dialogue->martin->can_interact = true;
    else
        rpg->dialogue->martin->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->martin);
    find_if_print(rpg, rpg->dialogue->martin);
    draw_text_in_chatbox(rpg, rpg->dialogue->martin);
}

static int find_gradd(rpg_t *rpg)
{
    if (rpg->dialogue->cow->can_interact == true &&
        rpg->quests->quests[3]->is_discovered == true &&
        rpg->inv->conso->secret[1]->unlock == true) {
        render_reward_pigs(rpg);
        return 1;
    }
    return 0;
}

void find_cow(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->cow->x_min &&
        player->position.x <= rpg->dialogue->cow->x_max &&
        player->position.y >= rpg->dialogue->cow->y_min &&
        player->position.y <= rpg->dialogue->cow->y_max)
        rpg->dialogue->cow->can_interact = true;
    else
        rpg->dialogue->cow->can_interact = false;
    if (find_gradd(rpg) == 1)
        return;
    find_key_interactions(rpg, player, rpg->dialogue->cow);
    find_if_print(rpg, rpg->dialogue->cow);
    draw_text_in_chatbox(rpg, rpg->dialogue->cow);
    if (rpg->dialogue->cow->talked == true) {
        rpg->quests->quests[3]->is_discovered = true;
        rpg->pig->is_active = true;
    }
}

static void find_dungeon(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->dungeon_old->x_min &&
        player->position.x <= rpg->dialogue->dungeon_old->x_max &&
        player->position.y >= rpg->dialogue->dungeon_old->y_min &&
        player->position.y <= rpg->dialogue->dungeon_old->y_max)
        rpg->dialogue->dungeon_old->can_interact = true;
    else
        rpg->dialogue->dungeon_old->can_interact = false;
    find_key_interactions(rpg, player, rpg->dialogue->dungeon_old);
    find_if_print(rpg, rpg->dialogue->dungeon_old);
    draw_text_in_chatbox(rpg, rpg->dialogue->dungeon_old);
}

void find_pnj_upt(rpg_t *rpg)
{
    if (rpg->maps->upstairs->is_active == true) {
        find_chat(rpg, rpg->characters->main);
        find_martin(rpg, rpg->characters->main);
    }
    if (rpg->maps->dungeon->is_active == true)
        find_dungeon(rpg, rpg->characters->main);
}
