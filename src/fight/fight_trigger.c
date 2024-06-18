/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** fight_trigger
*/

#include "rpg.h"

int choose_enemy(int chance, bool is_active, rpg_t *rpg)
{
    int enemy = (chance % 5) + 1;

    if (rpg->characters->main->weapon == 3)
        rpg->fight->life2 = 20;
    if (rpg->characters->main->weapon == 4)
        rpg->fight->life2 = 15;
    if (rpg->characters->main->weapon == 8)
        rpg->fight->life2 = 12;
    if (rpg->characters->main->weapon == 9)
        rpg->fight->life2 = 8;
    if (is_active)
        enemy += 5;
    return enemy;
}

int set_with_delta(int delta, int value)
{
    int minimum = value - delta;
    int maximum = value + delta / 2;
    int new_value = minimum + rand() % (maximum - minimum + 1);

    return new_value;
}

enemy_t *prepare_enemy(rpg_t *rpg, enemy_t *enemy)
{
    if (rpg->fight->e_active - 1 > 9) {
        enemy->hp = enemy->hp_max;
        return enemy;
    }
    enemy->hp = set_with_delta(5, rpg->characters->main->hp_max);
    enemy->hp_max = enemy->hp;
    enemy->lvl = rpg->characters->main->lvl;
    return enemy;
}

bool fight_trigger(rpg_t *rpg)
{
    int chance = rand() % 100;

    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        rpg->fight->e_active = choose_enemy(chance,
            rpg->maps->dungeon->is_active, rpg);
        prepare_enemy(rpg, rpg->fight->enemy[rpg->fight->e_active - 1]);
        return true;
    }
    if (!rpg->maps->swamp->is_active && !rpg->maps->dungeon->is_active)
        return false;
    if (chance < 10 && time_elapsed(rpg->fight->trig_clock) > 2) {
        sfClock_restart(rpg->fight->trig_clock);
        rpg->fight->e_active = choose_enemy(chance,
            rpg->maps->dungeon->is_active, rpg);
        prepare_enemy(rpg, rpg->fight->enemy[rpg->fight->e_active - 1]);
        return true;
    }
    if (time_elapsed(rpg->fight->trig_clock) > 2)
        sfClock_restart(rpg->fight->trig_clock);
    return false;
}
