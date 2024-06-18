/*
** EPITECH PROJECT, 2023
** my_set_window
** File description:
** Create a window
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfRenderWindow *my_set_window(char *title, sfVideoMode mode,
    unsigned int bits)
{
    sfRenderWindow *window = sfRenderWindow_create(mode, title,
        sfResize | sfClose, NULL);

    return window;
}
