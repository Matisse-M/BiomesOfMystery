/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** manage_fight
*/

#include "rpg.h"

const int deg[10] = {10, 10, 15, 5, 7, 25, 35, 40, 12, 18};

int is_animal(main_player_t *main)
{
    if (main->weapon == 3 || main->weapon == 4 || main->weapon == 8 ||
        main->weapon == 9)
        return 1;
    return 0;
}

static void respawn(rpg_t *rpg)
{
    rpg = find_map(rpg);
    rpg->maps->downstairs->is_active = true;
    rpg->maps->under = rpg->maps->downstairs->under;
    rpg->characters->main->hp = rpg->characters->main->hp_max;
    rpg->characters->main->position = (sfVector2f) {653, 163};
    sfSprite_setPosition(rpg->characters->main->sprite,
        rpg->characters->main->position);
    sfView_setCenter(rpg->game->view, (sfVector2f) {640, 160});
}

static bool handle_death(rpg_t *rpg)
{
    int exp = rpg->fight->enemy[rpg->fight->e_active - 1]->exp;

    if (rpg->fight->enemy[rpg->fight->e_active - 1]->hp <= 0) {
        sfClock_restart(rpg->fight->clock);
        sfClock_restart(rpg->fight->trig_clock);
        rpg->fight->exp_won = exp;
        rpg->characters->main->exp += exp;
        rpg->characters->main->money += 5;
        return true;
    }
    if (rpg->characters->main->hp < 1) {
        rpg->fight->is_active = false;
        respawn(rpg);
        sfClock_restart(rpg->fight->clock);
        sfClock_restart(rpg->fight->trig_clock);
        return true;
    }
    return false;
}

static int handle_attack(int atk, bool critical, bool boost,
    main_player_t *main)
{
    int prob = rand() % 10;
    int atk2 = atk;

    if (main->weapon >= 0)
        atk2 = deg[main->weapon];
    if (boost && main->weapon >= 0)
        atk2 *= 2;
    if (!prob && critical) {
        if (is_animal(main))
            return (atk + atk2) * 2;
        return atk2 * 2;
    }
    if (is_animal(main))
        return atk + atk2;
    return atk2;
}

static int handle_eattack(int atk, bool critical, bool boost, rpg_t *rpg)
{
    int prob = rand() % 10;
    int atk2 = atk;

    if (rpg->fight->ice && prob == 0)
        return 0;
    if (rpg->fight->stone)
        atk2 = (int)(atk / 2);
    return atk2;
}

static void lose_hp(rpg_t *rpg)
{
    if (!is_animal(rpg->characters->main) || rpg->fight->life2 <= 0)
        rpg->characters->main->hp -= handle_eattack(rpg->fight->enemy
            [rpg->fight->e_active - 1]->atk, rand() % 100 < 10, false, rpg);
    else
        rpg->fight->life2 -= handle_eattack(rpg->fight->enemy
            [rpg->fight->e_active - 1]->atk, rand() % 100 < 10, false, rpg);
}

void e_attack(rpg_t *rpg)
{
    if (rpg->fight->enemy[rpg->fight->e_active - 1]->hp <= 0)
        return;
    lose_hp(rpg);
    if (rpg->characters->main->ricochets)
        rpg->fight->enemy[rpg->fight->e_active - 1]->hp -= 2;
    if (handle_death(rpg))
        return;
    if (rpg->characters->main->sustain) {
        rpg->characters->main->hp += 2;
        rpg->fight->enemy[rpg->fight->e_active - 1]->hp -= 5;
    }
    if (handle_death(rpg))
        return;
    if (rpg->fight->fire)
        rpg->fight->enemy[rpg->fight->e_active - 1]->hp -= 2;
    if (handle_death(rpg))
        return;
    sfClock_restart(rpg->fight->clock);
}

static void handle_attacks(rpg_t *rpg)
{
    if (rpg->fight->exp_won)
        return;
    if (rpg->fight->e_active > 9)
        rpg->fight->state = 1;
    sfClock_restart(rpg->fight->anim);
    rpg->fight->btn[0]->state = 0;
    rpg->fight->enemy[rpg->fight->e_active - 1]->hp -=
        handle_attack(rpg->characters->main->atk,
        rpg->characters->main->critical, rpg->characters->main->boost,
        rpg->characters->main);
    if (handle_death(rpg)) {
        rpg->fight->enemy[rpg->fight->e_active - 1]->hp =
            rpg->fight->enemy[rpg->fight->e_active - 1]->hp_max;
        sfSprite_setTextureRect(rpg->fight->player_life[0],
            (sfIntRect) {0, 0, 18, 4});
        sfSprite_setTextureRect(rpg->fight->enemy_life[0],
            (sfIntRect) {0, 0, 18, 4});
        return;
    }
    e_attack(rpg);
}

void main_button_effect(rpg_t *rpg)
{
    if (button_view_hover(rpg, rpg->fight->btn[0]))
        handle_attacks(rpg);
    if (button_view_hover(rpg, rpg->fight->btn[1])) {
        rpg->fight->btn[1]->state = 0;
        rpg->fight->scrolls->is_active = true;
    }
    if (button_view_hover(rpg, rpg->fight->btn[2])) {
        rpg->fight->btn[2]->state = 0;
        rpg->fight->items->is_active = true;
    }
    if (rpg->fight->e_active < 10) {
        if (button_view_hover(rpg, rpg->fight->btn[3])) {
            rpg->fight->btn[3]->state = 0;
            sfClock_restart(rpg->fight->clock);
            sfClock_restart(rpg->fight->trig_clock);
            rpg->fight->is_active = false;
        }
    } else
        sfRectangleShape_setTexture(rpg->fight->btn[3]->rect,
            rpg->assets->wrong, sfTrue);
}

void manage_fight(rpg_t *rpg)
{
    if (!rpg->maps->swamp->is_trans && !rpg->maps->dungeon->is_trans &&
        !rpg->fight->is_active && !rpg->inv->is_active &&
        rpg->chest->level->is_active != true) {
        rpg->fight->is_active = fight_trigger(rpg);
        rpg->fight->stone = false;
        rpg->fight->ice = false;
        rpg->fight->fire = false;
        return;
    }
    if (rpg->fight->is_active)
        draw_fight(rpg);
}
