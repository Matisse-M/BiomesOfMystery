/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** render_chat_box
*/

#include "rpg.h"
#include <string.h>

static void render_sprites(rpg_t *rpg, room_t *room, sfVector2f center)
{
    if (rpg->maps->downstairs->pnj_mat->is_active == true
        && room->pnj_mat->is_print == false) {
        sfSprite_setPosition(rpg->maps->downstairs->pnj_mat->box_sprite,
            (sfVector2f) {center.x - 129.3, center.y + 70});
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->downstairs->pnj_mat->box_sprite, NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->downstairs->pnj_mat->sprite[1], NULL);
        sfRenderWindow_drawText(rpg->game->window, room->pnj_mat->name, NULL);
        sfRenderWindow_drawText(rpg->game->window,
            room->pnj_mat->text, NULL);
        room->pnj_mat->can_interact = false;
        rpg->quests->discovery[0]->is_discovered = true;
    }
}

static void render_text(rpg_t *rpg, room_t *room, sfVector2f center,
    int count_line)
{
    if (room->pnj_mat->is_print == true &&
        room->pnj_mat->lines[room->pnj_mat->i] != NULL &&
        room->pnj_mat->is_active == true) {
        sfText_setPosition(room->pnj_mat->text, (sfVector2f)
            {center.x - 76, center.y + 72});
        if (room->pnj_mat->line_count == count_line - 1)
            rpg->maps->inter->enter = false;
        room->pnj_mat->is_print = false;
        room->pnj_mat->i += 1;
    }
}

static void draw_chatbox(rpg_t *rpg, room_t *room, int count_line)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (room->pnj_mat->lines[room->pnj_mat->i + 1] == NULL) {
        room->pnj_mat->is_active = false;
        rpg->maps->inter->enter = false;
        rpg->maps->inter->e_relased = false;
        rpg->chatbox->is_active = false;
        room->pnj_mat->i = 0;
    }
    if (room->pnj_mat->lines[room->pnj_mat->i + 1] != NULL) {
        sfText_setString(room->pnj_mat->text,
            room->pnj_mat->lines[room->pnj_mat->i]);
        if (room->pnj_mat->i == 0)
            sfText_setPosition(room->pnj_mat->text, (sfVector2f)
                {center.x - 76, center.y + 85});
    }
    render_text(rpg, room, center, count_line);
    render_sprites(rpg, room, center);
}

static int check_if_can_interact(rpg_t *rpg, room_t *room)
{
    if (rpg->maps->inter->e_relased == true &&
        room->pnj_mat->is_active == false &&
        room->pnj_mat->can_interact
        == true && rpg->chatbox->is_active == false) {
        room->pnj_mat->is_active = true;
        rpg->chatbox->is_active = true;
        rpg->maps->inter->e_relased = false;
        rpg->maps->upstairs->unlock = true;
    }
    if (rpg->maps->inter->e_relased == true &&
        room->pnj_mat->is_active == true
        && rpg->chatbox->is_active == true) {
        room->pnj_mat->is_active = false;
        rpg->maps->inter->enter = false;
        rpg->maps->inter->e_relased = false;
        rpg->chatbox->is_active = false;
        room->pnj_mat->i = 0;
    }
    return 0;
}

void render_chatbox(rpg_t *rpg, main_player_t *player, room_t *room)
{
    if (player->position.x >= 650 && player->position.x <= 670
        && player->position.y >= 138 && player->position.y <= 150 &&
        room->pnj_mat->is_active == false) {
        room->pnj_mat->can_interact = true;
    } else
        room->pnj_mat->can_interact = false;
    if (room->pnj_mat->can_interact == true) {
        sfSprite_setPosition(rpg->maps->inter->sprite,
        (sfVector2f) {player->position.x - 30, player->position.y - 50});
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->inter->sprite, NULL);
    }
    check_if_can_interact(rpg, room);
    if (rpg->maps->inter->enter == true &&
        room->pnj_mat->is_active == true) {
        rpg->maps->inter->enter = false;
        room->pnj_mat->is_print = true;
    }
    draw_chatbox(rpg, rpg->maps->downstairs,
        room->pnj_mat->count_line);
}
