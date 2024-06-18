/*
** EPITECH PROJECT, 2023
** float.c
** File description:
** float
*/

#include "my.h"

int my_long(double nb, int modif_long)
{
    if (modif_long == 0) {
        modif_long = 6;
    }
    return (modif_long);
}

static int printnbf(double nb, double nbf, int reste, int modif_long)
{
    nbf = (nbf * my_compute_power_rec(10, modif_long)) + 0.5;
    nbf = nbf / my_compute_power_rec(10, modif_long);
    for (int i = 0; i < modif_long; i++) {
        reste = nbf;
        nbf = nbf - reste;
        nbf *= 10;
        reste = nbf;
        my_put_nbr(nbf);
    }
}

int my_put_float(double nb, int modif_long)
{
    int reste = nb;
    int fin = my_compute_power_rec(10, 7);
    long part2;
    int nb_of_caractere = 0;
    double nbf = nb;

    if (nb < 0) {
        my_putchar('-');
        nb_of_caractere++;
        nb = nb * (-1);
        nbf = nbf * (-1);
    }
    modif_long = my_long(nb, modif_long);
    my_put_nbr(nb);
    nb_of_caractere += my_intlen(nb);
    my_putchar('.');
    nb_of_caractere++;
    printnbf(nb, nbf, reste, modif_long);
    nb_of_caractere += modif_long;
    return (nb_of_caractere);
}
