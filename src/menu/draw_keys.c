/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** draw_keys
*/

#include "rpg.h"

static void draw_zqsd_game(rpg_t *rpg)
{
    if (button_view_hover(rpg, rpg->key_board->right_param) == 1) {
        key_zqsd(rpg);
        rpg->key_board->right_bool = true;
        rpg->key_board->left_bool = false;
        rpg->key_board->left_param->state = 0;
    }
    if (rpg->key_board->right_bool == true)
        rpg->key_board->right_param->state = 3;
    sfRectangleShape_setTexture(rpg->key_board->right_param->rect,
        rpg->key_board->right_param->texture
        [rpg->key_board->right_param->state], sfTrue);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->key_board->right_param->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->key_board->right_param->text, NULL);
}

void set_in_game_pos(rpg_t *rpg, sfVector2f left)
{
    sfRectangleShape_setPosition(rpg->key_board->left_param->rect,
        (sfVector2f){left.x - 40, left.y - 80});
    sfRectangleShape_setPosition(rpg->key_board->right_param->rect,
        (sfVector2f){left.x - 40, left.y - 35});
    sfText_setPosition(rpg->key_board->left_param->text,
        (sfVector2f){left.x - 35, left.y - 77});
    sfText_setPosition(rpg->key_board->right_param->text,
        (sfVector2f){left.x - 35, left.y - 32});
    sfRectangleShape_setTexture(rpg->key_board->left_param->rect,
        rpg->key_board->left_param->texture
        [rpg->key_board->left_param->state], sfTrue);
}

void draw_key_game(rpg_t *rpg)
{
    sfVector2f left = sfView_getCenter(rpg->game->view);

    if (button_view_hover(rpg, rpg->key_board->left_param) == 1) {
        key_arrows(rpg);
        rpg->key_board->right_bool = false;
        rpg->key_board->left_bool = true;
        rpg->key_board->right_param->state = 0;
    }
    if (rpg->key_board->left_bool == true)
        rpg->key_board->left_param->state = 3;
    set_in_game_pos(rpg, left);
    sfRenderWindow_drawRectangleShape(rpg->game->window,
        rpg->key_board->left_param->rect, NULL);
    sfRenderWindow_drawText(rpg->game->window,
        rpg->key_board->left_param->text, NULL);
    draw_zqsd_game(rpg);
}
