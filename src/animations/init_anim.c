/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_anim
*/

#include "rpg.h"

void int_anim(rpg_t *rpg)
{
    rpg->anim = malloc(sizeof(animations_t));
    rpg->anim->rain_anim = malloc(sizeof(anim_t));
    rpg->anim->texture = sfTexture_createFromFile
        (my_scat(rpg->name, "/animations/Leaf.png"), NULL);
    if (rpg->anim->texture == NULL)
        exit(84);
    rpg->anim->rain_anim->texture_rain = sfTexture_createFromFile
        (my_scat(rpg->name, "/animations/Rain.png"), NULL);
    if (rpg->anim->rain_anim->texture_rain == NULL)
        exit(84);
    rpg->anim->rain_anim->texture_puddle = sfTexture_createFromFile
        (my_scat(rpg->name, "/animations/RainOnFloor.png"), NULL);
    if (rpg->anim->rain_anim->texture_puddle == NULL)
        exit(84);
    rpg->anim->clock = sfClock_create();
    rpg->anim->rain_anim->clock = sfClock_create();
    setup_maze_chest(rpg);
}
