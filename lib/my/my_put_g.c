/*
** EPITECH PROJECT, 2023
** my_put_g
** File description:
** my_put_g
*/
#include "my.h"
#include <stdio.h>

static int printnbf(double nbf, int reste)
{
    int nbreste = nbf;
    int count = 0;
    double nb1;
    int nb = my_compute_power_rec(10, 4);

    nbf = (nbf * 1000000) + 0.5;
    nbf = nbf / 1000000;
    nb1 = nbf - nbreste;
    nbreste = nb1 * 10000;
    while (nbreste % 10 == 0) {
        nbreste = nbreste / 10;
    }
    count = my_intlen(nbreste);
    for (int i = 0; i < count; i++) {
        reste = nbf;
        nbf = nbf - reste;
        nbf *= 10;
        reste = nbf;
        my_put_nbr(nbf);
    }
}

int my_put_g(double nb)
{
    int reste = nb;
    long part2;
    int nb_of_caractere = 0;
    double nbf = nb;

    if (nb == reste) {
        my_put_nbr(reste);
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb_of_caractere++;
        nb = nb * (-1);
    }
    my_put_nbr(nb);
    nb_of_caractere += my_intlen(nb);
    my_putchar('.');
    nb_of_caractere++;
    printnbf(nbf, reste);
    nb_of_caractere += 6;
}
