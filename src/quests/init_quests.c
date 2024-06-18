/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_quests
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "rpg.h"

void free_quest(quest_t *quest)
{
    if (quest->title != NULL)
        free(quest->title);
    if (quest->description != NULL)
        free(quest->description);
    if (quest != NULL)
        free(quest);
}

quest_t *init_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));

    if (quest == NULL)
        exit(84);
    quest->id = 0;
    quest->title = NULL;
    quest->description = NULL;
    quest->is_completed = false;
    quest->is_discovered = false;
    return quest;
}

static quests_t *init_quests(void)
{
    quests_t *quests = malloc(sizeof(quests_t));

    if (quests == NULL)
        exit(84);
    quests->nbquest = 7;
    quests->discovery_nb = 5;
    quests->quests = malloc(sizeof(quest_t *) * quests->nbquest);
    quests->discovery = malloc(sizeof(quest_t *) * quests->discovery_nb);
    quests->btn = malloc(sizeof(inv_btn_t *) * 8);
    quests->is_done = false;
    return quests;
}

button_t *create_quest_btn(sfVector2f pos, assets_t *assets,
    sfVector2f pos_text, char *name)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box3;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {100, 15});
    sfRectangleShape_setPosition(btn->rect, pos);
    btn->text = sfText_create();
    sfText_setString(btn->text, name);
    sfText_setFont(btn->text, assets->font);
    sfText_setCharacterSize(btn->text, 8);
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setPosition(btn->text, pos_text);
    btn->state = 0;
    return btn;
}

inv_btn_t *create_btn_quest(char *str, bool bin, assets_t *assets)
{
    inv_btn_t *btn = malloc(sizeof(inv_btn_t));

    btn->is_active = bin;
    btn->btn = create_quest_btn((sfVector2f) {0, 0}, assets, (sfVector2f)
        {0, 0}, str);
    return btn;
}

quests_t *fill_quests(rpg_t *rpg)
{
    quests_t *quests = init_quests();
    char *name[8] = {"DISCOVERY", "MAIN QUEST", "MAZE", "MUSEUM", "PIGS",
        "MUSHROOMS", "FAMILIER", "QUEST6"};

    quests->discovery = parse_and_fill(my_scat(rpg->name, QUESTS_BEGIN));
    quests->quests = parse_and_fill(my_scat(rpg->name, QUESTS_ALL));
    for (int i = 0; i < 8; i++) {
        if (i == 0) {
            quests->btn[i] = create_btn_quest(name[i], true, rpg->assets);
        } else {
            quests->btn[i] = create_btn_quest(name[i], false, rpg->assets);
        }
        quests->btn[i]->is_discovered = false;
        quests->btn[i]->id = i;
    }
    return quests;
}
