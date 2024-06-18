/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** modify_view
*/

#include "rpg.h"

void map_chatbox(rpg_t *rpg)
{
    sfVector2f center = rpg->characters->main->position;

    center.x -= 135;
    center.y += 60;
    rpg->chatbox->position = center;
    sfSprite_setPosition(rpg->chatbox->sprite, rpg->chatbox->position);
}

void modif_center(sfVector2f *center, sfVector2f view_center,
    sfFloatRect area)
{
    if ((*center).x > area.left && (*center).x < area.width) {
        (*center).x += 8;
        (*center).y = view_center.y;
    } else if ((*center).y > area.top && (*center).y < area.height) {
        (*center).x = view_center.x;
        (*center).y += 8;
    } else {
        (*center).x = view_center.x;
        (*center).y = view_center.y;
    }
}

void map_view(rpg_t *rpg, sfFloatRect area)
{
    sfVector2f view_center = sfView_getCenter(rpg->game->view);
    sfVector2f center = rpg->characters->main->position;

    if (center.x > area.left && center.x < area.width && center.y > area.top &&
        center.y < area.height) {
        center.x += 8;
        center.y += 8;
        sfView_setCenter(rpg->game->view, center);
        sfRenderWindow_setView(rpg->game->window, rpg->game->view);
        return;
    }
    modif_center(&center, view_center, area);
    sfView_setCenter(rpg->game->view, center);
    sfRenderWindow_setView(rpg->game->window, rpg->game->view);
}
