/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** create_pnj
*/

#include "rpg.h"
#include <sys/stat.h>
#include <fcntl.h>

static dialog_player_t *fill_rest_pnj(char **assets, dialog_player_t *dialogue,
    sfFont *font)
{
    dialogue->line_count = 0;
    dialogue->array = read_text_file(assets[1], &dialogue->line_count);
    dialogue->i = 0;
    dialogue->count_line = 0;
    dialogue->text = sfText_create();
    sfText_setCharacterSize(dialogue->text, 12);
    sfText_setColor(dialogue->text, sfBlack);
    sfText_setFont(dialogue->text, font);
    dialogue->name = sfText_create();
    sfText_setCharacterSize(dialogue->name, 8);
    sfText_setColor(dialogue->name, sfBlack);
    sfText_setFont(dialogue->name, font);
    sfText_setString(dialogue->name, my_strdup(assets[2]));
    dialogue->talked = false;
    return dialogue;
}

static dialog_player_t *fill_pnj(rpg_t *rpg, sfVector2f min,
    sfVector2f max, char **assets)
{
    dialog_player_t *dialogue = malloc(sizeof(dialog_player_t));
    sfFont *font = sfFont_createFromFile(my_scat(rpg->name, rpg->font));

    dialogue->can_interact = false;
    dialogue->is_print = false;
    dialogue->is_active = false;
    dialogue->faces_texture = sfTexture_createFromFile(assets[0], NULL);
    if (!dialogue->faces_texture)
        exit(84);
    dialogue->faces_sprite = sfSprite_create();
    sfSprite_setTexture(dialogue->faces_sprite,
        dialogue->faces_texture, sfTrue);
    dialogue->x_min = min.x;
    dialogue->x_max = min.y;
    dialogue->y_min = max.x;
    dialogue->y_max = max.y;
    dialogue = fill_rest_pnj(assets, dialogue, font);
    return dialogue;
}

static void init_last_pnjs(rpg_t *rpg)
{
    rpg->dialogue->swamp_frog = fill_pnj(rpg, (sfVector2f){114, 141},
        (sfVector2f){100, 120.2},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/swamp_frog.png"),
        my_scat(rpg->name, "/PNJ/pnj/swamp_frog.txt"), "D E M E T A N"});
    rpg->dialogue->chat = fill_pnj(rpg, (sfVector2f){149, 176},
        (sfVector2f){322, 342},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/chat.png"),
        my_scat(rpg->name, "/PNJ/pnj/chat.txt"), "A L B A N E"});
    rpg->dialogue->museum_satue = fill_pnj(rpg, (sfVector2f){307, 330},
        (sfVector2f){122, 149},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/museum_statue.png"),
        my_scat(rpg->name, "/PNJ/pnj/museum_statue.txt"), "M A T H I S"});
    rpg->dialogue->martin = fill_pnj(rpg, (sfVector2f){510, 545},
        (sfVector2f){395, 421},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/martin.png"),
        my_scat(rpg->name, "/PNJ/pnj/martin.txt"), "A N C R A S"});
    rpg->dialogue->cow = fill_pnj(rpg, (sfVector2f){56, 78},
        (sfVector2f){363, 397},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/cow.png"),
        my_scat(rpg->name, "/PNJ/pnj/cow.txt"), "M A T H E O"});
}

static void creat_last_pnj(rpg_t *rpg)
{
    rpg->dialogue->plage_kid = fill_pnj(rpg, (sfVector2f){455, 475},
        (sfVector2f){356, 375},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/plage_kid.png"),
        my_scat(rpg->name, "/PNJ/pnj/plage_kid.txt"), "T O M"});
    rpg->dialogue->plage_old = fill_pnj(rpg, (sfVector2f){232, 258},
        (sfVector2f){325, 337},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/old_plage.png"),
        my_scat(rpg->name, "/PNJ/pnj/plage_old.txt"), "Y A N N"});
    rpg->dialogue->plage_woman = fill_pnj(rpg, (sfVector2f){160, 186.8},
        (sfVector2f){83.8, 99.2},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/plage_woman.png"),
        my_scat(rpg->name, "/PNJ/pnj/plage_woman.txt"), "Q N A "});
    init_last_pnjs(rpg);
}

static void creat_pnj_rest(rpg_t *rpg)
{
    rpg->dialogue->museum_blue = fill_pnj(rpg, (sfVector2f){287, 314.8},
        (sfVector2f){466, 480},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/museum_blue.png"),
        my_scat(rpg->name, "/PNJ/pnj/museum_blue.txt"), "K O N O G A N"});
    rpg->dialogue->museum_red = fill_pnj(rpg, (sfVector2f){151, 170},
        (sfVector2f){275.2, 290},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/museum_red.png"),
        my_scat(rpg->name, "/PNJ/pnj/museum_red.txt"), "M A T I S S E"});
    rpg->dialogue->old_bp = fill_pnj(rpg, (sfVector2f){181, 205},
        (sfVector2f){197, 219},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/old_bp.png"),
        my_scat(rpg->name, "/PNJ/pnj/old_bp.txt"), "F L A B I E N"});
    creat_last_pnj(rpg);
}

static void init_shop_skill(rpg_t *rpg)
{
    rpg->dialogue->shop = malloc(sizeof(shop_t));
    rpg->dialogue->shop->can_interact_shop = false;
    rpg->dialogue->shop->shop_active = false;
    rpg->dialogue->shop->can_interact_skill = false;
    rpg->dialogue->shop->skill_active = false;
}

void create_all_pnj(rpg_t *rpg)
{
    rpg->dialogue = malloc(sizeof(dialogue_t));
    rpg->dialogue->aymeric = fill_pnj(rpg, (sfVector2f){430, 488},
        (sfVector2f){61, 90}, (char *[3]){my_scat(rpg->name,
        "/PNJ/pnj/aymeric_face.png"),
        my_scat(rpg->name, "/PNJ/pnj/ameryc.txt"), "A M E R Y C"});
    rpg->dialogue->dungeon_old = fill_pnj(rpg, (sfVector2f){0, 0},
        (sfVector2f){1, 1}, (char *[3]){my_scat(rpg->name,
        "/PNJ/pnj/dungeon_old.png"), my_scat(rpg->name,
        "/PNJ/pnj/dungeon_old.txt"), "H U G O"});
    rpg->dialogue->kid_bp = fill_pnj(rpg, (sfVector2f){371, 397},
        (sfVector2f){275, 292}, (char *[3]){my_scat(rpg->name,
        "/PNJ/pnj/kid_bp.png"), my_scat(rpg->name,
        "/PNJ/pnj/kid_bp.txt"), "G O D E F R O Y"});
    rpg->dialogue->plage_ninja = fill_pnj(rpg, (sfVector2f){58.8, 72.8},
        (sfVector2f){195.2, 211.2},
        (char *[3]){my_scat(rpg->name, "/PNJ/pnj/green_nija.png"),
        my_scat(rpg->name, "/PNJ/pnj/plage_ninja.txt"), "DRAGOSITO"});
    creat_pnj_rest(rpg);
    init_shop_skill(rpg);
}
