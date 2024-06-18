/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** draw_fight
*/

#include "rpg.h"
#include <string.h>

static void draw_texts(rpg_t *rpg, sfVector2f center)
{
    sfText_setPosition(rpg->fight->player_hp, (sfVector2f) {center.x - 220,
        center.y - 5});
    sfText_setPosition(rpg->fight->enemy_hp, (sfVector2f) {center.x + 88,
        center.y - 115});
    sfText_setString(rpg->fight->player_hp, rpg->characters->main->name);
    sfText_setString(rpg->fight->enemy_hp, rpg->fight->enemy[
        rpg->fight->e_active - 1]->name);
    sfRenderWindow_drawText(rpg->game->window, rpg->fight->player_hp, NULL);
    sfRenderWindow_drawText(rpg->game->window, rpg->fight->enemy_hp, NULL);
}

static void draw_enemy(rpg_t *rpg, enemy_t *enemy, sfVector2f center)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(enemy->clock)) > 100) {
        sfClock_restart(enemy->clock);
        sfSprite_setTextureRect(enemy->sprite,
            (sfIntRect) {0, 16 * (rand() % 4), 16, 16});
    }
    sfSprite_setPosition(enemy->sprite,
        (sfVector2f) {center.x - 5, center.y - 60});
    sfRenderWindow_drawSprite(rpg->game->window, enemy->sprite, NULL);
}

static void draw_buttons(rpg_t *rpg, sfVector2f center)
{
    if (rpg->fight->exp_won)
        return;
    main_button_effect(rpg);
    for (int i = 0; i < 4; i++) {
        sfRectangleShape_setPosition(rpg->fight->btn[i]->rect,
            (sfVector2f) {center.x - 220 + i * 112, center.y + 70});
        sfText_setPosition(rpg->fight->btn[i]->text,
            (sfVector2f) {center.x - 205 + i * 112, center.y + 85});
        sfRenderWindow_drawRectangleShape(rpg->game->window,
            rpg->fight->btn[i]->rect, NULL);
        sfRenderWindow_drawText(rpg->game->window, rpg->fight->btn[i]->text,
            NULL);
    }
}

void draw_lifebar(rpg_t *rpg, sfVector2f pos)
{
    sfSprite_setTextureRect(rpg->fight->enemy_life[0], (sfIntRect)
        {0, 0, ((int)(18 * rpg->fight->enemy[rpg->fight->e_active - 1]->hp /
        rpg->fight->enemy[rpg->fight->e_active - 1]->hp_max)), 4});
    sfSprite_setTextureRect(rpg->fight->player_life[0], (sfIntRect)
        {0, 0, ((int)(18 * rpg->characters->main->hp /
        rpg->characters->main->hp_max)), 4});
    sfSprite_setTextureRect(rpg->fight->animal_life, (sfIntRect)
            {0, 0, ((int)(18 * rpg->fight->life2 / 20)), 4});
    sfSprite_setPosition(rpg->fight->player_life[0],
        (sfVector2f) {pos.x - 218, pos.y + 20});
    sfSprite_setPosition(rpg->fight->player_life[1],
        (sfVector2f) {pos.x - 218, pos.y + 20});
    if (is_animal(rpg->characters->main))
        sfSprite_setPosition(rpg->fight->animal_life,
            (sfVector2f) {pos.x - 218, pos.y + 20});
    sfSprite_setPosition(rpg->fight->enemy_life[0],
        (sfVector2f) {pos.x + 90, pos.y - 90});
    sfSprite_setPosition(rpg->fight->enemy_life[1],
        (sfVector2f) {pos.x + 90, pos.y - 90});
}

static void draw_boxes(rpg_t *rpg, sfVector2f pos)
{
    sfRectangleShape_setPosition(rpg->fight->player_box,
        (sfVector2f) {pos.x - 230, pos.y - 10});
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->fight->player_box, NULL);
    if (rpg->fight->e_active)
        draw_lifebar(rpg, pos);
    sfRectangleShape_setPosition(rpg->fight->enemy_box,
        (sfVector2f) {pos.x + 80, pos.y - 120});
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->fight->enemy_box, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->fight->player_life[1], NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->fight->enemy_life[1], NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->fight->player_life[0], NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->fight->animal_life, NULL);
    sfRenderWindow_drawSprite(rpg->game->window,
        rpg->fight->enemy_life[0], NULL);
}

static void draw_background(rpg_t *rpg, sfVector2f pos)
{
    if (rpg->maps->dungeon->is_active) {
        sfRectangleShape_setPosition(rpg->fight->bbg,
            (sfVector2f) {pos.x - 250, pos.y - 140});
        sfRenderWindow_drawRectangleShape(rpg->game->window, rpg->fight->bbg,
            NULL);
    } else {
        sfRectangleShape_setPosition(rpg->fight->bg,
            (sfVector2f) {pos.x - 250, pos.y - 140});
        sfRenderWindow_drawRectangleShape(rpg->game->window, rpg->fight->bg,
            NULL);
    }
    sfRectangleShape_setPosition(rpg->fight->menu,
        (sfVector2f) {pos.x - 240, pos.y + 55});
    sfRenderWindow_drawRectangleShape(rpg->game->window, rpg->fight->menu,
        NULL);
}

static int pos_spell(fight_t *f, sfClock *clock)
{
    float time = time_elapsed(clock);

    if (time < 0.25)
        return 0;
    if (time < 0.5)
        return 40;
    if (time < 0.75)
        return 80;
    if (time > 1) {
        f->state = 0;
        sfClock_restart(clock);
    }
    return 120;
}

static void draw_fx(rpg_t *rpg, sfVector2f pos)
{
    sfTexture *fire = rpg->assets->fire_spell;
    sfTexture *ice = rpg->assets->ice_spell;
    sfTexture *stone = rpg->assets->stone_spell;

    if (rpg->fight->state > 1) {
        if (rpg->fight->state == 2)
            sfSprite_setTexture(rpg->fight->scroll, fire, 1);
        if (rpg->fight->state == 3)
            sfSprite_setTexture(rpg->fight->scroll, ice, 1);
        if (rpg->fight->state == 4)
            sfSprite_setTexture(rpg->fight->scroll, stone, 1);
        sfSprite_setTextureRect(rpg->fight->scroll,
            (sfIntRect) {pos_spell(rpg->fight, rpg->fight->anim), 0, 40, 40});
        sfSprite_setPosition(rpg->fight->scroll,
            (sfVector2f) {pos.x - 15, pos.y - 60});
        sfRenderWindow_drawSprite(rpg->game->window, rpg->fight->scroll, NULL);
    }
}

static void draw_won_msg(rpg_t *rpg)
{
    char str[20] = {0};
    sfVector2f pos = sfView_getCenter(rpg->game->view);

    snprintf(str, 20, "YOU WON %d XP !", rpg->fight->exp_won);
    sfText_setPosition(rpg->fight->end_msg,
        (sfVector2f) {pos.x - 150, pos.y + 80});
    sfText_setPosition(rpg->fight->lvl_up, (sfVector2f) {pos.x + 50,
        pos.y + 80});
    sfText_setString(rpg->fight->end_msg, str);
    sfRenderWindow_drawText(rpg->game->window, rpg->fight->end_msg, NULL);
    if (rpg->characters->main->exp >= 100)
        sfRenderWindow_drawText(rpg->game->window, rpg->fight->lvl_up, NULL);
    if (time_elapsed(rpg->fight->clock) > 2) {
        update_level(rpg->characters->main);
        rpg->fight->exp_won = 0;
        rpg->fight->is_active = false;
        get_reward(rpg);
        sfClock_restart(rpg->fight->clock);
    }
}

void draw_fight(rpg_t *rpg)
{
    sfVector2f pos = sfView_getCenter(rpg->game->view);

    sfRenderWindow_clear(rpg->game->window, sfWhite);
    draw_background(rpg, pos);
    draw_boxes(rpg, pos);
    if (rpg->fight->e_active <= 10 && rpg->fight->e_active > 0)
        draw_enemy(rpg, rpg->fight->enemy[rpg->fight->e_active - 1], pos);
    if (rpg->fight->e_active > 10)
        draw_boss(rpg, rpg->fight->enemy[rpg->fight->e_active - 1], pos);
    draw_fx(rpg, pos);
    draw_texts(rpg, pos);
    if (!rpg->fight->items->is_active && !rpg->fight->scrolls->is_active) {
        draw_buttons(rpg, pos);
    } else {
        draw_item_menu(rpg, rpg->fight->items);
        draw_scrolls(rpg, rpg->fight->scrolls);
    }
    if (rpg->fight->exp_won)
        draw_won_msg(rpg);
}
