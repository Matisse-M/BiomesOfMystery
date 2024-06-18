/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** parse
*/

#pragma once

#include "rpg/quests.h"


#define QUESTS_ALL "/ressources/all_quests.txt"
#define QUESTS_BEGIN "/ressources/beginquests.txt"

quest_t **parse_and_fill(char *file);
