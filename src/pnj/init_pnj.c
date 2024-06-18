/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_pnj
*/

#include "rpg.h"
#include <sys/stat.h>
#include <fcntl.h>


static sfSprite *my_sprite(sfTexture *texture, sfVector2f pos, sfVector2f size)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, size);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

char **read_text_file(const char *filename, int *line_count)
{
    char **temp = NULL;
    char *buf = NULL;
    int file = open(filename, O_RDONLY);
    struct stat stt;

    if (file == -1)
        exit(84);
    if (stat(filename, &stt) == -1)
        exit(84);
    buf = calloc(stt.st_size + 1, sizeof(char));
    read(file, buf, stt.st_size);
    close(file);
    temp = tok_word_array(buf, "~");
    return (temp);
}

static void create_and_check_assets(rpg_t *rpg, room_t *room, char **asset,
    char *filename)
{
    room->pnj_mat = malloc(sizeof(pnjs_t));
    room->pnj_mat->texture = malloc(sizeof(sfTexture *) * 2);
    room->pnj_mat->sprite = malloc(sizeof(sfSprite *) * 2);
    room->pnj_mat->texture[0] = sfTexture_createFromFile(asset[0], NULL);
    room->pnj_mat->texture[1] = sfTexture_createFromFile(asset[1], NULL);
    room->pnj_mat->box_texture = sfTexture_createFromFile(filename, NULL);
    if (!room->pnj_mat->texture[0] || !room->pnj_mat->texture[1] ||
        !room->pnj_mat->box_texture)
        exit(84);
}

void init_pnj(rpg_t *rpg, room_t *room, char **asset)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);
    char *filename = my_strdup(my_scat(rpg->name, "/img/dialog.png"));

    rpg->boss = fill_mapboss(rpg);
    create_and_check_assets(rpg, room, asset, filename);
    room->pnj_mat->sprite[0] = my_sprite(room->pnj_mat->texture[0],
        (sfVector2f) {653, 135}, (sfVector2f) {1, 1});
    sfSprite_setTextureRect(room->pnj_mat->sprite[0], (sfIntRect)
            {0, 0, 16, 16});
    room->pnj_mat->sprite[1] = my_sprite(room->pnj_mat->texture[1],
        (sfVector2f) {center.x - 284, center.y - 197}, (sfVector2f) {1, 1});
    room->pnj_mat->box_sprite = my_sprite(room->pnj_mat->box_texture,
        (sfVector2f) {center.x - 130, center.y - 120}, (sfVector2f) {1, 1});
}

void init_string(rpg_t *rpg, room_t *room)
{
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f c = sfView_getCenter(view);
    sfFont *font = sfFont_createFromFile(my_scat(rpg->name, rpg->font));

    room->pnj_mat->name = sfText_create();
    sfText_setString(room->pnj_mat->name, "MATHILDE");
    sfText_setFont(room->pnj_mat->name, font);
    sfText_setColor(room->pnj_mat->name, sfBlack);
    sfText_setCharacterSize(room->pnj_mat->name, 8);
    sfText_setPosition(room->pnj_mat->name, (sfVector2f)
        {c.x - 278, c.y - 210});
    room->pnj_mat->text = sfText_create();
    sfText_setFont(room->pnj_mat->text, font);
    sfText_setCharacterSize(room->pnj_mat->text, 12);
    sfText_setColor(room->pnj_mat->text, sfBlack);
    room->pnj_mat->lines = read_text_file(my_scat(rpg->name,
        "/PNJ/pnj/mathilde.txt"), &room->pnj_mat->line_count);
    room->pnj_mat->count_line = 0;
}

static void init_end_struct(rpg_t *rpg, room_t *room, sfVector2f center)
{
    rpg->maps->inter->sprite = my_sprite(rpg->maps->inter->texture,
        (sfVector2f) {center.x - 100, center.y - 300},
        (sfVector2f) {0.3, 0.3});
    room->pnj_mat->line_count = 0;
    init_string(rpg, room);
    rpg->maps->inter->enter = false;
    rpg->maps->inter->e_relased = false;
    room->pnj_mat->is_active = false;
    room->pnj_mat->can_interact = false;
    room->pnj_mat->i = 0;
    create_all_pnj(rpg);
}

void load_assets(rpg_t *rpg, room_t *room)
{
    char **asset = malloc(sizeof(char *) * 4);
    const sfView *view = sfRenderWindow_getView(rpg->game->window);
    sfVector2f center = sfView_getCenter(view);

    asset[0] = my_scat(rpg->name, "/PNJ/pnj/mathile.png");
    asset[1] = my_scat(rpg->name, "/PNJ/pnj/Facemathilde.png");
    asset[2] = my_scat(rpg->name, "/PNJ/pnj/inter.png");
    asset[3] = NULL;
    init_pnj(rpg, room, asset);
    rpg->maps->inter = malloc(sizeof(key_inter_t));
    rpg->maps->inter->clock_e = sfClock_create();
    rpg->maps->inter->clock_enter = sfClock_create();
    rpg->maps->inter->texture = sfTexture_createFromFile(asset[2], NULL);
    if (!rpg->maps->inter->texture)
        exit(84);
    init_end_struct(rpg, room, center);
    init_music(rpg);
    setup_piggies(rpg);
    rpg_is_open(rpg);
}
