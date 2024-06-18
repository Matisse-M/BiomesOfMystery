/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** find_chest
*/

#include "rpg.h"

static void check_chest_state(rpg_t *rpg, chest_open_t *chest)
{
    if (chest->is_open == false) {
        if (check_bag_size(rpg, 3) == 0) {
            sfText_setString(rpg->inv->conso->conso[9]->qty, my_itoa
            (atoi(sfText_getString(rpg->inv->conso->conso[9]->qty)) + 3));
            chest->is_open = true;
            rpg->characters->main->bag += 3;
        }
    }
}

void draw_chest_text(rpg_t *rpg, chest_open_t *chest, sfVector2f center)
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
            "YOU FOUND  3  \nFORTUNE  COOKIES!\n");
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->downstairs->pnj_mat->box_sprite, NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->chest->chest_maze->sprite, NULL);
        check_chest_state(rpg, chest);
        sfRenderWindow_drawText(rpg->game->window,
            rpg->chest->chest_maze->text, NULL);
    }
}

void open_chest_maze(rpg_t *rpg, main_player_t *player)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (player->position.x >= 12 && player->position.x <= 25 &&
        player->position.y >= 78 && player->position.y <= 96 &&
        rpg->chest->chest_one->is_active == false &&
        rpg->chest->chest_one->is_open == false) {
        rpg->chest->chest_one->can_interact = true;
    } else
        rpg->chest->chest_one->can_interact = false;
    find_kei_released(rpg, player, rpg->chest->chest_one);
    find_if_pritable(rpg, rpg->chest->chest_one);
    draw_chest_text(rpg, rpg->chest->chest_one, center);
}
