/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** save_game
*/

#include "rpg.h"

static char *get_oth_maps(maps_t *maps)
{
    if (maps->bathroom->is_active)
        return "BATHROOM";
    if (maps->weapon_shop->is_active)
        return "WEAPON SHOP";
    if (maps->maze->is_active)
        return "MAZE";
    if (maps->grotte->is_active)
        return "GROTTE";
    return "DOWNSTAIRS";
}

static char *get_map_active(maps_t *maps)
{
    if (maps->museum->is_active)
        return "MUSEUM";
    if (maps->upstairs->is_active)
        return "UPSTAIRS";
    if (maps->swamp->is_active)
        return "SWAMP";
    if (maps->beach->is_active)
        return "BEACH";
    if (maps->village->is_active)
        return "VILLAGE";
    if (maps->dungeon->is_active)
        return "DUNGEON";
    if (maps->food_shop->is_active)
        return "FOOD SHOP";
    if (maps->house->is_active)
        return "HOUSE";
    return get_oth_maps(maps);
}

static char *add_field(char *field, char *value)
{
    char *str = calloc(100, sizeof(char));

    str = my_strcat(str, field);
    str = my_strcat(str, value);
    str = my_strcat(str, "\n");
    return str;
}

static char *put_pos(sfVector2f pos)
{
    char *str = calloc(12, sizeof(char));

    str = my_strcat(str, "(");
    str = my_strcat(str, my_itoa((int)pos.x));
    str = my_strcat(str, ";");
    str = my_strcat(str, my_itoa((int)pos.y));
    str = my_strcat(str, ")");
    return str;
}

static char *put_hp(int int1, int int2)
{
    char *str = calloc(10, sizeof(char));

    str = my_strcat(str, my_itoa(int1));
    str = my_strcat(str, "/");
    str = my_strcat(str, my_itoa(int2));
    return str;
}

static char *put_inv(inventory_t *inv)
{
    char *str = calloc(1, sizeof(char));

    for (int i = 0; i < 10; i++)
        str = my_strcat(str, inv->armor->get_item[i] ? "1" : "0");
    str = my_strcat(str, ";");
    for (int i = 0; i < 6; i++)
        str = my_strcat(str, inv->conso->secret[i]->unlock ? "1" : "0");
    str = my_strcat(str, ";");
    for (int i = 0; i < 12; i++) {
        str = my_strcat(str, sfText_getString(inv->conso->conso[i]->qty));
        str = my_strcat(str, ",");
    }
    return str;
}

static char *put_quests(quests_t *quests)
{
    char *str = calloc(1, sizeof(char));

    for (int i = 0; quests->discovery[i]; i++) {
        str = my_strcat(str, (quests->discovery[i]->is_completed) ? "1" :
            "0");
        str = my_strcat(str, (quests->discovery[i]->is_discovered) ? "1" :
            "0");
        if (quests->discovery[i + 1])
            str = my_strcat(str, ",");
        else
            str = my_strcat(str, ";");
    }
    for (int i = 0; quests->quests[i]; i++) {
        str = my_strcat(str, (quests->quests[i]->is_completed) ? "1" : "0");
        str = my_strcat(str, (quests->quests[i]->is_discovered) ? "1" : "0");
        if (quests->quests[i + 1])
            str = my_strcat(str, ",");
    }
    return str;
}

static char *put_boss(mapboss_t *bosses)
{
    char *str = calloc(6, sizeof(char));

    str = my_strcat(str, (bosses->frog) ? "1" : "0");
    str = my_strcat(str, (bosses->pyro) ? "1" : "0");
    str = my_strcat(str, (bosses->cryo) ? "1" : "0");
    str = my_strcat(str, (bosses->cyclop) ? "1" : "0");
    str = my_strcat(str, (bosses->rajah) ? "1" : "0");
    str = my_strcat(str, (bosses->dog) ? "1" : "0");
    str = my_strcat(str, (bosses->monkey) ? "1" : "0");
    return str;
}

static char **prepare_savee(rpg_t *to_save, char **save)
{
    save[11] = add_field("INVENTORY=", put_inv(to_save->inv));
    save[12] = add_field("SKILLTREE=", put_hp(to_save->skilltree->atk_progress,
        to_save->skilltree->hp_progress));
    save[13] = add_field("QUESTS=", put_quests(to_save->quests));
    save[14] = add_field("BOSS=", put_boss(to_save->boss));
    save[15] = add_field("ACCESS=", put_access(to_save->maps));
    return save;
}

char **prepare_save(rpg_t *to_save)
{
    char **save = calloc(17, sizeof(char *));

    save[0] = add_field("GENDER=", to_save->begin->gender == 1 ? "M" : "F");
    save[1] = add_field("NAME=", to_save->characters->main->name);
    save[2] = add_field("POSITION=",
        put_pos(to_save->characters->main->position));
    save[3] = add_field("MAP=", get_map_active(to_save->maps));
    save[4] = add_field("POS VIEW=", put_pos(to_save->maps->center));
    save[5] = add_field("LEVEL=", my_itoa(to_save->characters->main->lvl));
    save[6] = add_field("ATTACK=", my_itoa(to_save->characters->main->atk));
    save[7] = add_field("HP=", put_hp(to_save->characters->main->hp,
    to_save->characters->main->hp_max));
    save[8] = add_field("EXPERIENCE=",
        my_itoa(to_save->characters->main->exp));
    save[9] = add_field("MONEY=", my_itoa(to_save->characters->main->money));
    save[10] = add_field("GPA=", my_itoa(to_save->characters->main->emo));
    return prepare_savee(to_save, save);
}
