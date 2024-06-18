/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** key_handler
*/

#include "rpg.h"

void modify_key_pos(rpg_t *rpg, sfVector2f left, sfVector2f right)
{
    sfRectangleShape_setPosition(rpg->key_board->left_btn->rect, left);
    sfText_setPosition(rpg->key_board->left_btn->text, (sfVector2f)
        {left.x + 40, left.y + 20});
    sfRectangleShape_setPosition(rpg->key_board->right_btn->rect, right);
    sfText_setPosition(rpg->key_board->right_btn->text, (sfVector2f)
        {right.x + 40, right.y + 20});
    sfRectangleShape_setPosition(rpg->key_board->left_btn->rect, left);
    sfText_setPosition(rpg->key_board->left_param->text, (sfVector2f)
        {left.x + 40, left.y + 20});
    sfRectangleShape_setPosition(rpg->key_board->right_param->rect, right);
    sfText_setPosition(rpg->key_board->right_btn->text, (sfVector2f)
        {right.x + 40, right.y + 20});
}

void key_zqsd(rpg_t *rpg)
{
    rpg->key_board->up = sfKeyZ;
    rpg->key_board->down = sfKeyS;
    rpg->key_board->left = sfKeyQ;
    rpg->key_board->right = sfKeyD;
}

void key_arrows(rpg_t *rpg)
{
    rpg->key_board->up = sfKeyUp;
    rpg->key_board->down = sfKeyDown;
    rpg->key_board->left = sfKeyLeft;
    rpg->key_board->right = sfKeyRight;
}

void create_key_button(rpg_t *rpg)
{
    rpg->key_board->left_btn = create_button_arrow((sfVector2f){170, 530},
        rpg->assets, (sfVector2f){210, 550}, "KEY TYPE :\n    A R R O W");
    rpg->key_board->right_btn = create_button_arrow((sfVector2f){980, 530},
        rpg->assets, (sfVector2f){1000, 550}, "KEY TYPE :\n    Z Q S D");
    rpg->key_board->left_param = create_button_arrow_game((sfVector2f)
        {170, 530}, rpg->assets, (sfVector2f){210, 550},
        "KEY TYPE :\n    A R R O W");
    rpg->key_board->right_param = create_button_arrow_game(
        (sfVector2f){980, 530}, rpg->assets, (sfVector2f){1000, 550},
        "KEY TYPE :\n    Z Q S D");
}

void init_keys(rpg_t *rpg)
{
    rpg->key_board = malloc(sizeof(key_board_t));
    rpg->key_board->up = sfKeyUp;
    rpg->key_board->down = sfKeyDown;
    rpg->key_board->left = sfKeyLeft;
    rpg->key_board->right = sfKeyRight;
    rpg->key_board->left_bool = false;
    rpg->key_board->right_bool = false;
    create_key_button(rpg);
}
