/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** setup_fight
*/

#include "rpg.h"

static fight_t *create_texts_spell(fight_t *fight, assets_t *assets)
{
    sfText_setFont(fight->player_hp, assets->font);
    sfText_setFont(fight->enemy_hp, assets->font);
    sfText_setFont(fight->end_msg, assets->font);
    sfText_setFont(fight->lvl_up, assets->font);
    sfText_setCharacterSize(fight->player_hp, 15);
    sfText_setCharacterSize(fight->enemy_hp, 15);
    sfText_setCharacterSize(fight->end_msg, 15);
    sfText_setCharacterSize(fight->lvl_up, 15);
    sfText_setColor(fight->player_hp, sfBlack);
    sfText_setColor(fight->enemy_hp, sfBlack);
    sfText_setColor(fight->end_msg, sfBlack);
    sfText_setColor(fight->lvl_up, sfBlack);
    sfText_setString(fight->lvl_up, "LEVEL UP !");
    fight->scroll = sfSprite_create();
    sfSprite_setScale(fight->scroll, (sfVector2f) {1.5, 1.5});
    return fight;
}

static button_t *create_fbutton(sfVector2f size, assets_t *assets, char *name)
{
    button_t *btn = calloc(1, sizeof(button_t));

    btn->texture[0] = assets->box3;
    btn->texture[1] = assets->box1;
    btn->texture[2] = assets->box1h;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, size);
    btn->text = sfText_create();
    sfText_setFont(btn->text, assets->font);
    sfText_setCharacterSize(btn->text, 15);
    sfText_setColor(btn->text, sfBlack);
    sfText_setString(btn->text, name);
    return btn;
}

static button_t **create_fbuttons(assets_t *assets)
{
    button_t **btn = calloc(4 + 1, sizeof(button_t *));

    btn[0] = create_fbutton((sfVector2f) {100, 50}, assets, "ATTACK");
    btn[1] = create_fbutton((sfVector2f) {100, 50}, assets, "ACTION");
    btn[2] = create_fbutton((sfVector2f) {100, 50}, assets, "ITEMS");
    btn[3] = create_fbutton((sfVector2f) {100, 50}, assets, "RUN");
    return btn;
}

static void create_entity_boxes(fight_t *fight, assets_t *assets)
{
    fight->player_life[0] = sfSprite_create();
    sfSprite_setTexture(fight->player_life[0], assets->bar100, sfTrue);
    sfSprite_setScale(fight->player_life[0], (sfVector2f) {6, 2});
    fight->player_life[1] = sfSprite_create();
    sfSprite_setTexture(fight->player_life[1], assets->barback, sfTrue);
    sfSprite_setScale(fight->player_life[1], (sfVector2f) {6, 2});
    fight->enemy_life[0] = sfSprite_create();
    sfSprite_setTexture(fight->enemy_life[0], assets->bar100, sfTrue);
    sfSprite_setScale(fight->enemy_life[0], (sfVector2f) {6, 2});
    fight->enemy_life[1] = sfSprite_create();
    sfSprite_setTexture(fight->enemy_life[1], assets->barback, sfTrue);
    sfSprite_setScale(fight->enemy_life[1], (sfVector2f) {6, 2});
    fight->player_box = sfRectangleShape_create();
    sfRectangleShape_setTexture(fight->player_box, assets->box3, sfTrue);
    sfRectangleShape_setSize(fight->player_box, (sfVector2f) {150, 50});
    fight->enemy_box = sfRectangleShape_create();
    sfRectangleShape_setTexture(fight->enemy_box, assets->box3, sfTrue);
    sfRectangleShape_setSize(fight->enemy_box, (sfVector2f) {150, 50});
}

static button_t *create_item_button(assets_t *assets, char *qty)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box3;
    btn->texture[1] = assets->box1;
    btn->texture[2] = assets->box1h;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {175, 22});
    btn->text = sfText_create();
    sfText_setCharacterSize(btn->text, 8);
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setFont(btn->text, assets->font);
    sfText_setString(btn->text, qty);
    btn->state = 0;
    return btn;
}

static button_t *create_arrow_button(assets_t *assets)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->arrow0;
    btn->texture[1] = assets->arrow1;
    btn->texture[2] = assets->arrow2;
    btn->texture[3] = assets->arrow3;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {20, 20});
    btn->text = NULL;
    btn->state = 0;
    return btn;
}

static void create_sup_animations(assets_t *assets, fight_t *fight)
{
    fight->e_hit[0] = sfSprite_create();
    sfSprite_setTexture(fight->e_hit[0], assets->frog_hit, sfTrue);
    sfSprite_setTextureRect(fight->e_hit[0], (sfIntRect) {0, 0, 40, 40});
    sfSprite_setScale(fight->e_hit[0], (sfVector2f) {3, 3});
    fight->e_hit[1] = sfSprite_create();
    sfSprite_setTexture(fight->e_hit[1], assets->bfire_hit, sfTrue);
    sfSprite_setTextureRect(fight->e_hit[1], (sfIntRect) {0, 0, 50, 50});
    sfSprite_setScale(fight->e_hit[1], (sfVector2f) {2.4, 2.4});
    fight->e_hit[2] = sfSprite_create();
    sfSprite_setTexture(fight->e_hit[2], assets->bice_hit, sfTrue);
    sfSprite_setTextureRect(fight->e_hit[2], (sfIntRect) {0, 0, 50, 50});
    sfSprite_setScale(fight->e_hit[2], (sfVector2f) {2.4, 2.4});
    fight->e_hit[3] = sfSprite_create();
    sfSprite_setTexture(fight->e_hit[3], assets->cyclop_hit, sfTrue);
    sfSprite_setTextureRect(fight->e_hit[3], (sfIntRect) {0, 0, 50, 50});
    sfSprite_setScale(fight->e_hit[3], (sfVector2f) {2.4, 3});
    fight->e_hit[4] = sfSprite_create();
    sfSprite_setTexture(fight->e_hit[4], assets->rajah_hit, sfTrue);
    sfSprite_setTextureRect(fight->e_hit[4], (sfIntRect) {0, 0, 50, 50});
    sfSprite_setScale(fight->e_hit[4], (sfVector2f) {2.4, 2.4});
}

static void fill_submenus(rpg_t *rpg, fight_t *fight)
{
    fight->items = malloc(sizeof(items_fight_t));
    fight->items->is_active = false;
    fight->items->current = 0;
    fight->items->quit = create_fbutton((sfVector2f) {100, 50},
        rpg->assets, "RETURN");
    for (int i = 0; i < 10; i++) {
        fight->items->items[i] = create_item_button(rpg->assets,
            (char *) sfText_getString(rpg->inv->conso->conso[i + 2]->qty));
        fight->items->asset[i] = rpg->inv->conso->conso[i + 2]->sprite;
        fight->items->name[i] = rpg->inv->conso->conso[i + 2]->name;
    }
    fight->items->next = create_arrow_button(rpg->assets);
    sfRectangleShape_setRotation(fight->items->next->rect, 270);
    fight->items->prev = create_arrow_button(rpg->assets);
    sfRectangleShape_setRotation(fight->items->prev->rect, 90);
    create_sup_animations(rpg->assets, fight);
}

static void fill_effect_bool(fight_t *fight, assets_t *assets)
{
    create_entity_boxes(fight, assets);
    fight->stone = false;
    fight->ice = false;
    fight->fire = false;
    fight->music = false;
    fight->life2 = 0;
    fight->animal_life = sfSprite_create();
    sfSprite_setTexture(fight->animal_life, assets->animals, sfTrue);
    sfSprite_setScale(fight->animal_life, (sfVector2f) {6, 2});
    fight->clock = sfClock_create();
    fight->trig_clock = sfClock_create();
    fight->btn = create_fbuttons(assets);
    fight->enemy = create_enemies(assets);
    fight->player_hp = sfText_create();
    fight->enemy_hp = sfText_create();
    fight->end_msg = sfText_create();
    fight->lvl_up = sfText_create();
    fight = create_texts_spell(fight, assets);
}

fight_t *create_fight(rpg_t *rpg)
{
    fight_t *fight = calloc(1, sizeof(fight_t));

    fight->bg = sfRectangleShape_create();
    sfRectangleShape_setTexture(fight->bg, rpg->assets->swamp, sfTrue);
    sfRectangleShape_setSize(fight->bg, (sfVector2f) {500, 200});
    fight->bbg = sfRectangleShape_create();
    sfRectangleShape_setTexture(fight->bbg, rpg->assets->dungeon, sfTrue);
    sfRectangleShape_setSize(fight->bbg, (sfVector2f) {500, 200});
    fight->menu = sfRectangleShape_create();
    sfRectangleShape_setTexture(fight->menu, rpg->assets->box3, sfTrue);
    sfRectangleShape_setSize(fight->menu, (sfVector2f) {480, 80});
    fill_effect_bool(fight, rpg->assets);
    fight->scrolls = fill_scroll_menu(rpg);
    fight->state = 0;
    fight->anim = sfClock_create();
    fill_submenus(rpg, fight);
    return fight;
}
