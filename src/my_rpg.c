/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main loops of our rpg
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "csfml.h"

static void restart_move_clock(sfClock **clock)
{
    sfTime time = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(time);

    if (f > 0.8)
        sfClock_restart(*clock);
}

static void menu_scene(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->game->window, rpg->menu->background, NULL);
    if (rpg->menu->title->is_active == true)
        draw_title_screen(rpg);
    if (rpg->menu->start->is_active == true)
        draw_start_menu(rpg);
    if (rpg->menu->settings->is_active == true)
        draw_settings(rpg);
}

static void is_a_man(rpg_t *rpg, main_player_t *main)
{
    main->texture[0] = sfTexture_createFromFile(
        my_scat(rpg->name, "/PNJ/main-male/SpriteSheet.png"), NULL);
    main->texture[1] = sfTexture_createFromFile(
        my_scat(rpg->name, "/PNJ/main-male/Faceset.png"), NULL);
    if (main->texture[0] == NULL || main->texture[1] == NULL)
        exit(84);
    main->sprite = my_set_sprite(main->texture[0],
        main->position, (sfVector2f) {1, 1}, 0);
    main->face = my_set_sprite(main->texture[1],
        main->position, (sfVector2f) {1, 1}, 0);
}

static void is_a_girl(rpg_t *rpg, main_player_t *main)
{
    main->texture[0] = sfTexture_createFromFile(
        my_scat(rpg->name, "/PNJ/main-female/SpriteSheet.png"), NULL);
    main->texture[1] = sfTexture_createFromFile(
        my_scat(rpg->name, "/PNJ/main-female/Faceset.png"), NULL);
    main->sprite = my_set_sprite(main->texture[0],
        main->position, (sfVector2f) {1, 1}, 0);
    main->face = my_set_sprite(main->texture[1],
        main->position, (sfVector2f) {1, 1}, 0);
}

void chara_chosen(rpg_t *rpg)
{
    if (rpg->begin->gender == 1)
        is_a_man(rpg, rpg->characters->main);
    else
        is_a_girl(rpg, rpg->characters->main);
    if (rpg->begin->alpha->answer != NULL)
        rpg->characters->main->name = my_strdup(rpg->begin->alpha->answer);
    else
        rpg->characters->main->name = my_strdup("SACHA");
}

static void beginning_scene(rpg_t *rpg)
{
    sfVector2f pos = sfRectangleShape_getPosition(rpg->begin->name_bar->rect);
    sfTime time = sfClock_getElapsedTime(rpg->begin->alpha->write_clock);
    float f = sfTime_asSeconds(time);

    sfRenderWindow_drawSprite(rpg->game->window, rpg->menu->background, NULL);
    select_anim(rpg, 0);
    select_anim(rpg, 1);
    hover_choose_chara(rpg);
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(rpg->game->window,
            rpg->begin->sprites[i], NULL);
    hover_textbox(rpg, f);
    sfText_setPosition(rpg->begin->name, (sfVector2f) {pos.x + 250 -
        (float) (my_strlen(rpg->begin->alpha->answer) * 12), 502});
    sfRenderWindow_drawText(rpg->game->window, rpg->begin->name, NULL);
    validate_hover(rpg, rpg->begin);
}

static void game_scene(rpg_t *rpg, main_player_t *main)
{
    restart_move_clock(&rpg->game->clock_mv);
    which_map(rpg, main);
    if (!rpg->fight->is_active && !rpg->chatbox->is_active &&
        sfKeyboard_isKeyPressed(sfKeyEscape) &&
        time_elapsed(rpg->inv->clock) > 0.2 &&
        rpg->maps->is_trans == false) {
        rpg->inv->is_active = !rpg->inv->is_active;
        sfClock_restart(rpg->inv->clock);
    }
    draw_inv_menu(rpg);
    if (!rpg->inv->is_active && !rpg->store->is_active &&
        !rpg->skilltree->is_active)
        draw_infobar(rpg);
    manage_fight(rpg);
    render_chatbox(rpg, main, rpg->maps->downstairs);
    draw_inv_menu(rpg);
}

static void handle_scene_transition(rpg_t *rpg)
{
    if (rpg->menu->is_active) {
        rpg->maps->num = 0;
        menu_scene(rpg);
    }
    if (rpg->begin->is_active) {
        rpg->maps->num = 0;
        beginning_scene(rpg);
    }
    if (rpg->game->is_active) {
        game_scene(rpg, rpg->characters->main);
    }
}

void rpg_is_open(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->game->window)) {
        event_handler(rpg);
        update_bag(rpg, rpg->inv->conso);
        sfRenderWindow_clear(rpg->game->window, sfBlack);
        if (rpg->splash->splash_active)
            preload_splash_screen(rpg, rpg->splash->clock);
        else
            handle_scene_transition(rpg);
        sfRenderWindow_display(rpg->game->window);
    }
}

void my_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    test_assets(rpg);
    rpg->assets = fill_assets_struct(rpg);
    rpg->game = fill_game_params(rpg);
    rpg->chatbox = fill_chatboxes(rpg);
    rpg->menu = fill_menu(rpg, rpg->assets);
    rpg->quests = fill_quests(rpg);
    rpg->inv = create_inventory(rpg);
    rpg->maps = fill_maps(rpg);
    rpg->begin = fill_beginning_menu(rpg->assets);
    rpg->characters = malloc(sizeof(characters_t));
    rpg->characters->main = fill_main_player();
    rpg->skilltree = fill_skilltree(rpg->assets);
    rpg->store = fill_store(rpg);
    rpg->fight = create_fight(rpg);
    rpg->info_bar = fill_infobar(rpg);
    rpg->splash = init_splash_screen(rpg);
    fill_anim_layer(rpg);
    load_assets(rpg, rpg->maps->downstairs);
}
