/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Return the length of a string
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int my_arrlen(char **arr)
{
    int i = 0;

    if (!arr)
        return 0;
    while (arr[i])
        i++;
    return i;
}
