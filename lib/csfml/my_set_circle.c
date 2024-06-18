/*
** EPITECH PROJECT, 2023
** my_set_rectangle
** File description:
** Create a rectangle
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfCircleShape *my_set_circle(float radius, sfVector2f pos, sfColor color)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setFillColor(circle, color);
    return (circle);
}
