/*
** EPITECH PROJECT, 2023
** setup game params
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"

game_t *fill_game_params(rpg_t *rpg)
{
    game_t *game = malloc(sizeof(game_t));

    game->is_active = false;
    game->vol_music = 5;
    game->vol_sound = 5;
    game->mode = MEDIUM_MODE;
    game->window = my_set_window("Biomes of Mystery", MEDIUM_MODE, 32);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->view = sfView_create();
    sfView_setSize(game->view, (sfVector2f) {480, 270});
    sfView_setCenter(game->view, (sfVector2f) {640, 160});
    game->clock_mv = sfClock_create();
    game->clock_menu = sfClock_create();
    game->music = sfMusic_createFromFile(rpg->assets->music_menu);
    return game;
}
