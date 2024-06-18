/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** global_chest_func
*/

#include "rpg.h"

int check_bag_size(rpg_t *rpg, int size)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);
    int nb = rpg->characters->main->bag;
    char s[100];
    int elements = 0;
    int temp = 0;

    if (nb + size > 25) {
        elements = size + nb;
        temp = elements - 25;
        snprintf(s, sizeof(s), "YOUR BAG WILL BE TOO FULL\nREMOVE %i ITEMS\n",
            temp);
        sfText_setPosition(rpg->chest->chest_maze->text,
        (sfVector2f) {center.x - 80, center.y + 68});
        sfText_setString(rpg->chest->chest_maze->text, s);
        return 1;
    }
    return 0;
}

void open_chest(rpg_t *rpg, main_player_t *player, chest_open_t *chest)
{
    if (rpg->maps->inter->e_relased == true &&
        chest->is_active == false &&
        chest->can_interact == true &&
        rpg->chatbox->is_active == false) {
        chest->is_active = true;
        rpg->chatbox->is_active = true;
        rpg->maps->inter->e_relased = false;
    }
    if (rpg->maps->inter->e_relased == true &&
        chest->is_active == true
        && rpg->chatbox->is_active == true) {
        chest->is_active = false;
        rpg->maps->inter->enter = false;
        rpg->maps->inter->e_relased = false;
        rpg->chatbox->is_active = false;
        chest->is_active = false;
    }
}

void find_kei_released(rpg_t *rpg, main_player_t *player, chest_open_t *chest)
{
    if (chest->can_interact == true && rpg->chatbox->is_active == false) {
        sfSprite_setPosition(rpg->maps->inter->sprite, (sfVector2f)
            {rpg->characters->main->position.x + 50,
            rpg->characters->main->position.y});
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->inter->sprite, NULL);
    }
    open_chest(rpg, player, chest);
}

void find_if_pritable(rpg_t *rpg, chest_open_t *chest)
{
    if (rpg->maps->inter->enter == true &&
        chest->is_active == true) {
        rpg->maps->inter->enter = false;
        chest->is_print = false;
        rpg->chatbox->is_active = false;
        chest->is_active = false;
    }
}
