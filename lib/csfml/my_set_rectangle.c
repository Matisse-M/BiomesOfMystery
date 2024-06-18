/*
** EPITECH PROJECT, 2023
** my_set_rectangle
** File description:
** Create a rectangle
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfRectangleShape *my_set_rectangle(sfVector2f size, sfVector2f pos,
    sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setFillColor(rect, color);
    return rect;
}
