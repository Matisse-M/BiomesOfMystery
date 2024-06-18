/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_qi
*/

#include "rpg.h"

static float *get_pos_from_str(char *str)
{
    float *pos = calloc(2, sizeof(float));
    int j = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == 59)
            j = i;
    pos[0] = atof(str + 1);
    pos[1] = atof(str + j + 1);
    if (!pos[0] && !pos[1]) {
        pos[0] = 500;
        pos[1] = 500;
    }
    return pos;
}

static char *get_comma(char *str, int *i)
{
    char *new = NULL;
    int start = *i;
    int length = 0;

    if (!str || !i || !str[*i])
        return NULL;
    while (str[*i] && str[*i] != ',') {
        length++;
        (*i)++;
    }
    new = calloc(length + 1, sizeof(char));
    if (!new)
        exit(84);
    strncpy(new, str + start, length);
    if (str[*i] == ',')
        (*i)++;
    return new;
}

static rpg_t *set_str(rpg_t *rpg, char *toto, int i)
{
    if (!toto)
        return rpg;
    sfText_setString(rpg->inv->conso->conso[i]->qty, toto);
    free(toto);
    return rpg;
}

rpg_t *get_inventory(char *str, rpg_t *save)
{
    char *toto = NULL;
    int pos = 10;

    if (strlen(str) < 51)
        str = "INVENTORY=0000000000;000000;0,0,0,0,0,0,0,0,0,0,0,0";
    for (int i = 0; str[pos] && str[pos] != ';' && i < 10; pos++) {
        save->inv->armor->get_item[i] = (str[pos] == '1' ? true : false);
        i++;
    }
    pos++;
    for (int i = 0; str[pos] && str[pos] != ';' && i < 6; pos++) {
        save->inv->conso->secret[i]->unlock = (str[pos] == '1' ? true : false);
        i++;
    }
    pos++;
    for (int i = 0; str[pos] && i < 12; i++) {
        toto = get_comma(str, &pos);
        save = set_str(save, toto, i);
    }
    return save;
}

rpg_t *get_skilltree(char *str, rpg_t *save)
{
    if (strlen(str) < 15)
        str = "SKILLTREE=1/1";
    save->skilltree->atk_progress = str[10] - '0';
    save->skilltree->hp_progress = str[12] - '0';
    return save;
}

static void get_one_quest(quest_t *quest, char one, char two, char three)
{
    quest->is_completed = two - 48;
    quest->is_discovered = three - 48;
}

rpg_t *get_quests(char *str, rpg_t *save)
{
    int pos = 7;

    if (strlen(str) < 8)
        str = "QUESTS=00,00,00,00,00;00,00,00,00,00,00,00";
    for (int i = 0; str[pos] && str[pos + 1] && str[pos + 2] &&
        save->quests->discovery[i]; i++) {
        get_one_quest(save->quests->discovery[i], str[pos], str[pos + 1],
            str[pos + 2]);
        pos += 4;
    }
    for (int i = 0; str[pos] && str[pos + 1] && str[pos + 2] &&
        save->quests->quests[i]; i++) {
        get_one_quest(save->quests->quests[i], str[pos], str[pos + 1],
            str[pos + 2]);
        pos += 4;
    }
    return save;
}

rpg_t *get_pos_view(char *str, rpg_t *save)
{
    float *pos = NULL;

    if (strlen(str) < 10)
        str = "POS VIEW=(640;160)";
    pos = get_pos_from_str(str + 9);
    save->maps->center.x = pos[0];
    save->maps->center.y = pos[1];
    if (pos)
        free(pos);
    return save;
}

rpg_t *get_access(char *str, rpg_t *save)
{
    if (strlen(str) < 14)
        str = "ACCESS=0000000";
    save->maps->museum->unlock = str[7] - '0';
    save->maps->upstairs->unlock = str[8] - '0';
    save->maps->swamp->unlock = str[9] - '0';
    save->maps->beach->unlock = str[10] - '0';
    save->maps->village->unlock = str[11] - '0';
    save->maps->dungeon->unlock = str[12] - '0';
    save->maps->maze->unlock = str[13] - '0';
    return save;
}
