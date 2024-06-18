/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** setup_chest
*/

#include "rpg.h"

chest_open_t *init_bools(rpg_t *rpg, chest_open_t *chest)
{
    chest = malloc(sizeof(chest_maze_t));
    chest->can_interact = false;
    chest->is_active = false;
    chest->is_print = false;
    chest->is_open = false;
    return (chest);
}

static void set_rest(rpg_t *rpg)
{
    rpg->chest->cow = init_bools(rpg, rpg->chest->cow);
    rpg->chest->kid_bp = init_bools(rpg, rpg->chest->kid_bp);
    rpg->chest->chest_maze->sprite = sfSprite_create();
    if (rpg->chest->chest_maze->sprite == NULL)
        exit(84);
    sfSprite_setTexture(rpg->chest->chest_maze->sprite,
        rpg->chest->chest_maze->texture, sfTrue);
    rpg->chest->chest_maze->text = sfText_create();
    sfText_setCharacterSize(rpg->chest->chest_maze->text, 15);
    sfText_setFillColor(rpg->chest->chest_maze->text, sfBlack);
    sfText_setFont(rpg->chest->chest_maze->text, rpg->assets->font);
}

void setup_maze_chest(rpg_t *rpg)
{
    rpg->chest = malloc(sizeof(chest_t));
    rpg->chest->chest_maze = malloc(sizeof(chest_maze_t));
    rpg->chest->chest_one = init_bools(rpg, rpg->chest->chest_one);
    rpg->chest->chest_two = init_bools(rpg, rpg->chest->chest_two);
    rpg->chest->chest_three = init_bools(rpg, rpg->chest->chest_three);
    rpg->chest->chest_four = init_bools(rpg, rpg->chest->chest_four);
    rpg->chest->chest_dungeon = init_bools(rpg, rpg->chest->chest_dungeon);
    rpg->chest->chest_dun_two = init_bools(rpg, rpg->chest->chest_dun_two);
    rpg->chest->level = init_bools(rpg, rpg->chest->level);
    rpg->chest->chest_maze_quest = init_bools(rpg,
        rpg->chest->chest_maze_quest);
    rpg->chest->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->chest->sprite, rpg->assets->box3, sfTrue);
    rpg->chest->chest_maze->texture = sfTexture_createFromFile(
        my_scat(rpg->name, "/PNJ/pnj/chest_face.png"), NULL);
    if (rpg->chest->chest_maze->texture == NULL)
        exit(84);
    set_rest(rpg);
}
