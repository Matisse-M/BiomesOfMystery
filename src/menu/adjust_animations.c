/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** adjust_animations
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "csfml.h"

void adjust_animations(rpg_t *rpg, sfVideoMode res)
{
    for (int i = 0; i < 2; i++) {
        set_new_pos_sprite(rpg->menu->animations->tree[i], res);
        set_new_pos_sprite(rpg->begin->sprites[i], res);
    }
}
