/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_pnj
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "rpg.h"

void init_music(rpg_t *rpg)
{
    sfMusic_play(rpg->game->music);
    sfMusic_setVolume(rpg->game->music, 100);
    init_keys(rpg);
}

void modif_music(rpg_t *rpg, char *path)
{
    sfMusic_stop(rpg->game->music);
    sfMusic_destroy(rpg->game->music);
    rpg->game->music = sfMusic_createFromFile(path);
    sfMusic_setLoop(rpg->game->music, sfTrue);
    sfMusic_setVolume(rpg->game->music, rpg->game->vol_music * 20);
    sfMusic_play(rpg->game->music);
}

void music_fight(rpg_t *rpg)
{
    if (rpg->fight->music == false)
        modif_music(rpg, rpg->assets->music_final);
}
