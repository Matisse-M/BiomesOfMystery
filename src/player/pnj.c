/*
** EPITECH PROJECT, 2023
** setup player
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "csfml.h"
#include "rpg/player.h"

pnj_t *add_pnj(char *name, char *asset, sfVector2f pos, pnj_t **begin)
{
    pnj_t *new_pnj = malloc(sizeof(pnj_t));

    new_pnj->name = my_strdup(name);
    new_pnj->position = pos;
    new_pnj->texture = sfTexture_createFromFile(asset, NULL);
    if (new_pnj->texture == NULL)
        exit(84);
    new_pnj->sprite = my_set_sprite(new_pnj->texture, new_pnj->position,
        (sfVector2f) {1, 1}, 0);
    return new_pnj;
}

static void dup_array(char **speech, pnj_t *node)
{
    if (speech == NULL)
        return;
    node->speech = malloc(sizeof(char *) * (my_tablen(speech) + 1));
    for (int i = 0; i < my_tablen(speech); i++)
        node->speech[i] = my_strdup(speech[i]);
    node->speech[my_tablen(speech)] = NULL;
}

void add_dialogue(char *name, char **speech, pnj_t **begin)
{
    pnj_t *save = *begin;
    pnj_t **current = begin;

    while (*current != NULL) {
        if (my_strcmp(name, (*current)->name) == 0) {
            dup_array(speech, *current);
            break;
        }
        *current = (*current)->next;
    }
    *begin = save;
}
