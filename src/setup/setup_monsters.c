/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** setup_fight
*/

#include "rpg.h"

static enemy_t *create_boss(char *name, sfTexture *texture, int stats[4])
{
    enemy_t *enemy = calloc(1, sizeof(enemy_t));

    enemy->name = name;
    enemy->atk = stats[0];
    enemy->hp = stats[1];
    enemy->hp_max = stats[2];
    enemy->exp = stats[3];
    enemy->clock = sfClock_create();
    enemy->texture = texture;
    enemy->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    if (!strcmp(name, "FROG")) {
        sfSprite_setTextureRect(enemy->sprite, (sfIntRect) {0, 0, 40, 40});
        sfSprite_setScale(enemy->sprite, (sfVector2f) {3, 3});
    } else {
        sfSprite_setTextureRect(enemy->sprite, (sfIntRect) {0, 0, 50, 50});
        sfSprite_setScale(enemy->sprite, (sfVector2f) {2.4, 2.4});
    }
    return enemy;
}

static enemy_t *create_enemy(char *name, sfTexture *texture, int exp, int atk)
{
    enemy_t *enemy = calloc(1, sizeof(enemy_t));

    enemy->name = name;
    enemy->exp = exp;
    enemy->atk = atk;
    enemy->clock = sfClock_create();
    enemy->texture = texture;
    enemy->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setTextureRect(enemy->sprite,
        (sfIntRect) {0, 0, 16, 16});
    sfSprite_setScale(enemy->sprite, (sfVector2f) {3, 3});
    return enemy;
}

static void create_monsters(assets_t *assets, enemy_t **enemies)
{
    enemies[0] = create_enemy("GLOOPY", assets->slime, 5, 3);
    enemies[1] = create_enemy("DIPPER", assets->mole, 10, 4);
    enemies[2] = create_enemy("STALOX", assets->larva, 10, 4);
    enemies[3] = create_enemy("MABEL", assets->shroom, 15, 5);
    enemies[4] = create_enemy("BRANCH", assets->bamboo, 15, 6);
    enemies[5] = create_enemy("CHUCHU", assets->blob, 15, 8);
    enemies[6] = create_enemy("CHEAUCHO", assets->burner, 30, 8);
    enemies[7] = create_enemy("GLAGLA", assets->freezer, 30, 8);
    enemies[8] = create_enemy("NEUIL", assets->eye, 40, 9);
    enemies[9] = create_enemy("BOOTH", assets->skull, 50, 10);
}

enemy_t **create_enemies(assets_t *assets)
{
    enemy_t **enemies = calloc(16, sizeof(enemy_t *));

    create_monsters(assets, enemies);
    enemies[10] = create_boss("RENATANE", assets->frog, (int[4])
        {6, 30, 30, 60});
    enemies[11] = create_boss("PYRO", assets->bfire, (int[4])
        {12, 50, 50, 100});
    enemies[12] = create_boss("CRYO", assets->bice, (int[4])
        {12, 50, 50, 100});
    enemies[13] = create_boss("PERSONNE", assets->cyclop, (int[4])
        {15, 150, 150, 125});
    enemies[14] = create_boss("RAJAH", assets->rajah, (int[4])
        {20, 250, 250, 200});
    return enemies;
}
