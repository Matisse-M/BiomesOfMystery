/*
** EPITECH PROJECT, 2023
** setup player
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"

chatbox_t *fill_chatboxes(rpg_t *rpg)
{
    chatbox_t *box = malloc(sizeof(chatbox_t));

    box->is_active = false;
    box->position.x = 0;
    box->position.y = 0;
    box->texture = sfTexture_createFromFile(
        my_scat(rpg->name, "/img/dialog.png"), NULL);
    if (box->texture == NULL)
        exit(84);
    box->sprite = my_set_sprite(box->texture,
        box->position, (sfVector2f) {1, 1}, 0);
    return box;
}
