/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** create_chatboxes
*/

#include "rpg.h"

static void render_sprites(rpg_t *rpg, dialog_player_t *dialogue,
    sfVector2f center)
{
    if (dialogue->is_active == true &&
        dialogue->is_print == false) {
        sfSprite_setPosition(dialogue->faces_sprite, (sfVector2f)
            {center.x - 122, center.y + 70});
        sfSprite_setPosition(rpg->maps->downstairs->pnj_mat->box_sprite,
        (sfVector2f) {center.x - 130, center.y + 58});
        sfText_setPosition(dialogue->name, (sfVector2f)
            {center.x - 120, center.y + 60});
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->downstairs->pnj_mat->box_sprite, NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            dialogue->faces_sprite, NULL);
        sfRenderWindow_drawText(rpg->game->window, dialogue->name, NULL);
        sfRenderWindow_drawText(rpg->game->window, dialogue->text, NULL);
        dialogue->can_interact = false;
        dialogue->talked = true;
    }
}

static void render_texts(rpg_t *rpg, sfVector2f center,
    dialog_player_t *dialogue)
{
    if (dialogue->is_print == true &&
        dialogue->array[dialogue->i] != NULL &&
        dialogue->is_active == true) {
        sfSprite_setPosition(dialogue->faces_sprite, (sfVector2f)
            {center.x - 122, center.y + 70});
        sfText_setPosition(dialogue->name, (sfVector2f)
        {center.x - 122, center.y + 52});
        if (dialogue->line_count == dialogue->count_line - 1)
            rpg->maps->inter->enter = false;
        dialogue->is_print = false;
        dialogue->i += 1;
    }
}

static void init_first_text(rpg_t *rpg, dialog_player_t *dialogue,
    sfVector2f center)
{
    if (dialogue->array[dialogue->i] != NULL) {
        if (dialogue->i == 0)
            sfText_setPosition(dialogue->text, (sfVector2f)
                {center.x - 76, center.y + 70});
        else
            sfText_setPosition(dialogue->text, (sfVector2f)
                {center.x - 76, center.y + 60});
        sfText_setString(dialogue->text,
            dialogue->array[dialogue->i]);
    }
}

void draw_text_in_chatbox(rpg_t *rpg,
    dialog_player_t *dialogue)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (dialogue->array[dialogue->i + 1] == NULL) {
        dialogue->is_active = false;
        rpg->maps->inter->enter = false;
        rpg->maps->inter->e_relased = false;
        rpg->chatbox->is_active = false;
        dialogue->i = 0;
    }
    init_first_text(rpg, dialogue, center);
    render_texts(rpg, center, dialogue);
    render_sprites(rpg, dialogue, center);
}

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

void find_key_interactions(rpg_t *rpg,
    main_player_t *player, dialog_player_t *dialogue)
{
    if (dialogue->can_interact == true && rpg->chatbox->is_active == false) {
        sfSprite_setPosition(rpg->maps->inter->sprite, (sfVector2f)
            {rpg->characters->main->position.x + 50,
            rpg->characters->main->position.y});
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->inter->sprite, NULL);
    }
    find_if_key_pressed(rpg, player, dialogue);
}

void find_if_print(rpg_t *rpg, dialog_player_t *dialogue)
{
    if (rpg->maps->inter->enter == true &&
        dialogue->is_active == true) {
        rpg->maps->inter->enter = false;
        dialogue->is_print = true;
    }
}
