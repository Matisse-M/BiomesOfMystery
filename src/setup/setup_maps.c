/*
** EPITECH PROJECT, 2023
** setup maps
** File description:
** Some function to setup <maps_t *maps;> in rpg_t
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"
#include <string.h>

static room_t *init_transition(room_t *room)
{
    room->sprite[0] = my_set_sprite(room->texture[0], (sfVector2f) {0, 0},
        (sfVector2f) {1, 1}, 0);
    room->sprite[1] = my_set_sprite(room->texture[1], (sfVector2f) {0, 0},
        (sfVector2f) {1, 1}, 0);
    room->sprite[2] = my_set_sprite(room->texture[2], (sfVector2f) {0, 0},
        (sfVector2f) {1, 1}, 0);
    room->is_trans = false;
    room->duration = 10.0f;
    room->originalSize = (sfVector2f) {480, 270};
    room->clock = sfClock_create();
    return room;
}

static room_t *fill_room(sfFloatRect area, char **asset)
{
    room_t *room = malloc(sizeof(room_t));

    room->is_active = false;
    room->unlock = false;
    room->area = area;
    room->texture = malloc(sizeof(sfTexture *) * 3);
    room->sprite = malloc(sizeof(sfSprite *) * 3);
    room->texture[0] = sfTexture_createFromFile(asset[0], NULL);
    room->texture[1] = sfTexture_createFromFile(asset[1], NULL);
    room->under = sfImage_createFromFile(asset[2]);
    room->texture[2] = sfTexture_createFromImage(room->under, NULL);
    if (room->texture[0] == NULL || room->texture[1] == NULL
        || room->texture[2] == NULL)
        exit(84);
    room = init_transition(room);
    return room;
}

static void create_896x560_map(maps_t *maps, rpg_t *rpg)
{
    maps->downstairs = fill_room((sfFloatRect) {232, 160, 630, 417},
        (char *[3]) {my_scat(rpg->name, "/img/hub/rez-chausée_base.png"),
        my_scat(rpg->name, "/img/hub/rez-chausée_col.png"),
        my_scat(rpg->name, "/img/hub/hub_under.png")});
    maps->upstairs = fill_room((sfFloatRect) {328, 160, 488, 353},
        (char *[3]) {my_scat(rpg->name, "/img/etage/etage_base.png"),
        my_scat(rpg->name, "/img/etage/etage_colision.png"),
        my_scat(rpg->name, "/img/etage/up_under.png")});
}

static void create_512x512_map(rpg_t *rpg, maps_t *maps)
{
    maps->beach = fill_room((sfFloatRect) {230, 127, 265, 370},
        (char *[3]) {my_scat(rpg->name, "/img/plage/beach_good_base.png"),
        my_scat(rpg->name, "/img/plage/beach_good_col.png"),
        my_scat(rpg->name, "/img/plage/plage_under.png")});
    maps->swamp = fill_room((sfFloatRect) {230, 127, 265, 370},
        (char *[3]) {my_scat(rpg->name, "/img/swamp/swamp_good_base.png"),
        my_scat(rpg->name, "/img/swamp/swamp_good_col.png"),
        my_scat(rpg->name, "/img/swamp/swamp_under.png")});
    maps->village = fill_room((sfFloatRect) {230, 127, 265, 370},
        (char *[3]) {my_scat(rpg->name, "/img/bp/bp_base.png"),
        my_scat(rpg->name, "/img/bp/bp_colision.png"),
        my_scat(rpg->name, "/img/bp/bp_under.png")});
    maps->museum = fill_room((sfFloatRect) {230, 127, 265, 370},
        (char *[3]) {my_scat(rpg->name, "/img/museum/museum_base.png"),
        my_scat(rpg->name, "/img/museum/museum_col.png"),
        my_scat(rpg->name, "/img/museum/musuem_under.png")});
}

static void create_192x144_map(rpg_t *rpg, maps_t *maps)
{
    maps->bathroom = fill_room((sfFloatRect) {0, 0, 0, 0},
        (char *[3]) {my_scat(rpg->name, "/img/salle_bain/salle_bain_base.png"),
        my_scat(rpg->name, "/img/salle_bain/salle_bain_col.png"),
        my_scat(rpg->name, "/img/salle_bain/bathroom_under.png")});
    maps->food_shop = fill_room((sfFloatRect) {0, 0, 0, 0},
        (char *[3]) {my_scat(rpg->name, "/img/food_shop/magasin_food_base.png")
        , my_scat(rpg->name, "/img/food_shop/magasin_food_col.png"),
        my_scat(rpg->name, "/img/food_shop/food_under.png")});
    maps->house = fill_room((sfFloatRect) {0, 0, 0, 0},
        (char *[3]) {my_scat(rpg->name, "/img/maison/maison_base.png"),
        my_scat(rpg->name, "/img/maison/maison_col.png"),
        my_scat(rpg->name, "/img/maison/maison_under.png")});
    maps->weapon_shop = fill_room((sfFloatRect) {0, 0, 0, 0},
        (char *[3]) {my_scat(rpg->name,
        "/img/weapon_shop/weapon_market_base.png"), my_scat(rpg->name,
        "/img/weapon_shop/weapon_market_col.png"), my_scat(rpg->name,
        "/img/weapon_shop/weapon_under.png")});
}

static void create_128x128_map(rpg_t *rpg, maps_t *maps)
{
    maps->dungeon = fill_room((sfFloatRect) {300, 200, 790, 580},
        (char *[3]) {my_scat(rpg->name, "/img/dungeon/dungeon.png"),
        my_scat(rpg->name, "/img/dungeon/dungeon_col.png"),
        my_scat(rpg->name, "/img/dungeon/uder_dugeon.png")});
    maps->grotte = fill_room((sfFloatRect) {0, 0, 0, 0},
        (char *[3]) {my_scat(rpg->name, "/img/museum/grotte.png"),
        my_scat(rpg->name, "/img/museum/grotte_col.png"),
        my_scat(rpg->name, "/img/museum/grotte_under.png")});
}

maps_t *fill_maps(rpg_t *rpg)
{
    maps_t *maps = malloc(sizeof(maps_t));

    maps->is_active = true;
    maps->is_trans = false;
    create_128x128_map(rpg, maps);
    create_512x512_map(rpg, maps);
    create_192x144_map(rpg, maps);
    create_896x560_map(maps, rpg);
    maps->maze = fill_room((sfFloatRect) {232, 128, 392, 351},
        (char *[3]) {my_scat(rpg->name, "/img/maze/maze_base.png"),
        my_scat(rpg->name, "/img/maze/maze_colision.png"),
        my_scat(rpg->name, "/img/maze/maze_under.png")});
    maps->downstairs->unlock = true;
    return maps;
}
