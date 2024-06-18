/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** find_weapon
*/

#include "rpg.h"

static void find_if_can_draw_skill(rpg_t *rpg)
{
    if (rpg->maps->inter->e_relased == true &&
        rpg->dialogue->shop->skill_active == false &&
        rpg->dialogue->shop->can_interact_skill == true) {
            rpg->skilltree->is_active = true;
            rpg->dialogue->shop->skill_active = true;
            rpg->maps->inter->e_relased = false;
    }
    if (rpg->maps->inter->e_relased == true &&
        rpg->dialogue->shop->skill_active == true &&
        rpg->dialogue->shop->can_interact_skill == true) {
        rpg->maps->inter->e_relased = false;
        rpg->skilltree->is_active = false;
        rpg->dialogue->shop->skill_active = false;
    }
    if (rpg->skilltree->is_active == true &&
        rpg->dialogue->shop->skill_active == true)
        draw_skilltree(rpg, rpg->skilltree);
}

void find_weapon(rpg_t *rpg)
{
    if (rpg->characters->main->position.x >= 89 &&
        rpg->characters->main->position.x <= 118 &&
        rpg->characters->main->position.y >= 83 &&
        rpg->characters->main->position.y <= 100) {
        rpg->dialogue->shop->can_interact_skill = true;
    } else
        rpg->dialogue->shop->can_interact_skill = false;
    if (rpg->dialogue->shop->can_interact_skill == true) {
        sfSprite_setPosition(rpg->maps->inter->sprite, (sfVector2f)
            {rpg->characters->main->position.x + 50,
            rpg->characters->main->position.y});
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->inter->sprite, NULL);
    }
    find_if_can_draw_skill(rpg);
}

static void find_if_draw_store(rpg_t *rpg)
{
    if (rpg->maps->inter->e_relased == true &&
        rpg->dialogue->shop->shop_active == false &&
        rpg->dialogue->shop->can_interact_shop == true) {
            rpg->store->is_active = true;
            rpg->dialogue->shop->shop_active = true;
            rpg->dialogue->shop->can_interact_shop = false;
            rpg->maps->inter->e_relased = false;
    }
    if (rpg->maps->inter->e_relased == true &&
        rpg->dialogue->shop->shop_active == true &&
        rpg->store->is_active == true) {
            rpg->store->is_active = false;
            rpg->dialogue->shop->shop_active = false;
            rpg->maps->inter->enter = false;
            rpg->maps->inter->e_relased = false;
    }
    if (rpg->dialogue->shop->shop_active == true) {
        draw_store(rpg, rpg->store);
    }
}

void find_market(rpg_t *rpg)
{
    if (rpg->characters->main->position.x >= 83 &&
        rpg->characters->main->position.x <= 96 &&
        rpg->characters->main->position.y >= 51 &&
        rpg->characters->main->position.y <= 75) {
        rpg->dialogue->shop->can_interact_shop = true;
    } else
        rpg->dialogue->shop->can_interact_shop = false;
    if (rpg->dialogue->shop->can_interact_shop == true &&
        rpg->dialogue->shop->shop_active == false) {
        sfSprite_setPosition(rpg->maps->inter->sprite, (sfVector2f)
            {rpg->characters->main->position.x + 50,
            rpg->characters->main->position.y});
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->inter->sprite, NULL);
    }
    find_if_draw_store(rpg);
}
