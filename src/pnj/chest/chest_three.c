/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** chest__three
*/

#include "rpg.h"

static void check_chest_stat(rpg_t *rpg, chest_open_t *chest)
{
    if (chest->is_open == false) {
        rpg->characters->main->money += 500;
        chest->is_open = true;
    }
}

void draw_chest_text_t(rpg_t *rpg, chest_open_t *chest, sfVector2f center)
{
    if (chest->is_print == false &&
        rpg->chatbox->is_active == true &&
        chest->is_active == true) {
        sfSprite_setPosition(rpg->maps->downstairs->pnj_mat->box_sprite,
            (sfVector2f) {center.x - 130, center.y + 58});
        sfSprite_setPosition(rpg->chest->chest_maze->sprite, (sfVector2f)
            {center.x - 122, center.y + 70});
        sfText_setPosition(rpg->chest->chest_maze->text,
            (sfVector2f) {center.x - 80, center.y + 68});
        sfText_setString(rpg->chest->chest_maze->text,
            "YOU WON  500 $!\n");
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->downstairs->pnj_mat->box_sprite, NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->chest->chest_maze->sprite, NULL);
        check_chest_stat(rpg, chest);
        sfRenderWindow_drawText(rpg->game->window,
            rpg->chest->chest_maze->text, NULL);
    }
}

void find_chest_three(rpg_t *rpg, main_player_t *player)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (player->position.x >= 539.9 && player->position.x <= 5776.9 &&
        player->position.y >= 30.3 && player->position.y <= 52 &&
        rpg->chest->chest_three->is_active == false &&
        rpg->chest->chest_three->is_open == false) {
        rpg->chest->chest_three->can_interact = true;
    } else
        rpg->chest->chest_three->can_interact = false;
    find_kei_releaseds(rpg, player, rpg->chest->chest_three);
    find_if_pritable(rpg, rpg->chest->chest_three);
    draw_chest_text_t(rpg, rpg->chest->chest_three, center);
}

static void check_chest_state(rpg_t *rpg, chest_open_t *chest)
{
    if (chest->is_open == false) {
        rpg->inv->armor->get_item[5] = true;
        chest->is_open = true;
    }
}

static void draw_chest_text_f(rpg_t *rpg, chest_open_t *chest,
    sfVector2f center)
{
    if (chest->is_print == false &&
        rpg->chatbox->is_active == true &&
        chest->is_active == true) {
        sfSprite_setPosition(rpg->maps->downstairs->pnj_mat->box_sprite,
            (sfVector2f) {center.x - 130, center.y + 58});
        sfSprite_setPosition(rpg->chest->chest_maze->sprite, (sfVector2f)
            {center.x - 122, center.y + 70});
        sfText_setPosition(rpg->chest->chest_maze->text,
            (sfVector2f) {center.x - 80, center.y + 68});
        sfText_setString(rpg->chest->chest_maze->text,
            "YOU FOUND THE  MASTER \n !  SWORD  !\n");
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->downstairs->pnj_mat->box_sprite, NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->chest->chest_maze->sprite, NULL);
        check_chest_state(rpg, chest);
        sfRenderWindow_drawText(rpg->game->window,
            rpg->chest->chest_maze->text, NULL);
    }
}

static void find_chest_four(rpg_t *rpg, main_player_t *player)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (player->position.x >= 591 && player->position.x <= 609 &&
        player->position.y >= 26.3 && player->position.y <= 57 &&
        rpg->chest->chest_four->is_active == false &&
        rpg->chest->chest_four->is_open == false &&
        rpg->inv->armor->get_item[5] == false) {
        rpg->chest->chest_four->can_interact = true;
    } else
        rpg->chest->chest_four->can_interact = false;
    find_kei_releaseds(rpg, player, rpg->chest->chest_four);
    find_if_pritable(rpg, rpg->chest->chest_four);
    draw_chest_text_f(rpg, rpg->chest->chest_four, center);
}

void find_chest_in_maze(rpg_t *rpg, main_player_t *player)
{
    open_chest_maze(rpg, player);
    find_chest_two(rpg, player);
    find_chest_three(rpg, player);
    find_chest_four(rpg, player);
}
