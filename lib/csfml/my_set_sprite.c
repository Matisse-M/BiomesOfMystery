/*
** EPITECH PROJECT, 2023
** my_set_sprite
** File description:
** Create a sprite
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>

sfSprite *my_set_sprite(sfTexture *texture, sfVector2f pos, sfVector2f size,
    float rotate)
{
    sfSprite *sprite = sfSprite_create();

    if (texture == NULL)
        exit(84);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, size);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setRotation(sprite, rotate);
    return (sprite);
}
