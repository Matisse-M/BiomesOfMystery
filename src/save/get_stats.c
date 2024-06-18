/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_stats
*/

#include "rpg.h"

static int *get_int_from_str(char *str)
{
    int *nb = calloc(2, sizeof(int));
    int j = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == 47)
            j = i;
    nb[0] = atoi(str);
    nb[1] = atoi(str + j + 1);
    return nb;
}

rpg_t *get_hp(char *str, rpg_t *save)
{
    int *nb = NULL;

    if (strlen(str) < 6)
        str = "HP=20/20";
    nb = get_int_from_str(str + 3);
    save->characters->main->hp = nb[0];
    save->characters->main->hp_max = nb[1];
    if (save->characters->main->hp > save->characters->main->hp_max)
        save->characters->main->hp = save->characters->main->hp_max;
    if (save->characters->main->hp_max < 20)
        save->characters->main->hp_max = 20;
    if (nb)
        free(nb);
    return save;
}

rpg_t *get_level(char *str, rpg_t *save)
{
    int lvl = 0;

    if (strlen(str) < 7)
        str = "LEVEL=1";
    lvl = atoi(str + 6);
    save->characters->main->lvl = lvl < 1 ? 1 : lvl;
    return save;
}

rpg_t *get_experience(char *str, rpg_t *save)
{
    if (strlen(str) < 12)
        str = "EXPERIENCE=0";
    save->characters->main->exp = atoi(str + 11);
    return save;
}

rpg_t *get_attack(char *str, rpg_t *save)
{
    if (strlen(str) < 8)
        str = "ATTACK=5";
    save->characters->main->atk = atoi(str + 7);
    save->characters->main->atk = save->characters->main->atk < 5 ?
        5 : save->characters->main->atk;
    return save;
}

rpg_t *get_money(char *str, rpg_t *save)
{
    if (strlen(str) < 7)
        str = "MONEY=0";
    save->characters->main->money = atoi(str + 6);
    return save;
}
