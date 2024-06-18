/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** quests
*/

#pragma once

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "csfml.h"
#include "my.h"

typedef struct quest_s {
    int id;
    char *title;
    char *description;
    bool is_completed;
    bool is_discovered;
    sfText *text;
} quest_t;

typedef struct quests_s {
    inv_btn_t **btn;
    quest_t **discovery;
    quest_t **quests;
    sfText **title;
    int nbquest;
    int discovery_nb;
    bool is_done;
} quests_t;

quest_t *init_quest(void);
