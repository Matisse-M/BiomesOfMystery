/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rpg.h"
#include "csfml.h"
#include "my.h"

static void del_character(rpg_t *rpg, sfClock **clock, float f)
{
    char *new = NULL;

    if (rpg->begin->alpha->answer == NULL)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyBack) && f > 0.2) {
        new = malloc(sizeof(char) * my_strlen(rpg->begin->alpha->answer) + 1);
        for (int i = 0; i < my_strlen(rpg->begin->alpha->answer) - 1; i++)
            new[i] = rpg->begin->alpha->answer[i];
        new[my_strlen(rpg->begin->alpha->answer) - 1] = '\0';
        if (new[0] != '\0')
            rpg->begin->alpha->answer = my_strdup(new);
        else
            rpg->begin->alpha->answer = NULL;
        if (new != NULL)
            free(new);
        sfText_setString(rpg->begin->name, rpg->begin->alpha->answer);
        rpg->begin->alpha->size -= 1;
        sfClock_restart(*clock);
        return;
    }
}

void update_name(rpg_t *rpg, sfClock **clock, char c)
{
    if (rpg->begin->alpha->size < rpg->begin->alpha->max) {
        rpg->begin->alpha->answer = my_realloc(rpg->begin->alpha->answer, 1);
        rpg->begin->alpha->answer[rpg->begin->alpha->size] = c;
        sfText_setString(rpg->begin->name, rpg->begin->alpha->answer);
        rpg->begin->alpha->size++;
        sfClock_restart(*clock);
    }
}

void my_put_alphabet(rpg_t *rpg, sfClock **clock, float f)
{
    my_alpha(rpg, clock, f);
    my_alpha_maj(rpg, clock, f);
    del_character(rpg, clock, f);
}
