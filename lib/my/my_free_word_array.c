/*
** EPITECH PROJECT, 2023
** my_free_word_array
** File description:
** Remove content of a word array
*/

#include <stdlib.h>

void my_free_word_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    if (array != NULL)
        free(array);
}
