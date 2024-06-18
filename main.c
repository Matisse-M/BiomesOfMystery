/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include "rpg.h"

int helper(void)
{
    puts("USAGE\n\t./my_rpg\n\nDESCRIPTION\n\tOur RPG game");
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && (strncmp(av[1], "-h", 2) == 0 ||
        strncmp(av[1], "--help", 6) == 0))
        return helper();
    if (ac != 1)
        return 84;
    my_rpg();
    return 0;
}
