/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** chest__maze_two
*/

#include "rpg.h"

static void check_chest_stat(rpg_t *rpg, chest_open_t *chest)
{
    if (chest->is_open == false) {
        if (check_bag_size(rpg, 5) == 0) {
            sfText_setString(rpg->inv->conso->conso[0]->qty, my_itoa
            (atoi(sfText_getString(rpg->inv->conso->conso[0]->qty)) + 5));
            chest->is_open = true;
            rpg->characters->main->bag += 5;
        }
    }
}

static void draw_chestb(rpg_t *rpg, chest_open_t *chest, sfVector2f center)
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
            "YOU FOUND  5  A T K +!\n");
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->downstairs->pnj_mat->box_sprite, NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->chest->chest_maze->sprite, NULL);
        check_chest_stat(rpg, chest);
        sfRenderWindow_drawText(rpg->game->window,
            rpg->chest->chest_maze->text, NULL);
    }
}

void find_kei_releaseds(rpg_t *rpg, main_player_t *player,
    chest_open_t *chest)
{
    if (chest->can_interact == true && rpg->chatbox->is_active == false) {
        sfSprite_setPosition(rpg->maps->inter->sprite, (sfVector2f)
            {rpg->characters->main->position.x - 150,
            rpg->characters->main->position.y});
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->inter->sprite, NULL);
    }
    open_chest(rpg, player, chest);
}

void find_chest_two(rpg_t *rpg, main_player_t *player)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (player->position.x >= 583 && player->position.x <= 610 &&
        player->position.y >= 383 && player->position.y <= 413 &&
        rpg->chest->chest_two->is_active == false &&
        rpg->chest->chest_two->is_open == false) {
        rpg->chest->chest_two->can_interact = true;
    } else
        rpg->chest->chest_two->can_interact = false;
    find_kei_releaseds(rpg, player, rpg->chest->chest_two);
    find_if_pritable(rpg, rpg->chest->chest_two);
    draw_chestb(rpg, rpg->chest->chest_two, center);
}
