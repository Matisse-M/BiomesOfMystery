/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_basics
*/

#include "rpg.h"

rpg_t *get_gender(char *str, rpg_t *save)
{
    if (strlen(str) < 8)
        str = "GENDER=M";
    save->begin->gender = (str[7] == 'F') ? 2 : 1;
    return save;
}

rpg_t *get_name(char *str, rpg_t *save)
{
    if (save->characters->main->name)
        free(save->characters->main->name);
    if (!str || strlen(str) > 7 + 5 || strlen(str) < 6)
        save->begin->alpha->answer = strdup("SACHA");
    else
        save->begin->alpha->answer = strdup(str + 5);
    return save;
}

static float *get_pos_from_str(char *str)
{
    float *pos = calloc(2, sizeof(float));
    int j = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == 59)
            j = i;
    pos[0] = atof(str + 1);
    pos[1] = atof(str + j + 1);
    return pos;
}

rpg_t *get_position(char *str, rpg_t *save)
{
    float *pos = NULL;

    if (strlen(str) < 11)
        str = "POSITION=(653;163)";
    pos = get_pos_from_str(str + 9);
    save->characters->main->position.x = pos[0];
    save->characters->main->position.y = pos[1];
    if (pos)
        free(pos);
    return save;
}

static rpg_t *get_mapss(char *str, rpg_t *save)
{
    save->maps->weapon_shop->is_active = !strcmp(str + 4, "WEAPON SHOP") ? true
        : false;
    save->maps->maze->is_active = !strcmp(str + 4, "MAZE") ? true : false;
    save->maps->grotte->is_active = !strcmp(str + 4, "GROTTE") ? true : false;
    choose_under_map(save, save->characters->main);
    if (save->maps->museum->is_active)
        modif_music(save, save->assets->music_museum);
    if (save->maps->downstairs->is_active || save->maps->upstairs->is_active)
        modif_music(save, save->assets->music_menu);
    if (save->maps->swamp->is_active)
        modif_music(save, save->assets->music_swamp);
    if (save->maps->beach->is_active)
        modif_music(save, save->assets->music_beach);
    if (save->maps->village->is_active)
        modif_music(save, save->assets->music_village);
    if (save->maps->dungeon->is_active)
        modif_music(save, save->assets->music_donjon);
    if (save->maps->grotte->is_active)
        modif_music(save, save->assets->music_cave);
    return save;
}

rpg_t *get_map(char *str, rpg_t *save)
{
    if (strlen(str) < 5)
        str = "MAP=DOWNSTAIRS";
    save->maps->museum->is_active = !strcmp(str + 4, "MUSEUM") ? true : false;
    save->maps->downstairs->is_active = !strcmp(str + 4, "DOWNSTAIRS") ? true :
        false;
    save->maps->upstairs->is_active = !strcmp(str + 4, "UPSTAIRS") ? true :
        false;
    save->maps->swamp->is_active = !strcmp(str + 4, "SWAMP") ? true : false;
    save->maps->beach->is_active = !strcmp(str + 4, "BEACH") ? true : false;
    save->maps->village->is_active = !strcmp(str + 4, "VILLAGE") ? true :
        false;
    save->maps->dungeon->is_active = !strcmp(str + 4, "DUNGEON") ? true :
        false;
    save->maps->food_shop->is_active = !strcmp(str + 4, "FOOD SHOP") ? true :
        false;
    save->maps->house->is_active = !strcmp(str + 4, "HOUSE") ? true : false;
    save->maps->bathroom->is_active = !strcmp(str + 4, "BATHROOM") ? true :
        false;
    return get_mapss(str, save);
}

rpg_t *get_gpa(char *str, rpg_t *save)
{
    if (strlen(str) < 5)
        str = "GPA=0";
    save->characters->main->emo = atoi(str + 4);
    return save;
}
