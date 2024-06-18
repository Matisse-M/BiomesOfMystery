/*
** EPITECH PROJECT, 2023
** my_set_sprite
** File description:
** Create a sprite
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "rpg.h"

sfText *my_set_text(rpg_t *rpg, char *str, int size, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, sfFont_createFromFile(my_scat(rpg->name, rpg->font)));
    if (text == NULL)
        exit(84);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setColor(text, sfBlack);
    return (text);
}
