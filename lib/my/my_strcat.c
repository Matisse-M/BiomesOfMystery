/*
** EPITECH PROJECT, 2023
** my_cat
** File description:
** Concatenates 2 strings
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    char *result = malloc(sizeof(char) * (len_dest + len_src + 1));

    if (!result || !dest || !src)
        return NULL;
    for (; i < len_dest; i++)
        result[i] = dest[i];
    for (int j = 0; j < len_src; j++) {
        result[i] = src[j];
        i++;
    }
    result[i] = '\0';
    return (result);
}

char *my_tac(char *src, char *dest)
{
    char *temp = my_strdup(src);
    char *result = strcat(temp, dest);

    return (result);
}

char *my_scat(char *destination, char *source)
{
    char *temp = strdup(destination);
    int len_dest = my_strlen(destination);
    int len_src = my_strlen(source);
    char *res = malloc(sizeof(char) * (len_dest + len_src + 1));

    if (res == NULL) {
        exit(84);
    }
    strcpy(res, temp);
    strcat(res, source);
    if (temp != NULL)
        free(temp);
    return res;
}

const char *my_scate(char *destination, const char *source)
{
    char *temp = strdup(destination);
    int len_dest = my_strlen(destination);
    int len_src = my_strlen(source);
    const char *res = malloc(sizeof(char) * (len_dest + len_src + 1));

    if (res == NULL) {
        exit(84);
    }
    strcpy((char *)res, temp);
    strcat((char *)res, source);
    if (temp != NULL)
        free(temp);
    return (const char *)res;
}
