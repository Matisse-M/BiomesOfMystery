/*
** EPITECH PROJECT, 2023
** my_float_len.c
** File description:
** my_floatlen
*/

#include "my.h"

int my_float_len(double nb, int len)
{
    int integer = nb;

    return (my_intlen(integer) + len + 1);
}
