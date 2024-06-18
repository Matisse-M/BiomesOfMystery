/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** update_level
*/

#include "rpg.h"


void update_level(main_player_t *main)
{
    int lvl = main->lvl;

    if (main->exp >= 100) {
        main->lvl += main->exp / 100;
        main->emo += (main->lvl - lvl) * 2;
        main->hp += (main->lvl - lvl) * 2;
        main->hp_max += (main->lvl - lvl) * 2;
        main->atk += (main->lvl - lvl) * 2;
        main->exp = main->exp % 100;
    }
}

static void find_kei_releds(rpg_t *rpg, main_player_t *player,
    chest_open_t *chest, sfVector2f center)
{
    if (chest->can_interact == false) {
        sfSprite_setPosition(rpg->chest->sprite,
            (sfVector2f) {center.x - 130, center.y + 58});
        sfText_setPosition(rpg->chest->chest_maze->text,
            (sfVector2f) {center.x - 90, center.y + 68});
        sfText_setString(rpg->chest->chest_maze->text,
            "YOU LEVELD UP + 2 GPA +500 $\n GO IN YOUR QUEST MENU\n");
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->chest->sprite, NULL);
        sfRenderWindow_drawText(rpg->game->window,
            rpg->chest->chest_maze->text, NULL);
        chest->is_active = true;
    }
}

static void find_if_prit(rpg_t *rpg, chest_open_t *chest)
{
    if (rpg->maps->inter->enter == true &&
        chest->is_active == true &&
        chest->is_open == false) {
        chest->can_interact = true;
        rpg->maps->inter->enter = false;
        rpg->characters->main->exp += 100;
        update_level(rpg->characters->main);
        rpg->characters->main->emo += 2;
        rpg->characters->main->money += 500;
        rpg->chatbox->is_active = false;
        chest->is_open = true;
    }
}

void render_wins(rpg_t *rpg)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    find_kei_releds(rpg, rpg->characters->main, rpg->chest->level, center);
    find_if_prit(rpg, rpg->chest->level);
}

void find_if_level_upt(rpg_t *rpg)
{
    if (rpg->quests->is_done == false &&
        rpg->chest->level->is_open == false)
        return;
    render_wins(rpg);
}

static void find_kei_releddss(rpg_t *rpg, main_player_t *player,
    sfVector2f center, chest_open_t *chest)
{
    if (chest->can_interact == false) {
        sfSprite_setPosition(rpg->chest->sprite,
            (sfVector2f) {center.x - 130, center.y + 58});
        sfText_setPosition(rpg->chest->chest_maze->text,
            (sfVector2f) {center.x - 90, center.y + 68});
        sfText_setString(rpg->chest->chest_maze->text,
            "YOU WON +500 $\n");
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->chest->sprite, NULL);
        sfRenderWindow_drawText(rpg->game->window,
            rpg->chest->chest_maze->text, NULL);
        chest->is_active = true;
    }
}

static void find_if_prt(rpg_t *rpg, chest_open_t *chest)
{
    if (rpg->maps->inter->enter == true &&
        chest->is_active == true) {
        chest->can_interact = true;
        rpg->maps->inter->enter = false;
        rpg->characters->main->money += 500;
        rpg->quests->quests[1]->is_completed = true;
        chest->is_open = true;
        rpg->chatbox->is_active = false;
    }
}

void draw_reward(rpg_t *rpg, dialog_player_t *dialogue)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    if (rpg->chest->chest_maze_quest->is_open == true)
        return;
    find_kei_releddss(rpg, rpg->characters->main,
        center, rpg->chest->chest_maze_quest);
    find_if_prt(rpg, rpg->chest->chest_maze_quest);
}
