/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** reward_pigs
*/

#include "rpg.h"

void find_released(rpg_t *rpg, main_player_t *player,
    chest_open_t *chest, sfVector2f center)
{
    if (chest->can_interact == false) {
        sfSprite_setPosition(rpg->chest->sprite,
            (sfVector2f) {center.x - 130, center.y + 58});
        sfText_setPosition(rpg->chest->chest_maze->text,
            (sfVector2f) {center.x - 90, center.y + 68});
        sfText_setString(rpg->chest->chest_maze->text,
            "YOU FOUND ALL 4 FLUFFY'S\n HERE IS YOUR REWARD +500$\n");
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->chest->sprite, NULL);
        sfRenderWindow_drawText(rpg->game->window,
            rpg->chest->chest_maze->text, NULL);
        chest->is_active = true;
        rpg->chatbox->is_active = true;
    }
}

static void find_if_printabel(rpg_t *rpg, chest_open_t *chest)
{
    if (rpg->maps->inter->enter == true &&
        chest->is_active == true) {
        chest->can_interact = true;
        rpg->maps->inter->enter = false;
        rpg->characters->main->money += 500;
        rpg->quests->quests[5]->is_completed = true;
        chest->is_open = true;
        rpg->chatbox->is_active = false;
    }
}

void render_reward_kid(rpg_t *rpg)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (rpg->chest->kid_bp->is_open == true)
        return;
    find_released(rpg, rpg->characters->main,
        rpg->chest->kid_bp, center);
    find_if_printabel(rpg, rpg->chest->kid_bp);
}

static void find_key_niter(rpg_t *rpg, main_player_t *player,
    chest_open_t *chest, sfVector2f center)
{
    if (chest->can_interact == false) {
        sfSprite_setPosition(rpg->chest->sprite,
            (sfVector2f) {center.x - 130, center.y + 58});
        sfText_setPosition(rpg->chest->chest_maze->text,
            (sfVector2f) {center.x - 90, center.y + 68});
        sfText_setString(rpg->chest->chest_maze->text,
            "YOU FOUND ALL 3 PIGS\n HERE IS PANDA\n");
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->chest->sprite, NULL);
        sfRenderWindow_drawText(rpg->game->window,
            rpg->chest->chest_maze->text, NULL);
        chest->is_active = true;
    }
}

static void find_if_printssss(rpg_t *rpg, chest_open_t *chest)
{
    if (rpg->maps->inter->enter == true &&
        chest->is_active == true) {
        chest->can_interact = true;
        rpg->maps->inter->enter = false;
        rpg->quests->quests[3]->is_completed = true;
        rpg->inv->armor->get_item[3] = true;
        rpg->chatbox->is_active = false;
    }
}

void render_reward_pigs(rpg_t *rpg)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (rpg->chest->cow->is_open == true)
        return;
    find_key_niter(rpg, rpg->characters->main,
        rpg->chest->cow, center);
    find_if_printssss(rpg, rpg->chest->cow);
}
