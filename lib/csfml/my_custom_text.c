/*
** EPITECH PROJECT, 2023
** my_custom_rectangle
** File description:
** Customize a rectangle
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

void my_custom_text(sfText *text, float thickness, sfColor color,
    sfColor outline_color)
{
    sfText_setOutlineThickness(text, thickness);
    sfText_setOutlineColor(text, outline_color);
    sfText_setColor(text, color);
}
