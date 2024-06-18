/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** under_map
*/

#include "rpg.h"

static void choose_under_pos(rpg_t *rpg, main_player_t *main)
{
    if (rpg->maps->village->is_active == true) {
        rpg->maps->under = rpg->maps->village->under;
    }
    if (rpg->maps->weapon_shop->is_active == true) {
        rpg->maps->under = rpg->maps->weapon_shop->under;
    }
}

static void under_map_pos(rpg_t *rpg, main_player_t *main)
{
    choose_under_pos(rpg, main);
    if (rpg->maps->food_shop->is_active == true) {
        rpg->maps->under = rpg->maps->food_shop->under;
    }
    if (rpg->maps->bathroom->is_active == true) {
        rpg->maps->under = rpg->maps->bathroom->under;
    }
    if (rpg->maps->museum->is_active == true) {
        rpg->maps->under = rpg->maps->museum->under;
    }
}

static void choose_under_map_pos(rpg_t *rpg, main_player_t *main)
{
    under_map_pos(rpg, main);
    if (rpg->maps->upstairs->is_active == true) {
        rpg->maps->under = rpg->maps->upstairs->under;
    }
    if (rpg->maps->swamp->is_active == true) {
        rpg->maps->under = rpg->maps->swamp->under;
    }
    if (rpg->maps->dungeon->is_active == true)
        rpg->maps->under = rpg->maps->dungeon->under;
    if (rpg->maps->grotte->is_active == true)
        rpg->maps->under = rpg->maps->grotte->under;
}

static void map_pos_under(rpg_t *rpg, main_player_t *main)
{
    choose_under_map_pos(rpg, main);
    if (rpg->maps->beach->is_active == true) {
        rpg->maps->under = rpg->maps->beach->under;
    }
    if (rpg->maps->house->is_active == true) {
        rpg->maps->under = rpg->maps->house->under;
    }
    if (rpg->maps->maze->is_active == true) {
        rpg->maps->under = rpg->maps->maze->under;
    }
}

void choose_under_map(rpg_t *rpg, main_player_t *main)
{
    map_pos_under(rpg, main);
    if (rpg->maps->downstairs->is_active == true)
        rpg->maps->under = rpg->maps->downstairs->under;
    sfView_setCenter(rpg->game->view,
        (sfVector2f) {rpg->maps->center.x, rpg->maps->center.y});
}
