/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** clock_management
*/

#include "rpg.h"

void clock_management(rpg_t *rpg)
{
    if (time_elapsed(rpg->maps->inter->clock_e) > 0.3) {
        rpg->maps->inter->e_relased = false;
        sfClock_restart(rpg->maps->inter->clock_e);
    }
    if (time_elapsed(rpg->maps->inter->clock_enter) > 0.5) {
        rpg->maps->inter->enter = false;
        sfClock_restart(rpg->maps->inter->clock_enter);
    }
}
