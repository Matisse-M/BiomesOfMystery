/*
** EPITECH PROJECT, 2024
** bck
** File description:
** get_boss
*/

#include "rpg.h"

rpg_t *get_boss(char *str, rpg_t *save)
{
    if (strlen(str) < 12)
        return save;
    save->boss->frog = str[5] == '1' ? 1 : 0;
    save->boss->pyro = str[6] == '1' ? 1 : 0;
    save->boss->cryo = str[7] == '1' ? 1 : 0;
    save->boss->cyclop = str[8] == '1' ? 1 : 0;
    save->boss->rajah = str[9] == '1' ? 1 : 0;
    save->boss->dog = str[10] == '1' ? 1 : 0;
    save->boss->monkey = str[11] == '1' ? 1 : 0;
    return save;
}
