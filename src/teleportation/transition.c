/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** transition
*/

#include "rpg.h"


sfCircleShape *creat_circle(sfVector2f pos, float radius, float thick)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setOutlineColor(circle, sfBlack);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, thick);
    return circle;
}

int close_circle(rpg_t *rpg, int radius, room_t *room)
{
    sfRenderWindow_clear(rpg->game->window, sfBlack);
    if (radius > 4) {
        sfRenderWindow_drawSprite(rpg->game->window,
            room->sprite[0], NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->characters->main->sprite, NULL);
        sfRenderWindow_drawSprite(rpg->game->window,
            room->sprite[1], NULL);
        radius -= 4;
    } else if (radius <= 4) {
        radius -= 1;
    }
    return radius;
}

int render_circles(rpg_t *rpg, sfCircleShape *circle, int radius,
    int windowWidth)
{
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfBlack);
    sfCircleShape_setOutlineThickness(circle, windowWidth);
    return radius;
}

void render_trans(rpg_t *rpg, room_t *room, int windowWidth,
    sfVector2f position)
{
    int radius = windowWidth / 4;
    int centerX = position.x;
    int centerY = position.y;
    sfCircleShape *circle = creat_circle((sfVector2f){centerX - radius,
        centerY - radius}, radius, 1);

    while (radius >= 0) {
        radius = render_circles(rpg, circle, radius, windowWidth);
        sfCircleShape_setPosition(circle, (sfVector2f)
            {centerX - radius, centerY - radius});
        sfRenderWindow_drawCircleShape(rpg->game->window, circle, NULL);
        sfRenderWindow_display(rpg->game->window);
        radius = close_circle(rpg, radius, room);
    }
    sfRenderWindow_clear(rpg->game->window, sfBlack);
    sfRenderWindow_display(rpg->game->window);
    sfCircleShape_destroy(circle);
    rpg->maps->num = 1;
    return;
}
