/*
** EPITECH PROJECT, 2023
** my_framebuffer
** File description:
** Create and destroy a framebuffer
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "csfml.h"

void my_put_pixel(framebuffer_t *framebuffer, unsigned x, unsigned y,
    sfColor color)
{
    if (x < framebuffer->width && y < framebuffer->height) {
        framebuffer->pixels[(y * framebuffer->width + x) * 4] = color.r;
        framebuffer->pixels[(y * framebuffer->width + x) * 4 + 1] = color.g;
        framebuffer->pixels[(y * framebuffer->width + x) * 4 + 2] = color.b;
        framebuffer->pixels[(y * framebuffer->width + x) * 4 + 3] = color.a;
    }
}

void draw_square(framebuffer_t *framebuffer, sfVector2i position,
    unsigned int size, sfColor color)
{
    int x = position.x - (size / 2);
    int y = position.y - (size / 2);

    for (int i = 1; i < size - 1; i++) {
        my_put_pixel(framebuffer, x + i, y, color);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - 1; j++) {
            my_put_pixel(framebuffer, x + i, y + j, color);
        }
    }
    for (int i = 1; i < size - 1; i++) {
        my_put_pixel(framebuffer, x + i, y + size - 1, color);
    }
}

void draw_horizontal_line(framebuffer_t *framebuffer, sfVector2i position,
    unsigned int size, sfColor color)
{
    for (int i = 0; i < size; i++) {
        my_put_pixel(framebuffer, position.x + i, position.y, color);
    }
}
