/*
** EPITECH PROJECT, 2024
** bck
** File description:
** save_game2
*/

#include "rpg.h"

char *put_access(maps_t *maps)
{
    char *str = calloc(1, sizeof(char));

    str = my_strcat(str, (maps->museum->unlock) ? "1" : "0");
    str = my_strcat(str, (maps->upstairs->unlock) ? "1" : "0");
    str = my_strcat(str, (maps->swamp->unlock) ? "1" : "0");
    str = my_strcat(str, (maps->beach->unlock) ? "1" : "0");
    str = my_strcat(str, (maps->village->unlock) ? "1" : "0");
    str = my_strcat(str, (maps->dungeon->unlock) ? "1" : "0");
    str = my_strcat(str, (maps->maze->unlock) ? "1" : "0");
    return str;
}
