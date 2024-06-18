/*
** EPITECH PROJECT, 2023
** my_custom_rectangle
** File description:
** Customize a rectangle
*/

#include <SFML/Audio.h>
#include <stdlib.h>

sfMusic *my_set_music(char *name, sfBool loop, float vol)
{
    sfMusic *music = sfMusic_createFromFile(name);

    if (music == NULL)
        exit(84);
    sfMusic_setLoop(music, loop);
    sfMusic_setVolume(music, vol);
    return (music);
}
