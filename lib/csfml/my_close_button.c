/*
** EPITECH PROJECT, 2023
** my_close_button
** File description:
** Detect if the close button is pressed
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

int my_close_button(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            return (0);
    }
    return (1);
}
