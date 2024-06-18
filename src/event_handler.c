/*
** EPITECH PROJECT, 2024
** crpg
** File description:
** event_handler
*/

#include "rpg.h"

int event_handler(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->game->window, &rpg->game->event)) {
        if (rpg->game->event.type == sfEvtClosed) {
            destroy_assets(rpg);
            sfRenderWindow_close(rpg->game->window);
            exit(0);
        }
        if (rpg->game->event.type == sfEvtKeyReleased &&
            rpg->game->event.key.code == sfKeyE)
            rpg->maps->inter->e_relased = true;
        if (rpg->game->event.type == sfEvtKeyReleased &&
            rpg->game->event.key.code == sfKeyEnter)
            rpg->maps->inter->enter = true;
        if (time_elapsed(rpg->maps->inter->clock_e) > 0.3) {
            rpg->maps->inter->e_relased = false;
            sfClock_restart(rpg->maps->inter->clock_e);
        }
    }
    return (1);
}
