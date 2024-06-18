/*
** EPITECH PROJECT, 2023
** setup player
** File description:
** Some function to setup <character_t *characters;> in rpg_t
*/

#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "csfml.h"
#include "my.h"
#include "rpg.h"
#include <string.h>

static sfTexture *create_asset_texture(char *path, char **array, char *name)
{
    sfTexture *texture = NULL;

    for (int i = 0; array[i] != NULL; i++) {
        if (strncmp(array[i], name, strlen(name)) == 0) {
            texture = sfTexture_createFromFile(my_scat(path, &array[i]
                [strlen(name)]), NULL);
            break;
        }
    }
    if (texture == NULL)
        exit(84);
    return texture;
}

static sfFont *create_asset_font(char *path, char **array, char *name)
{
    sfFont *font = NULL;

    for (int i = 0; array[i] != NULL; i++) {
        if (strncmp(array[i], name, strlen(name)) == 0) {
            font = sfFont_createFromFile(my_scate(path, &array[i]
                [strlen(name)]));
            break;
        }
    }
    if (font == NULL)
        exit(84);
    return font;
}

static char **open_asset_file(rpg_t *rpg)
{
    char *buffer = NULL;
    int fd = open(my_scat(rpg->name, "/ressources/assets.txt"), O_RDONLY);
    struct stat s;
    char **array = NULL;

    if (fd < 0)
        exit(84);
    if (stat(my_scat(rpg->name, "/ressources/assets.txt"), &s) < 0)
        exit(84);
    buffer = calloc(1, sizeof(char) * (s.st_size + 1));
    if (read(fd, buffer, s.st_size) < 0)
        exit(84);
    array = my_str_to_word_array(buffer);
    free(buffer);
    close(fd);
    return array;
}

static void fill_music(rpg_t *rpg, assets_t *assets)
{
    assets->music_menu = my_scat(rpg->name, "/ost/menu.ogg");
    assets->music_swamp = my_scat(rpg->name, "/ost/swamp.ogg");
    assets->music_beach = my_scat(rpg->name, "/ost/beach.ogg");
    assets->music_lighthouse = my_scat(rpg->name, "/ost/lighthouse.ogg");
    assets->music_shop = my_scat(rpg->name, "/ost/shop.ogg");
    assets->music_village = my_scat(rpg->name, "/ost/village.ogg");
    assets->music_museum = my_scat(rpg->name, "/ost/museum.ogg");
    assets->music_cave = my_scat(rpg->name, "/ost/cave.ogg");
    assets->music_donjon = my_scat(rpg->name, "/ost/donjon.ogg");
    assets->music_rajah = my_scat(rpg->name, "/ost/rajah.ogg");
    assets->music_final = my_scat(rpg->name, "/ost/final_fight.ogg");
}

static void fill_bars(rpg_t *rpg, assets_t *assets, char **array)
{
    assets->bar80 = create_asset_texture(rpg->name, array, "BAR80=");
    assets->bar60 = create_asset_texture(rpg->name, array, "BAR60=");
    assets->bar40 = create_asset_texture(rpg->name, array, "BAR40=");
    assets->bar20 = create_asset_texture(rpg->name, array, "BAR20=");
    assets->bar0 = create_asset_texture(rpg->name, array, "BAR0=");
    assets->barback = create_asset_texture(rpg->name, array, "BARBACK=");
    assets->animals = create_asset_texture(rpg->name, array, "ANIMAL=");
    assets->expbar = create_asset_texture(rpg->name, array, "EXPBAR=");
}

static void fill_enemies_dlc(rpg_t *rpg, assets_t *assets, char **array)
{
    assets->frog_hit = create_asset_texture(rpg->name, array, "FROG_HIT=");
    assets->bfire_hit = create_asset_texture(rpg->name, array, "BFLAME_HIT=");
    assets->bice_hit = create_asset_texture(rpg->name, array, "BICE_HIT=");
    assets->cyclop_hit = create_asset_texture(rpg->name, array, "CYCLOP_HIT=");
    assets->rajah_hit = create_asset_texture(rpg->name, array, "RAJAH_HIT=");
    fill_music(rpg, assets);
    assets->fire_spell = create_asset_texture(rpg->name, array, "FIRE_SPELL=");
    assets->ice_spell = create_asset_texture(rpg->name, array, "ICE_SPELL=");
    assets->stone_spell = create_asset_texture(rpg->name, array,
        "STONE_SPELL=");
}

static void fill_enemies(rpg_t *rpg, assets_t *assets, char **array)
{
    assets->slime = create_asset_texture(rpg->name, array, "SLIME=");
    assets->mole = create_asset_texture(rpg->name, array, "MOLE=");
    assets->larva = create_asset_texture(rpg->name, array, "LARVA=");
    assets->shroom = create_asset_texture(rpg->name, array, "SHROOM=");
    assets->bamboo = create_asset_texture(rpg->name, array, "BAMBOO=");
    assets->burner = create_asset_texture(rpg->name, array, "BURNER=");
    assets->freezer = create_asset_texture(rpg->name, array, "FREEZER=");
    assets->skull = create_asset_texture(rpg->name, array, "SKULL=");
    assets->eye = create_asset_texture(rpg->name, array, "EYE=");
    assets->blob = create_asset_texture(rpg->name, array, "BLOB=");
    assets->frog = create_asset_texture(rpg->name, array, "FROG=");
    assets->bfire = create_asset_texture(rpg->name, array, "BFLAME=");
    assets->bice = create_asset_texture(rpg->name, array, "BICE=");
    assets->cyclop = create_asset_texture(rpg->name, array, "CYCLOP=");
    assets->rajah = create_asset_texture(rpg->name, array, "RAJAH=");
}

static void fill_buttons(rpg_t *rpg, assets_t *assets, char **array)
{
    assets->btn1 = create_asset_texture(rpg->name, array, "BTN1=");
    assets->btn2 = create_asset_texture(rpg->name, array, "BTN2=");
    assets->btn3 = create_asset_texture(rpg->name, array, "BTN3=");
    assets->btn4 = create_asset_texture(rpg->name, array, "BTN4=");
    assets->box1 = create_asset_texture(rpg->name, array, "BOX1=");
    assets->box1h = create_asset_texture(rpg->name, array, "BOX1H=");
    assets->box2 = create_asset_texture(rpg->name, array, "BOX2=");
    assets->box2h = create_asset_texture(rpg->name, array, "BOX2H=");
    assets->box3 = create_asset_texture(rpg->name, array, "BOX3=");
    assets->wrong = create_asset_texture(rpg->name, array, "WRONG=");
    assets->bar100 = create_asset_texture(rpg->name, array, "BAR100=");
}

void fill_arrows(rpg_t *rpg, assets_t *assets, char **array)
{
    assets->arrow0 = create_asset_texture(rpg->name, array, "ARROW0=");
    assets->arrow1 = create_asset_texture(rpg->name, array, "ARROW1=");
    assets->arrow2 = create_asset_texture(rpg->name, array, "ARROW2=");
    assets->arrow3 = create_asset_texture(rpg->name, array, "ARROW3=");
    assets->info_bar = create_asset_texture(rpg->name, array, "INFO_BAR=");
    assets->settings_bg = create_asset_texture(rpg->name, array,
        "SETTINGS_BG=");
}

assets_t *fill_assets_struct(rpg_t *rpg)
{
    assets_t *assets = malloc(sizeof(assets_t));
    char **array = open_asset_file(rpg);

    rpg->font = strdup("/font.ttf");
    assets->font = create_asset_font(rpg->name, array, "FONT=");
    assets->swamp = create_asset_texture(rpg->name, array, "SWAMP=");
    assets->dungeon = create_asset_texture(rpg->name, array, "DUNGEON=");
    assets->grocery = create_asset_texture(rpg->name, array, "GROCERY=");
    fill_arrows(rpg, assets, array);
    fill_buttons(rpg, assets, array);
    fill_bars(rpg, assets, array);
    fill_enemies(rpg, assets, array);
    fill_enemies_dlc(rpg, assets, array);
    assets->splash = sfTexture_createFromFile
        (my_scat(rpg->name, "/img/kamastudio.png"), NULL);
    return assets;
}
