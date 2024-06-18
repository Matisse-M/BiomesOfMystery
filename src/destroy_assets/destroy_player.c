/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** destroy_player
*/

#include "rpg.h"

void destroy_player(rpg_t *rpg)
{
    sfSprite_destroy(rpg->characters->main->face);
    sfSprite_destroy(rpg->characters->main->sprite);
}

void destroy_maps(rpg_t *rpg)
{
    for (int i = 0; i < 1; i++) {
        sfSprite_destroy(rpg->maps->downstairs->sprite[i]);
        sfTexture_destroy(rpg->maps->downstairs->texture[i]);
        sfImage_destroy(rpg->maps->downstairs->under);
        sfSprite_destroy(rpg->maps->bathroom->sprite[i]);
        sfTexture_destroy(rpg->maps->bathroom->texture[i]);
        sfImage_destroy(rpg->maps->bathroom->under);
        sfSprite_destroy(rpg->maps->beach->sprite[i]);
        sfTexture_destroy(rpg->maps->beach->texture[i]);
        sfImage_destroy(rpg->maps->beach->under);
        sfSprite_destroy(rpg->maps->food_shop->sprite[i]);
        sfTexture_destroy(rpg->maps->food_shop->texture[i]);
        sfImage_destroy(rpg->maps->food_shop->under);
        sfSprite_destroy(rpg->maps->house->sprite[i]);
        sfTexture_destroy(rpg->maps->house->texture[i]);
        sfImage_destroy(rpg->maps->house->under);
        sfSprite_destroy(rpg->maps->maze->sprite[i]);
        sfTexture_destroy(rpg->maps->maze->texture[i]);
        sfImage_destroy(rpg->maps->maze->under);
    }
}

void destroy_enemy(enemy_t *enemy)
{
    if (enemy->sprite)
        sfSprite_destroy(enemy->sprite);
    if (enemy->clock)
        sfClock_destroy(enemy->clock);
    free(enemy);
}

void destroy_fight(fight_t *fight)
{
    if (fight->bg)
        sfRectangleShape_destroy(fight->bg);
    if (fight->clock)
        sfClock_destroy(fight->clock);
    for (int i = 0; fight->enemy && fight->enemy[i]; i++)
        destroy_enemy(fight->enemy[i]);
    if (fight->enemy)
        free(fight->enemy);
    if (fight->enemy_box)
        sfRectangleShape_destroy(fight->enemy_box);
    if (fight->enemy_hp)
        sfText_destroy(fight->enemy_hp);
    if (fight->menu)
        sfRectangleShape_destroy(fight->menu);
    if (fight->player_hp)
        sfText_destroy(fight->player_hp);
}

void destroy_assets(rpg_t *rpg)
{
    destroy_maps(rpg);
    destroy_player(rpg);
    sfClock_destroy(rpg->game->clock_menu);
    sfClock_destroy(rpg->game->clock_mv);
}
