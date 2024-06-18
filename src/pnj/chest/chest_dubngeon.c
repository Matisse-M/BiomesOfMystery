/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** chest_dubngeon
*/

#include "rpg.h"

static void check_chest_state(rpg_t *rpg, chest_open_t *chest)
{
    if (chest->is_open == false) {
        if (check_bag_size(rpg, 10) == 0) {
            sfText_setString(rpg->inv->conso->conso[1]->qty, my_itoa
            (atoi(sfText_getString(rpg->inv->conso->conso[1]->qty)) + 10));
            chest->is_open = true;
            rpg->characters->main->bag += 10;
        }
    }
}

static void draw_chest_text_fd(rpg_t *rpg, chest_open_t *chest,
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
            "YOU FOUND 10  HP + !\n");
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->downstairs->pnj_mat->box_sprite, NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->chest->chest_maze->sprite, NULL);
        check_chest_state(rpg, chest);
        sfRenderWindow_drawText(rpg->game->window,
            rpg->chest->chest_maze->text, NULL);
    }
}

void chest_dungeon_one(rpg_t *rpg, main_player_t *player)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (player->position.x >= 983.8 && player->position.x <= 1004.8 &&
        player->position.y >= 256.8 && player->position.y <= 283.8 &&
        rpg->chest->chest_dungeon->is_active == false &&
        rpg->chest->chest_dungeon->is_open == false) {
        rpg->chest->chest_dungeon->can_interact = true;
    } else
        rpg->chest->chest_dungeon->can_interact = false;
    find_kei_releaseds(rpg, player, rpg->chest->chest_dungeon);
    find_if_pritable(rpg, rpg->chest->chest_dungeon);
    draw_chest_text_fd(rpg, rpg->chest->chest_dungeon, center);
}

static void check_chest_stat(rpg_t *rpg, chest_open_t *chest)
{
    if (chest->is_open == false) {
        rpg->inv->armor->get_item[7] = true;
        chest->is_open = true;
    }
}

static void draw_chest_text_d(rpg_t *rpg, chest_open_t *chest,
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
            "YOU FOUND E X C A L I B U R  !\n WELL  DONE\n");
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->downstairs->pnj_mat->box_sprite, NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->chest->chest_maze->sprite, NULL);
        check_chest_stat(rpg, chest);
        sfRenderWindow_drawText(rpg->game->window,
            rpg->chest->chest_maze->text, NULL);
    }
}

void chest_dungeon_two(rpg_t *rpg, main_player_t *player)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (player->position.x >= 724.4 && player->position.x <= 749.6 &&
        player->position.y >= 192.8 && player->position.y <= 218 &&
        rpg->chest->chest_dun_two->is_active == false &&
        rpg->chest->chest_dun_two->is_open == false) {
        rpg->chest->chest_dun_two->can_interact = true;
    } else
        rpg->chest->chest_dun_two->can_interact = false;
    find_kei_releaseds(rpg, player, rpg->chest->chest_dun_two);
    find_if_pritable(rpg, rpg->chest->chest_dun_two);
    draw_chest_text_d(rpg, rpg->chest->chest_dun_two, center);
}

void check_chest_dungeon(rpg_t *rpg, main_player_t *player)
{
    if (rpg->maps->dungeon->is_active == true) {
        chest_dungeon_one(rpg, player);
        chest_dungeon_two(rpg, player);
    }
}
