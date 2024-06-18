/*
** EPITECH PROJECT, 2023
** my_longlen
** File description:
** Return the length of a long
*/

int my_longlen(long nb)
{
    int i = 0;

    while (nb / 10 > 0) {
        i++;
        nb /= 10;
    }
    i++;
    return (i);
}
