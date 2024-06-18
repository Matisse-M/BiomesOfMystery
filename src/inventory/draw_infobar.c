/*
** EPITECH PROJECT, 2024
** crpg
** File description:
** draw_infobar
*/

#include "rpg.h"

void draw_pnj_infobar(rpg_t *rpg, sfVector2f view)
{
    sfSprite_setPosition(rpg->info_bar->box, (sfVector2f) {view.x + 11
        , view.y + 13});
    sfRenderWindow_drawSprite(rpg->game->window, rpg->info_bar->box, NULL);
    sfSprite_setScale(rpg->characters->main->face, (sfVector2f) {0.42, 0.42});
    sfSprite_setPosition(rpg->characters->main->face, (sfVector2f) {view.x
        + 14, view.y + 16});
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->characters->main->face, NULL);
    sfText_setPosition(rpg->info_bar->name, (sfVector2f)
        {view.x + 39, view.y + 12});
    sfText_setString(rpg->info_bar->name, rpg->characters->main->name);
    sfRenderWindow_drawText(rpg->game->window, rpg->info_bar->name, NULL);
    sfText_setPosition(rpg->info_bar->lvl, (sfVector2f)
        {view.x + 39, view.y + 20});
    sfText_setString(rpg->info_bar->lvl, my_itoa(rpg->characters->main->lvl));
    sfRenderWindow_drawText(rpg->game->window, rpg->info_bar->lvl, NULL);
}

void update_quest_txt(rpg_t *rpg, sfVector2f view)
{
    for (int i = 0; rpg->quests->discovery[i]; i++)
        if (rpg->quests->discovery[i]->is_discovered
        && rpg->quests->discovery[i + 1] != NULL) {
            sfText_setString(rpg->info_bar->quest,
                rpg->quests->discovery[i + 1]->title);
        }
}

static void update_info(rpg_t *rpg, sfVector2f view, int i)
{
    if (rpg->quests->is_done == true && rpg->quests->btn[i]->is_active &&
        rpg->quests->btn[i]->id > 0) {
            sfText_setPosition(rpg->info_bar->quest, (sfVector2f) {view.x + 12,
                view.y + 37.8});
            sfText_setString(rpg->info_bar->quest,
                rpg->quests->quests[i - 1]->title);
            sfRenderWindow_drawText(rpg->game->window, rpg->info_bar->quest,
                NULL);
    }
}

void draw_quest_infobar(rpg_t *rpg, sfVector2f view)
{
    sfText_setString(rpg->info_bar->quest,
        rpg->quests->discovery[0]->title);
    sfText_setScale(rpg->info_bar->quest, (sfVector2f) {0.65, 0.65});
    for (int i = 0; i < 7; i++) {
        if (rpg->quests->btn[i]->is_active && rpg->quests->btn[i]->id == 0
            && rpg->quests->is_done != true) {
            update_quest_txt(rpg, view);
            sfText_setPosition(rpg->info_bar->quest, (sfVector2f)
            {view.x + 12, view.y + 37.8});
            sfRenderWindow_drawText(rpg->game->window, rpg->info_bar->quest,
                NULL);
        }
        update_info(rpg, view, i);
    }
}

void draw_infobar(rpg_t *rpg)
{
    const sfView *curr_view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f view = {
        sfView_getCenter(curr_view).x - sfView_getSize(curr_view).x / 2,
        sfView_getCenter(curr_view).y - 5 - sfView_getSize(curr_view).y / 2
    };

    sfSprite_setPosition(rpg->info_bar->sprite, view);
    sfRenderWindow_drawSprite(rpg->game->window, rpg->info_bar->sprite, NULL);
    draw_pnj_infobar(rpg, view);
    draw_quest_infobar(rpg, view);
    sfSprite_setTextureRect(rpg->info_bar->exp[1], (sfIntRect)
        {0, 0, (int)(18 * rpg->characters->main->exp / 100), 4});
    for (int i = 0; i < 2; i++) {
        sfSprite_setPosition(rpg->info_bar->exp[i],
            (sfVector2f) {view.x + 7, view.y + 58});
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->info_bar->exp[i], NULL);
    }
}
