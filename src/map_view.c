/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "csfml.h"

static void find_if_anim(rpg_t *rpg, room_t *room)
{
    if (rpg->maps->village->is_active == true)
        init_anim(rpg, rpg->anim);
    if (rpg->maps->swamp->is_active == true)
        update_rain(rpg->anim->rain_anim, rpg);
    find_pnjs(rpg);
}

static void draw_map(rpg_t *rpg, room_t *room)
{
    if (!rpg->chatbox->is_active && !rpg->inv->is_active &&
        !rpg->fight->is_active) {
        map_view(rpg, room->area);
        map_chatbox(rpg);
        move_player(rpg->game->clock_mv, rpg->characters->main, rpg);
    }
    if (room->is_trans == true)
        zoom_out_trans(rpg, room);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[0], NULL);
    if (rpg->maps->swamp->is_active == true)
        updtate_pudlle(rpg->anim->rain_anim, rpg);
    draw_pig3(rpg);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->characters->main->sprite, NULL);
    draw_monkey(rpg);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[1], NULL);
    find_if_anim(rpg, room);
    return;
}

static void draw_hub(rpg_t *rpg, room_t *room)
{
    if (rpg->chatbox->is_active == false && rpg->inv->is_active == false
        && rpg->fight->is_active == false) {
        map_view(rpg, room->area);
        map_chatbox(rpg);
        move_player(rpg->game->clock_mv, rpg->characters->main, rpg);
    }
    if (room->is_trans == true)
        zoom_out_trans(rpg, room);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[0], NULL);
    if (rpg->maps->downstairs->is_active == true)
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->maps->downstairs->pnj_mat->sprite[0], NULL);
    draw_pig2(rpg);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->characters->main->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[1], NULL);
    render_pnjs(rpg);
}

static void draw_submap(rpg_t *rpg, room_t *room)
{
    if (!rpg->chatbox->is_active && !rpg->inv->is_active &&
        !rpg->fight->is_active) {
        map_chatbox(rpg);
        sfView_setCenter(rpg->game->view, (sfVector2f) {97, 72});
        sfRenderWindow_setView(rpg->game->window, rpg->game->view);
        move_player(rpg->game->clock_mv, rpg->characters->main, rpg);
    }
    if (room->is_trans == true)
        zoom_out_trans(rpg, room);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[0], NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->characters->main->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[1], NULL);
    if (rpg->maps->food_shop->is_active == true)
        find_market(rpg);
    return;
}

static void draw_maze(rpg_t *rpg, room_t *room)
{
    if (!rpg->chatbox->is_active && !rpg->inv->is_active &&
        !rpg->fight->is_active) {
        map_view(rpg, room->area);
        map_chatbox(rpg);
        move_player(rpg->game->clock_mv, rpg->characters->main, rpg);
    }
    if (room->is_trans == true)
        zoom_out_trans(rpg, room);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[0], NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->characters->main->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[1], NULL);
    find_chest_in_maze(rpg, rpg->characters->main);
}

static void draw_weapon_area(rpg_t *rpg, room_t *room)
{
    if (!rpg->chatbox->is_active && !rpg->inv->is_active &&
        !rpg->fight->is_active) {
        map_chatbox(rpg);
        sfView_setCenter(rpg->game->view, (sfVector2f) {120, 96});
        sfRenderWindow_setView(rpg->game->window, rpg->game->view);
        move_player(rpg->game->clock_mv, rpg->characters->main, rpg);
    }
    if (room->is_trans == true)
        zoom_out_trans(rpg, room);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[0], NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->characters->main->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[1], NULL);
    if (rpg->maps->weapon_shop->is_active == true)
        find_weapon(rpg);
}

static void draw_groot(rpg_t *rpg, room_t *room)
{
    if (!rpg->chatbox->is_active && !rpg->inv->is_active &&
        !rpg->fight->is_active) {
        map_chatbox(rpg);
        sfView_setCenter(rpg->game->view, (sfVector2f) {97, 112});
        sfRenderWindow_setView(rpg->game->window, rpg->game->view);
        move_player(rpg->game->clock_mv, rpg->characters->main, rpg);
    }
    if (room->is_trans == true)
        zoom_out_trans(rpg, room);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[0], NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->characters->main->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        room->sprite[1], NULL);
}

void wich_map_two(rpg_t *rpg)
{
    if (rpg->maps->weapon_shop->is_active == true)
        draw_weapon_area(rpg, rpg->maps->weapon_shop);
    if (rpg->maps->maze->is_active == true)
        draw_maze(rpg, rpg->maps->maze);
    if (rpg->maps->museum->is_active == true)
        draw_map(rpg, rpg->maps->museum);
    if (rpg->maps->dungeon->is_active == true) {
        draw_hub(rpg, rpg->maps->dungeon);
        draw_rajah(rpg);
        draw_cyclop(rpg);
        check_chest_dungeon(rpg, rpg->characters->main);
    }
    if (rpg->maps->grotte->is_active == true) {
        if (!rpg->boss->pyro && !rpg->boss->cryo)
            rpg->maps->dungeon->unlock = true;
        draw_groot(rpg, rpg->maps->grotte);
        draw_pyro(rpg);
        draw_cryo(rpg);
    }
}

static void which_map_three(rpg_t *rpg)
{
    if (rpg->maps->village->is_active == true)
        draw_map(rpg, rpg->maps->village);
    if (rpg->maps->bathroom->is_active == true)
        draw_submap(rpg, rpg->maps->bathroom);
    if (rpg->maps->food_shop->is_active == true)
        draw_submap(rpg, rpg->maps->food_shop);
    if (rpg->maps->house->is_active == true) {
        draw_submap(rpg, rpg->maps->house);
        draw_dog(rpg);
    }
}

void which_map(rpg_t *rpg, main_player_t *main)
{
    if (rpg->maps->upstairs->is_active == true)
        draw_hub(rpg, rpg->maps->upstairs);
    if (rpg->maps->downstairs->is_active == true) {
        draw_hub(rpg, rpg->maps->downstairs);
        draw_pig1(rpg);
    }
    if (rpg->maps->beach->is_active == true)
        draw_map(rpg, rpg->maps->beach);
    if (rpg->maps->swamp->is_active == true) {
        draw_map(rpg, rpg->maps->swamp);
        draw_frog(rpg);
    }
    which_map_three(rpg);
    wich_map_two(rpg);
}
