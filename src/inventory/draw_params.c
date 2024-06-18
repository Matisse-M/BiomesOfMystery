/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main loops of our rpg
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "csfml.h"

static void draw_btn_reso(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->settings->resolutions[0]->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->settings->resolutions[1]->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->settings->resolutions[2]->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->resolutions[0]->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->resolutions[1]->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->resolutions[2]->text, NULL);
    draw_key_game(rpg);
}

static void draw_resolutions(rpg_t *rpg, sett_t *sett)
{
    if (button_view_hover(rpg, sett->resolutions[0]) == 1) {
        sett->resolutions[0]->state = 0;
        modify_key_pos(rpg, (sfVector2f) {150, 470}, (sfVector2f) {820, 470});
        rpg->game->window = change_res(rpg, LOW_MODE, LOW_FM);
        rpg->inv->is_active = false;
    }
    if (button_view_hover(rpg, sett->resolutions[1]) == 1) {
        sett->resolutions[1]->state = 0;
        modify_key_pos(rpg, (sfVector2f){170, 530}, (sfVector2f){980, 530});
        rpg->game->window = change_res(rpg, MEDIUM_MODE, LOW_FM);
        rpg->inv->is_active = false;
    }
    if (button_view_hover(rpg, sett->resolutions[2]) == 1) {
        sett->resolutions[2]->state = 0;
        modify_key_pos(rpg, (sfVector2f) {220, 600}, (sfVector2f) {1200, 600});
        rpg->game->window = change_res(rpg, HIGH_MODE, LOW_FM);
        rpg->inv->is_active = false;
    }
    draw_btn_reso(rpg);
}

static void draw_btn_params(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->settings->resume->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->settings->save->rect, NULL);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->inv->settings->exit->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->resume->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->save->text, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->inv->settings->exit->text, NULL);
}

static void resume_game(rpg_t *rpg)
{
    char **array = read_file(my_scat(rpg->name, SAVE));

    if (!array)
        return;
    rpg = parse_save(rpg, array);
    rpg->inv->is_active = false;
}

static void save_game(rpg_t *rpg)
{
    char **array = prepare_save(rpg);

    write_file(my_scat(rpg->name, SAVE), array);
    rpg->inv->is_active = false;
}

static void draw_params(rpg_t *rpg, sett_t *sett)
{
    if (!access(my_scat(rpg->name, SAVE), F_OK) &&
        button_view_hover(rpg, sett->resume) == 1) {
        sett->resume->state = 0;
        resume_game(rpg);
    }
    if (access(my_scat(rpg->name, SAVE), F_OK))
        sfRectangleShape_setTexture(sett->resume->rect,
            rpg->assets->wrong, sfTrue);
    if (button_view_hover(rpg, sett->save) == 1) {
        sett->save->state = 0;
        save_game(rpg);
    }
    if (button_view_hover(rpg, sett->exit) == 1) {
        sett->exit->state = 0;
        rpg->game->is_active = false;
        rpg->menu->is_active = true;
        rpg->menu->title->is_active = true;
        sfRenderWindow_close(rpg->game->window);
    }
    draw_btn_params(rpg);
}

void draw_resolutions_params(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->inv->settings->under_music, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->inv->settings->under_sound, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->inv->settings->musicbar, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->inv->settings->soundbar, NULL);
    draw_resolutions(rpg, rpg->inv->settings);
    draw_params(rpg, rpg->inv->settings);
}
