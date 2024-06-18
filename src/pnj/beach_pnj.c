/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** beach_pnj
*/

#include "rpg.h"

static void find_if_key_pressed(rpg_t *rpg, main_player_t *player,
    dialog_player_t *dialogue)
{
    if (rpg->maps->inter->e_relased == true &&
        dialogue->is_active == false &&
        dialogue->can_interact == true &&
        rpg->chatbox->is_active == false) {
        dialogue->is_active = true;
        rpg->chatbox->is_active = true;
        rpg->maps->inter->e_relased = false;
    }
    if (rpg->maps->inter->e_relased == true &&
        dialogue->is_active == true
        && rpg->chatbox->is_active == true) {
        dialogue->is_active = false;
        rpg->maps->inter->enter = false;
        rpg->maps->inter->e_relased = false;
        rpg->chatbox->is_active = false;
        dialogue->i = 0;
    }
}

void find_key_interactions_beach(rpg_t *rpg,
    main_player_t *player, dialog_player_t *dialogue)
{
    if (dialogue->can_interact == true) {
        sfSprite_setPosition(rpg->maps->inter->sprite, (sfVector2f)
            {rpg->characters->main->position.x - 150,
            rpg->characters->main->position.y});
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->inter->sprite, NULL);
    }
    find_if_key_pressed(rpg, player, dialogue);
}

void find_kid_beach(rpg_t *rpg, main_player_t *player)
{
    if (player->position.x >= rpg->dialogue->plage_kid->x_min &&
        player->position.x <= rpg->dialogue->plage_kid->x_max &&
        player->position.y >= rpg->dialogue->plage_kid->y_min &&
        player->position.y <= rpg->dialogue->plage_kid->y_max
        && rpg->dialogue->plage_kid->is_active == false) {
        rpg->dialogue->plage_kid->can_interact = true;
    } else
        rpg->dialogue->plage_kid->can_interact = false;
    find_key_interactions_beach(rpg, player, rpg->dialogue->plage_kid);
    find_if_print(rpg, rpg->dialogue->plage_kid);
    draw_text_in_chatbox(rpg, rpg->dialogue->plage_kid);
}
