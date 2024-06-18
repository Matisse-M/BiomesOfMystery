/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** find_which
*/

#include "rpg.h"

static int wich_room4(rpg_t *rpg, main_player_t *player,
    sfVector2f position)
{
    if (rpg->maps->grotte->is_active == true) {
        if (find_where_grotte(rpg, player, position) == 0)
            return 0;
    }
    if (rpg->maps->dungeon->is_active == true) {
        if (find_where_dungeon(rpg, player, position) == 0)
            return 0;
    }
    return 1;
}

int wich_room3(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    if (rpg->maps->upstairs->is_active == true) {
        if (find_where_upstairs(rpg, player, position) == 0)
            return 0;
    }
    if (rpg->maps->maze->is_active == true) {
        if (find_where_maze(rpg, player, position) == 0)
            return 0;
    }
    if (rpg->maps->village->is_active == true) {
        if (find_where_village(rpg, player, position) == 0)
            return 0;
    }
    if (rpg->maps->museum->is_active == true) {
        if (find_where_museum(rpg, player, position) == 0)
            return 0;
    }
    if (wich_room4(rpg, player, position) == 0)
        return 0;
    return 1;
}

int wich_room2(rpg_t *rpg, main_player_t *player, sfVector2f position)
{
    if (rpg->maps->weapon_shop->is_active == true) {
        if (find_where_weapon(rpg, player, position) == 0)
            return 0;
    }
    if (rpg->maps->house->is_active == true) {
        if (find_where_house(rpg, player, position) == 0)
            return 0;
    }
    if (rpg->maps->bathroom->is_active == true) {
        if (find_where_bathroom(rpg, player, position) == 0)
            return 0;
    }
    if (wich_room3(rpg, player, position) == 0)
        return 0;
    return 1;
}
