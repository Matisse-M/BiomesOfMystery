/*
** EPITECH PROJECT, 2023
** my_custom_rectangle
** File description:
** Customize a rectangle
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

void my_custom_rectangle(sfRectangleShape *rect, float thickness,
    sfColor color, sfColor outline_color)
{
    sfRectangleShape_setOutlineThickness(rect, thickness);
    sfRectangleShape_setOutlineColor(rect, outline_color);
    sfRectangleShape_setFillColor(rect, color);
}
