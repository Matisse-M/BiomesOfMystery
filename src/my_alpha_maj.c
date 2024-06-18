/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rpg.h"
#include "csfml.h"
#include "my.h"

static void put_alpha1(rpg_t *rpg, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'A');
    if (sfKeyboard_isKeyPressed(sfKeyB) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'B');
    if (sfKeyboard_isKeyPressed(sfKeyC) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'C');
    if (sfKeyboard_isKeyPressed(sfKeyD) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'D');
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'E');
}

static void put_alpha2(rpg_t *rpg, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyF) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'F');
    if (sfKeyboard_isKeyPressed(sfKeyG) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'G');
    if (sfKeyboard_isKeyPressed(sfKeyH) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'H');
    if (sfKeyboard_isKeyPressed(sfKeyI) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'I');
    if (sfKeyboard_isKeyPressed(sfKeyJ) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'J');
}

static void put_alpha3(rpg_t *rpg, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyK) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'K');
    if (sfKeyboard_isKeyPressed(sfKeyL) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'L');
    if (sfKeyboard_isKeyPressed(sfKeyM) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'M');
    if (sfKeyboard_isKeyPressed(sfKeyN) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'N');
    if (sfKeyboard_isKeyPressed(sfKeyO) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'O');
}

static void put_alpha4(rpg_t *rpg, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyP) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'P');
    if (sfKeyboard_isKeyPressed(sfKeyQ) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'Q');
    if (sfKeyboard_isKeyPressed(sfKeyR) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'R');
    if (sfKeyboard_isKeyPressed(sfKeyS) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'S');
    if (sfKeyboard_isKeyPressed(sfKeyT) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'T');
}

static void put_alpha5(rpg_t *rpg, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyU) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'U');
    if (sfKeyboard_isKeyPressed(sfKeyV) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'V');
    if (sfKeyboard_isKeyPressed(sfKeyW) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'W');
    if (sfKeyboard_isKeyPressed(sfKeyX) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'X');
    if (sfKeyboard_isKeyPressed(sfKeyY) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'Y');
    if (sfKeyboard_isKeyPressed(sfKeyZ) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_name(rpg, clock, 'Z');
}

void my_alpha_maj(rpg_t *rpg, sfClock **clock, float f)
{
    put_alpha1(rpg, clock, f);
    put_alpha2(rpg, clock, f);
    put_alpha3(rpg, clock, f);
    put_alpha4(rpg, clock, f);
    put_alpha5(rpg, clock, f);
}
