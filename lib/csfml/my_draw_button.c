/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** my_draw_button
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

void my_draw_button(sfRenderWindow *window, sfRectangleShape *rect,
    sfText *text)
{
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    if (text)
        sfRenderWindow_drawText(window, text, NULL);
}
