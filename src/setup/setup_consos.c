/*
** EPITECH PROJECT, 2023
** setup game params
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "rpg.h"


const char *name_file[12] = {
    "/item_txt/1.txt", "/item_txt/2.txt", "/item_txt/3.txt", "/item_txt/4.txt",
    "/item_txt/5.txt", "/item_txt/6.txt", "/item_txt/7.txt", "/item_txt/8.txt",
    "/item_txt/9.txt", "/item_txt/10.txt", "/item_txt/11.txt",
    "/item_txt/12.txt"
};

const char *name_item[12] = {"ATK +", "HP +", "POTION", "POTION +",
    "POTION ++", "MEDIKIT", "SHRIMP", "SUSHI", "OCTOPUS", "FORTUNE",
    "WATER", "MILK"};

const char *assets_item[12] = {
    "/conso/1.png", "/conso/2.png", "/conso/3.png", "/conso/4.png",
    "/conso/5.png", "/conso/6.png", "/conso/7.png", "/conso/8.png",
    "/conso/9.png", "/conso/10.png", "/conso/11.png", "/conso/12.png"};

button_t *create_use_btn(assets_t *assets)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box3;
    btn->texture[3] = assets->box2;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {32, 16});
    btn->text = sfText_create();
    sfText_setCharacterSize(btn->text, 8);
    sfText_setString(btn->text, "USE");
    sfText_setFillColor(btn->text, sfBlack);
    sfText_setFont(btn->text, assets->font);
    btn->state = 0;
    return btn;
}

button_t *create_item_btn(assets_t *assets)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->texture[0] = assets->box1;
    btn->texture[1] = assets->box1h;
    btn->texture[2] = assets->box2;
    btn->texture[3] = assets->box3;
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(btn->rect, btn->texture[0], sfTrue);
    sfRectangleShape_setSize(btn->rect, (sfVector2f) {100, 22});
    btn->text = NULL;
    btn->state = 0;
    return btn;
}

static secret_t *create_secret(const char *name, const char *assets,
    rpg_t *rpg)
{
    secret_t *new = malloc(sizeof(secret_t));
    sfTexture *texture = sfTexture_createFromFile(assets, NULL);
    sfTexture *btn = sfTexture_createFromFile(my_scat(rpg->name,
        "/btn/purple.png"), NULL);
    sfFont *font = sfFont_createFromFile(my_scat(rpg->name, rpg->font));

    if (new == NULL || texture == NULL || btn == NULL || font == NULL)
        exit(84);
    new->name = sfText_create();
    sfText_setCharacterSize(new->name, 8);
    sfText_setString(new->name, name);
    sfText_setFont(new->name, font);
    sfText_setFillColor(new->name, sfBlack);
    new->sprite = my_set_sprite(texture, (sfVector2f) {0, 0}, (sfVector2f)
        {1, 1}, 0);
    new->btn = sfRectangleShape_create();
    sfRectangleShape_setTexture(new->btn, btn, sfTrue);
    sfRectangleShape_setSize(new->btn, (sfVector2f) {100, 22});
    new->unlock = false;
    return new;
}

static conso_list_t *create_item(rpg_t *rpg, const char *name, int qty,
    const char *item)
{
    conso_list_t *new = malloc(sizeof(conso_list_t));
    sfTexture *texture = sfTexture_createFromFile(item, NULL);

    if (new == NULL || texture == NULL)
        exit(84);
    new->is_active = false;
    new->btn = create_item_btn(rpg->assets);
    new->name = sfText_create();
    sfText_setCharacterSize(new->name, 8);
    sfText_setString(new->name, name);
    sfText_setFont(new->name, rpg->assets->font);
    sfText_setFillColor(new->name, sfBlack);
    new->qty = my_set_text(rpg, my_itoa(qty), 8, (sfVector2f) {0, 0});
    new->sprite = my_set_sprite(texture, (sfVector2f) {0, 0}, (sfVector2f)
        {1, 1}, 0);
    return new;
}

static void open_descriptions(rpg_t *rpg, conso_list_t *conso,
    const char *file)
{
    int fd = open(file, O_RDONLY);
    char *buf = NULL;
    struct stat s;

    if (stat(file, &s) == -1)
        exit(84);
    if (fd < 0)
        exit(84);
    buf = calloc(1, sizeof(char) * (s.st_size + 1));
    read(fd, buf, s.st_size);
    conso->desc = my_set_text(rpg, buf, 8, (sfVector2f) {0, 0});
    close(fd);
}

static void fill_conso_conso(rpg_t *rpg, conso_t *conso, assets_t *assets)
{
    int qty[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    void *func[12] = {&atk_plus, &hp_plus, &potion, &potion_plus, &potion_max,
        &medikit, &shrimp, &sushi, &octopus, &fortune, &water, &milk};

    for (int i = 0; i < 12; i++) {
        conso->conso[i] = create_item(rpg, name_item[i], qty[i],
            my_scate(rpg->name, assets_item[i]));
        conso->conso[i]->func = func[i];
        open_descriptions(rpg, conso->conso[i],
            my_scate(rpg->name, name_file[i]));
    }
    conso->conso[0]->is_active = true;
}

static void fill_conso_secret(rpg_t *rpg, conso_t *conso)
{
    char *secret[6] = {"BOTTLE", "PIGGIES", "SHROOMS", "STONE", "ICE", "FIRE"};
    char *assets[6] = {my_scat(rpg->name, "/secr/1.png"), my_scat(rpg->name,
        "/secr/2.png"),
        my_scat(rpg->name, "/secr/3.png"), my_scat(rpg->name, "/secr/4.png"),
        my_scat(rpg->name, "/secr/5.png"), my_scat(rpg->name, "/secr/6.png")};

    for (int i = 0; i < 6; i++)
        conso->secret[i] = create_secret(secret[i], assets[i], rpg);
}

static void create_background(rpg_t *rpg, conso_t *conso, assets_t *assets)
{
    conso->chatbox = sfRectangleShape_create();
    sfRectangleShape_setTexture(conso->chatbox, assets->box1, sfTrue);
    sfRectangleShape_setSize(conso->chatbox, (sfVector2f) {205, 52});
    conso->rect_use = create_use_btn(assets);
    conso->clock = sfClock_create();
    conso->t_piece = sfTexture_createFromFile(my_scat(rpg->name,
        "/secr/coin.png"), NULL);
    conso->t_bag = sfTexture_createFromFile(my_scat(rpg->name,
        "/secr/chest.png"), NULL);
    if (conso->t_piece == NULL || conso->t_bag == NULL)
        exit(84);
    conso->piece = my_set_sprite(conso->t_piece, (sfVector2f) {0, 0},
        (sfVector2f) {1, 1}, 0);
    conso->bag = my_set_sprite(conso->t_bag, (sfVector2f) {0, 0},
        (sfVector2f) {1.2, 1.4}, 0);
    conso->money = sfText_create();
    sfText_setCharacterSize(conso->money, 8);
    sfText_setFillColor(conso->money, sfBlack);
    sfText_setFont(conso->money, assets->font);
}

conso_t *fill_conso_item(assets_t *assets, rpg_t *rpg)
{
    conso_t *conso = malloc(sizeof(conso_t));

    conso->conso = malloc(sizeof(conso_list_t) * 12);
    conso->secret = malloc(sizeof(secret_t) * 6);
    create_background(rpg, conso, assets);
    conso->stock = sfText_create();
    sfText_setCharacterSize(conso->stock, 8);
    sfText_setFillColor(conso->stock, sfBlack);
    sfText_setFont(conso->stock, assets->font);
    fill_conso_conso(rpg, conso, assets);
    conso->conso[0]->btn->state = 3;
    fill_conso_secret(rpg, conso);
    return conso;
}
