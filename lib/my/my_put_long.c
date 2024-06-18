/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Display a int
*/

#include "my.h"
#include <stdio.h>

int my_put_long(long nb)
{
    long n = nb;

    if (nb < 0) {
        my_putchar('-');
        n *= -1;
    }
    if (n / 10 != 0)
        my_put_long(n / 10);
    if (n % 10 >= 0) {
        my_putchar(n % 10 + '0');
        return (0);
    }
    return (0);
}
