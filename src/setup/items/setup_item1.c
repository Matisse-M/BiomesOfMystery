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

void hp_plus(main_player_t *main)
{
    main->hp += 1;
    main->hp_max += 1;
}

void atk_plus(main_player_t *main)
{
    main->atk += 1;
}

void medikit(main_player_t *main)
{
}
