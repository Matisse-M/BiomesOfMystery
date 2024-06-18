/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** edit_file
*/

#include "rpg.h"

FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);

    if (!file)
        return NULL;
    return file;
}

char **read_file(char *filename)
{
    FILE *file = open_file(filename, "r");
    char **array = calloc(1, sizeof(char *));
    char *buffer = NULL;
    size_t len[2] = {0};

    if (!file)
        return NULL;
    for (ssize_t read = getline(&buffer, &len[1], file); read != -1; read =
        getline(&buffer, &len[1], file)) {
        array = realloc(array, sizeof(char *) * (len[0] + 2));
        array[len[0]] = my_strdup(buffer);
        if (array[len[0]][my_strlen(array[len[0]]) - 1] == 10)
            array[len[0]][my_strlen(array[len[0]]) - 1] = 0;
        len[0]++;
    }
    array[len[0]] = NULL;
    fclose(file);
    return array;
}

void write_file(char *filename, char **array)
{
    FILE *file = open_file(filename, "w");

    if (!file)
        return;
    for (int i = 0; array[i]; i++)
        fwrite(array[i], 1, my_strlen(array[i]), file);
    fclose(file);
}
