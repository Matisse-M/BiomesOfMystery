/*
** EPITECH PROJECT, 2023
** my_framebuffer
** File description:
** Create and destroy a framebuffer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "csfml.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(width * height * 32 / 8);
    return (framebuffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    if (framebuffer->pixels != NULL)
        free(framebuffer->pixels);
    if (framebuffer != NULL)
        free(framebuffer);
}
