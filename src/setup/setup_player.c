/*
** EPITECH PROJECT, 2023
** setup player
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdbool.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg/player.h"

static void set_values(main_player_t *main)
{
    main->critical = false;
    main->boost = false;
    main->ricochets = false;
    main->sustain = false;
    main->lvl = 1;
    main->hp = 20;
    main->hp_max = 20;
    main->exp = 0;
    main->atk = 5;
    main->emo = 0;
    main->money = 1000;
    main->bag = 0;
    main->weapon = -1;
}

main_player_t *fill_main_player(void)
{
    main_player_t *main = malloc(sizeof(main_player_t));

    set_values(main);
    main->direction = 16;
    main->name = NULL;
    main->position.x = 653;
    main->position.y = 163;
    main->sound = malloc(sizeof(sfSound *) * 3);
    main->texture = malloc(sizeof(sfTexture *) * 2);
    main->sprite = NULL;
    main->face = NULL;
    return main;
}
