/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** parse_save
*/

#include "rpg.h"

// const array of the fields to get
const char *fields[] = {
    "GENDER=",
    "NAME=",
    "POSITION=",
    "MAP=",
    "LEVEL=",
    "HP=",
    "EXPERIENCE=",
    "GPA=",
    "ATTACK=",
    "INVENTORY=",
    "SKILLTREE=",
    "QUESTS=",
    "POS VIEW=",
    "MONEY=",
    "BOSS=",
    "ACCESS=",
    NULL
};

// array of the functions to get the fields
rpg_t *(*functions[])(char *, rpg_t *) = {
    &get_gender,
    &get_name,
    &get_position,
    &get_map,
    &get_level,
    &get_hp,
    &get_experience,
    &get_gpa,
    &get_attack,
    &get_inventory,
    &get_skilltree,
    &get_quests,
    &get_pos_view,
    &get_money,
    &get_boss,
    &get_access,
    NULL
};

rpg_t *find_map(rpg_t *rpg)
{
    rpg->maps->beach->is_active = false;
    rpg->maps->downstairs->is_active = false;
    rpg->maps->dungeon->is_active = false;
    rpg->maps->maze->is_active = false;
    rpg->maps->museum->is_active = false;
    rpg->maps->grotte->is_active = false;
    rpg->maps->swamp->is_active = false;
    rpg->maps->upstairs->is_active = false;
    rpg->maps->village->is_active = false;
    rpg->maps->bathroom->is_active = false;
    rpg->maps->weapon_shop->is_active = false;
    return rpg;
}

rpg_t *fill_field(char *str, rpg_t *save)
{
    for (int i = 0; str && fields[i]; i++)
        if (strlen(str) > 1 && !strncmp(str, fields[i], strlen(fields[i])))
            return functions[i](str, save);
    return save;
}

void check_fields(main_player_t *player)
{
    if (!player->position.x || !player->position.y || !player->hp ||
        !player->lvl || !player->atk || player->hp > player->hp_max)
        exit(84);
}

void lets_do_some_magic(rpg_t *save)
{
    save->menu->start->is_active = false;
    save->begin->is_active = false;
    save->menu->is_active = false;
    save->maps->is_active = true;
    save->game->is_active = true;
    if (save->begin->gender && save->begin->alpha->answer)
        chara_chosen(save);
    int_anim(save);
    init_rain(save->anim->rain_anim, save);
    init_sprite(save, save->anim);
    sfSprite_setPosition(save->characters->main->sprite,
    save->characters->main->position);
    sfView_setCenter(save->game->view, save->characters->main->position);
}

rpg_t *parse_save(rpg_t *save, char **arr)
{
    if (!arr || my_arrlen(arr) != 16)
        return save;
    for (int i = 0; arr[i]; i++) {
        if (arr[i][my_strlen(arr[i]) - 1] == 10)
            arr[i][my_strlen(arr[i]) - 1] = 0;
        save = fill_field(arr[i], save);
    }
    lets_do_some_magic(save);
    check_fields(save->characters->main);
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    return save;
}
