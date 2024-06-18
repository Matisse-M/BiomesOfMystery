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

void shrimp(main_player_t *main)
{
    main->hp += 5;
    if (main->hp > main->hp_max)
        main->hp = main->hp_max;
}

void sushi(main_player_t *main)
{
    main->hp += 10;
    if (main->hp > main->hp_max)
        main->hp = main->hp_max;
}

void octopus(main_player_t *main)
{
    main->hp += 15;
    if (main->hp > main->hp_max)
        main->hp = main->hp_max;
}

static void update_fortune_hp(main_player_t *main, int i)
{
    if (i == 0)
        main->hp -= main->hp_max * 50 / 100;
    if (i == 1)
        main->hp += main->hp_max * 10 / 100;
    if (i == 2)
        main->hp += main->hp_max * 25 / 100;
    if (i == 3)
        main->hp += main->hp_max * 50 / 100;
    if (i == 4)
        main->hp += main->hp_max * 75 / 100;
    if (i == 5)
        main->hp += main->hp_max;
}

void fortune(main_player_t *main)
{
    int i = 0;

    srand(time(NULL));
    i = rand() % 6;
    update_fortune_hp(main, i);
    if (main->hp > main->hp_max)
        main->hp = main->hp_max;
    if (main->hp <= 0)
        main->hp = 1;
}

void medikit2(rpg_t *rpg)
{
    if (is_animal(rpg->characters->main)) {
        if (rpg->characters->main->weapon == 3)
            rpg->fight->life2 = 20;
        if (rpg->characters->main->weapon == 4)
            rpg->fight->life2 = 15;
        if (rpg->characters->main->weapon == 8)
            rpg->fight->life2 = 12;
        if (rpg->characters->main->weapon == 9)
            rpg->fight->life2 = 8;
    }
}
