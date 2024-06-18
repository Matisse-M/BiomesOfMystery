/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** zoom_out
*/

#include "rpg.h"

static int get_zoom_factor(sfVector2f currentSize, sfVector2f originalSize,
    rpg_t *rpg, float zoom_factor)
{
    if (zoom_factor > 1.0f)
        zoom_factor = 1.0f;
    currentSize.x = originalSize.x * (0.5f + 0.5f * zoom_factor);
    currentSize.y = originalSize.y * (0.5f + 0.5f * zoom_factor);
    sfView_setSize(rpg->game->view, currentSize);
    return zoom_factor;
}

int zoom_transition(rpg_t *rpg, sfVector2f originalSize,
    float duration, float deltaTime)
{
    static float elapsed = 0.0f;
    static int zooming = 1;
    sfVector2f currentSize = {0, 0};
    float zoom_factor = 0.0f;

    if (zooming)
        zooming = 0;
    elapsed += deltaTime * 5;
    zoom_factor = elapsed / duration;
    zoom_factor = get_zoom_factor(currentSize, originalSize, rpg, zoom_factor);
    elapsed += deltaTime;
    if (zoom_factor >= 1.0f) {
        sfView_setSize(rpg->game->view, originalSize);
        elapsed = 0.0f;
        zooming = 1;
        return 1;
    }
    return 0;
}

void zoom_out_trans(rpg_t *rpg, room_t *room)
{
    int i = 0;

    room->time = sfClock_restart(room->clock);
    room->deltaTime = sfTime_asSeconds(room->time);
    while (room->deltaTime > 1) {
        room->time = sfClock_restart(room->clock);
        room->deltaTime = sfTime_asSeconds(room->time);
    }
    i = zoom_transition(rpg, room->originalSize, room->duration,
        room->deltaTime);
    if (i == 1) {
        room->is_trans = false;
        rpg->maps->is_trans = false;
    }
}
