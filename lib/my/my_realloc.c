/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** write a charcter string
*/

#include <stdlib.h>
#include "my.h"

char *my_realloc(char *array, int size)
{
    char *new = NULL;

    if (array == NULL) {
        new = malloc(sizeof(char) * 2);
        for (int i = 0; i < 2; i++)
            new[i] = '\0';
        return new;
    }
    new = malloc(sizeof(char) * (my_strlen(array) + size + 1));
    for (int i = 0; i < my_strlen(array); i++)
        new[i] = array[i];
    for (int i = 0; i <= size; i++)
        new[my_strlen(array) + i] = '\0';
    return new;
}

char **my_realloc2(char **array, int size)
{
    char **new = NULL;

    if (array == NULL) {
        new = malloc(sizeof(char *) * 2);
        for (int i = 0; i < 2; i++)
            new[i] = NULL;
        return new;
    }
    new = malloc(sizeof(char *) * (my_tablen(array) + size + 1));
    for (int i = 0; i < my_tablen(array); i++)
        new[i] = my_strdup(array[i]);
    for (int i = 0; i <= size; i++)
        new[my_tablen(array) + i] = NULL;
    return new;
}
