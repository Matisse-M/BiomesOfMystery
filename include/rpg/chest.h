/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** chest
*/

#ifndef CHEST_H_
    #define CHEST_H_

typedef struct chest_maze_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
} chest_maze_t;

typedef struct chest_open_s {
    bool can_interact;
    bool is_active;
    bool is_print;
    bool is_open;
} chest_open_t;

typedef struct chest_s {
    chest_maze_t *chest_maze;
    chest_open_t *chest_one;
    chest_open_t *chest_two;
    chest_open_t *chest_three;
    chest_open_t *chest_four;
    chest_open_t *chest_dungeon;
    chest_open_t *chest_dun_two;
    chest_open_t *level;
    chest_open_t *chest_maze_quest;
    chest_open_t *kid_bp;
    chest_open_t *cow;
    sfSprite *sprite;
} chest_t;

#endif /* !CHEST_H_ */
