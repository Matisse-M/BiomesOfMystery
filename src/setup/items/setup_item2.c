/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main loops of our rpg
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "csfml.h"

void potion(main_player_t *main)
{
    main->hp += main->hp_max * 25 / 100;
    if (main->hp > main->hp_max)
        main->hp = main->hp_max;
}

void potion_plus(main_player_t *main)
{
    main->hp += main->hp_max * 50 / 100;
    if (main->hp > main->hp_max)
        main->hp = main->hp_max;
}

void potion_max(main_player_t *main)
{
    main->hp = main->hp_max;
}

void water(main_player_t *main)
{
    main->hp += main->hp_max * 10 / 100;
    if (main->hp > main->hp_max)
        main->hp = main->hp_max;
}

void milk(main_player_t *main)
{
    main->hp += main->hp_max * 20 / 100;
    if (main->hp > main->hp_max)
        main->hp = main->hp_max;
}
